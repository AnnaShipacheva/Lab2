#ifndef SORTBLOCK_H
#define SORTBLOCK_H

#include "Worker.h"
#include <algorithm>

class SortBlock :public Worker
{
public:
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) override;
};
#endif
