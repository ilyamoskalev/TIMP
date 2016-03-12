#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

void dif(fstream &f1, fstream &f2) 
{ 
	string s1, s2; 
	int i(0); 
	cout << "File 1: "<< endl; 
	while (!f1.eof()) 
	{ 
		getline(f1, s1); 
		while (!f2.eof()) 
		{ 
			getline(f2, s2); 
			if (s1 == s2) 
			{ 
				i++; 
				break; 
			} 
		} 
		if (i == 0) 
			cout << s1 << endl; 
		i = 0; 
		f2.seekg(0); 
	} 
	cout << "File 2: " << endl; 
	while (!f2.eof()) 
	{ 
		getline(f2, s2); 
		while (!f1.eof()) 
		{ 
			getline(f1, s1); 
			if (s2 == s1) 
			{ 
				i++; 
				break; 
			} 
		} 
		if (i == 0) 
			cout << s2 << endl; 
		i = 0; 
		f1.seekg(0); 
	} 
} 

int main() 
{ 
	fstream f1("file1.txt"), f2("file2.txt"); 
	string s; 
	dif(f1, f2); 
	system("pause"); 
	return 0; 
}