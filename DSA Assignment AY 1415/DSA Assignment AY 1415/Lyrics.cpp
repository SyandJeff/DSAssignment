#include <iostream>
#include <string>
using namespace std;
#include "Lyrics.h"


Lyrics::Lyrics(string tid, string mxmTid, string wStr)
:tid(tid), mxmTid(mxmTid), wStr(wStr)
{
	setTID(tid);
	setMxmTid(mxmTid);
	setWordIdCountString(wStr);
}

Lyrics::Lyrics(){}

void Lyrics::setTID(string tid){ tid = tid; }
string Lyrics::getTID(){ return tid; }

void Lyrics::setMxmTid(string mxmTid) { mxmTid = mxmTid; }
string Lyrics::getMxmTid(){ return mxmTid; }

void Lyrics::setWordIdCountString(string wStr) { wStr = wStr; }
string Lyrics::getWordIdCountString(){ return wStr; }
