#include <iostream>

using namespace GeniusNote;

int main(){

	char bufout[200][10];

	Sqlite test;
	test.init("testsqliet");
	test.open("testsqliet");
	int add = test.addNote("study");
	int add = test.addNote("stud");
	int de = test.deleteNote("study");
	int read = test.reNote(bufout);

}