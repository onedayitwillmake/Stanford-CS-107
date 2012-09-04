#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <iomanip>
#include "imdb.h"
#include "path.h"
using namespace std;

/**
 * Using the specified prompt, requests that the user supply
 * the name of an actor or actress.  The code returns
 * once the user has supplied a name for which some record within
 * the referenced imdb existsif (or if the user just hits return,
 * which is a signal that the empty string should just be returned.)
 *
 * @param prompt the text that should be used for the meaningful
 *               part of the user prompt.
 * @param db a reference to the imdb which can be used to confirm
 *           that a user's response is a legitimate one.
 * @return the name of the user-supplied actor or actress, or the
 *         empty string.
 */

static string promptForActor(const string& prompt, const imdb& db) {
	string response;
	while (true) {
		cout << prompt << " [or <enter> to quit]: ";
		getline(cin, response);
		if (response == "")
			return "";
		vector<film> credits;
		if (db.getCredits(response, credits))
			return response;
		cout << "We couldn't find \"" << response
				<< "\" in the movie database. " << "Please try again." << endl;
	}

	return "";
}


void generateShortestPath( const std::string& source, const std::string& target, const imdb& db ) {
	std::list<path> partialPaths;
	std::set< std::string > previouslySeenActors;
	std::set< film > previouslySeenFilms;

	// Add the initial node
	partialPaths.push_back( path( source ) );

	// If the queue is not empty and its front element is of length 5 or less
	while( !partialPaths.empty() && partialPaths.front().getLength() < 5 ) {

		// Pop the front
		path aPath = partialPaths.front();
		partialPaths.pop_front();

		std::cout << aPath << std::endl;

		// Get all of the last actors films
		std::vector<film> films;
		db.getCredits( aPath.getLastPlayer(), films );

		std::cout << "Checking actor " << aPath.getLastPlayer() << "'s films (total=" << films.size() << ")" << std::endl;

		// Iterate through all this actors movies, but first make sure we've not seen this movie already
		std::set< film >::iterator setItr;
		for( std::vector<film>::iterator movieItr = films.begin(); movieItr != films.end(); ++movieItr ) {
			std::pair< std::set<film>::iterator, bool > found = previouslySeenFilms.insert( *movieItr );
			if( !found.second ) {
				std::cout << "Already checked film '" << (*movieItr).title << "' skipping..." << std::endl;
				continue; /* movie was already in set */
			}

			std::vector< std::string >players;
			db.getCast( *movieItr, players );

			// Add all not seen cast members
			for( std::vector<std::string>::iterator playerItr = players.begin(); playerItr != players.end(); ++playerItr ) {
				std::pair< std::set<std::string>::iterator, bool > playerPair = previouslySeenActors.insert( *playerItr );
				if( !playerPair.second ) {
					std::cout << "Already checked actor '" << *playerItr << "' skipping..." << std::endl;
					continue;
				}

				path deeperPath = path( aPath );
				deeperPath.addConnection( *movieItr, *playerItr );

				// Connection made!
				if( *playerItr == target ) {
					std::cout << deeperPath << std::endl;
					return;
				}

				partialPaths.push_back( deeperPath );
			}
		}
	}
}

/**
 * Serves as the main entry point for the six-degrees executable.
 * There are no parameters to speak of.
 *
 * @param argc the number of tokens passed to the command line to
 *             invoke this executable.  It's completely ignored
 *             here, because we don't expect any arguments.
 * @param argv the C strings making up the full command line.
 *             We expect argv[0] to be logically equivalent to
 *             "six-degrees" (or whatever absolute path was used to
 *             invoke the program), but otherwise these are ignored
 *             as well.
 * @return 0 if the program ends normally, and undefined otherwise.
 */

int main(int argc, const char *argv[]) {
	imdb db(determinePathToData("./")); // inlined in imdb-utils.h
	if (!db.good()) {
		cout << "Failed to properly initialize the imdb database." << endl;
		cout
				<< "Please check to make sure the source files exist and that you have permission to read them."
				<< endl;
		exit(1);
	}

	while (true) {
		string source = "Carol Eby";//promptForActor("Actor or actress", db);
		if (source == "")
			break;
		string target = "Debra Muubu"; //promptForActor("Another actor or actress", db);
		if (target == "")
			break;
		if (source == target) {
			cout
					<< "Good one.  This is only interesting if you specify two different people."
					<< endl;
		} else {
			generateShortestPath( source, target, db );
			break;
			// replace the following line by a call to your generateShortestPath routine...
//			cout << endl << "No path between those two people could be found." << endl << endl;
		}
	}

	cout << "Thanks for playing!" << endl;
	return 0;
}

