/*
 * SpacingHelper.cpp
 *
 *  Created on: Feb 2, 2012
 *      Author: onedayitwillmake
 */

#include "SpacingHelper.h"
#include <iostream>

SpacingHelper::SpacingHelper() {
	_rules["."] = "\n";
	_rules[","] = "";
	_rules[""] = "";
}
SpacingHelper::~SpacingHelper() {
}


void SpacingHelper::getSpaceRuleFor( const std::string& needle, std::string&result ) {

	std::map<std::string, std::string>::const_iterator found = _rules.find(needle);
	if( found == _rules.end() ) {
		result = " ";
		return;
	}

	result = _rules[needle];
}
