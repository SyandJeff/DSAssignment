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
	cout << size <<": USA SUCCESS" << endl;
	return true;
}

bool UnsortedArrayList::remove(int index)
{
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int i = index; i <= size; i++)
		{
			USAList[i] = USAList[i + 1];
		}
		size--;
	}
	return 0;
}

void UnsortedArrayList::display()
{
	Song item;
	for (int i = 0; i < getLength(); i++)
	{
		item = get(i);
		cout << "For Example: item.getAName" << endl;
	}
}

void UnsortedArrayList::display(int index)
{
	Song item;
	item = get(index);
	cout << "for exmaple : item.getName" << endl;
}

/*int UnsortedArrayList::sqSearch(Song USAList[], string target)
{
int n = getLength();
for (int i = 0; i < n; i++)
{
if (USAList[i].getTID == target)//found
return i;
}
return -1; // not found
} //Some weird error asking me to use pointers*/

int UnsortedArrayList::binSearch(Song USAList[], string target)
{
	return 0;//Unable to do because it is not sorted
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
	bool success = (index >= 1) && (index <= size);
	if (success)
		item = USAList[index];
	return item;
}
