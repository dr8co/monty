#include "monty.h"

/**
 * op_pchar - print the character at the top of the stack
 * @pStack: stack pointer
 */
void op_pchar(stack_t **pStack)
{
	if (*pStack)
	{
		if ((*pStack)->n > 0 && (*pStack)->n < 128)
			printf("%c\n", (*pStack)->n);
		else
			print_err("L%u: can't pchar, value out of range\n", op_env.lineno);
	}
	else
		print_err("L%u: can't pchar, stack empty\n", op_env.lineno);


}
