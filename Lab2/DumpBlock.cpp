#include "DumpBlock.h"

DumpBlock::DumpBlock(string& output)
{
	m_args.push_back(output);
}

bool DumpBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)
{
	if (!haveInput)
		throw logic_error("null input on dump. Block index:" + to_string(index));
	
	(*output) = (*input);
	ofstream ofile(m_args[0]);
	if (!ofile.is_open())
		Validator::badFile("File" + m_args[0] + "cannot open");
	for (const auto &i : *input)
		ofile << i << endl;
	ofile.close();
	haveOutput = true;
	return true;
}