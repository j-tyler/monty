#include "monty.h"
/**                                                                                  
 * _queue - Set the mode to queuing
 * @stack: the stack                                                                 
 * @line: line number                                                                
 */                                                                                  
void _queue(stack_t **stack, unsigned int line)                                        
{                                                                                    
	(void) stack;
     (void) line;
	global.mode = 1;
}
