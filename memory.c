#include "shell.h"

/**
 * bfree - Deallocates memory pointed to by a pointer and sets it to NULL.
 * @ptr: A pointer to a pointer that needs to be freed.
 *
 * Return: 1 if memory was freed, 0 otherwise.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return 1;
    }
    return 0;
}

