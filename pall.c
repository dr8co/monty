#include "monty.h"

/**
 * op_pall - print each element on the stack
 * @pStack: stack pointer
 */
void op_pall(stack_t **pStack)
{
	stack_t *p = NULL;

	if (*pStack)
	{
		(*pStack)->next->prev = NULL;

		for (p = *pStack; p; p = p->prev)
			printf("%d\n", p->n);

		(*pStack)->next->prev = *pStack;
	}
}
