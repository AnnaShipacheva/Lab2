#include "ReadFileBlock.h"

ReadFileBlock::ReadFileBlock(string &ifile)
{
	m_args.push_back(ifile);
}

void ReadFileBlock::readFile(string input, vector<string> &output) 
//используется если имя входного файла было передано аргументом командной строки, в схеме нет чтения файла
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
//используется если в схеме есть блок чтения файла
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