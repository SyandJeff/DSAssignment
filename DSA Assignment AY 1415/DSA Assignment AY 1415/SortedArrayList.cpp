#include <string>
#include <iostream>
#include "SortedArrayList.h"
using namespace std;

SortedArrayList::SortedArrayList()
{
	size = 0;
}
bool SortedArrayList::add(SongItem song)
{
	bool success = size < SA_MAX_SIZE;
	if (success)
	{
		SAList[size] = song;
		size++;
	}
	return success;
}

bool SortedArrayList::remove(int index)
{
	return false;
}
void SortedArrayList::display()
{
	SongItem item;
	for (int i = 0; i < getLength(); i++)
	{
		item = get(i);
		cout << "For Example: item.getAName" << endl;
	}
}
void SortedArrayList::display(int index)
{
	SongItem item;
	item = get(index);
	cout << "For Example: item.getAName" << endl;
}
/*int SortedArrayList::sqSearch(Song SAList[], string target)
{
	int n = getLength();
	for (int i = 0; i < n; i++)
	{
		if (SAList[i].getTID == target)//found
			return i;
		else if (SAList[i].getTID > target)//not found
			return -1;
	}
	return -1;
}
int SortedArrayList::binSearch(Song SAList[], string target)
{
	int n = getLength();
	int mid, first = 0, last = n - 1;
	while (first<=last)
	{
		mid = (first + last) / 2;
		if (SAList[mid].getTID = target) //found
			return mid;
		else if (target < SAList[mid].getTID) //searching through first half
			last = mid - 1;
		else
			first = mid + 1;//searching through second half
	}
	return -1; //not found
}*/
SongItem SortedArrayList::get(int index)
{
	SongItem item;
	bool success = (index >= 1) && (index <= size);
	if (success)
		item = SAList[index];
	return item;
}
bool SortedArrayList::isEmpty()
{
	return (size == 0);
}
int SortedArrayList::getLength()
{
	return size;
}