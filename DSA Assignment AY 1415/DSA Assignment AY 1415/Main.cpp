#include <iostream>
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"

using namespace std;

int choiceSelection(int option)
{
	switch (option)
	{
	case '1':
		//Import songs
		break;
	case '2':
		//Add songs
		break;
	case '3':
		//Remove songs
		break;
	case '4':
		//Search using sequential search
		break;
	case '5':
		//search using binary search
		break;
	case '0':
		//exit program
		break;
	}

}

int main()
{
	cout << "Welcome to DSA Assignment AY1415" << endl;
	cout << "====================================" << endl; //36 =
	cout << "What would you like to do?" << endl;
	cout << "1) Import the songs into the program" << endl;
	cout << "2) Add new song" << endl;
	cout << "3) Remove a song" << endl;
	cout << "4) Search a song using Sequential Search" << endl;
	cout << "5) Search a song using Binary Search" << endl;
	cout << "0) End the program" << endl;

	int option;
	cin >> option;
	choiceSelection(option);

	return 0;
}