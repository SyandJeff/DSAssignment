#ifndef UNSORTEDARRAYLIST_H
#define UNSORTEDARRATLIST_H

#include <string>
#include <iostream>
using namespace std;

const int MAX_SIZE = 10000;

typedef string ItemType;

class SortedArrayList
{
private:
	string SAList[MAX_SIZE];
	int size;

public:
	SortedArrayList::SortedArrayList();

	bool SortedArrayList::add(ItemType song);
	//add item to the back to the list
	//pre:size<MAX_SIZE
	//post: music added to the list

	bool SortedArrayList::remove(int index);
	//remove item by searching for the music name
	//pre: music name must exist and look for the position of the music if it exist
	//post: music deleted

	bool SortedArrayList::display();
	//Display all the songs

	bool SortedArrayList::display(int index);
	//Search for the song title which returns index
	//display specific song information using the index

	int SortedArrayList::sqSearch(ItemType searchItem);
	//Searching of song title using sequential search

	int SortedArrayList::binSearch(ItemType searchItem);
	//Searching of song title using binary search

};
#endif