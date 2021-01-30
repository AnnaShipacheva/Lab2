#ifndef PROGRAMPARSER_H
#define PROGRAMPARSER_H

#include <utility>
#include <fstream>
#include <iostream>
#include "BlockProgram.h"
#include "Validator.h"
#include "ReadFileBlock.h"
#include "WriteFileBlock.h"
#include "GrepBlock.h"
#include "SortBlock.h"
#include "ReplaceBlock.h"
#include "DumpBlock.h"

class ProgramParser
{
public:
	static BlockProgram parseProgram(string file, string input = "", string output = "");
};
#endif
