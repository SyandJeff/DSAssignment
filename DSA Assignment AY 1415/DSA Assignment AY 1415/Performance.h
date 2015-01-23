#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>
#include <iostream>
using namespace std;

class Performance
{
public:
	Performance();
	Performance(int, int, int, double, double);
//	Performance(Operation, List Type, Size, Time, Mem)

	void setOperation(int); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	int getOperation();

	void setListType(int); // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
	int getListType();

	void setSize(int);
	int getSize();

	void setTime(double);
	double getTime();

	void setMem(double);
	double getMem();

private:
	int op, type, size;
	double time, mem;
};
#endif