#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;

class Song
{
public:
	Song();
	Song(string, string, string, string, string, string);
	void setTID(string);
	string getTID();
	void setAName(string);
	string getAName();
	void setTitle(string);
	string getTitle();
	void setMxmTid(string);
	string getMxmTid();
	void setMxmName(string);
	string getMxmName();
	void setMxmTitle(string);
	string getMxmTitle();
private:
	string tid;
	string aName;
	string title;
	string mxmName;
	string mxmTitle;
	string mxmTid;

};
#endif