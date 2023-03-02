/* -*- mode: C; buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#define PERL_BISON_VERSION  30005

#ifdef PERL_CORE
/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GRAMPROG = 258,
    GRAMEXPR = 259,
    GRAMBLOCK = 260,
    GRAMBARESTMT = 261,
    GRAMFULLSTMT = 262,
    GRAMSTMTSEQ = 263,
    GRAMSUBSIGNATURE = 264,
    PERLY_AMPERSAND = 265,
    PERLY_BRACE_OPEN = 266,
    PERLY_BRACE_CLOSE = 267,
    PERLY_BRACKET_OPEN = 268,
    PERLY_BRACKET_CLOSE = 269,
    PERLY_COMMA = 270,
    PERLY_DOLLAR = 271,
    PERLY_DOT = 272,
    PERLY_EQUAL_SIGN = 273,
    PERLY_MINUS = 274,
    PERLY_PERCENT_SIGN = 275,
    PERLY_PLUS = 276,
    PERLY_SEMICOLON = 277,
    PERLY_SLASH = 278,
    PERLY_SNAIL = 279,
    PERLY_STAR = 280,
    KW_FORMAT = 281,
    KW_PACKAGE = 282,
    KW_CLASS = 283,
    KW_LOCAL = 284,
    KW_MY = 285,
    KW_FIELD = 286,
    KW_IF = 287,
    KW_ELSE = 288,
    KW_ELSIF = 289,
    KW_UNLESS = 290,
    KW_FOR = 291,
    KW_UNTIL = 292,
    KW_WHILE = 293,
    KW_CONTINUE = 294,
    KW_GIVEN = 295,
    KW_WHEN = 296,
    KW_DEFAULT = 297,
    KW_TRY = 298,
    KW_CATCH = 299,
    KW_FINALLY = 300,
    KW_DEFER = 301,
    KW_REQUIRE = 302,
    KW_DO = 303,
    KW_USE_or_NO = 304,
    KW_SUB_named = 305,
    KW_SUB_named_sig = 306,
    KW_SUB_anon = 307,
    KW_SUB_anon_sig = 308,
    KW_METHOD_named = 309,
    KW_METHOD_anon = 310,
    BAREWORD = 311,
    METHCALL0 = 312,
    METHCALL = 313,
    THING = 314,
    PMFUNC = 315,
    PRIVATEREF = 316,
    QWLIST = 317,
    FUNC0OP = 318,
    FUNC0SUB = 319,
    UNIOPSUB = 320,
    LSTOPSUB = 321,
    PLUGEXPR = 322,
    PLUGSTMT = 323,
    LABEL = 324,
    LOOPEX = 325,
    DOTDOT = 326,
    YADAYADA = 327,
    FUNC0 = 328,
    FUNC1 = 329,
    FUNC = 330,
    UNIOP = 331,
    LSTOP = 332,
    POWOP = 333,
    MULOP = 334,
    ADDOP = 335,
    DOLSHARP = 336,
    HASHBRACK = 337,
    NOAMP = 338,
    COLONATTR = 339,
    FORMLBRACK = 340,
    FORMRBRACK = 341,
    SUBLEXSTART = 342,
    SUBLEXEND = 343,
    PHASER = 344,
    PREC_LOW = 345,
    PLUGIN_LOW_OP = 346,
    OROP = 347,
    PLUGIN_LOGICAL_OR_LOW_OP = 348,
    ANDOP = 349,
    PLUGIN_LOGICAL_AND_LOW_OP = 350,
    NOTOP = 351,
    ASSIGNOP = 352,
    PLUGIN_ASSIGN_OP = 353,
    PERLY_QUESTION_MARK = 354,
    PERLY_COLON = 355,
    OROR = 356,
    DORDOR = 357,
    PLUGIN_LOGICAL_OR_OP = 358,
    ANDAND = 359,
    PLUGIN_LOGICAL_AND_OP = 360,
    BITOROP = 361,
    BITANDOP = 362,
    CHEQOP = 363,
    NCEQOP = 364,
    CHRELOP = 365,
    NCRELOP = 366,
    PLUGIN_REL_OP = 367,
    SHIFTOP = 368,
    PLUGIN_ADD_OP = 369,
    PLUGIN_MUL_OP = 370,
    MATCHOP = 371,
    PERLY_EXCLAMATION_MARK = 372,
    PERLY_TILDE = 373,
    UMINUS = 374,
    REFGEN = 375,
    PLUGIN_POW_OP = 376,
    PREINC = 377,
    PREDEC = 378,
    POSTINC = 379,
    POSTDEC = 380,
    POSTJOIN = 381,
    PLUGIN_HIGH_OP = 382,
    ARROW = 383,
    PERLY_PAREN_CLOSE = 384,
    PERLY_PAREN_OPEN = 385
  };
#endif

/* Value type.  */
#ifdef PERL_IN_TOKE_C
static bool
S_is_opval_token(int type) {
    switch (type) {
    case BAREWORD:
    case FUNC0OP:
    case FUNC0SUB:
    case LABEL:
    case LSTOPSUB:
    case METHCALL:
    case METHCALL0:
    case PLUGEXPR:
    case PLUGSTMT:
    case PMFUNC:
    case PRIVATEREF:
    case QWLIST:
    case THING:
    case UNIOPSUB:
	return 1;
    }
    return 0;
}
#endif /* PERL_IN_TOKE_C */
#endif /* PERL_CORE */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

    I32	ival; /* __DEFAULT__ (marker for regen_perly.pl;
				must always be 1st union member) */
    void *pval;
    OP *opval;
    GV *gvval;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);


/* Generated from:
 * 772de3ed75dc4010fd79a22e9c90253232ab5af632d3657c55a670d510ee71ef perly.y
 * acf1cbfd2545faeaaa58b1cf0cf9d7f98b5be0752eb7a54528ef904a9e2e1ca7 regen_perly.pl
 * ex: set ro ft=C: */
