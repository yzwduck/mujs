#ifndef js_h
#define js_h

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>

/* noreturn is a GCC extension */
#ifdef __GNUC__
#define JS_NORETURN __attribute__((noreturn))
#else
#ifdef _MSC_VER
#define JS_NORETURN __declspec(noreturn)
#else
#define JS_NORETURN
#endif
#endif

/* GCC can do type checking of printf strings */
#ifndef __printflike
#if __GNUC__ > 2 || __GNUC__ == 2 && __GNUC_MINOR__ >= 7
#define __printflike(fmtarg, firstvararg) \
	__attribute__((__format__ (__printf__, fmtarg, firstvararg)))
#else
#define __printflike(fmtarg, firstvararg)
#endif
#endif

typedef struct js_State js_State;

#define JS_REGEXP_G 1
#define JS_REGEXP_I 2
#define JS_REGEXP_M 4

js_State *js_newstate(void);
void js_close(js_State *J);

int js_error(js_State *J, const char *fmt, ...);

int js_loadstring(js_State *J, const char *s);
int js_loadfile(js_State *J, const char *filename);

/* binding API: TODO: move from jsrun.h */

typedef int (*js_CFunction)(js_State *J, int argc);

/* private */

typedef struct js_Ast js_Ast;
typedef struct js_Environment js_Environment;
typedef struct js_Function js_Function;
typedef struct js_Object js_Object;
typedef struct js_StringNode js_StringNode;

const char *js_intern(js_State *J, const char *s);
void js_printstringtree(js_State *J);

#endif
