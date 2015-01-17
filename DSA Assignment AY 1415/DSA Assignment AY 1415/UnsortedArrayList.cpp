#include "UnsortedArrayList.h"

UnsortedArrayList::UnsortedArrayList()
{
	size = 0;
}

bool UnsortedArrayList::add(string song)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		USAList[size] = song;
		size++;
	}
	return true;
}

bool UnsortedArrayList::remove()
{}

bool UnsortedArrayList::display()
{}



