#ifndef MONTY_H
#define MONTY_H

#define N_OPCODES 18


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
 * @number: number found in line
 * @mode: mode for stacking or queuing
 */
typedef struct global_s
{
    char **stack;
    char **tail;
    int number;
    int mode;
} global_t;

extern global_t global;

/* monty_interpreter.c */
void exit_with_error(char *msg);
void file_open_error(char *file);
void invalid_code_error(int line, char *opcode);
void op_function_error(int line, char *msg);

/* helpers.c */
char *find_arg1(char *buf);
char *find_arg2(char *buf);
int word_match(char *s1, char *s2);
#endif
