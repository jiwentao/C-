#pragma once
#include"Common.h"
#include"DataManager.h"

//Ҫ��ɨ�跽�����е��������̻߳���ʵ����ʵʱ��
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