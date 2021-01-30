#include "ReplaceBlock.h"

ReplaceBlock::ReplaceBlock(string &from, string &to)
{
	m_args.push_back(from);
	m_args.push_back(to);
}

bool ReplaceBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)
{
	if (!haveInput)
		throw logic_error("null input on replace. Block index: " + to_string(index));
	
	(*output) = (*input);
	if (input->empty())
		return true;
	size_t ind;
	for (string &i : *output)
	{
		while ((ind = i.find(m_args[0])) != string::npos)
			i.replace(ind, m_args[0].size(), m_args[1]);
	}
	haveOutput = true;
	return true;
}