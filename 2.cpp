#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	char  s1[64] , s2[6];
	string FileName;
	strcpy_s(s2,"\\func");
	cout << "vvedite nazvanie fayla" << endl;
	cin >> FileName;
	ifstream fin(FileName);
	if(!fin.is_open())
		cout << "NOT OPEN!!!" <<endl;
	while(!fin.eof())
	{
		fin.getline(s1,64);
		if (strstr(s1 ,s2))
			cout << strstr(s1,s2)+5 << endl;
	}
	fin.close();
	system("pause");
}
