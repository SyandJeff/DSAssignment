#ifndef LYRICS_H
#define LYRICS_H

#include <string>
#include <iostream>
using namespace std;

class Lyrics
{
public:
	Lyrics();
	Lyrics(string, string, string);
	void setTID(string);
	string getTID();
	void setMxmTid(string);
	string getMxmTid();
	void setWordIdCountString(string);
	string getWordIdCountString();
	
	
private:
	string tid;
	string mxmTid;
	string wStr;

};
#endif