#ifndef BLOCKPROGRAM_H
#define BLOCKPROGRAM_H

#include <utility> // для move()
#include <memory> //для shared_ptr
#include "Worker.h"
#include "ReadFileBlock.h"
#include "WriteFileBlock.h"
#include <map>

class BlockProgram
{
private:
	map<unsigned int, shared_ptr<Worker>> blocks;
	vector<int> queue;
	string input;
	string output;
public:
	BlockProgram(map<unsigned int, shared_ptr<Worker>> Blocks, vector<int> Queue, string Input, string Output) :
		blocks(move(Blocks)), queue(move(Queue)), input(move(Input)), output(move(Output)) {}
	~BlockProgram();
	void execute();
};
#endif 

