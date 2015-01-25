#include <string>
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include "UnsortedArrayList.h"

UnsortedArrayList::UnsortedArrayList()
{
	size = 0;
}

bool UnsortedArrayList::add(Song song)
{
	bool success = size < USA_MAX_SIZE;
	if (success)
	{
		USAList[size] = song;
		size++;
	}
	return true;
}

bool UnsortedArrayList::remove(int index, SIZE_T* aM)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int i = index; i <= size; i++)
		{
			USAList[i] = USAList[i + 1];

			GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
			*aM = pmc.PrivateUsage;
		}
		size--;
		
	}
	return 0;
}

void UnsortedArrayList::display(SIZE_T* aM)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	Song item;
	for (int i = 0; i < getLength(); i++)
	{
		item = get(i);
		cout << "Song[" << i << "]" << endl;
		cout << "TrackID: " << item.getTID() << endl;
		cout << "Artist Name: " << item.getAName() << endl;
		cout << "Song Title: " << item.getMxmTitle() << endl;
		cout << "MxmID: " << item.getMxmTid() << endl;
		cout << "" << endl;

		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		*aM = pmc.PrivateUsage;
	}
}
void UnsortedArrayList::display(int index)
{
	Song item;
	item = get(index);
	cout << "Song[" << index << "]" << endl;
	cout << "TrackID: " << item.getTID() << endl;
	cout << "Artist Name: " << item.getAName() << endl;
	cout << "Song Title: " << item.getMxmTitle() << endl;
	cout << "MxmID: " << item.getMxmTid() << endl;
	cout << "" << endl;
}

int UnsortedArrayList::sqSearch(string target, SIZE_T* aM)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	int comparisons = 0;
	int n = getLength();
	for (int i = 0; i < n; i++)
	{
		
		comparisons++;
		if (USAList[i].getTID() == target)//found
		{
			cout << "No. of Comparisons: " << comparisons << endl;
			return i;
		}
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		*aM = pmc.PrivateUsage;
	}
	return -1; // not found
}

void UnsortedArrayList::binSearch()
{
	
	cout << "Binary Search cannot be carried out on Unsorted Array List." << endl;
}

int UnsortedArrayList::getLength()
{
	return size;
}

bool UnsortedArrayList::isEmpty()
{
	return 0;
}

SongItem UnsortedArrayList::get(int index)
{
	SongItem item;
	bool success = (index <= size);
	if (success)
		item = USAList[index];
	return item;
}
void UnsortedArrayList::clear()
{
	size = 0;
}
