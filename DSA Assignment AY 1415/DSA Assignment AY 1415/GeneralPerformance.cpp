#include <iostream>
#include <string>
using namespace std;
#include "GeneralPerformance.h"

//op, type, size
//saTime, usaTime, upTime, saMem, usaMem, upMem
GP::GP(int op, int size, double Atime, double Amem, double Btime, double Bmem, double Ctime, double Cmem)
:op(op), size(size), Atime(Atime), Amem(Amem), Btime(Btime), Bmem(Bmem), Ctime(Ctime), Cmem(Cmem)
{
	setOperation(op); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	setSize(size);
	setATime(Atime);
	setAMem(Amem);
	setBTime(Btime);
	setBMem(Bmem);
	setCTime(Ctime);
	setCMem(Cmem);
}

GP::GP(){}

void GP::setOperation(int op){ op = op; } // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
int GP::getOperation(){ return op; }

void GP::setSize(int size){ size = size; }
int GP::getSize(){ return size; }

void GP::setATime(double Atime){ Atime = Atime; }
double GP::getATime(){ return Atime; }

void GP::setAMem(double Amem){ Amem = Amem; }
double GP::getAMem(){ return Amem; }

void GP::setBTime(double Btime){ Btime = Btime; }
double GP::getBTime(){ return Btime; }

void GP::setBMem(double Amem){ Amem = Amem; }
double GP::getBMem(){ return Amem; }

void GP::setCTime(double Ctime){ Ctime = Ctime; }
double GP::getCTime(){ return Ctime; }

void GP::setCMem(double Cmem){ Cmem = Cmem; }
double GP::getCMem(){ return Cmem; }