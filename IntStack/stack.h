/*
 * stack
 *
 *  Created on: Sep 2, 2012
 *      Author: onedayitwillmake
 */

#ifndef STACK_H
#define STACK_H
typedef struct {
	void *elems;
	int elemSize;
	int logLength;
	int allocLength;
} stack;

void StackNew( stack* s, int elemSize );
void StackDispose( stack*s );
void StackPush( stack *s, void* elemAddress );
void StackPop( stack *s, void* elemAddress );

#endif /* STACK_H */
