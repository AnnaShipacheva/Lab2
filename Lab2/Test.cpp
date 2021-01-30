#include "Test.h"

void printExept(std::exception &e, std::ofstream &file)
{
	file << e.what();
}