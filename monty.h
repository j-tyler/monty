#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define N_OPCODES 17


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global - pile of useful global variables
 * @stack: top of the stack
 * @tail: bottom of the stack
 * @buf: readline buffer
 * @mode: 0 = stacking, 1 = queuing, 2 = program error, clean and exit
 */
typedef struct global_s
{
    stack_t **stack;
    stack_t **tail;
    char **buf;
    int mode;
} global_t;

extern global_t global;

/* monty_interpreter.c */
void exit_fail_cleanup(char *buf, FILE fd);
void init_program(int argc, char **argv, FILE *fd, char **buf, size_t *bufsize);

/* exits.c */
void exit_with_error(char *msg);
void file_open_error(char *file);
void invalid_code_error(int line, char *opcode);
void op_function_error(int line, char *msg);

/* helpers.c */
char *find_arg1(char *buf);
char *find_arg2(char *buf);
int word_match(char *s1, char *s2);
int parse_number(void);

/* helpers2.c */
int valid_stack(stack_t **stack);
int valid_top_two(stack_t **stack);

/* push.c */
void _push(stack_t **stack, unsigned int line);
stack_t *create_node(void);

/* pop.c */
void pop(stack_t **stack, unsigned int line);

/* swap */
void _swap(stack_t **stack, unsigned int line);

/* add.c */
void _add(stack_t **stack, unsigned int line);

/* div.c */
void _div(stack_t **stack, unsigned int line);

/* mul.c */
void _mul(stack_t **stack, unsigned int line);

/* mod.c */
void _mod(stack_t **stack, unsigned int line);

/* nop.c */
void _nop(stack_t **stack, unsigned int line);

/* pall.c */
void _pall(stack_t **stack, unsigned int line);

/* pchar.c */
void _pchar(stack_t **stack, unsigned int line);

/* pint.c */
void _pint(stack_t **stack, unsigned int line);

/* pstr.c */
void _pstr(stack_t **stack, unsigned int line);

/* rotl.c */
void _rotl(stack_t **stack, unsigned int line);

/* rotr.c */
void _rotr(stack_t **stack, unsigned int line);

/* sub.c */
void _sub(stack_t **stack, unsigned int line);

/* swap.c */
void _swap(stack_t **stack, unsigned int line);

/* stack.c */
void _stack(stack_t **stack, unsigned int line);

/* queue.c */
void _queue(stack_t **stack, unsigned int line);


int fork_and_execute(char **argv);
#endif
