#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Worker {
protected:
	vector <string> m_args;
public:
	virtual ~Worker() = default;
	virtual bool execute(vector<string> *input, vector<string> *output, bool &haveInput, bool &haveOutput, unsigned int index) = 0;
};

#endif