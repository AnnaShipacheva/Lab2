#include "WriteFileBlock.h"

WriteFileBlock::WriteFileBlock(string &ofile)
{
	m_args.push_back(ofile);
}

void WriteFileBlock::writeFile(string output, vector<string> &text)
//используется если имя выходного задается через командную строку, в схеме нет блока записи в файл
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
//используется если в схеме есть блок записи в файл
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