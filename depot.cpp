#include <stdlib.h>
#include "depot.h"
#include "stack.h"

struct DepotImplementation {
    Stack stack_of_stacks;
};

Depot create_depot()
{
  Depot new_depot = (Depot)smalloc(sizeof(struct DepotImplementation));
  new_depot->stack_of_stacks = create_stack();
  return new_depot;
}

void delete_depot(Depot depot)
{
  while (get_count(depot->stack_of_stacks) != 0)
  {
    delete_stack((Stack)pop_stack(depot->stack_of_stacks));
  }
  sfree(depot->stack_of_stacks);
  sfree(depot);
}

void push_depot(Depot depot, Product *product)
{
  if (get_count(depot->stack_of_stacks) == 0)
  {
    Stack new_stack = create_stack();
    push_stack(new_stack,product);
    push_stack(depot->stack_of_stacks,new_stack);
    return;
  }
  Stack current = (Stack)peek_stack(depot->stack_of_stacks);
  if (get_count(current) == STACK_SIZE_LIMIT)
  {
    Stack new_stack = create_stack();
    push_stack(new_stack,product);
    push_stack(depot->stack_of_stacks,new_stack);
    return;
  }
  push_stack(current, product);
}


int get_count(Depot depot)
{
    return get_count(depot->stack_of_stacks);
}

Product* pop_depot(Depot depot)
{

  if (get_count(depot->stack_of_stacks) == 0){
		return 0;
    }
	Stack curr_stack = (Stack) peek_stack(depot->stack_of_stacks);
	if (get_count(curr_stack) == 1) {
		curr_stack = (Stack) pop_stack(depot->stack_of_stacks);
		Product *prod = (Product*) pop_stack(curr_stack);
		delete_stack(curr_stack);
		return prod;
	}
return (Product*) pop_stack(curr_stack);
}
