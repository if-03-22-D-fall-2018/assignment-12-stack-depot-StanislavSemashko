#include <stdlib.h>
#include "stack.h"

typedef struct NodeImplementation* Node;

struct NodeImplementation {
    Node next;
    void* data;
};

struct StackImplementation {
    Node head;
    int count;
};

/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack()
{
  Stack new_stack = (Stack)smalloc(sizeof(struct StackImplementation));
  new_stack->count = 0;
  new_stack->head = 0;
  return new_stack;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack)
{

  Node current = stack->head;
  while (current != 0)
  {
    Node to_delate = current;
    current = current->next;
    sfree(to_delate);
  }
  sfree(stack);
}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data)
{
  Node new_node = (Node)smalloc(sizeof(struct NodeImplementation));
  new_node->data = data;
  new_node->next = stack->head;
  stack->head = new_node;
  stack->count++;

}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack)
{
  return stack->count;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack)
{
  if (get_count(stack) == 0)
  {
    return 0;
  }
  Node tmp = stack->head;
  stack->head = stack->head->next;
  stack->count--;
  void* data = tmp->data;
  sfree(tmp);
  return data;
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.z
*/
void* peek_stack(Stack stack)
{
  if (stack == 0)
  {
    return 0;
  }
  return stack->head->data;
}
