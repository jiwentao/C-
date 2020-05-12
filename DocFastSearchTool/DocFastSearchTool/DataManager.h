#pragma once
#include"Common.h"

class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string & path);
	void ExcuteSql(const string & sql);
	void GetResultTable(const string & sql,int & row,int & col, char ** & ppRet);
	void Close();
private:
	sqlite3 * m_db;
};
////////////////////////////////////////////////////////////////////////////
//利用RAII机制
class AutoGetResultTable
{
public:
	AutoGetResultTable(SqliteManager * db, const string & sql, int & row, int & col, char ** &ppRet);
	~AutoGetResultTable();
public:
	//C++11的语法，阻止拷贝构造和赋值构造(也可以将这两个方法声明为保护的，效果一样)
	AutoGetResultTable(const AutoGetResultTable &) = delete;
	AutoGetResultTable & operator=(const AutoGetResultTable &) = delete;
private:
	SqliteManager * m_db;
	char ** m_ppRet;
};
///////////////////////////////////////////////////////////////////////////
#define DOC_DB "doc.db"
#define DOC_TABLE "doc_tb"
//////////////////////////////////////////////////////////////////////////
class DataManager
{
public:
	~DataManager();
public:
	static DataManager & GetInstance();
public:
	void InitSqlite();
	void InsertDoc(const string & path,const string & doc);
	void GetDoc(const string & path,multiset<string> &docs);
	void DeleteDoc(const string & path,const string & doc);
public:
	void Search(const string &key,vector<pair<string,string>>& doc_path);
	static void SpliteHighLight(const string &str,const string &key,
		                        string &prefix,string &highlight,string &suffix);
private:
	DataManager();
private:
	//数据管理类管的是数据库，要对其进行增删等操作，所以需要的是该对象
	SqliteManager m_sqmgr;  	
};