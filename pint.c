#include "monty.h"

/**
 * op_pint - print the value at the top of the stack
 * @pStack: stack pointer
 */
void op_pint(stack_t **pStack)
{
	if (*pStack)
		printf("%d\n", (*pStack)->n);
	else
        print_err("L%u: can't pint, stack empty\n", op_env.lineno);
}
