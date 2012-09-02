/*
 * stack.c
 *
 *  Created on: Sep 2, 2012
 *      Author: onedayitwillmake
 */
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void StackGrow( stack *s ) {
	s->allocLength *= 2;
	s->elems = realloc( s->elems, s->allocLength * s->elemSize );
}

void StackNew( stack *s, int elemSize ) {
	assert( elemSize > 0 );

	s->elemSize = elemSize;
	s->logLength = 0;
	s->allocLength = 4;
	s->elems = malloc( s->allocLength * elemSize );

	assert( s->elems != NULL );
}

void StackDispose( stack *s ) {
	free(s->elems);
}

void StackPush( stack*s, void* elemAddress ) {
	if( s->logLength == s->allocLength ) {
		StackGrow( s );
	}

	void* target = (char*)s->elems + (s->logLength * s->elemSize);
	// Copy into target, s->elemSize bytes from memory address elemAddress
	memcpy( target, elemAddress, s->elemSize );
	s->logLength++;
}

void StackPop( stack *s, void* elemAddress ) {
	assert(s->logLength > 0 );
	s->logLength--;
	void *source = (char*)s->elems+(s->logLength*s->elemSize);

	// Copy into elemAddress[0],
	// a total of (s->elemSize[2]) bytes
	// starting from the memory location of source[1]
	memcpy( elemAddress, source, s->elemSize );
}
