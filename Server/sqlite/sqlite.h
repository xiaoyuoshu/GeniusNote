#ifndef Included_NameModel_H

#define Included_NameModel_H

#include  <sqlite3.h>
#include <cstdio>
#include <string>


namespace GeniusNote{
	class Sqlite
	{
		public:
			void init(string& name);
			void open(string& name);
			int addNote(void* bufin);
			int deleteNote(void* bufin);
			char** reNote();

		private:
			char bufout[200][10];
			const std::string& name;
	};
}

#endif