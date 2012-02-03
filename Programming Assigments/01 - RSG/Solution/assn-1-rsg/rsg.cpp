/**
 * File: rsg.cc
 * ------------
 * Provides the implementation of the full RSG application, which
 * relies on the services of the built-in string, ifstream, vector,
 * and map classes as well as the custom Production and Definition
 * classes provided with the assignment.
 */

#include <map>
#include <fstream>
#include "definition.h"
#include "production.h"
#include "SentenceGenerator.h"
using namespace std;

/**
 * Takes a reference to a legitimate infile (one that's been set up
 * to layer over a file) and populates the grammar map with the
 * collection of definitions that are spelled out in the referenced
 * file.  The function is written under the assumption that the
 * referenced data file is really a grammar file that's properly
 * formatted.  You may assume that all grammars are in fact properly
 * formatted.
 *
 * @param infile a valid reference to a flat text file storing the grammar.
 * @param grammar a reference to the STL map, which maps nonterminal strings
 *                to their definitions.
 */

static void readGrammar(ifstream& infile, map<string, Definition>& grammar) {
	while (true) {
		string uselessText;
		getline(infile, uselessText, '{');
		if (infile.eof())
			return; // true? we encountered EOF before we saw a '{': no more productions!
		infile.putback('{');
		Definition def(infile);
		grammar[def.getNonterminal()] = def;
	}
}

/**
 * Performs the rudimentary error checking needed to confirm that
 * the client provided a grammar file.  It then continues to
 * open the file, read the grammar into a map<string, Definition>,
 * and then print out the total number of Definitions that were read
 * in.  You're to update and decompose the main function to print
 * three randomly generated sentences, as illustrated by the sample
 * application.
 *
 * @param argc the number of tokens making up the command that invoked
 *             the RSG executable.  There must be at least two arguments,
 *             and only the first two are used.
 * @param argv the sequence of tokens making up the command, where each
 *             token is represented as a '\0'-terminated C string.
 */

int main(int argc, char *argv[]) {
	std::string filepath = "./data/bionic.g";
	if (argc == 1) {
	} else {
		filepath = std::string( argv[1] );
	}

	ifstream grammarFile( filepath.c_str() );
	if (grammarFile.fail()) {
		cerr << "Failed to open the file named \"" << filepath
				<< "\".  Check to ensure the file exists. " << endl;
		return 2; // each bad thing has its own bad return value
	}

	// things are looking good...
	map<string, Definition> grammar;
	readGrammar(grammarFile, grammar);
	cout << "The grammar file called \"" << filepath << "\" contains "
			<< grammar.size() << " definitions." << endl;


	// Create a sentence generator, and output the final sentence
	SentenceGenerator generator( grammar );
	cout << generator.getFinalSentence() << endl;
	return 0;
}
