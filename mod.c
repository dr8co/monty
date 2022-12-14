#include "monty.h"

/**
 * op_mod - mod the top two elements on the stack
 * @pStack: stack pointer
 */
void op_mod(stack_t **pStack)
{
	int to_mod = 0;

	if (!(*pStack && *pStack != (*pStack)->next))
        print_err("L%u: can't mod, stack too short\n", op_env.lineno);

	to_mod = (*pStack)->n;
	if (!to_mod)
        print_err("L%u: division by zero\n", op_env.lineno);

	op_pop(pStack);

	(*pStack)->n %= to_mod;
}
