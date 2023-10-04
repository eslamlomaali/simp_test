#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


extern char **en;


/**
 * struct main - struct
 * @argv: vector
 * @enter: cmd
 * @as: token
 * @sstt: status
 * @calc: count
 * @_environment: environment
 * @process: process id
 */
typedef struct main
{
	char **argv;
	char *enter;
	char **as;
	int sstt;
	int calc;
	char **_environment;
	char *process;
} main_data;

/**
 * struct LL -  linked list
 * @space: ;
 * @access: node
 * Description: linked list
 */
typedef struct LL
{
	char space;
	struct LL *access;
} Linked_List;

/**
 * struct LL_2 -  linked list
 * @l: cmd
 * @access:  node
 * Description: linked list
 */
typedef struct LL_2
{
	char *l;
	struct LL_2 *access;
} Linked_List_2;

/**
 * struct LL_3 - linked list
 * @length_variable: length
 * @vv: value
 * @length_value: length
 * @access: node
 * Description: linked list
 */
typedef struct LL_3
{
	int length_variable;
	char *vv;
	int length_value;
	struct LL_3 *access;
} Linked_List_3;

/**
 * struct internal_l - struct
 * @identifier:  name
 * @function: pointer
 */
typedef struct internal_l
{
	char *identifier;
	int (*function)(main_data *hash);
} internal_i;

/* list.c */
Linked_List *node_to_end(Linked_List **h, char s);
void ffree(Linked_List **h);
Linked_List_2 *node_to_end_2(Linked_List_2 **h, char *range);
void ffree_2(Linked_List_2 **h);

/* list2.c */
Linked_List_3 *add_node(Linked_List_3 **h, int eslam, char *ashraf, int ali);
void ffree_3(Linked_List_3 **h);

/* string functions */
char *_string_add(char *d, const char *s);
char *_string_copy(char *d, char *s);
int _string_compare(char *string1, char *string2);
char *_string_charcter(char *a, char b);
int _string_s(char *a, char *b);

/* aux_mem.c */
void _copy_c(void *n2, const void *pointer, unsigned int v);
void *_memory_reallocation(void *pointer, unsigned int n1, unsigned int n2);
char **_duplicates_reallocation(char **pointer,
		unsigned int n1, unsigned int n2);

/* aux_str2.c */
char *_string_duplicates(const char *c);
int _string_length(const char *c);
int _charcters_compare(char stringg[], const char *c);
char *_string_toknaization(char stringg[], const char *c);
int _dig(const char *c);

/* aux_str3.c */
void _revers_string(char *c);

/* check_syntax_error.c */
int _char_rep(char *c, int x);
int _find_err(char *c, int x, char y);
int _index_of_char(char *c, int *x);
void _p_err(main_data *hash, char *c, int x, int bool);
int _check_err(main_data *hash, char *c);

/* shell_loop.c */
char *_no_comm(char *c);
void _loop(main_data *hash);

/* read_line.c */
char *_read(int *x);

/* split.c */
char *_char_subs(char *c, int bool);
void _add(Linked_List **h1, Linked_List_2 **h2, char *c);
void _by(Linked_List **l1, Linked_List_2 **l2, main_data *hash);
int _cut_cmd(main_data *hash, char *c);
char **_cut(char *c);

/* rep_var.c */
void _check(Linked_List_3 **h, char *c, main_data *main);
int _check_2(Linked_List_3 **h, char *c, char *e, main_data *main);
char *_rep(Linked_List_3 **h, char *c, char *e, int l);
char *_rep_2(char *c, main_data *hash);

/* get_line.c */
void _come(char **lp, size_t *a, char *buf, size_t z);
ssize_t _have(char **lp, size_t *a, FILE *f);

/* exec_line */
int _exe(main_data *hash);

/* cmd_exec.c */
int _dir_or_not(char *p, int *x);
char *_is_that(char *command, char **_env);
int _exe_or_not(main_data *hash);
int _is_err(char *directory, main_data *hash);
int _executable(main_data *hash);

/* env1.c */
char *_have_env(const char *nn, char **_env);
int _environment_env(main_data *hash);

/* env2.c */
char *_cp_inf(char *nn, char *val);
void _setup_env(char *nn, char *val, main_data *hash);
int _ready_env(main_data *hash);
int _not_ready_env(main_data *hash);

/* cd.c */
void _cd_1(main_data *hash);
void _cd_2(main_data *hash);
void _cd_3(main_data *hash);
void _cd_4(main_data *hash);

/* cd_shell.c */
int _cd_5(main_data *hash);

/* get_builtin */
int (*have_b(char *command))(main_data *);

/* _exit.c */
int _sh_exit(main_data *hash);

/* aux_stdlib.c */
int _calc_length(int x);
char *_a_i(int x);
int _at(char *c);

/* aux_error1.c */
char *_string_cd(main_data *, char *, char *, char *);
char *_get_error(main_data *hash);
char *_err_not_exist(main_data *hash);
char *_err_close_sh(main_data *hash);

/* aux_error2.c */
char *_al_err(char **as);
char *_err_env(main_data *hash);
char *_err_s(char **as);
char *_err_per(char **as);
char *_err_p(main_data *hash);


/* get_error.c */
int _get_all_err(main_data *hash, int e);

/* get_sigint.c */
void _sig(int s);

/* aux_help.c */
void _h_env(void);
void _h_s_env(void);
void _h_uns_env(void);
void _h_g(void);
void _h_exit(void);

/* aux_help2.c */
void _h(void);
void _h_al(void);
void _h_c(void);

/* get_help.c */
int _call_h(main_data *hash);

#endif /*END SHELL_H*/
