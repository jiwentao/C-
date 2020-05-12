#include"ScanManager.h"
#include"Sysutil.h"

ScanManager::ScanManager()
{}

void ScanManager::StartScan(const string & path)
{
	while (1)
	{
		//�ȴ�����
		this_thread::sleep_for(chrono::seconds(3));
		ScanDirectory(path);	
	}
}

ScanManager & ScanManager::GreateInstance(const string & path)
{
	static ScanManager inst;
	thread scan_thread(&StartScan,&inst,path);
	scan_thread.detach();
	return inst;
}
void ScanManager::ScanDirectory(const string & path)
{
	//1.ɨ�豾���ļ�ϵͳ
	vector<string> local_files;
	vector<string> local_dirs;
	DirectionList(path, local_files, local_dirs);
	set<string> local_set;
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());
	//2.ɨ�����ݿ��ļ�ϵͳ
	multiset<string> db_set;
	//��ȡ���ݿ������
	DataManager &m_db = DataManager::GetInstance();
	m_db.GetDoc(path, db_set);
	//3.�Աȱ����ļ������ݿ��ļ�
	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while (local_it != local_set.end() && db_it != db_set.end())
	{
		if (*local_it < *db_it)
		{
			//�����ļ�����,���ݿ��ļ������ڣ����ݿ������ļ�
			m_db.InsertDoc(path, *local_it);
			local_it++;
		}
		else if (*local_it > *db_it)
		{
			//�����ļ������ڣ����ݿ��ļ����ڣ����ݿ�ɾ���ļ�
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//�����ļ������ݿ��ļ������ڣ����ݿ��ļ�����
			local_it++;
			db_it++;
		}
	}

	while (local_it != local_set.end())
	{
		//�����ļ����ڣ����ݿ��ļ������ڣ����ݿ������ļ�
		m_db.InsertDoc(path, *local_it);
		local_it++;
	}

	while (db_it != db_set.end())
	{
		//�����ļ������ڣ����ݿ��ļ����ڣ����ݿ�ɾ���ļ�
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}
	//�ݹ������Ŀ¼
	for (const auto & dir : local_dirs)
	{
		string dir_path = path;
		dir_path += "\\";
		dir_path += dir;
		ScanDirectory(dir_path);
	}
}