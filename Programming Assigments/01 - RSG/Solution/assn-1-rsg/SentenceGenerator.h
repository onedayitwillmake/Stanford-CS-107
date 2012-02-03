/*
 * SentenceGenerator.h
 *
 *  Created on: Jan 30, 2012
 *      Author: onedayitwillmake
 */

#ifndef SENTENCEGENERATOR_H_
#define SENTENCEGENERATOR_H_

#include "definition.h"
#include "random.h"
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include "SpacingHelper.h"

typedef std::map<std::string, Definition>    StringDefinitionMap;
class SentenceGenerator {
public:
	SentenceGenerator( StringDefinitionMap& grammer );
	virtual ~SentenceGenerator();

private:
	map<string, Definition> _grammer;
	std::vector<std::string> _nonTerminals;
	std::stringstream _sentence;
	SpacingHelper _spacingHelper;
	void expandSentence( const Production& prod ); // CDT debugger can't hit breakpoints in constructors
};

#endif /* SENTENCEGENERATOR_H_ */
