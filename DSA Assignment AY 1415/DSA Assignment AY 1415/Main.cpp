#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<string> songStorage;
vector<string> tok;
vector<Song> object;
vector<string> wordStorage;
vector<Lyrics> lyricStorage;

int importSongs()
{
	int noOfSongs = 0, count = 0, found = -1;
	string song, token, word, lyric, tid, mid;
	
	

	cout << "How many songs would you like to import? ";
	cin >> noOfSongs;
	ifstream sfile("mxm_779k_matches.txt");
	ifstream lyricFile("mxm_dataset_train.txt");

	if (sfile.is_open())
	{
		//Storing Words int Vector Word.
		while (found == -1)
		{
			getline(lyricFile, word);
			if (word[0] == '%')
				found = 1;
			istringstream ss(word);
			while (getline(ss, token, ','))
				wordStorage.push_back(token);
		}
		//Storing Songs and Lyrics into Vector song
		while (noOfSongs > count)
		{
			//Get Songs
			getline(sfile, song);
			if (song[0] != '#')
			{
				songStorage.push_back(song); //storing in the vector
				count++;
				//need to be stored into vectors
			}
			//Get Lyrics
			getline(lyricFile, lyric);
			if (lyric[0] != '%' && lyric[0] != '#')
			{
				istringstream ls(lyric);
				getline(ls, token, ',');
				tid = token;
				getline(ls, token, ',');
				mid = token;
				string total = tid + mid;
				int start = total.size();
				int end = lyric.size();
				lyric = lyric.substr((start + 2), end);
				Lyrics obj(tid, mid, lyric);
				lyricStorage.push_back(obj);
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
			//cout << s << endl;
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
int addSongs()
{
	string what;
	if (wordStorage.size() != 0)
	{
		for (size_t i = 0; i < wordStorage.size(); i++)
		{
			what = wordStorage[i];
			cout << what << endl;
		}
	}
	else
		cout << "You have not imported the songs yet." << endl;
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
		cout << "[2] Add songs into lists" << endl;
		cout << "[3] Remove a song" << endl;
		cout << "[4] Display list of songs" << endl;
		cout << "[5] Search a song using Sequential Search" << endl;
		cout << "[6] Search a song using Binary Search" << endl;
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
			importSongs();
			break;
		case 2:
			addSongs();
			break;
		case 3:
			//Remove songs
			break;
		case 4:
			break;
		case 5:
			//Searching using sequential search
			break;
		case 6:
			//Search using binary search
			break;
		default:
			cout << "Invalid Option! Please choose again." << endl;
			break;
		}
	}
}