
#include  <sqlite3.h>
#include <stdio.h>
#include <string.h>

sqlite3 *db=NULL;
char *zErrMsg=NULL;
int ret=0;

namespace GeniusNote{
	void Sqlite::init(){
		ret = sqlite3_open("youxiang"+".db",&db);
	}
	void Sqlite::open(){

	}
	int Sqlite::addNote(void* buf){

	}
	int Sqlite::deleteNote(){
		
	}
	int Sqlite::reNote(){

	}
	int Sqlite::close(){

	}
}