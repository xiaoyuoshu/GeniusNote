#include <iostream>
#include "sqlite.h"
#include <sqlite3.h>


using namespace GeniusNote;

int main(int argc,char* argv[]){

	char **bufou=(char**)malloc(sizeof(char*));

	char name[]="testsqliet";
	char note1[]="study1";
	char note2[]="study2";

	Sqlite test;
	int in = test.sqinit(name);
	int op = test.open(name);
	int add = test.addNote(note1);
	int add1 = test.addNote(note2);
	int de = test.deleteNote(note1);
	bufou= test.reNote();

}