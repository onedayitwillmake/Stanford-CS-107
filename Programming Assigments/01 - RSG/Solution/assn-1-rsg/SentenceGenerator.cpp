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
	for(StringDefinitionMap::iterator itr = _grammer.begin(); itr != _grammer.end(); ++itr ) {
		std::cout << itr->first << std::endl;
	}
}

SentenceGenerator::~SentenceGenerator() {
}
