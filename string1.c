#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Returns: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return dest;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * _strdup - Duplicates a given string.
 * @str: The string to duplicate.
 *
 * Returns: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
    int length = 0;
    char *ret;

    if (str == NULL)
        return NULL;

    while (*str++)
        length++;

    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return NULL;

    for (length++; length--;)
        ret[length] = *--str;

    return ret;
}

/**
 * _puts - Prints a string to the standard output.
 * @str: The string to be printed.
 *
 * Returns: Nothing.
 */
void _puts(char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to print.
 *
 * Returns: On success, it returns 1. On error, -1 is returned, and errno is set accordingly.
 */
int _putchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return 1;
}

