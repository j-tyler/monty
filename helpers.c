#include "monty.h"
/**
 * find_arg1 - Find the position of argument 1 in given string
 * @buf: buffer to search for first argument
 * Description: Skips past leading whitespace to find argument 1
 *              Only spaces are considered whitespace in monty!
 * Return: Pointer to first argument
 */
char *find_arg1(char *buf)
{
    while (*buf == ' ')
    {
        if (*buf == '\0')
            return (NULL);
        buf++;
    }
    return (buf);
}
/**
 * find_arg2 - Find the position of argument 2 in given string
 * @buf: buffer to search for second argument
 * Description: Skips past leading whitespace to find argument 1
 *              Skips past first argument to find whitespace
 *              Skips past delimiting whitespace to argument 2
 *              Only spaces are considered whitespace in monty!
 * Return: Pointer to second argument
 */
char *find_arg2(char *buf)
{
    while (*buf == ' ')
    {
        if (*buf == '\0')
            return (NULL);
        buf++;
    }
    while (*buf != ' ')
    {
        if (buf == '\0')
            return (NULL);
        buf++;
    }
    while (*buf == ' ')
    {
        if (*buf == '\0')
            return (NULL);
        buf++;
    }
    return (buf);
}
/**
 * word_match - matches two words space and \0 are end of word conditions.
 * @s1: string 1
 * @s2: string 2
 * Description: Matches words up to space or end of line.
 *              "hi " and "hi" match. "hii" and "hi" do not.
 * Return: 1 on match, 0 on no match
 */
int word_match(char *s1, char *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL)
        return (0);

    for (i = 0; s1[i] == s2[i]; i++)
    {
        if (s1[i] == '\0' || s1[i] == ' ')
            return (1);
    }
    if (s1[i] == ' ' || s1[i] == '\0')
        if (s2[i] == ' ' || s2[i] == '\0')
            return (1);
    if (s2[i] == ' ' || s2[i] == '\0')
        if (s1[i] == ' ' || s1[i] == '\0')
            return (1);

    return (0);
}
/**
 * parse_number - Return the number from the string
 * Description: If a non-number is found, set mode to 2 to signal error
 * Return: Number found
 */
int parse_number(void)
{
    char *arg;

    arg = find_arg2(*global.buf);
    if (*arg < '0' || *arg > '9')
    {
        global.mode = 2;
        return (0);
    }
    return (atoi(arg));
}
