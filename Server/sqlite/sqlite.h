#include  <sqlite3.h>
#include <stdio.h>
#include <string.h>

namespace GeniusNote{
	class Sqliet{
		public:
			void init(char* name);
			void open();
			int addNote(void* bufin);
			int deleteNote(void* bufin);
			int reNote(char buf[][10]);
			
			
	}
}