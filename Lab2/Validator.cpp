#include "Validator.h"

bool Validator :: fileExists(string file)
{
	ifstream iff(file);
	return iff.is_open();
}

void Validator::badFile(string message)
{
	throw invalid_argument("Bad program file. " + message);
}