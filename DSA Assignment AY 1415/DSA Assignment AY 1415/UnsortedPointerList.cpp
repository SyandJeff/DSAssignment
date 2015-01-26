#include <string>
#include <iostream>
#include <Windows.h>
#include <psapi.h>
#include "UnsortedPointerList.h"
using namespace std;

UnsortedPointerList::UnsortedPointerList()
{
	size = 0;
}
bool UnsortedPointerList::add(SongItem song)
{
	Node* newNode = new Node;
	newNode->item = song;
	newNode->next = NULL;

	if (size == 0) //Initially put, firstNode == NULL, doesnt work. WHY?!
		firstNode = newNode;
	else
	{
		Node *temp = firstNode;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	size++;
	return true;
}

void UnsortedPointerList::remove(int index, SIZE_T& aM)
{
	int shifts = 0;
	SIZE_T memUsed;
	PROCESS_MEMORY_COUNTERS_EX pmc;
	Node *temp;
	if (index == 0)
	{
		temp = firstNode;
		firstNode = firstNode->next;


	}
	else
	{
		Node *temp2 = firstNode;
		Node *temp1;
		for (int i = 0; i < index - 1; i++)
		{
			temp1 = temp2;
			temp2 = temp2->next;
			shifts++;
		}
		temp = temp2;
		temp1->next = temp2->next;

	}
	temp->next = NULL;
	delete temp;
	temp = NULL; //clear
	cout << "No. of Traversals for Unsorted Pointer List: " << shifts << endl;
	size--;

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	memUsed = pmc.PrivateUsage;
	aM = memUsed - aM;
}
void UnsortedPointerList::display(SIZE_T& aM)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T memUsed;
	int i = 0;
	Node *temp = firstNode;
	SongItem sItem;
	while (temp != NULL)
	{

		sItem = temp->item;
		cout << "Song[" << i << "]" << endl;
		cout << "TrackID: " << sItem.getTID() << endl;
		cout << "Artist Name: " << sItem.getAName() << endl;
		cout << "Song Title: " << sItem.getMxmTitle() << endl;
		cout << "MxmID: " << sItem.getMxmTid() << endl;
		cout << "" << endl;
		temp = temp->next;
		i++;
		
	}
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	memUsed = pmc.PrivateUsage;
	aM = memUsed - aM;
	cout << "" << endl;
}
void UnsortedPointerList::display(int index)
{
	Node *temp = firstNode;
	for (int i = 0; i < index - 2; i++)
		temp = temp->next;
	SongItem sItem = temp->item;
	cout << "TrackID: " << sItem.getTID() << endl;
	cout << "Artist Name: " << sItem.getAName() << endl;
	cout << "Song Title: " << sItem.getMxmTitle() << endl;
	cout << "MxmID: " << sItem.getMxmTid() << endl;
	cout << "" << endl;
}
int UnsortedPointerList::sqSearch(string target, SIZE_T& aM)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T memUsed;
	int n = getLength(), comparisons = 0;
	Node *temp = firstNode;
	string tItem = "";
	SongItem sItem;
	for (int i = 0; i < n; i++)
	{
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		memUsed = pmc.PrivateUsage;
		aM = memUsed - aM;

		comparisons++;
		sItem = temp->item;
		if (sItem.getTID() == target)
		{
			cout << "No. of Comparisons: " << comparisons << endl;
			return i; //found

			
		}
		else
			temp = temp->next;
	}
	cout << "No. of Comparisons: " << comparisons << endl;
	return -1;
}
void UnsortedPointerList::binSearch()
{
	cout << "Binary Search cannot be carried out on Linked-List." << endl;
}
SongItem* UnsortedPointerList::get(int index)
{
	if (index <= size)
	{
		Node *temp = firstNode;
		for (int i = 0; i <= index; i++)
			temp = temp->next;
		return &temp->item;
	}
	else
	{
		return NULL;
		cout << "Unable to retrieve. Index not found." << endl;
	}
}
bool UnsortedPointerList::isEmpty()
{
	return (size == 0);
}
int UnsortedPointerList::getLength()
{
	return size;
}
void UnsortedPointerList::clear()
{
	size = 0;
}