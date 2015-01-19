#include <iostream>
#include <string>
using namespace std;
#include "Lyrics.h"


Lyrics::Lyrics(string tid, int mxmTid, int wordid, int wordC)
:tid(tid), mxmTid(mxmTid), wordid(wordid), wordC(wordC)
{
	setTID(tid);
	setMxmTid(mxmTid);
	setWordId(wordid);
	setWordC(wordC);
}

Lyrics::Lyrics(){}

void Lyrics::setTID(string tid){ tid = tid; }
string Lyrics::getTID(){ return tid; }

void Lyrics::setMxmTid(int mxmTid) { mxmTid = mxmTid; }
int Lyrics::getMxmTid(){ return mxmTid; }

void Lyrics::setWordId(int wordid) { wordid = wordid; }
int Lyrics::getWordId(){ return wordid; }

void Lyrics::setWordC(int wordC) { wordC = wordC; }
int Lyrics::getWordC(){ return wordC; }
