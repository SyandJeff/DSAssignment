#ifndef UNSORTEDARRAYLIST_H
#define UNSORTEDARRATLIST_H

#include <string>
#include <iostream>
using namespace std;

const int USA_MAX_SIZE = 10000;

typedef string ItemType; //need help here

class UnsortedArrayList
{
private:
	string USAList[USA_MAX_SIZE];
	int size;

public:
	UnsortedArrayList::UnsortedArrayList();

	bool UnsortedArrayList::add(string song);
	//add item to the back to the list
	//pre:size<MAX_SIZE
	//post: music added to the list

	bool UnsortedArrayList::remove(int index);
	//remove item by searching for the music name
	//pre: music name must exist and look for the position of the music if it exist
	//post: music deleted

	void UnsortedArrayList::display();
	//display all songs

	void UnsortedArrayList::display(int index);
	//display specific song

	int UnsortedArrayList::sqSearch(ItemType searchItem);
	//sequential search

	int UnsortedArrayList::binSearch(ItemType searchItem);
	//binary search

	int UnsortedArrayList::getLength();
	//get the length of array

	bool UnsortedArrayList::isEmpty();
	//check if the array is empty

};
#endif