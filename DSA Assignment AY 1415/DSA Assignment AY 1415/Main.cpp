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

vector<string> unsortedsongStorage;
vector<string> sortedsongStorage;
vector<string> tok;
vector<Song> unsortedObj;
vector<Song> sortedObj;
vector<Word> wordStorage;
vector<Lyrics> lyricStorage;
SortedArrayList saSList, saWList, saLList;
UnsortedArrayList usaSList, usaWList, usaLList;
UnsortedPointerList upSList, upWList, upLList; //Name suppose to contain "LinkList" but accidentally set as "Pointer" instead.

int importSongs()
{
	int noOfSongs = 0, count = 0, found = -1, j = 0;
	string sSong, uSong, token, word, lyric, tid, mid;
	cout << "How many songs would you like to import? ";
	cin >> noOfSongs;
	ifstream ussfile("mxm_779k_matches.txt");
	ifstream ssfile("mxm_779k_matches_sorted.txt");
	ifstream lyricFile("mxm_dataset_train.txt");
	if (ussfile.is_open())
	{
		//Storing Words int Vector Word.
		while (found == -1)
		{
			getline(lyricFile, word);
			if (word[0] == '%')
				found = 1;
			istringstream ss(word);
			while (getline(ss, token, ','))
			{
				j++;
				Word w(j, token);
				wordStorage.push_back(w);
			}
		}
		//Storing Songs and Lyrics into Vector song
		while (noOfSongs > count)
		{
			//Get Songs
			//unsorted
			getline(ussfile, uSong);
			if (uSong[0] != '#')
			{
				unsortedsongStorage.push_back(uSong); //storing in the vector
				count++;//need to be stored into vectors
			}
			//sorted
			getline(ssfile, sSong);
			if (sSong[0] != '#')
			{
				sortedsongStorage.push_back(sSong); //storing in the vector
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
		ussfile.close();
		ssfile.close();
		lyricFile.close();
		//tokenization for unsorted song
		for (int i = 0; i < count; i++)
		{
			string s = unsortedsongStorage[i]; //store string song into s
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
			tok.push_back(s);
			Song su(tok[0], tok[1], tok[2], tok[3], tok[4], tok[5]);
			unsortedObj.push_back(su);
		}
		//tokenization for sorted song
		for (int i = 0; i < count; i++)
		{
			string s = sortedsongStorage[i]; //store string song into s
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
			tok.push_back(s);
			Song su(tok[0], tok[1], tok[2], tok[3], tok[4], tok[5]);
			sortedObj.push_back(su);
		}
	}
	else
		cout << "Unable to open file" << endl;
	cout << " " << endl;
	return 0;
}
int addSongs(SortedArrayList& saSList, UnsortedArrayList& usaSList, UnsortedPointerList& upSList)
{ 
	bool check = false; size_t input = -1;//default
	if (unsortedObj.size() != 0)
	{
		cout << "How many songs would you like to add to the lists? ";
		cin >> input;
		//SAList: Add start clock here.
		for (size_t i = 0; i < input; i++)
		{
			Song s = sortedObj[i];
			saSList.add(s);
		}
		//SAList: Add end clock here. Store in variable
		//USAList: Add start clock here.
		for (size_t i = 0; i < input; i++)
		{
			Song s = unsortedObj[i];
			usaSList.add(s);
		}
		//SAList: Add end clock here. Store in variable
		//UPList: Add start clock here.
		for (size_t i = 0; i < input; i++)
		{
			Song s = unsortedObj[i];
			upSList.add(s);
		}
		//UPList: Add end clock here. Store in variable
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
		cout << " " << endl;
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
			addSongs(saSList, usaSList, upSList);
			break;
		case 3:
			//Remove songs
			break;
		case 4:
			//display songs
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