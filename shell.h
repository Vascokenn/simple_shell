#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Buffer sizes for reading and writing */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Constants for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* Constants for number conversion */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* Set to 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * A singly linked list structure
 * @num: The numerical field
 * @str: A string
 * @next: Points to the next node
 */
typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;

/**
 * A structure to hold various shell-related information
 * @arg: A string generated from getline containing arguments
 * @argv: An array of strings generated from arg
 * @path: A string path for the current command
 * @argc: The argument count
 * @line_count: The error count
 * @err_num: The error code for exit()
 * @linecount_flag: If set, count this line of input
 * @fname: The program filename
 * @env: A linked list for a local copy of the environment variables
 * @history: The history node
 * @alias: The alias node
 * @environ: A custom modified copy of the environment variables from LL env
 * @env_changed: Set if environ was changed
 * @status: The return status of the last executed command
 * @cmd_buf: Address of a pointer to cmd_buf, used for command chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: The file descriptor from which to read line input
 * @histcount: The history line number count
 */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf; /* Pointer to cmd ; chain buffer, for memory management */
    int cmd_buf_type; /* CMD_type ||, &&, ; */
    int readfd;
    int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
    0, 0, 0}

/**
 * A structure to map built-in commands to their corresponding functions
 * @type: The built-in command string
 * @func: The associated function
 */
typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;

/* Function prototypes are provided for various components of the shell. */

#endif

