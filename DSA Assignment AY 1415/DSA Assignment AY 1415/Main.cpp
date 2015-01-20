#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int readSongs()
{
	int noOfSongs = 0, count = 0;
	string song;
	std::string delim = "<SEP>";
	size_t pos = 0;
	std::string token;
	vector<string> songStorage;
	cout << "How many songs would you like to import? ";
	cin >> noOfSongs;
	ifstream sfile("mxm_779k_matches.txt");
	if (sfile.is_open())
	{
		while (noOfSongs > count)
		{
			//getting songs line by line
			getline(sfile, song);
			if (song[0] != '#')
			{
				cout << song << endl; //need to be stored into vectors
				/*songStorage.push_back(song);*/

				//trying to seperate the string
				/*while ((pos = song.find(delim)) != std::string::npos)
				{
					token = song.substr(0, pos);
					std::cout << token << std::endl;
					song.erase(0, pos + delim.length());
					count++;
					if (noOfSongs = count)
						break;
				}
				std::cout << song << std::endl;*/
				//count++;
			}
			
		}
		sfile.close();
	}
	else
		cout << "Unable to open file" << endl;
	cout << " " << endl;
	return 0;
	//left with finishing list in order to use it
}

int test()
{
	std::string s = "scott>=tiger>=mushroom";
	std::string delimiter = ">=";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		std::cout << token << std::endl;
		s.erase(0, pos + delimiter.length());
	}
	std::cout << s << std::endl;
	return 0;
}
int main()
{
	int option = -1; //default
	while (option != 0)
	{
		cout << "Welcome to DSA Assignment AY1415" << endl;
		cout << "====================================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "" << endl;
		cout << "[1] Import the songs into the program" << endl;
		cout << "[2] Remove a song" << endl;
		cout << "[3] Search a song using Sequential Search" << endl;
		cout << "[4] Search a song using Binary Search" << endl;
		cout << "[0] End the program" << endl;
		cout << "" << endl;
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
			//Remove songs
			test();
			break;
		case 3:
			//Searching using sequential search
			break;
		case 4:
			//Search using binary search
			break;
		default:
			cout << "Invalid Option! Please choose again." << endl;
			break;
		}
	}
}