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
//����RAII����
class AutoGetResultTable
{
public:
	AutoGetResultTable(SqliteManager * db, const string & sql, int & row, int & col, char ** &ppRet);
	~AutoGetResultTable();
public:
	//C++11���﷨����ֹ��������͸�ֵ����(Ҳ���Խ���������������Ϊ�����ģ�Ч��һ��)
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
	//���ݹ�����ܵ������ݿ⣬Ҫ���������ɾ�Ȳ�����������Ҫ���Ǹö���
	SqliteManager m_sqmgr;  	
};