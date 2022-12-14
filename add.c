#include "monty.h"

/**
 * op_add - add the top two elements on the stack
 * @pStack: stack pointer
 */
void op_add(stack_t **pStack)
{
	int to_add = 0;

	if (!(*pStack && *pStack != (*pStack)->next))
        print_err("L%u: can't add, stack too short\n", op_env.lineno);

	to_add = (*pStack)->n;

	op_pop(pStack);

	(*pStack)->n += to_add;
}
