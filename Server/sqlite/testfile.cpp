#include <iostream>
#include "sqlite.h"
#include <sqlite3.h>


using namespace GeniusNote;

int main(int argc,char* argv[]){

	

	char name[]="testsqliet";
	char note1[]="study1";
	char note2[]="study2";

	Sqlite test;
	int in = test.sqinit(name);
	printf("open\n");
	int op = test.open(name);
	printf("read\n");
	//bufou= test.reNote();
	
	printf("add\n");
	//int add = test.addNote(note1);
	//bufou= test.reNote();
	
	printf("add\n");
	//int add1 = test.addNote(note2);
	//bufou= test.reNote();
	
	printf("delete\n");
	int de = test.deleteNote(note1);
	int re = test.reNote();

	//for(int i=0;bufout[i]!=NULL;i++){
	//	printf("%s\n", bufout[i]);
	//}

}
