/*
 * SpacingHelper.h
 *
 *  Created on: Feb 2, 2012
 *      Author: onedayitwillmake
 */

#ifndef SPACINGHELPER_H_
#define SPACINGHELPER_H_
#include <string>
#include <map>

class SpacingHelper {
public:
	SpacingHelper();
	~SpacingHelper();
	void getSpaceRuleFor( const std::string& needle, std::string&result );

private:
	std::map<std::string, std::string> _rules;
};

#endif /* SPACINGHELPER_H_ */
