#ifndef Included_NameModel_H

#define Included_NameModel_H

#include  <sqlite3.h>
//#include <stdio>
#include <string>

//using namespace std;

namespace GeniusNote{
	class Sqlite
	{
		public:
			//int callback(void *NotUsed,int argc,char **argv,char **azColName);

			int sqinit(char* name);

			int open(char* name);

			int addNote(void* bufin);

			int deleteNote(void* bufin);

			int reNote();
			//char **bufout=(char**)malloc(sizeof(char*));

		private:
			
			const char* name;
	};
}

#endif