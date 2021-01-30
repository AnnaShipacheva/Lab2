#include "WriteFileBlock.h"

WriteFileBlock::WriteFileBlock(string &ofile)
{
	m_args.push_back(ofile);
}

void WriteFileBlock::writeFile(string output, vector<string> &text)
//used if name output file was in cmd args, there is no writefile block in workflow
{
	ofstream ofile(output);

	if (!ofile.is_open())
		Validator::badFile("File" + output + "cannot open");
	for (const auto &i : text)
	{
		ofile << i << endl;
	}

	ofile.close();
}

bool WriteFileBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index)
//used if name output file was in workflow
{
	if (!haveInput)
		throw logic_error("null input on wtire file: " + m_args[0] + ". Block index: " + to_string(index));
	
	ofstream ofile(m_args[0]);
	if (!ofile.is_open())
		Validator::badFile("File" + m_args[0] + "cannot open");
	for (const auto &i : *input)
	{
		ofile << i << endl;
	}
	ofile.close();
	haveOutput = false;
	return true;
}