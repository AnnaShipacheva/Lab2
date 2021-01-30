#ifndef GREPBLOCK_H
#define GREPBLOCK_H

#include "Worker.h"

class GrepBlock:public Worker
{
public:
	GrepBlock(string&);
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) override;
};
#endif
