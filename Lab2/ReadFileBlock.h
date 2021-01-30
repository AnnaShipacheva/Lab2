#ifndef READFILEBLOCK_H
#define READFILEBLOCK_H

#include "Worker.h"
#include <fstream>
#include "Validator.h"

class ReadFileBlock: public Worker
{
public:
	ReadFileBlock(string &);
	static void readFile(string, vector<string> &);
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)override;
};

#endif 
