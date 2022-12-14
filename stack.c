#include "monty.h"

/**
 * op_stack - set stack mode to last-in first-out (default)
 * @pStack: stack pointer
 */
void op_stack(stack_t **pStack __attribute__((unused)))
{
	op_env.mode = LIFO;
}


/**
 * op_pop - remove the element at the top of the stack
 * @pStack: stack pointer
 */
void op_pop(stack_t **pStack)
{
    stack_t *top = NULL;

    if (!*pStack)
        print_err("L%u: can't pop an empty stack\n", op_env.lineno);

    if (*pStack != (*pStack)->prev)
    {
        top = (*pStack)->prev;
        (*pStack)->next->prev = top;
        top->next = (*pStack)->next;
    }
    free(*pStack);
    *pStack = top;
}


/**
 * op_push - push an element onto the stack
 * @pStack: stack pointer
 */
void op_push(stack_t **pStack)
{
    stack_t *new = NULL;
    const char *nstr = op_env.argv[1];

    if (!(nstr && isinteger(nstr)))
        print_err("L%u: usage: push integer\n", op_env.lineno);

    new = malloc(sizeof(*new));
    if (!new)
        print_err("Error: malloc failed\n");

    new->n = atoi(nstr);
    if (*pStack)
    {
        new->prev = (*pStack);
        new->next = (*pStack)->next;
        new->next->prev = new;
        (*pStack)->next = new;
        if (op_env.mode == LIFO)
            (*pStack) = new;
    }
    else
    {
        new->prev = new;
        new->next = new;
        (*pStack) = new;
    }
}


/**
 * free_stack - free and nullify a stack
 * @pStack: pointer to a pointer to the top of a stack
 */
void free_stack(stack_t **pStack)
{
    stack_t *top = NULL;

    if (pStack && *pStack)
    {
        top = *pStack;
        top->next->prev = NULL;
        do {
            *pStack = top->prev;
            free(top);
        } while ((top = *pStack));
    }
}


/**
 * free_env - clear stack operation environment
 */
void free_env(void)
{
    free_stack(&op_env.sp);
    free(op_env.argv);
    free(op_env.line);
    op_env.argv = NULL;
    op_env.line = NULL;
}


