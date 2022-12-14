#include "monty.h"
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

/**
 * str_to_words - split a string into words
 * @str: the string to str_to_words
 *
 * Return: If memory allocation fails, or if str is NULL or contains no words,
 * return NULL. Otherwise, return a NULL-terminated array of the words in str.
 */
char **str_to_words(char *str)
{
	char **tokens = NULL;
	size_t count = 0;

	if (!str)
		return (NULL);

	count = count_words(str);
	if (!count)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *str; ++count)
	{
		while (isspace(*str))
			*str++ = '\0';
		if (*str)
			tokens[count] = str;
		else
			break;
		do {
			++str;
		} while (*str && !isspace(*str));
	}
	tokens[count] = NULL;

	return (tokens);
}


/**
 * print_err - print an error message and exit.
 * @format: format string.
 * @...: format string parameters.
 *
 */
void print_err(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vfprintf(stderr, format, args);

	va_end(args);

	exit(EXIT_FAILURE);
}


/**
 * isinteger - check if a string represents an integer
 * @str: the string to check
 *
 * Return: 1 if str represents an integer, otherwise 0
 */
int isinteger(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;

	if (!*str)
		return (0);

	while (isdigit(*str))
		++str;

	return (!*str);
}


/**
 * count_words - counts the words in a string.
 * @str: the string to evaluate.
 *
 * Return: Return the number of tokens in str.
 */
size_t count_words(const char *str)
{
	size_t count = 0;

	while (*str)
	{
		while (isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !isspace(*str));

		++count;
	}
	return (count);
}
