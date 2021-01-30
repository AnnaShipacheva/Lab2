#include "GrepBlock.h"

GrepBlock::GrepBlock(string &find)
{
	m_args.push_back(find);
}

bool GrepBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)
{
	if (!haveInput)
		throw logic_error("null input on grep. Block index: " + to_string(index));
	
	if (input->empty())
	{
		(*output) = (*input);
		return true;
	}
	(*output).clear();
	for (const auto &i : *input)
	{
		if (i.find(m_args[0]) != string::npos)
			output->push_back(i);
	}
	haveOutput = true;
	return true;
}

