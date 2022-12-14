#include "monty.h"

/**
 * op_queue - set stack mode to first-in first-out
 * @pStack: stack pointer
 */
void op_queue(stack_t **pStack __attribute__((unused)))
{
	op_env.mode = FIFO;
}
