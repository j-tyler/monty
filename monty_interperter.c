#include "monty.h"
global_t global;

/**
 * main - Main execution loop of the monty interpreter
 * @argc: Number of arguments given
 * @argv: Argument vector
 * Description: See README for more information. Interpreters montyByteCode.
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	char *opcode;
	unsigned int i, line;
	FILE *fd;
	size_t bufsize;
	instruction_t table[N_OPCODES] = {
	{"push", &_push}, {"pall", &_pall}, {"pint", &_pint}, {"pop", &pop},
	{"swap", &_swap}, {"add", &_add}, {"nop", &_nop}, {"sub", &_sub},
	{"div", &_div}, {"mul", &_mul}, {"mod", &_mod},	{"pchar", &_pchar},
	{"pstr", &_pstr}, {"rotl", &_rotl}, {"rotr", &_rotr}, {"stack", &_stack},
	{"queue", &_queue}, };
	init_program(argc, argv, &fd, &global.buf, &bufsize);
	line = 0;
	while (1)
	{
		if (getline(&global.buf, &bufsize, fd) == -1)
			break;
		line += 1;

		opcode = find_arg1(global.buf);
		if (*opcode == '\0' || *opcode == '#' || *opcode == '\n')
			continue;

		for (i = 0; i < N_OPCODES; i++)
		{
			if (word_match(table[i].opcode, opcode))
			{
				table[i].f(&global.stack, line);
				break;
			}
		}
		if (i >= N_OPCODES)
			global.mode = 2, invalid_code_error(line, opcode);
		if (global.mode == 2)
		{
			exit_cleanup(global.buf, fd);
			exit(EXIT_FAILURE);
		}
	}
	exit_cleanup(global.buf, fd);
	return (EXIT_SUCCESS);
}

/**
 * init_program - initiates and checks for correct input to program
 * @argc: number of arguments
 * @argv: argument vector
 * @fd: memory address to save file descriptor
 * @buf: buffer to use for reading file
 * @bs: size of buffer
 */
void init_program(int argc, char **argv, FILE **fd, char **buf, size_t *bs)
{
	(void) buf;
	*bs = 0;
	*fd = fopen(argv[1], "r");
	if (argc != 2)
		exit_with_error("USAGE: monty file\n");
	if (*fd == NULL)
		file_open_error(argv[1]);
	global.mode = 0;
	global.stack = NULL;
	global.tail = NULL;
}
/**
 * exit_cleanup- clean up and exit the process
 * @buf: buffer to free
 * @fd: file to close
 */
void exit_cleanup(char *buf, FILE *fd)
{

	(void) buf;
	free(global.buf);
	free_stack();
	fclose(fd);
}
/**
 * free_stack - free all memory in the stack
 */
void free_stack(void)
{
	stack_t *tmp;

	while (global.stack != NULL)
	{
		tmp = global.stack;
		global.stack = (global.stack)->next;
		free(tmp);
	}
}
