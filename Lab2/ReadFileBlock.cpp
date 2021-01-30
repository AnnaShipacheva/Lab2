#include "ReadFileBlock.h"

ReadFileBlock::ReadFileBlock(string &ifile)
{
	m_args.push_back(ifile);
}

void ReadFileBlock::readFile(string input, vector<string> &output) 
//used if name input file was in cmd args, there is no readfile block in workflow
{
	if (!Validator::fileExists(input))
		Validator::badFile("File " + input + "does not exist or can not open");
	ifstream ifile(input);
	string line;
	while (getline(ifile, line))
	{
		output.push_back(line);
	}
	ifile.close();
}

bool ReadFileBlock::execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) 
//used if name input file was in workflow
{
	if (haveInput)
		throw logic_error("non null input on read file: " + m_args[0] + ". Block ingex: " + to_string(index));
	
	if (!Validator::fileExists(m_args[0]))
	{
		Validator::badFile("File " + m_args[0] + "does not exist or cannot open.");
	}

	string line;
	ifstream ifile(m_args[0]);

	while (getline(ifile, line))
	{
		output->push_back(line);
	}

	ifile.close();
	haveOutput = true;
	return true;
}