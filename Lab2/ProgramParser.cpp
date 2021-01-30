#include "ProgramParser.h"

bool parseBlockPart(map<unsigned int, shared_ptr<Worker>> &, ifstream&);
bool parseQueue(vector<int>&, ifstream&);

BlockProgram ProgramParser::parseProgram(string file, string input, string output)
{
		if (!Validator::fileExists(file))
			Validator::badFile("Bad file: " + file);
		if (!input.empty() && !Validator::fileExists(input))
			Validator::badFile("Bad file: " + input);
		ifstream scheme(file);

		map<unsigned int, shared_ptr<Worker>> blocks;
		parseBlockPart(blocks, scheme);

		vector<int> queue;
		parseQueue(queue, scheme);
		
		if (!dynamic_cast<ReadFileBlock*>(blocks[queue[0]].get()) && input.empty())
		{
			blocks.clear();
			queue.clear();
			throw invalid_argument("Haven't input");
		}

		if (!dynamic_cast<WriteFileBlock*>(blocks[queue.back()].get()) && output.empty())
		{
			blocks.clear();
			queue.clear();
			throw invalid_argument("Haven't output");
		}
		scheme.close();
	return BlockProgram(blocks, queue, move(input), move(output));
}

shared_ptr<Worker> parseBlock(ifstream &scheme)
{
	string str0;
	scheme >> str0;
	if (str0 != "=")
		Validator::badFile("There is not '=' in block part.");
	scheme >> str0;
	shared_ptr<Worker> block;
	string str1;
	if (str0 == "readfile")
	{
		scheme >> str1;
		block = make_shared<ReadFileBlock>(str1);
		return block;
	} 
	else if (str0 == "writefile") 
	{
		scheme >> str1;
		block = make_shared<WriteFileBlock>(str1);
		return block;
	}
	else if (str0 == "grep")
	{
		scheme >> str1;
		block = make_shared<GrepBlock>(str1);
		return block;
	}
	else if (str0 == "sort")
	{
		block = make_shared<SortBlock>();
		return block;
	}
	else if (str0 == "replace")
	{
		scheme >> str0 >> str1;
		block = make_shared<ReplaceBlock>(str0, str1);
		return block;
	}
	else if (str0 == "dump")
	{
		scheme >> str1;
		block = make_shared<DumpBlock>(str1);
		return block;
	}
	else
	{
		Validator::badFile("Unknown block name: " + str0);
	}
}
bool parseBlockPart(map<unsigned int, shared_ptr<Worker>> &blocks, ifstream& scheme)
{
	if (scheme.eof())
			Validator::badFile("EOF file.");
		string str;
		scheme >> str;
		if (str != "desc")
			Validator::badFile("Haven't 'desc' at block part.");

		unsigned int index;
		while (true)
		{
			if (scheme.eof())
				Validator::badFile("Haven't 'csed' at block part.");
			scheme >> str;
			if (str == "csed")
				break;
			index = stoi(str);
			if (blocks.count(index))
				Validator::badFile("Index " + to_string(index) + " already exists.");
			blocks[index] = parseBlock(scheme);	
		}
	return true;
}

bool parseQueue(vector<int> &queue, ifstream &scheme)
{
		if (scheme.eof())
			Validator::badFile("There is no queue part in file.");
		string str;
		unsigned int index;
		while (true)
		{
			if (scheme.eof())
				break;
			scheme >> str;
			index = stoi(str);
			queue.push_back(index);
			if (scheme.eof())
				break;
			scheme >> str;
			if (str != "->")
				Validator::badFile("Unknown symbol in queue part: "+ str);

		}
	return true;
}