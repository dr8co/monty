#include "monty.h"

/**
 * op_sub - sub the top two elements on the stack
 * @pStack: stack pointer
 */
void op_sub(stack_t **pStack)
{
	int to_sub = 0;

	if (!(*pStack && *pStack != (*pStack)->next))
        print_err("L%u: can't sub, stack too short\n", op_env.lineno);

	to_sub = (*pStack)->n;

	op_pop(pStack);

	(*pStack)->n -= to_sub;
}
