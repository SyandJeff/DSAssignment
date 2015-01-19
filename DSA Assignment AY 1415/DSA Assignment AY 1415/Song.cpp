#include <iostream>
#include <string>
using namespace std;
#include "Song.h"

Song::Song(){}
Song::Song(string tid, string aName, string title, int mxmTid, string mxmName, string mxmTitle)
:tid(tid), aName(aName), title(title), mxmTid(mxmTid), mxmName(mxmName), mxmTitle(mxmTitle)
{
	setTID(tid);
	setAName(aName);
	setTitle(title);
	setMxmTid(mxmTid);
	setMxmName(mxmName);
	setMxmTitle(mxmTitle);
}
void Song::setTID(string tid){ tid = tid; }
string Song::getTID(){ return tid; }
void Song::setAName(string aName){ aName = aName; }
string Song::getAName(){ return aName; }
void Song::setTitle(string title){ title = title; }
string Song::getTitle(){ return title; }
void Song::setMxmTid(int mxmTid) { mxmTid = mxmTid; }
int Song::getMxmTid(){ return mxmTid; }
void Song::setMxmName(string mxmName){ mxmName = mxmName; }
string Song::getMxmName(){ return mxmName; }
void Song::setMxmTitle(string mxmTitle) { mxmTitle = mxmTitle; }
string Song::getMxmTitle(){ return mxmTitle; }