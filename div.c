#include "monty.h"

/**
 * op_div - div the top two elements on the stack
 * @pStack: stack pointer
 */
void op_div(stack_t **pStack)
{
	int to_div = 0;

	if (!(*pStack && *pStack != (*pStack)->next))
		print_err("L%u: can't div, stack too short\n", op_env.lineno);

	to_div = (*pStack)->n;
	if (!to_div)
		print_err("L%u: division by zero\n", op_env.lineno);

	op_pop(pStack);

	(*pStack)->n /= to_div;
}
