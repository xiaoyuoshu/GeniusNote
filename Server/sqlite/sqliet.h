#include  <sqlite3.h>
#include <stdio.h>
#include <string.h>

namespace GeniusNote{
	class Sqliet{
		public:
			void init();
			void open();
			int addNote();
			int deleteNote();
			int reNote();
			int close();

		private:
			
	}
}