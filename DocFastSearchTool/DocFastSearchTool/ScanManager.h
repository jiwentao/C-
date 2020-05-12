#pragma once
#include"Common.h"
#include"DataManager.h"

//要对扫描方法进行单例化和线程化，实现其实时性
class ScanManager
{
public:
	static ScanManager & GreateInstance(const string & path);
public:
	void StartScan(const string & path);
	void ScanDirectory(const string & path);
private:
	//DataManager m_db;
	ScanManager();
};