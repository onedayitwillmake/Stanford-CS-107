#include "intstack.h"
#include "stdlib.h"
#include "assert.h"

void IntStackNew( intstack* s ) {
	s->logLength = 0;
	s->allocLength = 4;
	s->elems = malloc( 4 * sizeof(int) );

	assert( s->elems != NULL );
}

void IntStackDispose( intstack* s ) {
	free( s->elems );
}

void IntStackPush( intstack* s, int value ) {
	// Not enough space - allocate morep
	if( s->logLength == s->allocLength ) {
		s->allocLength *= 2;
		s->elems = realloc( s->elems, s->allocLength * sizeof(int) );
		assert( s->elems != NULL );
	}

	s->elems[s->logLength] = value;
	s->logLength++;
}
int	IntStackPop( intstack* s ) {
	assert( s->logLength > 0 );

	s->logLength--;
	return s->elems[ s->logLength ];
}
