#include <iostream>
#include "sqlite.h"


using namespace GeniusNote;

int main(int argc,char* argv[]){

	char bufout[200][10];

	Sqlite test;
	test.init("testsqliet");
	test.open("testsqliet");
	int add = test.addNote("study");
	int add1 = test.addNote("stud");
	int de = test.deleteNote("study");
	bufout= test.reNote();

}