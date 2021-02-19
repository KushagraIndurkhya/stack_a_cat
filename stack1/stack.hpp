/*
Stack1 stack.hpp
Author: Kushagra Indurkhya (CS19B1017)
*/


//interface for stack

//defining stack_id as an int
struct stack_id{ int i; };
/*
 * Function:  create
 * --------------------
 * Create a stack
 * returns: stack_id of the created stack
 *                     
 */
stack_id create(int) ;
/*
 * Function:  push
 * --------------------
 * pushes a long long int in the stack having given stack_id
 * returns: Void
 *                     
 */
void push(stack_id,long long int) ;
/*
 * Function:  pop
 * --------------------
 * performs pop operation on the stack with given stack_id
 * returns: Void
 *                     
 */
long long int pop(stack_id);
/*
 * Function:  destroys
 * --------------------
 * destroyes the  stack of given stack_id
 * returns: Void
 *                     
 */
void destroy(stack_id) ;
/*
 * Function:  printstack
 * --------------------
 * Print the contents of the stack with given stack_id
 * returns: Void
 *                     
 */
void printstack(stack_id);