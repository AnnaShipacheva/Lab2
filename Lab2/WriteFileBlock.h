#ifndef WRITEFILEBLOCK_H
#define WRITEFILEBLOCK_H

#include "Worker.h"
#include <fstream>
#include "Validator.h"

class WriteFileBlock:public Worker
{
public:
	WriteFileBlock(string &);
	static void writeFile(string, vector <string>&);
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) override;
};
#endif

