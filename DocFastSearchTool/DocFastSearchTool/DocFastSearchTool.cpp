#include"Common.h"
#include"Sysutil.h"
#include"DataManager.h"
#include"ScanManager.h"
#include<iomanip>
#include"sysframe.h"
char * title = "文档快速搜索工具";

int main(int argc, char * argv[])
{
	const string path = "E:\\wentao";
	//创建扫描实例
	ScanManager::GreateInstance(path).ScanDirectory(path);
	//创建搜索实例
	DataManager &dm = DataManager::GetInstance();
	vector<pair<string, string>> doc_path;
	string key;
	while (1)
	{
		DrawFrame(title);
		DrawMenu();
		cin >> key;
		if (key == "exit")
			break;
		dm.Search(key,doc_path);
		int init_row = 5;
		int count = 0;
		string prefix, highlight, suffix;
		for (const auto & e : doc_path)
		{
			string doc_name = e.first;
			string doc_path = e.second;
			DataManager::SpliteHighLight(doc_name,key,prefix,highlight,suffix);
			SetCurPos(2,init_row+count++);
			cout << prefix;
		    ColourPrintf(highlight.c_str());
			cout << suffix;
			SetCurPos(33,init_row+count-1);
			cout << doc_path;
			//printf("%-31s%-50s",e.first.c_str(),e.second.c_str());
		}
		SystemEnd();
		system("pause");
	}
	SystemEnd();
	return 0;
}
/*int main()
{
	string str = "aBs比特科技,文档快速搜索工具,Xyz服务就业6666";
	string key = "jy";
	string prefix, highlight, suffix;
	DataManager::SpliteHighLight(str,key,prefix,highlight,suffix);
	cout << prefix;
	ColourPrintf(highlight.c_str());
	cout << suffix << endl;
	return 0;
}*/
/*
void Test_DirectionList()
{
	const string path = "E:\\wentao";
	vector<string> subfile, subdir;
	DirectionList(path,subfile,subdir);
	for (const auto &e : subfile)
		cout << e << endl;
	for (const auto & e : subdir)
		cout << e << endl;
}
    
void Test_Sqlite()
{
	//鎵撳紑鏁版嵁搴?
	sqlite3 * db;
	int rc = sqlite3_open("D:\\编程之路\\C-\\DocFastSearchTool\\DocFastSearchTool\\you.db",&db);
	if (rc != SQLITE_OK)
		printf("Open database failed\n");
	else
		printf("Open database successed\n");
	//鎿嶄綔鏁版嵁搴?
	string sql = "select * from doc_tb";
	char ** result;
	int row, col;
	char * zErrMsg = 0;
	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//cout << *(result+i*col+j) << " ";//娌℃湁瀵归綈
			printf("%-5s",*(result+i*col+j));
		}
		cout << endl;
	}
	sqlite3_free_table(result);
	//鍏抽棴鏁版嵁搴?
	sqlite3_close(db);
}

void Test_SqliteManager()
{
	SqliteManager sm;
	sm.Open("you.db");
	//string sql = "create table if not exists doc_tb(id integer primary key autoincrement,doc_name text,doc_path text)";
	//sm.ExcuteSql(sql);
	//string sql1 = "insert into doc_tb values(null,'aaa','c:\\')";
	//sm.ExcuteSql(sql1);
	string sql = "select * from doc_tb";
	int row = 0, col = 0;
	char ** ppRest = 0;
	sm.GetResultTable(sql,row,col,ppRest);
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-10s",*(ppRest+i*col+j));
		}
		cout << endl;
	}
	sqlite3_free_table(ppRest);
}


void Test_Search()
{
	string path = "E:\\wentao";
	//先创建扫描实例
	ScanManager::GreateInstance(path).ScanDirectory(path);
	//sm.ScanDirectory(path);
	//创建搜索实例
	DataManager &dm = DataManager::GetInstance();
	string key;
	vector<pair<string, string>> doc_path;
	while (1)
	{
		cout << "请输入你搜索的关键字:>";
		cin >> key;
		dm.Search(key,doc_path);
		cout << setw(15) << setiosflags(ios::left) << "name" 
			<< setw(60) << setiosflags(ios::left) << "path" << endl;
		for (const auto & e : doc_path)
			cout << setw(15) << setiosflags(ios::left) << e.first.c_str()
			<< setw(60) << setiosflags(ios::left) << e.second.c_str() << endl;
	}
	
}

void Test_Frame()
{
	//system("mode con cols=100 lines=30");
	//SetCurPos(0,(100-strlen("hello"))/2);
	//printf("hello\n");
	char * title = "文件快速搜索工具";
	DrawFrame(title);
}
int main()
{ 
	//Test_DirectionList();
	//Test_Sqlite();
	//Test_SqliteManager();
	//Test_Scan();
	//Test_Search();
	Test_Frame();
	return 0;
}
*/