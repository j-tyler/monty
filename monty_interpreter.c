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
    {"NOMATCH", Unknown_instruction}
    };

    if (argc != 2)
        error_exit("USAGE: monty file\n");
    bufsize = 10;
    buf = malloc(bufsize);
    if (buf == NULL)
        error_exit("Error: malloc failed\n");
    fd = open(argv[1], O_RDONLY)
    if (fd == -1)
        // exit on file open error

    line = 0;
    while (1)
    {
        if (getline(&buf, &bufsize, /*FileDescriptor*/) == -1)
            break;
        line += 1;
        opcode = find_arg1(buf);
        if (*opcode == '\0')
            continue;
        Num = find_arg2(buf);

        for (i = 0; i < N_OPCODES; i++)
            if (word_match(table[i].opcode, opcode))
                table[i].f(Stack, line);
        if (i == N_OPCODES)
            // complex error exit here
    }
    return (EXIT_SUCCESS);
}
/**
 * error_exit - function to gracefully exit program on error
 * @msg: message to print before exit
 */
void error_exit(char *msg)
{
    write(STDOUT_FILENO, msg, strlen(msg));
    exit(EXIT_FAILURE);
}
