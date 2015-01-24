#ifndef UNSORTEDARRAYLIST_H
#define UNSORTEDARRATLIST_H

#include <string>
#include <iostream>
#include "Memory.h"
#include "Song.h"
#include "Lyrics.h"
#include "Word.h"

using namespace std;

const int USA_MAX_SIZE = 10000;

typedef Song SongItem;

class UnsortedArrayList
{
private:
	SongItem USAList[USA_MAX_SIZE];
	int size;

public:
	UnsortedArrayList::UnsortedArrayList();

	bool UnsortedArrayList::add(Song song);
	//add item to the back to the list
	//pre:size<MAX_SIZE
	//post: music added to the list

	bool UnsortedArrayList::remove(int index, SIZE_T* aM);
	//remove item by searching for the music name
	//pre: music name must exist and look for the position of the music if it exist
	//post: music deleted

	void UnsortedArrayList::display(SIZE_T* aM);
	//display all songs

	void UnsortedArrayList::display(int index);
	//display specific song

	int UnsortedArrayList::sqSearch(string target, SIZE_T* aM);
	//sequential search

	void UnsortedArrayList::binSearch();
	//binary search

	int UnsortedArrayList::getLength();
	//get the length of array

	bool UnsortedArrayList::isEmpty();
	//check if the array is empty

	SongItem UnsortedArrayList::get(int index);
	//get function to get the song

	void UnsortedArrayList::clear();

};
#endif