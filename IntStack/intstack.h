/*
 * stack.h
 *
 *  Created on: Sep 2, 2012
 *      Author: onedayitwillmake
 */
#ifndef INT_STACK_H
#define INT_STACK_H

typedef struct {
	int *elems;
	int logLength;
	int allocLength;
} intstack;

void	IntStackNew( intstack* s );
void	IntStackDispose( intstack* s );
void	IntStackPush( intstack* s, int value );
int		IntStackPop( intstack* s );

#endif
