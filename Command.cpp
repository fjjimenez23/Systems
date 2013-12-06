/*
Name:	Francisco Javier Jimenez
Course:	CSCI 3334

Description:  Parses the input string.  Determines which command is being called.
*/


#include "Command.h"
#include <iostream>

void Command::parse(string test, vector<string> &input)
{
	string token="";
	// breaks the command string into seperate tokens and inserts them to a vector
	for(int i =0; i<test.length(); i++)
	{// checks to see if the character is a space or a tab
		if( test[i] != 32 && test[i] != '\t')
		{
			token+=test[i];
		}
		else
		{
			input.push_back(token);
			token="";
		}
	}
	input.push_back(token);
}

void Command::command_chk(vector<string> &i)
{
	if(i.size()!=0)
	{
		if(i.front() == "dump")
		{
			if(i.size()<2||i.size()>3)
			{
				cout << "missing start and/or end refer to help" << endl;
				i.clear();
				return;
			}else{
					dump(i.at(1), i.back());
					i.clear();
					return;
				  }
		}else
		if(i.front()=="load")
		{
			if(i.size()<2)
			{
				cout << "missing filename refer to help" << endl;
				i.clear();
				return;
			}else{
					load_file(i.back());
					i.clear();
					return;
				}
		}else
		if(i.front()=="assemble")
		{
			if(i.size()<2)
			{
				cout << "missing filname refer to help" << endl;
				i.clear();
				return;
			}else{
					_obj.assemble(i.back());
					i.clear();
					return;
				}
		}else
		if(i.front()=="execute")
		{
			if(i.size()>2)
			{
				cout << "parameters not recognized with this command refer to help" << endl;
				i.clear();
				return;
			}else{
				exe();
				i.clear();
				return;
				}
		}else
		if(i.front()=="debug")
		{
			if(i.size()>2)
			{
				cout << "parameters not recognized with this command refer to help" << endl;
				i.clear();
				return;
			}else{
				debug();
				i.clear();
				return;
				}

		}else
		if(i.front()=="help")
		{
			if(i.size()>2)
			{
				cout << "parameters not recognized with this command refer to help" << endl;
				i.clear();
				return;
			}else{
				help();
				i.clear();
				return;
				}

		}else
		if(i.front()=="dir"||i.front()=="directory")
		{
			if(i.size()>2)
			{
				cout << "parameters not recognized with this command refer to help" << endl;
				i.clear();
				return;
			}else{
				directory();
				i.clear();
				return;
				}
		}else
		if(i.front()=="exit")
		{
			if(i.size()>2)
			{
				cout << "parameters not recognized with this command refer to help" << endl;
				i.clear();
				return;
			}else{
				exit();
				i.clear();
				return;
				}
		}
		
	}
	cout << "NOT VALID COMMAND See help" << endl;
}

void Command::dump(string start, string end)
{
	cout << "dump has been reached" << endl;
}

void Command::load_file(string file)
{
	cout << "load command has been reached" << endl;
}


void Command::exe()
{
	cout <<  "execute command has been reached" << endl;
}

void Command::debug()
{
	cout << "debug command has been reached" << endl;
}

void Command::help()
{
	cout << "AVAILABLE COMMANDS\n" << endl;
	cout << "load [filename]" << endl;
	cout << "execute" << endl;
	cout << "debug" << endl;
	cout << "dump [start] [end]" << endl;
	cout << "help" << endl;
	cout << "assemble [filename]" << endl;
	cout << "directory or dir"  << endl;
	cout << "exit\n" << endl;
}

void Command::directory()
{
	system("ls");
}

void Command::exit()
{

}
