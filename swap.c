#include "monty.h"

/**
 * op_swap - swap the top two elements on the stack
 * @pStack: stack pointer
 */
void op_swap(stack_t **pStack)
{
	stack_t *p = *pStack;

	if (!(p && p != p->next))
        print_err("L%u: can't swap, stack too short\n", op_env.lineno);

	p->n ^= p->prev->n;
	p->prev->n ^= p->n;
	p->n ^= p->prev->n;
}
