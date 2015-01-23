#include <iostream>
#include <string>
using namespace std;
#include "Performance.h"

//op, type, size
//saTime, usaTime, upTime, saMem, usaMem, upMem
Performance::Performance(int op, int type, int size, double time, double mem)
:op(op), type(type), size(size),time(time), mem(mem)
{
	setOperation(op); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	setListType(type); // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
	setSize(size);
	setTime(time);
	setMem(mem);
}

Performance::Performance(){}

void Performance::setOperation(int op){ op = op; } // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
int Performance::getOperation(){ return op; }

void Performance::setListType(int type){ type = type; } // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
int Performance::getListType(){ return type; }

void Performance::setSize(int size){ size = size; }
int Performance::getSize(){ return size; }

void Performance::setTime(double time){ time = time; }
double Performance::getTime(){ return time; }

void Performance::setMem(double mem){ mem = mem; }
double Performance::getMem(){ return mem; }