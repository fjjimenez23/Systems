/*
Name:	Francisco Javier Jimenez
Course:	CSCI 3334

Description:  Assemble function. PassOne.  Checks for Errors.
*/

#include "Assembler.h"

void Assembler::assemble(string file)
{
	ifstream source;
	string temp;
	int loc_cntr=0;
	map<string, int> Opcode;
	map<string, int> SymTab;

	Opcode["ADD"]=0x18;
	Opcode["AND"]=0x58;
	Opcode["COMP"]=0x28;
	Opcode["DIV"]=0x24;
	Opcode["J"]=0x3C;
	Opcode["JEQ"]=0x30;
	Opcode["JGT"]=0x34;
	Opcode["JLT"]=0x38;
	Opcode["JSUB"]=0x48;
	Opcode["LDA"]=0x00;
	Opcode["LDCH"]=0x50;
	Opcode["LDL"]=0x08;
	Opcode["LDX"]=0x04;
	Opcode["MUL"]=0x20;
	Opcode["OR"]=0x44;
	Opcode["RD"]=0xD8;
	Opcode["RSUB"]=0x4C;
	Opcode["STA"]=0x0C;
	Opcode["STCH"]=0x54;
	Opcode["STL"]=0x14;
	Opcode["STX"]=0x10;
	Opcode["SUB"]=0x1C;
	Opcode["TD"]=0xE0;
	Opcode["TIX"]=0x2C;
	Opcode["WD"]=0xDC;

	source.open(file.c_str());

	while(getline(source,temp))
	{
		vector<string> output;
		parse(temp,output);
		chk_lbl(Opcode,SymTab,output,loc_cntr);
	}

	source.close();
}

void Assembler::parse(string temp, vector<string> &output)
{
	string token="";
		// breaks the command string into seperate tokens and inserts them to a vector
		for(int i =0; i<temp.length(); i++)
		{// checks to see if the character is a space or a tab
			if( temp[i] != 32 && temp[i] != '\t')
			{
				token+=temp[i];
			}
			else
			{  //check beginning of line if empty=no label... insert a empty string
				//to track of labels and no labels
				if(token!=""|| i==0)
				output.push_back(token);
				token="";
			}
		}
		output.push_back(token);

}

void Assembler::chk_lbl(map<string,int> Opcode,map<string,int> &SymTab,vector<string> output, int loc_cntr)
{
	if(Opcode.find(output[0])!=Opcode.end())
		errors+="error 2\n";
	if(SymTab.find(output[0])!=SymTab.end())
	{
		errors+="error 1\n";
	}
	else
	{
		SymTab[output[0]]=loc_cntr;
	}
}

void Assembler::chk_mnm(map<string,int> Opcode,map<string,int> &SymTab, vector<string> output)
{

}


/*

//0 label 1 opcode 2 operand

*/
