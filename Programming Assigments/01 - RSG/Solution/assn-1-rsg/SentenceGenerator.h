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

typedef std::map<std::string, Definition>    StringDefinitionMap;
class SentenceGenerator {
public:
	SentenceGenerator( StringDefinitionMap& grammer );
	virtual ~SentenceGenerator();

private:
	map<string, Definition> _grammer;
};

#endif /* SENTENCEGENERATOR_H_ */
