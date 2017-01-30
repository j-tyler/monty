#include "monty.h"
/**
 * exit_with_error - function to gracefully exit program on generic error
 * @msg: message to print before exit
 */
void exit_with_error(char *msg)
{
    write(STDOUT_FILENO, msg, strlen(msg));
    exit(EXIT_FAILURE);
}
/**
 * file_open_error - Error on opening file
 * @file: file we tried to open
 */
void file_open_error(char *file)
{
    printf("Error: Can't open file %s\n", file);
    exit(EXIT_FAILURE);
}
/**
 * invalid_code_error - Error in opcode
 * @line: line number of error
 * @opcode: opcode that doesn't exist
 */
void invalid_code_error(int line, char *opcode)
{
    char *old;

    /* insert an end of string so the printout takes only the opcode */
    old = opcode;
    while (*opcode != ' ')
    {
        if (*opcode == '\0' || *opcode == '\n')
            break;
        opcode++;
    }
    *opcode = '\0';

    printf("L%d: unknown instruction %s\n", line, old);
}
/**
 * op_function_error - Error processing opcode function
 * @line: line number of error
 * @msg: message to send
 */
void op_function_error(int line, char *msg)
{
    printf("L%d: %s\n", line, msg);
}
