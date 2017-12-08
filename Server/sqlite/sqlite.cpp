
#include  <sqlite3.h>
#include <cstdio>
#include <string>

sqlite3 *db=NULL;
char *zErrMsg=NULL;
int ret=0;

namespace GeniusNote{
	static int Sqlite::callback(void *NotUsed,int argc,char **argv,char **azColName){
    int i;
    for(i=0;i<argc;i++){
        this->bufout[i]=argv[i];
    }
    return 0;
  }

	void Sqlite::init(string& name){
		name.append(".db");
		ret = sqlite3_open(name,&db);
		if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    	}else{
       	fprintf(stdout,"database create success\n");
    }

    char* sql=NULL;
    sql = "CREATE TABLE NOTE("  \
         "NOTEMESSAGE     TEXT    NOT NULL );";


	}
	void Sqlite::open(string& name){

		name.append(".db");

		this->name=name;

		ret = sqlite3_open(name,&db);
		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"open database success\n");
    }

	}
	int Sqlite::addNote(void* bufin){
		ret = sqlite3_open(this->name+".db",&db);
		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"open database success\n");
    }

    char *sql = sqlite3_mprintf("INSERT INTO NOTE (NOTEMESSAGE) VALUES(%s);",bufin);

		ret =sqlite3_exec(db,sql,0,0,&zErrMsg);

		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"write message success\n");
    }

    sqlite3_free(sql);
    sqlite3_close(db);

	}
	int Sqlite::deleteNote(void* bufin){
		ret = sqlite3_open(this->name+".db",&db);

		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"open database success\n");
    }

		char *sql= sqlite3_mprintf("DELETE from NOTE where NOTE=%s ;" \
            "SELECT * from STUDENT",bufin);

    ret =sqlite3_exec(db,sql,callback,0,&zErrMsg);

		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"delete message success\n");
    }

    sqlite3_free(sql);
    sqlite3_close(db);

    return 1;
	}
	char** Sqlite::reNote(char buf[][10]){
		ret=sqlite3_open(this->name+".db",&db);

    char* sql = "SELECT * from NOTE";
    ret = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"read success\n");
    }
    buf=this->bufout;
    //关闭数据库
    sqlite3_close(db);

    return this->bufout;
	}
}
