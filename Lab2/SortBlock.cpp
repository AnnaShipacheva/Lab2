#include "SortBlock.h"

bool SortBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)
{
	if (!haveInput)
		throw logic_error("null input on sort. Block index:" + to_string(index));
	
	(*output) = (*input);
	if (input->empty())
		return true;
	sort((*output).begin(), (*output).end());
	haveOutput = true;
	return true;
}