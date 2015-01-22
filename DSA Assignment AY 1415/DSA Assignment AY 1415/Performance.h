#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>
#include <iostream>
using namespace std;

class Performance
{
public:
	Performance();
	Performance(int, int, int, double, double, double, double, double, double);
//	Performance(Operation, List Type, Size, SAtime, USAtime, UPtime, SAmem, USAmem, UPmem)

	void setOperation(int); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	int getOperation();

	void setListType(int); // 1 - Sorted Array, 2 - Unsorted Array, 3 - Unsorted Linked List
	int getListType();

	void setSize(int);
	int getSize();

	void setSATime(double);
	double getSATime();

	void setUSATime(double);
	double getUSATime();

	void setUPTime(double);
	double getUPTime();

	void setSAMem(double);
	double getSAMem();

	void setUSAMem(double);
	double getUSAMem();

	void setUPMem(double);
	double getUPMem();

private:
	int op, type, size;
	double saTime, usaTime, upTime, saMem, usaMem, upMem;
};
#endif