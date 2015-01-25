#ifndef UNSORTEDPOINTERARRAYLIST_H
#define UNSORTEDPOINTERLIST_H

#include <string>
#include <iostream>
#include "Song.h"
#include "Lyrics.h"
#include "Word.h"

using namespace std;

const int UP_MAX_SIZE = 10000;

typedef Song SongItem;
//Fix Search first then continue with adding Word and Lyrics

class UnsortedPointerList
{
private:
	struct Node
	{
		SongItem item;
		Node *next;
	};
	Node *firstNode;
	int size;

public:
	UnsortedPointerList::UnsortedPointerList();

	bool UnsortedPointerList::add(SongItem song);
	//add item to the back to the list

	void UnsortedPointerList::remove(int index, SIZE_T* aM);
	//remove item by searching for the music name
	
	void UnsortedPointerList::display(SIZE_T* aM);
	//Display all the songs

	void UnsortedPointerList::display(int index);
	//Search for the song title which returns index
	//display specific song information using the index

	int UnsortedPointerList::sqSearch(string target, SIZE_T* aM);
	//Searching of song title using sequential search

	void UnsortedPointerList::binSearch();
	//Pointers cannot use binary Search

	SongItem* UnsortedPointerList::get(int index);
	// get item at specific position in list

	bool UnsortedPointerList::isEmpty();
	//check if empty

	int UnsortedPointerList::getLength();
	//return the size of list.
	void UnsortedPointerList::clear();
};
#endif