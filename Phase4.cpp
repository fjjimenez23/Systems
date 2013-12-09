/*
	Francisco Javier Jimenez
	CSCI 3334
	Phase 2
*/

#include "sicengine.c"
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Assembler.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int convert(string, int);
void parse(string s, vector<string> &i);
void exe(ADDRESS s);
void load_file(string file);
void debug();
void dump(string start, string end);
void help();
void directory();
void exit();
void command_chk(vector<string> &i);

int main()
{
	bool f_loaded=false;
	string stor;
	vector<string> input;
	ADDRESS address;

	cout << "Welcome to Phase1 command simulator!";
	do{
	cout << "\ncmd> ";
	getline(cin,stor);
	//Parses the string and inserts it into vector<>
	parse(stor, input);

	//Checks to see if the vector is a actual command and intiates corresponding command
	command_chk(input);
	
	//if command is exit it will break the loop
	}while(stor!="exit");

}
int convert(string temp, int base)
{
	int num;
	char *stop;
	num = strtol(temp.c_str(), &stop, base);
	
	if(!*stop)
		return num;
	return INT_MIN;
}
void parse(string test, vector<string> &input)
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

void command_chk(vector<string> &i, ADDRESS add)
{
	if(i.size()!=0)
	{
		if(i.front() == "dump")
		{
			if(i.size()<2||i.size()>3)
			{
				cout << "missing start and/or end refer to help" << endl;
				i.clear(); //clears out the vector
				return;
			}else{
					dump(i.at(1), i.back());
					i.clear();
					return;
				  }
		}else
		if(i.front()=="load")
		{
			if(i.size()<2||i.size()>3)
			{
				cout << "Missing/Excessive filename refer to help" << endl;
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
					//assemble(i.back());
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
				exe(add);
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
	cout << "...NOT VALID COMMAND See help..." << endl;
}

void dump(string start, string end)
{
	if(!file.fail())
	{
		int startAddress;
		int endAddress;
		BYTE value;
		int cnt = 0;

		startAddress = convert(start,16);
		endAddress = convert(end,16);
		
		for( int i = startAddress; i < endAddress; i+=2, cnt++)
		{
			if( cnt != 0 && cnt %16 ==0)
			{
				cout << "\n" << hex << i << ": ";
			}

			GetMem(i, &value, 0);
			cout << setfill('0') << setw(2) << (int) value << " ";

		}

		cout << "\n";
	}
	cout << "...No File Loaded..." << endl;
}
///////////////////////////////////////////////////phase4///////////////////////////////////////////////////
void load_file(string file)
{
	SICInit();

	ifstream InFile(file.c_str());

	string i_line;
	string num;
	
	while(getline(InFile, i_line))
	{
		if(i_line[0] == 'H')
		{
			string temp = i_line.substr(13, i_line.length());

			progLength = convert(temp,16);
		}
		if(i_line[0] == 'T')
		{
			ADDRESS address;
			BYTE value;

			num = i_line.substr(1,7);
			address = convert(num, 16);

			for(int i = 9; i < i_line.length(); i+=2)
			{
				num = i_line.substr(i,i+2);
				value = convert(num, 16);
			}
		}
		else if(i_line[0] == 'E')
		{

		}
		else if(i_line[0] != 'H')
		{

		}
	}

	//fileloaded = true;
}


void exe(ADDRESS end)
{
	if(!file.fail())
		SICRun(&end,0);
	else
		cout << "FILE NOT LOADED" << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void debug()
{
	cout << "debug command has been reached" << endl;
}

void help()
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

void directory()
{
	system("ls");
}

void exit()
{

}
