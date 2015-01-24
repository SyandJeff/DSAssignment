#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <windows.h>
#include <psapi.h>
#include "Performance.h"
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "UnsortedPointerList.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<string> unsortedsongStorage;
vector<string> sortedsongStorage;
vector<string> tok1;
vector<string> tok2;
vector<Song> unsortedObj;
vector<Song> sortedObj;
vector<Word> wordStorage;
vector<Lyrics> lyricStorage;
vector<Performance> pStorage;
SortedArrayList saSList;
UnsortedArrayList usaSList;
UnsortedPointerList upSList; //Name suppose to contain "LinkList" but accidentally set as "Pointer" instead.

int importSongs()
{
	int noOfSongs = 0, count = 0, found = -1, j = 0, z = 0;
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
				tok1.push_back(token);
			}
			tok1.push_back(s);
			Song temp1(tok1[z], tok1[z+1], tok1[z+2], tok1[z+3], tok1[z+4], tok1[z+5]);
			z += 6;
			unsortedObj.push_back(temp1);
		}
		z = 0; //resetting z
		//tokenization for sorted song
		for (int i = 0; i < count; i++)
		{
			string t = sortedsongStorage[i]; //store string song into s
			string delim = "<SEP>"; //declare delimiter

			size_t pos1 = 0; //declare variable pos that can be any size
			string token1;//declare token
			while ((pos1 = t.find(delim)) != string::npos)
			{
				token1 = t.substr(0, pos1);
				//cout << token << endl;//display token by token
				t.erase(0, pos1 + delim.length());
				tok2.push_back(token1);
			}
			tok2.push_back(t);
			Song temp2(tok2[z], tok2[z + 1], tok2[z + 2], tok2[z + 3], tok2[z + 4], tok2[z + 5]);
			z += 6;
			sortedObj.push_back(temp2);
		}
	}
	else
		cout << "Unable to open file" << endl;
	return 0;
}

void addSASongs(SortedArrayList& saSList, int input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem, totalMem;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage;
	for (int i = 0; i < input; i++)
	{
		Song sa = sortedObj[i];
		saSList.add(sa);
		(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		afterMem = pmc.PrivateUsage;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	totalMem = afterMem - beforeMem;
	Performance p(1, 1, input, duration, totalMem);
	pStorage.push_back(p);
}
void addUASongs(UnsortedArrayList& usaSList, int input)
{

	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem, totalMem;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();//USAList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage;
	for (int i = 0; i < input; i++)
	{
		Song usa = unsortedObj[i];
		usaSList.add(usa);
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		afterMem = pmc.PrivateUsage;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	totalMem = afterMem - beforeMem;
	Performance p(1, 2, input, duration, totalMem);
	pStorage.push_back(p);
}
void addUPSongs(UnsortedPointerList& upSList, int input)
{

	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem, totalMem;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();//UPList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage;
	for (int i = 0; i < input; i++)
	{
		Song up = unsortedObj[i];
		upSList.add(up);
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
		afterMem = pmc.PrivateUsage;
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	totalMem = afterMem - beforeMem;
	cout << "POINTER: " << totalMem << endl;
	Performance p(1, 3, input, duration, totalMem);
	pStorage.push_back(p);
}
int addSongs()
{ 
	int input;
	if (unsortedObj.size() != 0)
	{
		cout << "There are " << unsortedObj.size() << " songs that has been imported." << endl;
		cout << "How many songs would you like to add to the lists? ";
		cin >> input;
		if (input > 0 && input <= unsortedObj.size())
		{
			addSASongs(saSList, input);
			addUASongs(usaSList, input);
			addUPSongs(upSList, input);
		}
		else
			cout << "Your input has to be  0 < input <= " << sortedObj.size() << endl;
	}
	else
		cout << "You have not imported the songs yet." << endl;
	return 0;
}

void displaySASongs(SortedArrayList& saSList)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;

	cout << "========================" << endl; //25
	cout << "Sorted Array List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//SAList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage;

	saSList.display();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage;
}
void displayUASongs(UnsortedArrayList& usaSList)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;
	cout << "========================" << endl;
	cout << "Unsorted Array List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//USAList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage
	usaSList.display();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
void displayUPSongs(UnsortedPointerList& upSList)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;

	cout << "========================" << endl;
	cout << "Unsorted Pointer List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//UPList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage
	upSList.display();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
int displaySongs()
{
	if (saSList.getLength() != 0)
	{
		displaySASongs(saSList);
		displayUASongs(usaSList);
		displayUPSongs(upSList);
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

void removeSASongs(SortedArrayList& saSList, int input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;

	start = std::clock();//SAList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage
	saSList.remove(input);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
void removeUASongs(UnsortedArrayList& usaSList, int input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;

	start = std::clock();//USAList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage

	usaSList.remove(input);
	
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
void removeUPSongs(UnsortedPointerList& upSList, int input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;

	start = std::clock();//UPList: Add start clock here.
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage

	upSList.remove(input);
	
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
int removeSongs()
{
	int input = -1;//default
	if (saSList.getLength() != 0)
	{
		cout << "There are " << saSList.getLength() << " songs in the lists." << endl;
		cout <<"State the song index that you would like to remove: ";
		cin >> input;
		if (input >= 0 && input < saSList.getLength())
		{
			removeSASongs(saSList, input);
			removeUASongs(usaSList, input);
			removeUPSongs(upSList, input);
		}
		else
			cout << "Your input has to be 0 <= input < " << saSList.getLength() << "." << endl;
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

int BinarySearch(SortedArrayList& saSList, UnsortedArrayList& usaSList, UnsortedPointerList& upSList)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;
	string input;
	if (saSList.getLength() != 0)
	{
		cout << "Search for Track ID [Case-Sensitive]: ";
		cin >> input;
		start = std::clock(); //start timer
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		beforeMem = pmc.PrivateUsage; //memory usage

		int check = saSList.binSearch(input);
		if (check != -1)
		{
			cout << "Track ID found!" << endl;
			saSList.display(check);
		}
		else
			cout << "Track ID cannot be Found in Sorted Array List!" << endl;
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;//end;

		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		afterMem = pmc.PrivateUsage; //memory usage

		cout << "" << endl;
		usaSList.binSearch();
		Performance p(5, 2, NULL, NULL, NULL);
		cout << "" << endl;
		upSList.binSearch();
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

void SASqSearch(SortedArrayList& sasList)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;
	string input;
	cout << "[Sorted Array List] Search for Track ID [Case-Sensitive]: ";
	cin >> input;
	start = std::clock();//start timer
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage

	int check1 = saSList.sqSearch(input);
	if (check1 != -1)
	{
		cout << "Track ID found in Sorted Array List!" << endl;
		saSList.display(check1);
	}
	else
		cout << "Track ID cannot be Found in Sorted Array List!" << endl;
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC; //end

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
void UASqSearch(UnsortedArrayList& usasList, string input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;
	
	start = std::clock();//start timer
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage

	int check2 = usaSList.sqSearch(input);
	if (check2 != -1)
	{
		cout << "Track ID found in Unsorted Array List" << endl;
		usaSList.display(check2);
	}
	else
		cout << "Track ID cannot be Found in Unsorted Array List!" << endl;
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;//end

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
void UPSqSearch(UnsortedPointerList& upsList, string input)
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T beforeMem, afterMem;
	std::clock_t start;
	double duration;
	
	cout << "" << endl;
	start = std::clock(); //start timer
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	beforeMem = pmc.PrivateUsage; //memory usage

	int check3 = upSList.sqSearch(input);
	if (check3 != -1)
	{

		cout << "Track ID found in Unsorted Pointer List" << endl;
		upSList.display(check3);
	}
	else
		cout << "Track ID cannot be Found in Pointer Array List!" << endl;
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;//end

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	afterMem = pmc.PrivateUsage; //memory usage
}
int SequentialSearch()
{
	string input;
	if (saSList.getLength() != 0)
	{
		SASqSearch(saSList);
		cout << "" << endl;
		cout << "[Unsorted Array List] Search for Track ID [Case-Sensitive]: ";
		cin >> input;
		UASqSearch(usaSList, input);
		UPSqSearch(upSList, input);
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

string center(const string s, const int w) 
{
	//retrieved from: stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c
	stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i<padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding>0 && padding % 2 != 0)               // if odd #, add 1 space
		ss << " ";
	return ss.str();
}
void Table(int choice)
{
	Performance p;
	if (choice == 1)
		cout << "ADD Operation: " << endl;
	else if (choice == 2)
		cout << "REMOVE Operation: " << endl;
	else if (choice == 3)
		cout << "DISPLAY Operation: " << endl;
	else if (choice == 4)
		cout << "SEQUENTIAL SEARCH Operation: " << endl;
	else
		cout << "BINARY SEARCH Operation: " << endl;
	cout << center("", 5) << " | "
		<< center("Sorted Arr", 10) << " | "
		<< center("Unsorted Arr", 10) << " | "
		<< center("Unsorted Ptr", 10) << " | " << endl;
	for (int i = 0; i < pStorage.size(); i++)
	{
		p = pStorage[i];
		if (p.getOperation() == choice)
		{
			
		}
	}
}
int ViewPerformance()
{
	int choice = -1; //default
	while (choice != 0)
	{
		cout << "" << endl;
		cout << "Which operation of its performance you would like to analyse?" << endl;
		cout << "" << endl;
		cout << "[1] Add Operation" << endl;
		cout << "[2] Remove Operation" << endl;
		cout << "[3] Display Operation" << endl;
		cout << "[4] Sequential Search Operation" << endl;
		cout << "[5] Binary Search Operation" << endl;
		cout << "[0] Return to Main Menu" << endl;
		cout << "" << endl;
		cout << "Enter your option : ";
		cin >> choice;
		cout << " " << endl;
		if (choice >= 1 && choice <= 5)
		{
			Table(choice);
		}
		else if (choice == 0)
			choice = 0;
		else
			cout << "Incorrecto" << endl;
	}
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
		cout << "" << endl;
		cout << "[1] Import the songs into the program" << endl;
		cout << "[2] Add songs into lists" << endl;
		cout << "[3] Remove a song" << endl;
		cout << "[4] Display list of songs" << endl;
		cout << "[5] Search a song using Sequential Search" << endl;
		cout << "[6] Search a song using Binary Search" << endl;
		cout << "[7] View Performance of Lists" << endl;
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
			//Add songs
			addSongs();
			break;
		case 3:
			//Remove songs
			removeSongs();
			break;
		case 4:
			//display songs
			displaySongs();
			break;
		case 5:
			//Searching using sequential search
			SequentialSearch();
			break;
		case 6:
			//Search using binary search
			BinarySearch(saSList, usaSList, upSList);
			break;
		case 7:
			ViewPerformance();
			break;
		default:
			cout << "Invalid Option! Please choose again." << endl;
			break;
		}
	}
}