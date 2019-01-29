/**
@file stack.h
*/
#include "memcheck.h"

#ifndef SPL_STACK_H
#define SPL_STACK_H

typedef struct StackImplementation* Stack;

/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack();

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack);

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data);

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack);

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack);

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.z
*/
void* peek_stack(Stack stack);

#endif //SPL_STACK_H
