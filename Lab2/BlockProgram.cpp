#include "BlockProgram.h"

BlockProgram::~BlockProgram()
{
	blocks.clear();
	queue.clear();
}
void BlockProgram::execute()
{
	if (queue.empty() || blocks.empty())
		return;
	bool haveInput = false, haveOutput = false;
	vector<string>textI;
	vector<string>textO;
	if (!dynamic_cast<ReadFileBlock*>(blocks[queue[0]].get()) && !input.empty())
	{
		ReadFileBlock::readFile(input, textI);
		haveInput = true;
	}
	for (auto i : queue)
	{
		blocks[i]->execute(&textI, &textO, haveInput, haveOutput, i);
		textI = textO;
		haveInput = haveOutput;
	}

	if (!dynamic_cast<WriteFileBlock*>(blocks[queue.back()].get()) && !output.empty())
		WriteFileBlock::writeFile(output, textO);
}