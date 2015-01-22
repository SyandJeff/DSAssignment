#include <string>
#include <iostream>
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

void UnsortedPointerList::remove(int index)
{
	Node *temp;
	if (index == 1)
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
		}
		temp = temp2;
		temp1->next = temp2->next;
	}
	temp->next = NULL;
	delete temp;
	temp = NULL; //clear
	size--;
}
void UnsortedPointerList::display()
{
	Node *temp = firstNode;
	SongItem sItem;
	while (temp != NULL)
	{
		sItem = temp->item;
		cout << "For Example: sItem.getAName" << endl;
		temp = temp->next;
	}
	cout << "" << endl;
}
void UnsortedPointerList::display(int index)
{
	Node *temp = firstNode;
	for (int i = 0; i < index - 2; i++)
		temp = temp->next;
	SongItem sItem = temp->item;
	cout << "For Example: sItem.getAName" << endl;
}
int UnsortedPointerList::sqSearch(string target)
{
	int n = getLength();
	Node *temp = firstNode;
	string tItem = "";
	SongItem sItem;
	for (int i = 0; i < n; i++)
	{
		sItem = temp->item;
		if (sItem.getTID() == target)
			return i; //found
		else
			temp = temp->next;
	}
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