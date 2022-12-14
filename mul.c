#include "monty.h"

/**
 * op_mul - mul the top two elements on the stack
 * @pStack: stack pointer
 */
void op_mul(stack_t **pStack)
{
	int to_mul = 0;

	if (!(*pStack && *pStack != (*pStack)->next))
		print_err("L%u: can't mul, stack too short\n", op_env.lineno);

	to_mul = (*pStack)->n;

	op_pop(pStack);

	(*pStack)->n *= to_mul;
}
