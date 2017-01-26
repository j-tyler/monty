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
/* Head of the stack */
extern stack_t **Stack;

/* Tail of stack. Only changed in queue() and push() */
extern stack_t **Tail;

/* Pointer to arg2 of line */
extern char *Num;

/* Mode of program. 0 is Stack, 1 is Queue */
extern int Mode;

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
