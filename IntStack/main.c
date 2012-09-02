/*
 * main.c
 *
 *  Created on: Sep 2, 2012
 *      Author: onedayitwillmake
 */
#include "stdio.h"
#include "intstack.h"
#include "stack.h"

int main(void) {
	intstack intStack;
	IntStackNew(&intStack);
	IntStackPush(&intStack, 1);
	IntStackPush(&intStack, 9);
	IntStackPush(&intStack, 8);
	IntStackPush(&intStack, 3);
	IntStackPush(&intStack, 0xFF2);
	printf("IntStack=%i\n", IntStackPop(&intStack) );

	stack s;
	StackNew( &s, sizeof(double) );

	double num = 0.0;
	StackPush( &s, &num );

	int i;
	for(i = 0; i < 10; ++i ){
		num += 0.11;
		StackPush( &s, &num );
	}

	double a;
	StackPop(&s, &a);

	printf("DoubleStack=%f\n", a);
	return 0;
}

