#ifndef DUMPBLOCK_H
#define DUMPBLOCK_H

#include "Worker.h"
#include <fstream>
#include "Validator.h"

class DumpBlock :public Worker
{
public:
	DumpBlock(string&);
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)override;
};
#endif
