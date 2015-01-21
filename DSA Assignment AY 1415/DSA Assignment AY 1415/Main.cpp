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
	vector<string> songStorage;
	vector<string> tok;
	vector<Song> object;

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
				songStorage.push_back(song); //storing in the vector
				count++;
				//need to be stored into vectors
			}
		}
		sfile.close();



		//tokenization
		for (int i = 0; i < count; i++)
		{
			string s = songStorage[i]; //store string song into s
			//cout << songStorage[i] << endl; //test if the vector is still inside
			string delimiter = "<SEP>"; //declare delimiter

			size_t pos = 0; //declare variable pos that can be any size
			string token;//declare token
			while ((pos = s.find(delimiter)) != string::npos)
			{
				token = s.substr(0, pos);
				//cout << token << endl;//display token by token
				s.erase(0, pos + delimiter.length());
				tok.push_back(token);
			}
			cout << s << endl;
			tok.push_back(s);
			Song su(tok[0], tok[1], tok[2], tok[3], tok[4], tok[5]);
			object.push_back(su);
		}

		//int stringToken(vector<string> songStorage, int count);

	}
	else
		cout << "Unable to open file" << endl;
	cout << " " << endl;
	return 0;
	//left with finishing list in order to use it
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