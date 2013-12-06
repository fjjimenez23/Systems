/*
	Francisco Javier Jimenez
	CSCI 3334
	Phase 2
*/

#include <iostream>
#include "assembler.h"
#include "Command.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string stor;
	vector<string> input;
	Command command;

	cout << "Welcome to Phase1 command simulator!";
	do{
	cout << "\ncmd> ";
	getline(cin,stor);
	//Parses the string and inserts it into vector<>
	command.parse(stor, input);

	//Checks to see if the vector is a actual command and intiates corresponding command
	command.command_chk(input);
	
	//if command is exit it will break the loop
	}while(stor!="exit");

}
