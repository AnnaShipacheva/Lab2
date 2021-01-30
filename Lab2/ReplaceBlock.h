#ifndef REPLACEBLOCK_H
#define REPLACEBLOCK_H

#include "Worker.h"

class ReplaceBlock :public Worker
{
public:
	ReplaceBlock(string &, string &);
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) override;
};
#endif