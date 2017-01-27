#ifndef MONTY_H
#define MONTY_H

#define N_OPCODES 17


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
    char *buf;
    int mode;
} global_t;

extern global_t global;

/* monty_interpreter.c */
void exit_fail_cleanup(char *buf, int fd);

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

/* push.c */
void push(stack_t **stack, unsigned int line);
stack_t *create_node(void);

/* pop.c */
void pop(stack_t **stack, unsigned int line);

/* swap */
void swap(stack_t **stack, unsigned int line);

/* add.c */
void add(stack_t **stack, unsigned int line);

int fork_and_execute(char **argv);
#endif
