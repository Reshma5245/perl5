/* This is SipHash by Jean-Philippe Aumasson and Daniel J.  Bernstein.  The
 * authors claim it is relatively secure compared to the alternatives and that
 * performance wise it is a suitable hash for languages like Perl.  See:
 *
 * https://www.131002.net/siphash/
 *
 * This implementation seems to perform slightly slower than one-at-a-time for
 * short keys, but degrades slower for longer keys.  Murmur Hash outperforms
 * it regardless of keys size.
 *
 * It is 64 bit only.
 */

#ifdef CAN64BITHASH

#define SIPROUND                                                \
    STMT_START {                                                \
        v0 += v1; v1=ROTL64(v1,13); v1 ^= v0; v0=ROTL64(v0,32); \
        v2 += v3; v3=ROTL64(v3,16); v3 ^= v2;                   \
        v0 += v3; v3=ROTL64(v3,21); v3 ^= v0;                   \
        v2 += v1; v1=ROTL64(v1,17); v1 ^= v2; v2=ROTL64(v2,32); \
    } STMT_END

#define SIPHASH_SEED_STATE(key,v0,v1,v2,v3)     \
    do {                                        \
        v0 = v2 = U8TO64_LE(key + 0);           \
        v1 = v3 = U8TO64_LE(key + 8);           \
      /* "somepseudorandomlygeneratedbytes" */  \
        v0 ^= UINT64_C(0x736f6d6570736575);     \
        v1 ^= UINT64_C(0x646f72616e646f6d);     \
        v2 ^= UINT64_C(0x6c7967656e657261);     \
        v3 ^= UINT64_C(0x7465646279746573);     \
    } while (0)

PERL_STATIC_INLINE
void S_perl_siphash_seed_state(const unsigned char * const seed_buf, unsigned char * state_buf) {
    U64 *v= (U64*) state_buf;
    SIPHASH_SEED_STATE(seed_buf, v[0],v[1],v[2],v[3]);
}

#define PERL_SIPHASH_FNC(FNC,SIP_ROUNDS,SIP_FINAL_ROUNDS)                               \
    PERL_STATIC_INLINE U64                                                              \
    FNC ## _with_state_64                                                               \
      (const unsigned char * const state, const unsigned char *in, const STRLEN inlen)  \
    {                                                                                   \
      const int left = inlen & 7;                                                       \
      const U8 *end = in + inlen - left;                                                \
                                                                                        \
      U64 b = ( ( U64 )(inlen) ) << 56;                                                 \
      U64 m;                                                                            \
      U64 v0 = U8TO64_LE(state);                                                        \
      U64 v1 = U8TO64_LE(state+8);                                                      \
      U64 v2 = U8TO64_LE(state+16);                                                     \
      U64 v3 = U8TO64_LE(state+24);                                                     \
                                                                                        \
      for (; in != end; in += 8 )                                                       \
      {                                                                                 \
        m = U8TO64_LE( in );                                                            \
        v3 ^= m;                                                                        \
                                                                                        \
        SIP_ROUNDS;                                                                     \
                                                                                        \
        v0 ^= m;                                                                        \
      }                                                                                 \
                                                                                        \
      switch( left )                                                                    \
      {                                                                                 \
      case 7: b |= ( ( U64 )in[ 6] )  << 48; /*FALLTHROUGH */                           \
      case 6: b |= ( ( U64 )in[ 5] )  << 40; /*FALLTHROUGH */                           \
      case 5: b |= ( ( U64 )in[ 4] )  << 32; /*FALLTHROUGH */                           \
      case 4: b |= ( ( U64 )in[ 3] )  << 24; /*FALLTHROUGH */                           \
      case 3: b |= ( ( U64 )in[ 2] )  << 16; /*FALLTHROUGH */                           \
      case 2: b |= ( ( U64 )in[ 1] )  <<  8; /*FALLTHROUGH */                           \
      case 1: b |= ( ( U64 )in[ 0] ); break;                                            \
      case 0: break;                                                                    \
      }                                                                                 \
                                                                                        \
      v3 ^= b;                                                                          \
                                                                                        \
      SIP_ROUNDS;                                                                       \
                                                                                        \
      v0 ^= b;                                                                          \
                                                                                        \
      v2 ^= 0xff;                                                                       \
                                                                                        \
      SIP_FINAL_ROUNDS                                                                  \
                                                                                        \
      b = v0 ^ v1 ^ v2  ^ v3;                                                           \
      return b;                                                                         \
    }                                                                                   \
                                                                                        \
    PERL_STATIC_INLINE U32                                                              \
    FNC ## _with_state                                                                  \
      (const unsigned char * const state, const unsigned char *in, const STRLEN inlen)  \
    {                                                                                   \
        union {                                                                         \
            U64 h64;                                                                    \
            U32 h32[2];                                                                 \
        } h;                                                                            \
        h.h64= FNC ## _with_state_64(state,in,inlen);                                   \
        return h.h32[0] ^ h.h32[1];                                                     \
    }                                                                                   \
                                                                                        \
                                                                                        \
    PERL_STATIC_INLINE U32                                                              \
    FNC (const unsigned char * const seed, const unsigned char *in, const STRLEN inlen) \
    {                                                                                   \
        U64 state[4];                                                                   \
        SIPHASH_SEED_STATE(seed,state[0],state[1],state[2],state[3]);                   \
        return FNC ## _with_state((U8*)state,in,inlen);                                 \
    }


PERL_SIPHASH_FNC(
    S_perl_hash_siphash_1_3
    ,SIPROUND;
    ,SIPROUND;SIPROUND;SIPROUND;
)

PERL_SIPHASH_FNC(
    S_perl_hash_siphash_2_4
    ,SIPROUND;SIPROUND;
    ,SIPROUND;SIPROUND;SIPROUND;SIPROUND;
)

#endif /* defined(CAN64BITHASH) */
