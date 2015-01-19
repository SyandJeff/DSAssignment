#include <iostream>
#include <fstream>
#include <string>
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"
//#include "ReadingFile.h"

using namespace std;

int readSongs()
{
	int noOfSongs, count = 0;
	string song;
	cout << "How many songs would you like to import?" << endl;
	cin >> noOfSongs;
	/*ifstream file("mxm_779k_matches");
	while (std::getline(file, song))
	{
		//Process
		//commands to read a specific number of lines
		if (noOfSongs > count)
		{
			if (song.at(0) != '#')
			{
				//store it in an array
				count++;
				cout << count << " song" << endl; //testing only
			}
		}
		else
			false; //stop the reading
		
	}*/
	return 0;
}

int main()
{
	int option = -1; //default
	while (option != 0)
	{
		cout << "" << endl;
		cout << "Welcome to DSA Assignment AY1415" << endl;
		cout << "====================================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) Import the songs into the program" << endl;
		cout << "2) Add new song" << endl;
		cout << "3) Remove a song" << endl;
		cout << "4) Search a song using Sequential Search" << endl;
		cout << "5) Search a song using Binary Search" << endl;
		cout << "0) End the program" << endl;
		cout << "Enter your option : ";
		cin >> option;
		cout << "" << endl;
		switch (option)
		{
		case 0:
			option = 0;
			break;
		case 1:
			//Import songs
			readSongs();
			break;
		case 2:
			//Add songs
			break;
		case 3:
			//Remove songs
			break;
		case 4:
			//Search using sequential search
			break;
		case 5:
			//search using binary search
			break;
		default:
			cout << "Invalid Option! Please choose again." << endl;
			break;
		}
	}
}