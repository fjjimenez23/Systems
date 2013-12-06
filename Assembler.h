/*
Name:	Francisco Javier Jimenez
Course:	CSCI 3334

Description:  Assemble function. PassOne.  Checks for Errors.
*/

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Assembler
{
private:
	string errors;
public:

void assemble(string file);
void parse(string temp, vector<string> &output);
void chk_lbl(map<string,int> Opcode,map<string,int> &Symbol,vector<string> output, int loc_cntr);

};
#endif
