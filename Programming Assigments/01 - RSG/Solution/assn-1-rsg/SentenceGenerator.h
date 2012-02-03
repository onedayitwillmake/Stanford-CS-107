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

	//  const string& getNonterminal() const { return nonterminal; }

	const string getFinalSentence() const { return _sentence.str(); };
private:
	map<string, Definition> _grammer;
	SpacingHelper _spacingHelper;

	std::stringstream _sentence;
	std::string _lastString;

	void expandSentence( const Production& prod ); // CDT debugger can't hit breakpoints in constructors
};

#endif /* SENTENCEGENERATOR_H_ */
