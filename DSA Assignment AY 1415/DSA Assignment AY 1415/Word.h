#include <string>
#include <iostream>
using namespace std;

class Word
{
public:
	Word();
	Word(int, string);
	void setWordId(int);
	int getWordId();
	void setWordStr(string);
	string getWordStr();
	
private:
	string wordStr; //not to be confused with words
	int wordid;
};