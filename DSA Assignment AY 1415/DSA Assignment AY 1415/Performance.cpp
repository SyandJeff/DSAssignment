#include <iostream>
#include <string>
using namespace std;
#include "Performance.h"

//op, type, size
//saTime, usaTime, upTime, saMem, usaMem, upMem
Performance::Performance(int op, int type, int size, double saTime, double usaTime, double upTime, double saMem, double usaMem, double upMem)
:op(op), type(type), size(size), saTime(saTime), usaTime(usaTime), upTime(upTime), saMem(saMem), usaMem(usaMem), upMem(upMem)
{
	setOperation(op); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	setListType(type); // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
	setSize(size);
	setSATime(saTime);
	setUSATime(usaTime);
	setUPTime(upTime);
	setSAMem(saMem);
	setUSAMem(usaMem);
	setUPMem(upMem);
}

Performance::Performance(){}

void Performance::setOperation(int op){ op = op; } // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
int Performance::getOperation(){ return op; }

void Performance::setListType(int type){ type = type; } // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
int Performance::getListType(){ return type; }

void Performance::setSize(int size){ size = size; }
int Performance::getSize(){ return size; }

void Performance::setSATime(double saTime){ saTime = saTime; }
double Performance::getSATime(){ return saTime; }

void Performance::setUSATime(double usaTime){ usaTime = usaTime; }
double Performance::getUSATime(){ return usaTime; }

void Performance::setUPTime(double upTime){ upTime = upTime; }
double Performance::getUPTime(){ return upTime; }

void Performance::setSAMem(double saMem){ saMem = saMem; }
double Performance::getSAMem(){ return saMem; }

void Performance::setUSAMem(double usaMem){ usaMem = usaMem; }
double Performance::getUSAMem(){ return usaMem; }

void Performance::setUPMem(double upMem){ upMem = upMem; }
double Performance::getUPMem(){ return upMem; }