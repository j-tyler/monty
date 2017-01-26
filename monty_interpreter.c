#include "monty.h"
/**
 * main.c - Main execution loop of the monty interpreter
 * @argc: Number of arguments given
 * @argv: Argument vector
 * Description: See README for more information. Interpreters montyByteCode.
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv)
{
    Stack = Tail = Num = NULL;
    char *buf, *opcode;
    unsigned int i, line;
    int fd;
    size_t bufsize;
    instruction_t table[N_OPCODES] = {
    {"push", Matching_Function}, {"pall", Matching_Function}
    {"pint", Matching_Function}, {"pop", Matching_Function}
    {"swap", Matching_Function}, {"add", Matching_Function}
    {"nop", Matching_Function}, {"sub", Matching_Function}
    {"div", Matching_Function}, {"mul", Matching_Function}
    {"mod", Matching_Function}, {"#", Matching_Function}
    {"pchar", Matching_Function}, {"pstr", Matching_Function}
    {"rotl", Matching_Function}, {"rotr", Matching_Function}
    {"stack", Matching_Function}, {"queue", Matching_Function}
    };

    if (argc != 2)
        exit_with_error("USAGE: monty file\n");
    fd = open(argv[1], O_RDONLY)
    if (fd == -1)
        file_open_error(argv[1]);
    bufsize = 10;
    buf = malloc(bufsize);
    if (buf == NULL)
        exit_with_error("Error: malloc failed\n");

    line = 0;
    while (1)
    {
        if (getline(&buf, &bufsize, fd) == -1)
            break;
        line += 1;
        opcode = find_arg1(buf);
        if (*opcode == '\0')
            continue;
        global.number = find_arg2(buf);

        for (i = 0; i <= N_OPCODES; i++)
            if (word_match(table[i].opcode, opcode))
                table[i].f(global.stack, line);
        if (i > N_OPCODES)
            invalid_code_error(line, opcode);
    }
    return (EXIT_SUCCESS);
}
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
        if (*opcode == '\0')
            break;
        opcode++;
    }
    *opcode = '\0';

    printf("L%d: unknown instruction %s\n", line, old);
    exit(EXIT_FAILURE);
}
/**
 * op_function_error - Error processing opcode function
 * @line: line number of error
 * @msg: message to send
 */
void op_function_error(int line, char *msg)
{
    printf("L%d: %s\n", line, msg);
    exit(EXIT_FAILURE);
}
