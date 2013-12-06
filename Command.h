*
Name:	Francisco Javier Jimenez
Course:	CSCI 3334

Description:  Parses the input string.  Determines which command is being called.
*/


#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "Assembler.h"

using namespace std;

class Command
{
private:
	Assembler _obj;
public:
	void parse(string s, vector<string> &i);
	void exe();
	void load_file(string file);
	void debug();
	void dump(string start, string end);
	void help();
	void directory();
	void exit();
	void command_chk(vector<string> &i);
};

#endif
