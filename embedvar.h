/* -*- mode: C; buffer-read-only: t -*-
 *
 *    embedvar.h
 *
 *    Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001,
 *    2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013,
 *    2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022
 *    by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/embed.pl from embed.fnc, intrpvar.h,
 * perlvars.h, regen/opcodes, regen/embed.pl, regen/embed_lib.pl and
 * regen/HeaderParser.pm.
 * Any changes made here will be lost!
 *
 * Edit those files and run 'make regen_headers' to effect changes.
 */

#if defined(MULTIPLICITY)
# define vTHX                                   aTHX
# define PL_AboveLatin1                         (vTHX->IAboveLatin1)
# define PL_an                                  (vTHX->Ian)
# define PL_argvgv                              (vTHX->Iargvgv)
# define PL_argvout_stack                       (vTHX->Iargvout_stack)
# define PL_argvoutgv                           (vTHX->Iargvoutgv)
# define PL_Assigned_invlist                    (vTHX->IAssigned_invlist)
# define PL_basetime                            (vTHX->Ibasetime)
# define PL_beginav                             (vTHX->Ibeginav)
# define PL_beginav_save                        (vTHX->Ibeginav_save)
# define PL_blockhooks                          (vTHX->Iblockhooks)
# define PL_body_arenas                         (vTHX->Ibody_arenas)
# define PL_body_roots                          (vTHX->Ibody_roots)
# define PL_bodytarget                          (vTHX->Ibodytarget)
# define PL_breakable_sub_gen                   (vTHX->Ibreakable_sub_gen)
# define PL_CCC_non0_non230                     (vTHX->ICCC_non0_non230)
# define PL_checkav                             (vTHX->Icheckav)
# define PL_checkav_save                        (vTHX->Icheckav_save)
# define PL_chopset                             (vTHX->Ichopset)
# define PL_clocktick                           (vTHX->Iclocktick)
# define PL_collation_ix                        (vTHX->Icollation_ix)
# define PL_collation_name                      (vTHX->Icollation_name)
# define PL_collation_standard                  (vTHX->Icollation_standard)
# define PL_collxfrm_base                       (vTHX->Icollxfrm_base)
# define PL_collxfrm_mult                       (vTHX->Icollxfrm_mult)
# define PL_colors                              (vTHX->Icolors)
# define PL_colorset                            (vTHX->Icolorset)
# define PL_compcv                              (vTHX->Icompcv)
# define PL_compiling                           (vTHX->Icompiling)
# define PL_comppad                             (vTHX->Icomppad)
# define PL_comppad_name                        (vTHX->Icomppad_name)
# define PL_comppad_name_fill                   (vTHX->Icomppad_name_fill)
# define PL_comppad_name_floor                  (vTHX->Icomppad_name_floor)
# define PL_constpadix                          (vTHX->Iconstpadix)
# define PL_cop_seqmax                          (vTHX->Icop_seqmax)
# define PL_ctype_name                          (vTHX->Ictype_name)
# define PL_cur_LC_ALL                          (vTHX->Icur_LC_ALL)
# define PL_cur_locale_obj                      (vTHX->Icur_locale_obj)
# define PL_curcop                              (vTHX->Icurcop)
# define PL_curcopdb                            (vTHX->Icurcopdb)
# define PL_curlocales                          (vTHX->Icurlocales)
# define PL_curpad                              (vTHX->Icurpad)
# define PL_curpm                               (vTHX->Icurpm)
# define PL_curpm_under                         (vTHX->Icurpm_under)
# define PL_curstack                            (vTHX->Icurstack)
# define PL_curstackinfo                        (vTHX->Icurstackinfo)
# define PL_curstash                            (vTHX->Icurstash)
# define PL_curstname                           (vTHX->Icurstname)
# define PL_custom_op_descs                     (vTHX->Icustom_op_descs)
# define PL_custom_op_names                     (vTHX->Icustom_op_names)
# define PL_custom_ops                          (vTHX->Icustom_ops)
# define PL_cv_has_eval                         (vTHX->Icv_has_eval)
# define PL_dbargs                              (vTHX->Idbargs)
# define PL_DBcontrol                           (vTHX->IDBcontrol)
# define PL_DBcv                                (vTHX->IDBcv)
# define PL_DBgv                                (vTHX->IDBgv)
# define PL_DBline                              (vTHX->IDBline)
# define PL_DBsignal                            (vTHX->IDBsignal)
# define PL_DBsingle                            (vTHX->IDBsingle)
# define PL_DBsub                               (vTHX->IDBsub)
# define PL_DBtrace                             (vTHX->IDBtrace)
# define PL_debstash                            (vTHX->Idebstash)
# define PL_debug                               (vTHX->Idebug)
# define PL_debug_pad                           (vTHX->Idebug_pad)
# define PL_def_layerlist                       (vTHX->Idef_layerlist)
# define PL_defgv                               (vTHX->Idefgv)
# define PL_defoutgv                            (vTHX->Idefoutgv)
# define PL_defstash                            (vTHX->Idefstash)
# define PL_delaymagic                          (vTHX->Idelaymagic)
# define PL_delaymagic_egid                     (vTHX->Idelaymagic_egid)
# define PL_delaymagic_euid                     (vTHX->Idelaymagic_euid)
# define PL_delaymagic_gid                      (vTHX->Idelaymagic_gid)
# define PL_delaymagic_uid                      (vTHX->Idelaymagic_uid)
# define PL_destroyhook                         (vTHX->Idestroyhook)
# define PL_diehook                             (vTHX->Idiehook)
# define PL_Dir                                 (vTHX->IDir)
# define PL_doswitches                          (vTHX->Idoswitches)
# define PL_dowarn                              (vTHX->Idowarn)
# define PL_dump_re_max_len                     (vTHX->Idump_re_max_len)
# define PL_dumper_fd                           (vTHX->Idumper_fd)
# define PL_dumpindent                          (vTHX->Idumpindent)
# define PL_e_script                            (vTHX->Ie_script)
# define PL_efloatbuf                           (vTHX->Iefloatbuf)
# define PL_efloatsize                          (vTHX->Iefloatsize)
# define PL_endav                               (vTHX->Iendav)
# define PL_Env                                 (vTHX->IEnv)
# define PL_envgv                               (vTHX->Ienvgv)
# define PL_errgv                               (vTHX->Ierrgv)
# define PL_errors                              (vTHX->Ierrors)
# define PL_eval_begin_nest_depth               (vTHX->Ieval_begin_nest_depth)
# define PL_eval_root                           (vTHX->Ieval_root)
# define PL_eval_start                          (vTHX->Ieval_start)
# define PL_evalseq                             (vTHX->Ievalseq)
# define PL_exit_flags                          (vTHX->Iexit_flags)
# define PL_exitlist                            (vTHX->Iexitlist)
# define PL_exitlistlen                         (vTHX->Iexitlistlen)
# define PL_fdpid                               (vTHX->Ifdpid)
# define PL_filemode                            (vTHX->Ifilemode)
# define PL_firstgv                             (vTHX->Ifirstgv)
# define PL_fold_locale                         (vTHX->Ifold_locale)
# define PL_forkprocess                         (vTHX->Iforkprocess)
# define PL_formtarget                          (vTHX->Iformtarget)
# define PL_GCB_invlist                         (vTHX->IGCB_invlist)
# define PL_generation                          (vTHX->Igeneration)
# define PL_gensym                              (vTHX->Igensym)
# define PL_globalstash                         (vTHX->Iglobalstash)
# define PL_globhook                            (vTHX->Iglobhook)
# define PL_hash_rand_bits                      (vTHX->Ihash_rand_bits)
# define PL_hash_rand_bits_enabled              (vTHX->Ihash_rand_bits_enabled)
# define PL_HasMultiCharFold                    (vTHX->IHasMultiCharFold)
# define PL_hintgv                              (vTHX->Ihintgv)
# define PL_hv_fetch_ent_mh                     (vTHX->Ihv_fetch_ent_mh)
# define PL_in_clean_all                        (vTHX->Iin_clean_all)
# define PL_in_clean_objs                       (vTHX->Iin_clean_objs)
# define PL_in_eval                             (vTHX->Iin_eval)
# define PL_in_load_module                      (vTHX->Iin_load_module)
# define PL_in_some_fold                        (vTHX->Iin_some_fold)
# define PL_in_utf8_COLLATE_locale              (vTHX->Iin_utf8_COLLATE_locale)
# define PL_in_utf8_CTYPE_locale                (vTHX->Iin_utf8_CTYPE_locale)
# define PL_in_utf8_turkic_locale               (vTHX->Iin_utf8_turkic_locale)
# define PL_InBitmap                            (vTHX->IInBitmap)
# define PL_incgv                               (vTHX->Iincgv)
# define PL_initav                              (vTHX->Iinitav)
# define PL_InMultiCharFold                     (vTHX->IInMultiCharFold)
# define PL_inplace                             (vTHX->Iinplace)
# define PL_internal_random_state               (vTHX->Iinternal_random_state)
# define PL_isarev                              (vTHX->Iisarev)
# define PL_known_layers                        (vTHX->Iknown_layers)
# define PL_langinfo_buf                        (vTHX->Ilanginfo_buf)
# define PL_langinfo_bufsize                    (vTHX->Ilanginfo_bufsize)
# define PL_last_in_gv                          (vTHX->Ilast_in_gv)
# define PL_lastfd                              (vTHX->Ilastfd)
# define PL_lastgotoprobe                       (vTHX->Ilastgotoprobe)
# define PL_laststatval                         (vTHX->Ilaststatval)
# define PL_laststype                           (vTHX->Ilaststype)
# define PL_Latin1                              (vTHX->ILatin1)
# define PL_LB_invlist                          (vTHX->ILB_invlist)
# define PL_LIO                                 (vTHX->ILIO)
# define PL_locale_mutex_depth                  (vTHX->Ilocale_mutex_depth)
# define PL_localizing                          (vTHX->Ilocalizing)
# define PL_localpatches                        (vTHX->Ilocalpatches)
# define PL_lockhook                            (vTHX->Ilockhook)
# define PL_main_cv                             (vTHX->Imain_cv)
# define PL_main_root                           (vTHX->Imain_root)
# define PL_main_start                          (vTHX->Imain_start)
# define PL_mainstack                           (vTHX->Imainstack)
# define PL_markstack                           (vTHX->Imarkstack)
# define PL_markstack_max                       (vTHX->Imarkstack_max)
# define PL_markstack_ptr                       (vTHX->Imarkstack_ptr)
# define PL_max_intro_pending                   (vTHX->Imax_intro_pending)
# define PL_maxsysfd                            (vTHX->Imaxsysfd)
# define PL_mbrlen_ps                           (vTHX->Imbrlen_ps)
# define PL_mbrtowc_ps                          (vTHX->Imbrtowc_ps)
# define PL_Mem                                 (vTHX->IMem)
# define PL_mem_log                             (vTHX->Imem_log)
# define PL_memory_debug_header                 (vTHX->Imemory_debug_header)
# define PL_MemParse                            (vTHX->IMemParse)
# define PL_MemShared                           (vTHX->IMemShared)
# define PL_mess_sv                             (vTHX->Imess_sv)
# define PL_min_intro_pending                   (vTHX->Imin_intro_pending)
# define PL_minus_a                             (vTHX->Iminus_a)
# define PL_minus_c                             (vTHX->Iminus_c)
# define PL_minus_E                             (vTHX->Iminus_E)
# define PL_minus_F                             (vTHX->Iminus_F)
# define PL_minus_l                             (vTHX->Iminus_l)
# define PL_minus_n                             (vTHX->Iminus_n)
# define PL_minus_p                             (vTHX->Iminus_p)
# define PL_modcount                            (vTHX->Imodcount)
# define PL_modglobal                           (vTHX->Imodglobal)
# define PL_multideref_pc                       (vTHX->Imultideref_pc)
# define PL_my_cxt_list                         (vTHX->Imy_cxt_list)
# define PL_my_cxt_size                         (vTHX->Imy_cxt_size)
# define PL_na                                  (vTHX->Ina)
# define PL_nomemok                             (vTHX->Inomemok)
# define PL_numeric_name                        (vTHX->Inumeric_name)
# define PL_numeric_radix_sv                    (vTHX->Inumeric_radix_sv)
# define PL_numeric_standard                    (vTHX->Inumeric_standard)
# define PL_numeric_underlying                  (vTHX->Inumeric_underlying)
# define PL_numeric_underlying_is_standard      (vTHX->Inumeric_underlying_is_standard)
# define PL_ofsgv                               (vTHX->Iofsgv)
# define PL_oldname                             (vTHX->Ioldname)
# define PL_op                                  (vTHX->Iop)
# define PL_op_exec_cnt                         (vTHX->Iop_exec_cnt)
# define PL_op_mask                             (vTHX->Iop_mask)
# define PL_opfreehook                          (vTHX->Iopfreehook)
# define PL_origalen                            (vTHX->Iorigalen)
# define PL_origargc                            (vTHX->Iorigargc)
# define PL_origargv                            (vTHX->Iorigargv)
# define PL_origfilename                        (vTHX->Iorigfilename)
# define PL_ors_sv                              (vTHX->Iors_sv)
# define PL_osname                              (vTHX->Iosname)
# define PL_pad_reset_pending                   (vTHX->Ipad_reset_pending)
# define PL_padix                               (vTHX->Ipadix)
# define PL_padix_floor                         (vTHX->Ipadix_floor)
# define PL_padlist_generation                  (vTHX->Ipadlist_generation)
# define PL_padname_const                       (vTHX->Ipadname_const)
# define PL_padname_undef                       (vTHX->Ipadname_undef)
# define PL_parser                              (vTHX->Iparser)
# define PL_patchlevel                          (vTHX->Ipatchlevel)
# define PL_peepp                               (vTHX->Ipeepp)
# define PL_perl_destruct_level                 (vTHX->Iperl_destruct_level)
# define PL_perldb                              (vTHX->Iperldb)
# define PL_perlio                              (vTHX->Iperlio)
# define PL_phase                               (vTHX->Iphase)
# define PL_pidstatus                           (vTHX->Ipidstatus)
# define PL_Posix_ptrs                          (vTHX->IPosix_ptrs)
# define PL_preambleav                          (vTHX->Ipreambleav)
# define PL_Private_Use                         (vTHX->IPrivate_Use)
# define PL_Proc                                (vTHX->IProc)
# define PL_profiledata                         (vTHX->Iprofiledata)
# define PL_psig_name                           (vTHX->Ipsig_name)
# define PL_psig_pend                           (vTHX->Ipsig_pend)
# define PL_psig_ptr                            (vTHX->Ipsig_ptr)
# define PL_ptr_table                           (vTHX->Iptr_table)
# define PL_random_state                        (vTHX->Irandom_state)
# define PL_reentrant_buffer                    (vTHX->Ireentrant_buffer)
# define PL_reentrant_retint                    (vTHX->Ireentrant_retint)
# define PL_reg_curpm                           (vTHX->Ireg_curpm)
# define PL_regex_pad                           (vTHX->Iregex_pad)
# define PL_regex_padav                         (vTHX->Iregex_padav)
# define PL_registered_mros                     (vTHX->Iregistered_mros)
# define PL_regmatch_slab                       (vTHX->Iregmatch_slab)
# define PL_regmatch_state                      (vTHX->Iregmatch_state)
# define PL_replgv                              (vTHX->Ireplgv)
# define PL_restartjmpenv                       (vTHX->Irestartjmpenv)
# define PL_restartop                           (vTHX->Irestartop)
# define PL_rpeepp                              (vTHX->Irpeepp)
# define PL_rs                                  (vTHX->Irs)
# define PL_runops                              (vTHX->Irunops)
# define PL_savebegin                           (vTHX->Isavebegin)
# define PL_savestack                           (vTHX->Isavestack)
# define PL_savestack_ix                        (vTHX->Isavestack_ix)
# define PL_savestack_max                       (vTHX->Isavestack_max)
# define PL_SB_invlist                          (vTHX->ISB_invlist)
# define PL_scopestack                          (vTHX->Iscopestack)
# define PL_scopestack_ix                       (vTHX->Iscopestack_ix)
# define PL_scopestack_max                      (vTHX->Iscopestack_max)
# define PL_scopestack_name                     (vTHX->Iscopestack_name)
# define PL_scratch_locale_obj                  (vTHX->Iscratch_locale_obj)
# define PL_SCX_invlist                         (vTHX->ISCX_invlist)
# define PL_secondgv                            (vTHX->Isecondgv)
# define PL_setlocale_buf                       (vTHX->Isetlocale_buf)
# define PL_setlocale_bufsize                   (vTHX->Isetlocale_bufsize)
# define PL_sharehook                           (vTHX->Isharehook)
# define PL_sig_pending                         (vTHX->Isig_pending)
# define PL_sighandler1p                        (vTHX->Isighandler1p)
# define PL_sighandler3p                        (vTHX->Isighandler3p)
# define PL_sighandlerp                         (vTHX->Isighandlerp)
# define PL_signalhook                          (vTHX->Isignalhook)
# define PL_signals                             (vTHX->Isignals)
# define PL_Sock                                (vTHX->ISock)
# define PL_sortcop                             (vTHX->Isortcop)
# define PL_sortstash                           (vTHX->Isortstash)
# define PL_splitstr                            (vTHX->Isplitstr)
# define PL_srand_called                        (vTHX->Isrand_called)
# define PL_srand_override                      (vTHX->Isrand_override)
# define PL_srand_override_next                 (vTHX->Isrand_override_next)
# define PL_stack_base                          (vTHX->Istack_base)
# define PL_stack_max                           (vTHX->Istack_max)
# define PL_stack_sp                            (vTHX->Istack_sp)
# define PL_start_env                           (vTHX->Istart_env)
# define PL_stashcache                          (vTHX->Istashcache)
# define PL_stashpad                            (vTHX->Istashpad)
# define PL_stashpadix                          (vTHX->Istashpadix)
# define PL_stashpadmax                         (vTHX->Istashpadmax)
# define PL_statcache                           (vTHX->Istatcache)
# define PL_statgv                              (vTHX->Istatgv)
# define PL_statname                            (vTHX->Istatname)
# define PL_statusvalue                         (vTHX->Istatusvalue)
# define PL_statusvalue_posix                   (vTHX->Istatusvalue_posix)
# define PL_statusvalue_vms                     (vTHX->Istatusvalue_vms)
# define PL_stderrgv                            (vTHX->Istderrgv)
# define PL_stdingv                             (vTHX->Istdingv)
# define PL_StdIO                               (vTHX->IStdIO)
# define PL_stdize_locale_buf                   (vTHX->Istdize_locale_buf)
# define PL_stdize_locale_bufsize               (vTHX->Istdize_locale_bufsize)
# define PL_strtab                              (vTHX->Istrtab)
# define PL_strxfrm_is_behaved                  (vTHX->Istrxfrm_is_behaved)
# define PL_strxfrm_max_cp                      (vTHX->Istrxfrm_max_cp)
# define PL_strxfrm_NUL_replacement             (vTHX->Istrxfrm_NUL_replacement)
# define PL_sub_generation                      (vTHX->Isub_generation)
# define PL_subline                             (vTHX->Isubline)
# define PL_subname                             (vTHX->Isubname)
# define PL_Sv                                  (vTHX->ISv)
# define PL_sv_arenaroot                        (vTHX->Isv_arenaroot)
# define PL_sv_consts                           (vTHX->Isv_consts)
# define PL_sv_count                            (vTHX->Isv_count)
# define PL_sv_immortals                        (vTHX->Isv_immortals)
# define PL_sv_no                               (vTHX->Isv_no)
# define PL_sv_root                             (vTHX->Isv_root)
# define PL_sv_serial                           (vTHX->Isv_serial)
# define PL_sv_undef                            (vTHX->Isv_undef)
# define PL_sv_yes                              (vTHX->Isv_yes)
# define PL_sv_zero                             (vTHX->Isv_zero)
# define PL_sys_intern                          (vTHX->Isys_intern)
# define PL_taint_warn                          (vTHX->Itaint_warn)
# define PL_tainted                             (vTHX->Itainted)
# define PL_tainting                            (vTHX->Itainting)
# define PL_threadhook                          (vTHX->Ithreadhook)
# define PL_tmps_floor                          (vTHX->Itmps_floor)
# define PL_tmps_ix                             (vTHX->Itmps_ix)
# define PL_tmps_max                            (vTHX->Itmps_max)
# define PL_tmps_stack                          (vTHX->Itmps_stack)
# define PL_top_env                             (vTHX->Itop_env)
# define PL_toptarget                           (vTHX->Itoptarget)
# define PL_TR_SPECIAL_HANDLING_UTF8            (vTHX->ITR_SPECIAL_HANDLING_UTF8)
# define PL_underlying_numeric_obj              (vTHX->Iunderlying_numeric_obj)
# define PL_underlying_radix_sv                 (vTHX->Iunderlying_radix_sv)
# define PL_unicode                             (vTHX->Iunicode)
# define PL_unitcheckav                         (vTHX->Iunitcheckav)
# define PL_unitcheckav_save                    (vTHX->Iunitcheckav_save)
# define PL_unlockhook                          (vTHX->Iunlockhook)
# define PL_unsafe                              (vTHX->Iunsafe)
# define PL_UpperLatin1                         (vTHX->IUpperLatin1)
# define PL_utf8_charname_begin                 (vTHX->Iutf8_charname_begin)
# define PL_utf8_charname_continue              (vTHX->Iutf8_charname_continue)
# define PL_utf8_foldclosures                   (vTHX->Iutf8_foldclosures)
# define PL_utf8_idcont                         (vTHX->Iutf8_idcont)
# define PL_utf8_idstart                        (vTHX->Iutf8_idstart)
# define PL_utf8_mark                           (vTHX->Iutf8_mark)
# define PL_utf8_perl_idcont                    (vTHX->Iutf8_perl_idcont)
# define PL_utf8_perl_idstart                   (vTHX->Iutf8_perl_idstart)
# define PL_utf8_tofold                         (vTHX->Iutf8_tofold)
# define PL_utf8_tolower                        (vTHX->Iutf8_tolower)
# define PL_utf8_tosimplefold                   (vTHX->Iutf8_tosimplefold)
# define PL_utf8_totitle                        (vTHX->Iutf8_totitle)
# define PL_utf8_toupper                        (vTHX->Iutf8_toupper)
# define PL_utf8_xidcont                        (vTHX->Iutf8_xidcont)
# define PL_utf8_xidstart                       (vTHX->Iutf8_xidstart)
# define PL_utf8cache                           (vTHX->Iutf8cache)
# define PL_utf8locale                          (vTHX->Iutf8locale)
# define PL_warn_locale                         (vTHX->Iwarn_locale)
# define PL_warnhook                            (vTHX->Iwarnhook)
# define PL_watchaddr                           (vTHX->Iwatchaddr)
# define PL_watchok                             (vTHX->Iwatchok)
# define PL_WB_invlist                          (vTHX->IWB_invlist)
# define PL_wcrtomb_ps                          (vTHX->Iwcrtomb_ps)
# define PL_XPosix_ptrs                         (vTHX->IXPosix_ptrs)
# define PL_Xpv                                 (vTHX->IXpv)
# define PL_xsubfilename                        (vTHX->Ixsubfilename)
# if !defined(PL_sawampersand)
#   define PL_sawampersand                      (vTHX->Isawampersand)
# endif /* !defined(PL_sawampersand) */
#endif /* defined(MULTIPLICITY) */

/* ex: set ro ft=C: */
