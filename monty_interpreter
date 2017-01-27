#include "monty.h"
/**
 * main.c - Main execution loop of the monty interpreter
 * @argc: Number of arguments given
 * @argv: Argument vector
 * Description: See README for more information. Interpreters montyByteCode.
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
    char *opcode;
    unsigned int i, line;
    int fd;
    size_t bufsize;
    instruction_t table[N_OPCODES] = {
    {"push", Matching_Function}, {"pall", Matching_Function},
    {"pint", Matching_Function}, {"pop", Matching_Function},
    {"swap", Matching_Function}, {"add", Matching_Function},
    {"nop", Matching_Function}, {"sub", Matching_Function},
    {"div", Matching_Function}, {"mul", Matching_Function},
    {"mod", Matching_Function},
    {"pchar", Matching_Function}, {"pstr", Matching_Function},
    {"rotl", Matching_Function}, {"rotr", Matching_Function},
    {"stack", Matching_Function}, {"queue", Matching_Function},
    };

    init_program(argc, argv, &fd, global.(&buf), &bufsize);

    line = 0;
    while (1)
    {
        if (getline(global.(&buf), &bufsize, fd) == -1)
            break;
        line += 1;

        opcode = find_arg1(buf);
        if (*opcode == '\0' || '#')
            continue;
        // find_arg2(buf); only needs to run in push()

        for (i = 0; i <= N_OPCODES; i++)
        {
            if (word_match(table[i].opcode, opcode))
            {
                table[i].f(global.stack, line);
                break;
            }
        }
        if (i > N_OPCODES)
            global.mode = 2, invalid_code_error(line, opcode);
        if (global.mode == 2)
            exit_fail_cleanup(buf, fd);
    }
    return (EXIT_SUCCESS);
}
/**
 * init_program - initiates and checks for correct input to program
 * @argc: number of arguments
 * @argv: argument vector
 * @fd: memory address to save file descriptor
 * @buf: buffer to use for reading file
 * @bufsize: size of buffer
 */
void init_program(int argc, char **argv, int *fd, char **buf, int *bufsize)
{
    if (argc != 2)
        exit_with_error("USAGE: monty file\n");
    *fd = open(argv[1], O_RDONLY);
    if (*fd == -1)
        file_open_error(argv[1]);
    *bufsize = 100;
    *buf = malloc(sizeof(char) * bufsize);
    if (*buf == NULL)
    {
        close(*fd);
        exit_with_error("Error: malloc failed\n");
    }
    global.mode = 0;
    global.(*stack) = NULL;
    global.(*tail) = NULL;
}
/**
 * exit_fail_cleanup- clean up and exit the process
 * @buf: buffer to free
 * @fd: file to close
 */
void exit_fail_cleanup(char *buf, int fd)
{
    free(buf);
    // free stack
    close(fd);
    exit(EXIT_FAILURE);
}
