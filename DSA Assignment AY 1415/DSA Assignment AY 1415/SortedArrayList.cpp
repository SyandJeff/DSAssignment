#include <string>
#include <iostream>
#include "SortedArrayList.h"

#include <Windows.h>
#include <psapi.h>
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
bool SortedArrayList::add(int index, SongItem song)
{
	bool success = (index >= 1) && (index<size) && (size < SA_MAX_SIZE);
	if (success)
	{  // make room for new item 
		for (int pos = size; pos >= index; pos--)
			SAList[pos] = SAList[pos - 1];

		SAList[index - 1] = song; // insert the item
		size++;  // increase the size of the list by one
	}
	return success;
}

void SortedArrayList::remove(int index)
{
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int pos = index + 1; pos <= size; pos++)
			SAList[pos - 2] = SAList[pos - 1];
		size--;
	}
}
void SortedArrayList::display()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage;

	SongItem item;
	for (int i = 0; i < getLength(); i++)
	{
		item = get(i);
		cout << "Song[" << i << "]" << endl;
		cout << "TrackID: " << item.getTID() << endl;
		cout << "Artist Name: " << item.getAName() << endl;
		cout << "Song Title: " << item.getMxmTitle() << endl;
		cout << "MxmID: " << item.getMxmTid() << endl;
		cout << "" << endl;
	}

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage;

	cout << afterMem/1024 << " after" << endl;
	//cout << beforeMem << " before" << endl;
	//cout << afterMem - beforeMem << " difference" << endl;
}
void SortedArrayList::display(int index)
{
	SongItem item;
	item = get(index);
	cout << "TrackID: " << item.getTID() << endl;
	cout << "Artist Name: " << item.getAName() << endl;
	cout << "Song Title: " << item.getMxmTitle() << endl;
	cout << "MxmID: " << item.getMxmTid() << endl;
	cout << "" << endl;
}
int SortedArrayList::sqSearch(string target) //search using TrackID presumably. Can be changed
{
	int comparisons = 0;
	int n = getLength();
	for (int i = 0; i < n; i++)
	{
		comparisons++;
		if (SAList[i].getTID() == target)//found
		{
			cout << "No. of Comparisons: " << comparisons << endl;
			return i;
		}
		else if (SAList[i].getTID() > target)//not found
			return -1;
	}
	return -1;
}
int SortedArrayList::binSearch(string target)
{
	int comparisons = 0;
	int n = getLength();
	int mid, first = 0, last = n - 1;
	while (first<=last)
	{
		comparisons++;
		mid = (first + last) / 2;
		if (SAList[mid].getTID() == target) //found
		{
			cout << "No. of Comparisons: " << comparisons << endl;
			return mid;
		}
		else if (target < SAList[mid].getTID()) //searching through first half
			last = mid - 1;
		else
			first = mid + 1;//searching through second half
		
	}
	return -1; //not found
}
SongItem SortedArrayList::get(int index)
{
	SongItem item;
	bool success = (index <= size);
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
void SortedArrayList::clear()
{
	size = 0;
}