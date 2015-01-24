#ifndef GENERALPERFORMANCE_H
#define GENERALPERFORMANCE_H

#include <string>
#include <iostream>
using namespace std;

class GP
{
public:
	GP();
	GP(int, int, double, double, double, double, double, double);
	//	Performance(Operation, Size, Atime, Amem, Btime, Bmem, Ctime, Cmem)

	void setOperation(int); // 1 - Add, 2 - Remove, 3 - Display, 4 - Seq Search, 5- Binary Search
	int getOperation();

	void setSize(int);
	int getSize();

	void setATime(double);
	double getATime();

	void setAMem(double);
	double getAMem();

	void setBTime(double);
	double getBTime();

	void setBMem(double);
	double getBMem();

	void setCTime(double);
	double getCTime();

	void setCMem(double);
	double getCMem();

private:
	int op, type, size;
	double Atime, Amem, Btime, Bmem, Ctime, Cmem;
};
#endif