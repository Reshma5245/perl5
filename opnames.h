/* -*- mode: C; buffer-read-only: t -*-
 *
 *    opnames.h
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
 *    2008 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/opcode.pl from its data.
 * Any changes made here will be lost!
 */

typedef enum opcode {
	OP_NULL		 = 0,
	OP_STUB		 = 1,
	OP_SCALAR	 = 2,
	OP_PUSHMARK	 = 3,
	OP_WANTARRAY	 = 4,
	OP_CONST	 = 5,
	OP_GVSV		 = 6,
	OP_GV		 = 7,
	OP_GELEM	 = 8,
	OP_PADSV	 = 9,
	OP_PADSV_STORE	 = 10,
	OP_PADAV	 = 11,
	OP_PADHV	 = 12,
	OP_PADANY	 = 13,
	OP_RV2GV	 = 14,
	OP_RV2SV	 = 15,
	OP_AV2ARYLEN	 = 16,
	OP_RV2CV	 = 17,
	OP_ANONCODE	 = 18,
	OP_PROTOTYPE	 = 19,
	OP_REFGEN	 = 20,
	OP_SREFGEN	 = 21,
	OP_REF		 = 22,
	OP_BLESS	 = 23,
	OP_BACKTICK	 = 24,
	OP_GLOB		 = 25,
	OP_READLINE	 = 26,
	OP_RCATLINE	 = 27,
	OP_REGCMAYBE	 = 28,
	OP_REGCRESET	 = 29,
	OP_REGCOMP	 = 30,
	OP_MATCH	 = 31,
	OP_QR		 = 32,
	OP_SUBST	 = 33,
	OP_SUBSTCONT	 = 34,
	OP_TRANS	 = 35,
	OP_TRANSR	 = 36,
	OP_SASSIGN	 = 37,
	OP_AASSIGN	 = 38,
	OP_CHOP		 = 39,
	OP_SCHOP	 = 40,
	OP_CHOMP	 = 41,
	OP_SCHOMP	 = 42,
	OP_DEFINED	 = 43,
	OP_UNDEF	 = 44,
	OP_STUDY	 = 45,
	OP_POS		 = 46,
	OP_PREINC	 = 47,
	OP_I_PREINC	 = 48,
	OP_PREDEC	 = 49,
	OP_I_PREDEC	 = 50,
	OP_POSTINC	 = 51,
	OP_I_POSTINC	 = 52,
	OP_POSTDEC	 = 53,
	OP_I_POSTDEC	 = 54,
	OP_POW		 = 55,
	OP_MULTIPLY	 = 56,
	OP_I_MULTIPLY	 = 57,
	OP_DIVIDE	 = 58,
	OP_I_DIVIDE	 = 59,
	OP_MODULO	 = 60,
	OP_I_MODULO	 = 61,
	OP_REPEAT	 = 62,
	OP_ADD		 = 63,
	OP_I_ADD	 = 64,
	OP_SUBTRACT	 = 65,
	OP_I_SUBTRACT	 = 66,
	OP_CONCAT	 = 67,
	OP_MULTICONCAT	 = 68,
	OP_STRINGIFY	 = 69,
	OP_LEFT_SHIFT	 = 70,
	OP_RIGHT_SHIFT	 = 71,
	OP_LT		 = 72,
	OP_I_LT		 = 73,
	OP_GT		 = 74,
	OP_I_GT		 = 75,
	OP_LE		 = 76,
	OP_I_LE		 = 77,
	OP_GE		 = 78,
	OP_I_GE		 = 79,
	OP_EQ		 = 80,
	OP_I_EQ		 = 81,
	OP_NE		 = 82,
	OP_I_NE		 = 83,
	OP_NCMP		 = 84,
	OP_I_NCMP	 = 85,
	OP_SLT		 = 86,
	OP_SGT		 = 87,
	OP_SLE		 = 88,
	OP_SGE		 = 89,
	OP_SEQ		 = 90,
	OP_SNE		 = 91,
	OP_SCMP		 = 92,
	OP_BIT_AND	 = 93,
	OP_BIT_XOR	 = 94,
	OP_BIT_OR	 = 95,
	OP_NBIT_AND	 = 96,
	OP_NBIT_XOR	 = 97,
	OP_NBIT_OR	 = 98,
	OP_SBIT_AND	 = 99,
	OP_SBIT_XOR	 = 100,
	OP_SBIT_OR	 = 101,
	OP_NEGATE	 = 102,
	OP_I_NEGATE	 = 103,
	OP_NOT		 = 104,
	OP_COMPLEMENT	 = 105,
	OP_NCOMPLEMENT	 = 106,
	OP_SCOMPLEMENT	 = 107,
	OP_SMARTMATCH	 = 108,
	OP_ATAN2	 = 109,
	OP_SIN		 = 110,
	OP_COS		 = 111,
	OP_RAND		 = 112,
	OP_SRAND	 = 113,
	OP_EXP		 = 114,
	OP_LOG		 = 115,
	OP_SQRT		 = 116,
	OP_INT		 = 117,
	OP_HEX		 = 118,
	OP_OCT		 = 119,
	OP_ABS		 = 120,
	OP_LENGTH	 = 121,
	OP_SUBSTR	 = 122,
	OP_VEC		 = 123,
	OP_INDEX	 = 124,
	OP_RINDEX	 = 125,
	OP_SPRINTF	 = 126,
	OP_FORMLINE	 = 127,
	OP_ORD		 = 128,
	OP_CHR		 = 129,
	OP_CRYPT	 = 130,
	OP_UCFIRST	 = 131,
	OP_LCFIRST	 = 132,
	OP_UC		 = 133,
	OP_LC		 = 134,
	OP_QUOTEMETA	 = 135,
	OP_RV2AV	 = 136,
	OP_AELEMFAST	 = 137,
	OP_AELEMFAST_LEX = 138,
	OP_AELEMFASTLEX_STORE = 139,
	OP_AELEM	 = 140,
	OP_ASLICE	 = 141,
	OP_KVASLICE	 = 142,
	OP_AEACH	 = 143,
	OP_AVALUES	 = 144,
	OP_AKEYS	 = 145,
	OP_EACH		 = 146,
	OP_VALUES	 = 147,
	OP_KEYS		 = 148,
	OP_DELETE	 = 149,
	OP_EXISTS	 = 150,
	OP_RV2HV	 = 151,
	OP_HELEM	 = 152,
	OP_HSLICE	 = 153,
	OP_KVHSLICE	 = 154,
	OP_MULTIDEREF	 = 155,
	OP_UNPACK	 = 156,
	OP_PACK		 = 157,
	OP_SPLIT	 = 158,
	OP_JOIN		 = 159,
	OP_LIST		 = 160,
	OP_LSLICE	 = 161,
	OP_ANONLIST	 = 162,
	OP_ANONHASH	 = 163,
	OP_EMPTYAVHV	 = 164,
	OP_SPLICE	 = 165,
	OP_PUSH		 = 166,
	OP_POP		 = 167,
	OP_SHIFT	 = 168,
	OP_UNSHIFT	 = 169,
	OP_SORT		 = 170,
	OP_REVERSE	 = 171,
	OP_GREPSTART	 = 172,
	OP_GREPWHILE	 = 173,
	OP_MAPSTART	 = 174,
	OP_MAPWHILE	 = 175,
	OP_RANGE	 = 176,
	OP_FLIP		 = 177,
	OP_FLOP		 = 178,
	OP_AND		 = 179,
	OP_OR		 = 180,
	OP_XOR		 = 181,
	OP_DOR		 = 182,
	OP_COND_EXPR	 = 183,
	OP_ANDASSIGN	 = 184,
	OP_ORASSIGN	 = 185,
	OP_DORASSIGN	 = 186,
	OP_ENTERSUB	 = 187,
	OP_LEAVESUB	 = 188,
	OP_LEAVESUBLV	 = 189,
	OP_ARGCHECK	 = 190,
	OP_ARGELEM	 = 191,
	OP_ARGDEFELEM	 = 192,
	OP_CALLER	 = 193,
	OP_WARN		 = 194,
	OP_DIE		 = 195,
	OP_RESET	 = 196,
	OP_LINESEQ	 = 197,
	OP_NEXTSTATE	 = 198,
	OP_DBSTATE	 = 199,
	OP_UNSTACK	 = 200,
	OP_ENTER	 = 201,
	OP_LEAVE	 = 202,
	OP_SCOPE	 = 203,
	OP_ENTERITER	 = 204,
	OP_ITER		 = 205,
	OP_ENTERLOOP	 = 206,
	OP_LEAVELOOP	 = 207,
	OP_RETURN	 = 208,
	OP_LAST		 = 209,
	OP_NEXT		 = 210,
	OP_REDO		 = 211,
	OP_DUMP		 = 212,
	OP_GOTO		 = 213,
	OP_EXIT		 = 214,
	OP_METHOD	 = 215,
	OP_METHOD_NAMED	 = 216,
	OP_METHOD_SUPER	 = 217,
	OP_METHOD_REDIR	 = 218,
	OP_METHOD_REDIR_SUPER = 219,
	OP_ENTERGIVEN	 = 220,
	OP_LEAVEGIVEN	 = 221,
	OP_ENTERWHEN	 = 222,
	OP_LEAVEWHEN	 = 223,
	OP_BREAK	 = 224,
	OP_CONTINUE	 = 225,
	OP_OPEN		 = 226,
	OP_CLOSE	 = 227,
	OP_PIPE_OP	 = 228,
	OP_FILENO	 = 229,
	OP_UMASK	 = 230,
	OP_BINMODE	 = 231,
	OP_TIE		 = 232,
	OP_UNTIE	 = 233,
	OP_TIED		 = 234,
	OP_DBMOPEN	 = 235,
	OP_DBMCLOSE	 = 236,
	OP_SSELECT	 = 237,
	OP_SELECT	 = 238,
	OP_GETC		 = 239,
	OP_READ		 = 240,
	OP_ENTERWRITE	 = 241,
	OP_LEAVEWRITE	 = 242,
	OP_PRTF		 = 243,
	OP_PRINT	 = 244,
	OP_SAY		 = 245,
	OP_SYSOPEN	 = 246,
	OP_SYSSEEK	 = 247,
	OP_SYSREAD	 = 248,
	OP_SYSWRITE	 = 249,
	OP_EOF		 = 250,
	OP_TELL		 = 251,
	OP_SEEK		 = 252,
	OP_TRUNCATE	 = 253,
	OP_FCNTL	 = 254,
	OP_IOCTL	 = 255,
	OP_FLOCK	 = 256,
	OP_SEND		 = 257,
	OP_RECV		 = 258,
	OP_SOCKET	 = 259,
	OP_SOCKPAIR	 = 260,
	OP_BIND		 = 261,
	OP_CONNECT	 = 262,
	OP_LISTEN	 = 263,
	OP_ACCEPT	 = 264,
	OP_SHUTDOWN	 = 265,
	OP_GSOCKOPT	 = 266,
	OP_SSOCKOPT	 = 267,
	OP_GETSOCKNAME	 = 268,
	OP_GETPEERNAME	 = 269,
	OP_LSTAT	 = 270,
	OP_STAT		 = 271,
	OP_FTRREAD	 = 272,
	OP_FTRWRITE	 = 273,
	OP_FTREXEC	 = 274,
	OP_FTEREAD	 = 275,
	OP_FTEWRITE	 = 276,
	OP_FTEEXEC	 = 277,
	OP_FTIS		 = 278,
	OP_FTSIZE	 = 279,
	OP_FTMTIME	 = 280,
	OP_FTATIME	 = 281,
	OP_FTCTIME	 = 282,
	OP_FTROWNED	 = 283,
	OP_FTEOWNED	 = 284,
	OP_FTZERO	 = 285,
	OP_FTSOCK	 = 286,
	OP_FTCHR	 = 287,
	OP_FTBLK	 = 288,
	OP_FTFILE	 = 289,
	OP_FTDIR	 = 290,
	OP_FTPIPE	 = 291,
	OP_FTSUID	 = 292,
	OP_FTSGID	 = 293,
	OP_FTSVTX	 = 294,
	OP_FTLINK	 = 295,
	OP_FTTTY	 = 296,
	OP_FTTEXT	 = 297,
	OP_FTBINARY	 = 298,
	OP_CHDIR	 = 299,
	OP_CHOWN	 = 300,
	OP_CHROOT	 = 301,
	OP_UNLINK	 = 302,
	OP_CHMOD	 = 303,
	OP_UTIME	 = 304,
	OP_RENAME	 = 305,
	OP_LINK		 = 306,
	OP_SYMLINK	 = 307,
	OP_READLINK	 = 308,
	OP_MKDIR	 = 309,
	OP_RMDIR	 = 310,
	OP_OPEN_DIR	 = 311,
	OP_READDIR	 = 312,
	OP_TELLDIR	 = 313,
	OP_SEEKDIR	 = 314,
	OP_REWINDDIR	 = 315,
	OP_CLOSEDIR	 = 316,
	OP_FORK		 = 317,
	OP_WAIT		 = 318,
	OP_WAITPID	 = 319,
	OP_SYSTEM	 = 320,
	OP_EXEC		 = 321,
	OP_KILL		 = 322,
	OP_GETPPID	 = 323,
	OP_GETPGRP	 = 324,
	OP_SETPGRP	 = 325,
	OP_GETPRIORITY	 = 326,
	OP_SETPRIORITY	 = 327,
	OP_TIME		 = 328,
	OP_TMS		 = 329,
	OP_LOCALTIME	 = 330,
	OP_GMTIME	 = 331,
	OP_ALARM	 = 332,
	OP_SLEEP	 = 333,
	OP_SHMGET	 = 334,
	OP_SHMCTL	 = 335,
	OP_SHMREAD	 = 336,
	OP_SHMWRITE	 = 337,
	OP_MSGGET	 = 338,
	OP_MSGCTL	 = 339,
	OP_MSGSND	 = 340,
	OP_MSGRCV	 = 341,
	OP_SEMOP	 = 342,
	OP_SEMGET	 = 343,
	OP_SEMCTL	 = 344,
	OP_REQUIRE	 = 345,
	OP_DOFILE	 = 346,
	OP_HINTSEVAL	 = 347,
	OP_ENTEREVAL	 = 348,
	OP_LEAVEEVAL	 = 349,
	OP_ENTERTRY	 = 350,
	OP_LEAVETRY	 = 351,
	OP_GHBYNAME	 = 352,
	OP_GHBYADDR	 = 353,
	OP_GHOSTENT	 = 354,
	OP_GNBYNAME	 = 355,
	OP_GNBYADDR	 = 356,
	OP_GNETENT	 = 357,
	OP_GPBYNAME	 = 358,
	OP_GPBYNUMBER	 = 359,
	OP_GPROTOENT	 = 360,
	OP_GSBYNAME	 = 361,
	OP_GSBYPORT	 = 362,
	OP_GSERVENT	 = 363,
	OP_SHOSTENT	 = 364,
	OP_SNETENT	 = 365,
	OP_SPROTOENT	 = 366,
	OP_SSERVENT	 = 367,
	OP_EHOSTENT	 = 368,
	OP_ENETENT	 = 369,
	OP_EPROTOENT	 = 370,
	OP_ESERVENT	 = 371,
	OP_GPWNAM	 = 372,
	OP_GPWUID	 = 373,
	OP_GPWENT	 = 374,
	OP_SPWENT	 = 375,
	OP_EPWENT	 = 376,
	OP_GGRNAM	 = 377,
	OP_GGRGID	 = 378,
	OP_GGRENT	 = 379,
	OP_SGRENT	 = 380,
	OP_EGRENT	 = 381,
	OP_GETLOGIN	 = 382,
	OP_SYSCALL	 = 383,
	OP_LOCK		 = 384,
	OP_ONCE		 = 385,
	OP_CUSTOM	 = 386,
	OP_COREARGS	 = 387,
	OP_AVHVSWITCH	 = 388,
	OP_RUNCV	 = 389,
	OP_FC		 = 390,
	OP_PADCV	 = 391,
	OP_INTROCV	 = 392,
	OP_CLONECV	 = 393,
	OP_PADRANGE	 = 394,
	OP_REFASSIGN	 = 395,
	OP_LVREF	 = 396,
	OP_LVREFSLICE	 = 397,
	OP_LVAVREF	 = 398,
	OP_ANONCONST	 = 399,
	OP_ISA		 = 400,
	OP_CMPCHAIN_AND	 = 401,
	OP_CMPCHAIN_DUP	 = 402,
	OP_ENTERTRYCATCH = 403,
	OP_LEAVETRYCATCH = 404,
	OP_POPTRY	 = 405,
	OP_CATCH	 = 406,
	OP_PUSHDEFER	 = 407,
	OP_IS_BOOL	 = 408,
	OP_IS_WEAK	 = 409,
	OP_WEAKEN	 = 410,
	OP_UNWEAKEN	 = 411,
	OP_BLESSED	 = 412,
	OP_REFADDR	 = 413,
	OP_REFTYPE	 = 414,
	OP_CEIL		 = 415,
	OP_FLOOR	 = 416,
	OP_IS_TAINTED	 = 417,
	OP_HELEMEXISTSOR = 418,
	OP_METHSTART	 = 419,
	OP_INITFIELD	 = 420,
	OP_max		
} opcode;

#define MAXO 421
#define OP_FREED MAXO

/* the OP_IS_* macros are optimized to a simple range check because
    all the member OPs are contiguous in regen/opcodes table.
    opcode.pl verifies the range contiguity, or generates an OR-equals
    expression */

#define OP_IS_SOCKET(op)   \
	((op) >= OP_SEND && (op) <= OP_GETPEERNAME)

#define OP_IS_FILETEST(op)   \
	((op) >= OP_FTRREAD && (op) <= OP_FTBINARY)

#define OP_IS_FILETEST_ACCESS(op)   \
	((op) >= OP_FTRREAD && (op) <= OP_FTEEXEC)

#define OP_IS_NUMCOMPARE(op)   \
	((op) >= OP_LT && (op) <= OP_I_NCMP)

#define OP_IS_DIRHOP(op)   \
	((op) >= OP_READDIR && (op) <= OP_CLOSEDIR)

#define OP_IS_INFIX_BIT(op)   \
	((op) >= OP_BIT_AND && (op) <= OP_SBIT_OR)

/* ex: set ro ft=C: */
