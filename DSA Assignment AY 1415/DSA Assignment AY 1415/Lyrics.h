#ifndef LYRICS_H
#define LYRICS_H

#include <string>
#include <iostream>
using namespace std;

class Lyrics
{
public:
	Lyrics();
	Lyrics(string, int, int, int);
	void setTID(string);
	string getTID();
	void setMxmTid(int);
	int getMxmTid();
	void setWordId(int);
	int getWordId();
	void setWordC(int);
	int getWordC();
	
private:
	string tid;
	int mxmTid;
	int wordid;
	int wordC;

};
#endif