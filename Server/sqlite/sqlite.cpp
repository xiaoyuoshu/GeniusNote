#include <sqlite3.h>
#include <cstdio>
#include <string>
#include <malloc.h>

#include "sqlite.h"

sqlite3 *db=NULL;
char *zErrMsg=NULL;
int ret=0;
char* s = sqlite3_mprintf(".db");

using namespace std;
char **bufout=(char**)malloc(sizeof(char*));
namespace GeniusNote{
	int callback(void *NotUsed,int argc,char **argv,char **azColName){
    int i;
    //using namespace GeniusNote;

    for(i=0;i<argc;i++){
        bufout[i]=argv[i];
    }
    return 0;
  }

	int Sqlite::sqinit(char* name){
		*name << *s ;
		ret = sqlite3_open((const char*)name,&db);
		if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    	}else{
       	fprintf(stdout,"database create success\n");
    }

    char* sql=NULL;
    sql = sqlite3_mprintf("CREATE TABLE NOTE(NOTEMESSAGE  TEXT   NOT NULL );");

    return 1;

	}
	int Sqlite::open(char* name){

		*name << *s ;

		this->name=name;

		ret = sqlite3_open((const char*)name,&db);
		if(ret!=SQLITE_OK){
      fprintf(stderr,"SQL error:%s\n",zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout,"open database success\n");
    }

    return 1;

	}
	int Sqlite::addNote(void* bufin){
		ret = sqlite3_open((const char*)this->name,&db);
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
		ret = sqlite3_open((const char*)this->name,&db);

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
	char** Sqlite::reNote(){
		ret=sqlite3_open((const char*)this->name,&db);

    char* sql = sqlite3_mprintf("SELECT * from NOTE");
    ret = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"read success\n");
    }
    this->bufout=bufout;
    //关闭数据库
    sqlite3_close(db);

    return this->bufout;
	}


}
