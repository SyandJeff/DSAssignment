#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H

#include <string>
#include <iostream>
#include "Song.h"
#include "Lyrics.h"
#include "Word.h"

using namespace std;

const int SA_MAX_SIZE = 10000;

typedef Song SongItem;
//Fix Search first then continue with adding Word and Lyrics

class SortedArrayList
{
private:
	SongItem SAList[SA_MAX_SIZE];
	int size;

public:
	SortedArrayList::SortedArrayList();

	bool SortedArrayList::add(SongItem song);
	//add item to the back to the list
	//pre:size<MAX_SIZE
	//post: music added to the list

	void SortedArrayList::remove(int index);
	//remove item by searching for the music name
	//pre: music name must exist and look for the position of the music if it exist
	//post: music deleted

	void SortedArrayList::display();
	//Display all the songs

	void SortedArrayList::display(int index);
	//Search for the song title which returns index
	//display specific song information using the index

	int SortedArrayList::sqSearch(Song SAList[], string target);
	//Searching of song title using sequential search

	int SortedArrayList::binSearch(Song SAList[], string target);
	//Searching of song title using binary search

	SongItem SortedArrayList::get(int index);
	// get item at specific position in list

	bool SortedArrayList::isEmpty();
	//check if empty

	int SortedArrayList::getLength();
	//return the size of list.
};
#endif