#include "monty.h"

/**
 * rot_upward - rotate upward (toward top of stack)
 * @pStack: stack pointer
 */
void rot_upward(stack_t **pStack)
{
	if (*pStack)
		*pStack = (*pStack)->prev;
}

/**
 * rot_downward - rotate downward (toward bottom of stack)
 * @pStack: stack pointer
 */
void rot_downward(stack_t **pStack)
{
    if (*pStack)
        *pStack = (*pStack)->next;
}
