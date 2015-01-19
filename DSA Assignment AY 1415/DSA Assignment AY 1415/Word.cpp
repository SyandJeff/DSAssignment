#include <iostream>
#include <string>
using namespace std;
#include "Word.h"


Word::Word(int wordid, string wordStr)
:wordid(wordid), wordStr(wordStr)
{
	setWordId(wordid);
	setWordStr(wordStr);
}

Word::Word(){}

void Word::setWordId(int wordid) { wordid = wordid; }
int Word::getWordId(){ return wordid; }

void Word::setWordStr(string wordStr) { wordStr = wordStr; }
string Word::getWordStr(){ return wordStr; }