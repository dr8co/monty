#include "monty.h"

/**
 * op_pstr - print the string starting from the top of the stack
 * @pStack: stack pointer
 */
void op_pstr(stack_t **pStack)
{
	stack_t *p = NULL;

	if (*pStack)
	{
		(*pStack)->next->prev = NULL;

		for (p = *pStack; p && p->n > 0 && p->n < 128; p = p->prev)
			putchar(p->n);

		(*pStack)->next->prev = *pStack;
	}

	putchar('\n');
}
