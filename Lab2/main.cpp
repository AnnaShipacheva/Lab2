#include <iostream>
#include "ProgramParser.h"
#include "Test.h"

int main(int argc, char* argv[])
{
	//в файлы test для демонстрации выводятся аргументы командной строки и обработанные исключения, если есть 
	//testFile.open("test0.txt"); //для случая argc==1;
	/*string nameF = (string)"test_" + (string)argv[1];
	testFile.open(nameF);
	for (int i = 0; i < argc; ++i)
		testFile << argv[i] << " ";
	testFile << "\n";*/
	try {
		if (argc < 2)
			throw std::invalid_argument("Not enough args.");
		string workflow = argv[1];
		string input, output;
		if (argc > 2) {
			bool wasI = false, wasO = false;
			for (int i = 2; i < argc; ++i)
			{
				if (((string)"-i" == argv[i]) && (i + 1) != argc && !wasI)
				{
					wasI = true;
					++i;
					input = argv[i];
				}
				else if (((string)"-o" == argv[i]) && (i + 1) != argc && !wasO)
				{
					wasO = true;
					++i;
					output = argv[i];
				}
				else
				{
					throw invalid_argument("Wrong args.");
				}
			}
		}
		ProgramParser::parseProgram(workflow,input,output).execute();
	}
	catch (std::exception &exception)
	{
		cerr << exception.what();
		//printExept(exception, testFile);
	}
	testFile.close();
	return 0;
}