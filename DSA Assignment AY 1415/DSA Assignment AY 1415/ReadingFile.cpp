#include <iostream>
#include <fstream>
#include <string>
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"
using namespace std;

int readSongs()
{
	int noOfSongs, count;

	cout << "How many songs would you like to import?" << endl;
	cin >> noOfSongs;

	std::ifstream file("mxm_779k_matches");
	std::string song;
	while (std::getline(file, song))
	{
		//Process
		//commands to read a specific number of lines
		if (noOfSongs > count)
		{
			if (song.at(0) != '#')
			{
				//store it in an array
			}
		}
		else
			false; //stop the reading
		
	}

}