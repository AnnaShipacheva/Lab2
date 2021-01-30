#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

class Validator
{
public :
	static bool fileExists(string file);
	static void badFile(string message);
};
#endif
