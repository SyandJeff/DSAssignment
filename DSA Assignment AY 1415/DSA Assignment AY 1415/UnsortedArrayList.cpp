#include "UnsortedArrayList.h"

UnsortedArrayList::UnsortedArrayList()
{
	size = 0;
}

bool UnsortedArrayList::add(string song)
{
	bool success = size < USA_MAX_SIZE;
	if (success)
	{
		USAList[size] = song;
		size++;
	}
	return true;
}

bool UnsortedArrayList::remove(int index)
{
	return 0;
}

void UnsortedArrayList::display()
{}

void UnsortedArrayList::display(int index)
{

}

int UnsortedArrayList::sqSearch(ItemType searchItem)
{
	return 0;//temp for now
}

int UnsortedArrayList::binSearch(ItemType searchItem)
{
	return 0;//temp for now
}

int UnsortedArrayList::getLength()
{
	return size;
}

bool UnsortedArrayList::isEmpty()
{
	return 0;
}




