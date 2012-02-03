/*
 * SentenceGenerator.cpp
 *
 *  Created on: Jan 30, 2012
 *      Author: onedayitwillmake
 */

#include "SentenceGenerator.h"
#include <iostream>

SentenceGenerator::SentenceGenerator( StringDefinitionMap& grammer ) {
	_grammer = grammer;
	StringDefinitionMap::const_iterator found = _grammer.find("<start>");
	if( found != _grammer.end() ) {
		_lastString = "";
		expandSentence( found->second.getRandomProduction() );
	} else {
		std::cout << "Start not found!" << std::endl;
	}
}


// Recursively expands a sentence
void SentenceGenerator::expandSentence( const Production& prod ) {
	for (Production::const_iterator curr = prod.begin(); curr != prod.end(); ++curr) {
		StringDefinitionMap::const_iterator isNonTerminal = _grammer.find(*curr);

		// Non terminal - just append it to the string
		if( isNonTerminal == _grammer.end() ) {
			std::string spacing;
			_spacingHelper.getSpaceRuleFor( _lastString, spacing );

			_lastString = (*curr);
			_sentence << spacing << (*curr);
		} else {
			expandSentence( isNonTerminal->second.getRandomProduction() ) ;
		}
	}
}


SentenceGenerator::~SentenceGenerator() {
}
