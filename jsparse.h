#ifndef js_parse_h
#define js_parse_h

enum
{
	AST_LIST,

	AST_IDENTIFIER,
	AST_NUMBER,
	AST_STRING,
	AST_REGEXP,

	AST_FUNDEC,

	/* literals */
	EXP_UNDEF, /* for array elisions */
	EXP_NULL,
	EXP_TRUE,
	EXP_FALSE,
	EXP_THIS,

	EXP_FUN,

	EXP_ARRAY,
	EXP_OBJECT,
	EXP_PROP_VAL,
	EXP_PROP_GET,
	EXP_PROP_SET,

	/* expressions */
	EXP_INDEX,
	EXP_MEMBER,
	EXP_CALL,
	EXP_NEW,

	EXP_DELETE,
	EXP_VOID,
	EXP_TYPEOF,
	EXP_PREINC,
	EXP_PREDEC,
	EXP_POSTINC,
	EXP_POSTDEC,
	EXP_POS,
	EXP_NEG,
	EXP_BITNOT,
	EXP_LOGNOT,

	EXP_LOGOR,
	EXP_LOGAND,
	EXP_BITOR,
	EXP_BITXOR,
	EXP_BITAND,
	EXP_EQ,
	EXP_NE,
	EXP_STRICTEQ,
	EXP_STRICTNE,
	EXP_LT,
	EXP_GT,
	EXP_LE,
	EXP_GE,
	EXP_INSTANCEOF,
	EXP_IN,
	EXP_SHL,
	EXP_SHR,
	EXP_USHR,
	EXP_ADD,
	EXP_SUB,
	EXP_MUL,
	EXP_DIV,
	EXP_MOD,

	EXP_COND,

	EXP_ASS,
	EXP_ASS_MUL,
	EXP_ASS_DIV,
	EXP_ASS_MOD,
	EXP_ASS_ADD,
	EXP_ASS_SUB,
	EXP_ASS_SHL,
	EXP_ASS_SHR,
	EXP_ASS_USHR,
	EXP_ASS_BITAND,
	EXP_ASS_BITXOR,
	EXP_ASS_BITOR,

	EXP_COMMA,

	EXP_VAR, /* var initializer */

	/* statements */
	STM_BLOCK,
	STM_NOP,
	STM_VAR,
	STM_IF,
	STM_DO,
	STM_WHILE,
	STM_FOR,
	STM_FOR_VAR,
	STM_FOR_IN,
	STM_FOR_IN_VAR,
	STM_CONTINUE,
	STM_BREAK,
	STM_RETURN,
	STM_WITH,
	STM_SWITCH,
	STM_THROW,
	STM_TRY,
	STM_DEBUGGER,

	STM_LABEL,
	STM_CASE,
	STM_DEFAULT,
};

struct js_Ast
{
	int type;
	int line;
	js_Ast *a, *b, *c, *d;
	double number;
	const char *string;
	js_Ast *next; /* next in alloc list */
};
js_Ast *jsP_parse(js_State *J, const char *filename, const char *source);
void jsP_optimize(js_State *J, js_Ast *prog);
void jsP_freeparse(js_State *J);

void jsP_dumpsyntax(js_State *J, js_Ast *prog);
void jsP_dumplist(js_State *J, js_Ast *prog);

#endif
