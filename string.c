#include "shell.h"

/**
 * _strlen - Determines the length of a string.
 * @s: The string to measure.
 *
 * Returns: The length of the string as an integer.
 */
int _strlen(char *s)
{
    int length = 0;

    if (!s)
        return 0;

    while (*s++)
        length++;

    return length;
}

/**
 * _strcmp - Compares two strings lexicographically.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Returns: A negative value if s1 < s2, a positive value if s1 > s2, and 0 if s1 equals s2.
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);

        s1++;
        s2++;
    }

    if (*s1 == *s2)
        return 0;
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if the 'needle' string starts with the 'haystack'.
 * @haystack: The string to search.
 * @needle: The substring to find.
 *
 * Returns: The address of the next character in 'haystack' if found, or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return NULL;

    return (char *)haystack;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Returns: A pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
    char *result = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;

    return result;
}

