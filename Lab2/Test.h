#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <stdexcept>

static std::ofstream testFile;
void printExept(std::exception &, std::ofstream &);

#endif
