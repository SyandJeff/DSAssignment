#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "Memory.h"
#include "GeneralPerformance.h"
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
vector<GP> gpStorage;
SortedArrayList saSList;
UnsortedArrayList usaSList;
UnsortedPointerList upSList; //Name suppose to contain "LinkList" but accidentally set as "Pointer" instead.

void combiningPerformanceLists()
{
	Performance a, b, c;
	int op, size, temp = pStorage.size();
	//	Performance(Operation, Size, Atime, Amem, Btime, Bmem, Ctime, Cmem)
	for (SIZE_T i = 0; i < pStorage.size(); i += 3)
	{
		a = pStorage[i]; // index = 0, 3, 6, etc are all sorted arrays
		b = pStorage[i + 1]; // index = 1, 4, 7 etc all unsorted arrays
		c = pStorage[i + 2]; // index = 2, 5, 8 etc all unsorted pointers
		op = a.getOperation();
		size = a.getSize();
		GP gp(op, size, a.getTime(), a.getMem(), b.getTime(), b.getMem(), c.getTime(), c.getMem());
		gpStorage.push_back(gp);
	}
	for (int i = 0; i < temp; i++)
	{
		pStorage.pop_back();
	}
}
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
		cout << "Importing Songs in the process. May take a long time." << endl;
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
	SIZE_T bM = 0, aM = 0, tM = 0;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();
	bM = getMem();

	for (int i = 0; i < input; i++)
	{
		Song sa = sortedObj[i];
		saSList.add(sa);
		aM = getMem();
	}
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;
	tM = (aM - bM) / 1024;
	Performance p(1, 1, input, duration, tM);
	pStorage.push_back(p);
}
void addUASongs(UnsortedArrayList& usaSList, int input)
{

	SIZE_T bM = 0, aM = 0, tM = 0;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();//USAList: Add start clock here.
	bM = getMem();
	for (int i = 0; i < input; i++)
	{
		Song usa = unsortedObj[i];
		usaSList.add(usa);
		aM = getMem();
	}
	duration = double(std::clock() - start) / CLOCKS_PER_SEC;
	tM = (aM - bM)/1024;
	Performance p(1, 2, input, duration, tM);
	pStorage.push_back(p);
}
void addUPSongs(UnsortedPointerList& upSList, int input)
{

	SIZE_T bM = 0, aM = 0, tM = 0;
	std::clock_t start;
	double duration;
	Song sa;
	start = std::clock();//UPList: Add start clock here.
	bM = getMem();
	for (int i = 0; i < input; i++)
	{
		Song up = unsortedObj[i];
		upSList.add(up);
		aM = getMem();
	}
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;
	tM = (aM - bM)/1024;
	Performance p(1, 3, input, duration, tM);
	pStorage.push_back(p);
}
int addSongs()
{ 
	SIZE_T input;
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
			combiningPerformanceLists();
			cout << "Successfully added " << input << " song[s]." << endl;
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
	SIZE_T aM;
	std::clock_t start;
	double duration;

	cout << "========================" << endl; //25
	cout << "Sorted Array List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//SAList: Add start clock here.
	aM = getMem();

	saSList.display(aM);
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;

	//pass into performance
	Performance p(3, 1, saSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);
}
void displayUASongs(UnsortedArrayList& usaSList)
{
	SIZE_T aM;
	std::clock_t start;
	double duration;
	cout << "========================" << endl;
	cout << "Unsorted Array List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//USAList: Add start clock here.
	aM = getMem();
	usaSList.display(aM);
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;

	//store performance
	Performance p(3, 2, usaSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);
}
void displayUPSongs(UnsortedPointerList& upSList)
{
	SIZE_T aM;
	std::clock_t start;
	double duration;

	cout << "========================" << endl;
	cout << "Unsorted Pointer List" << endl;
	cout << "========================" << endl;
	cout << " " << endl;
	start = std::clock();//UPList: Add start clock here.
	aM = getMem();
	upSList.display(aM);
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;

	//store performance
	Performance p(3, 3, upSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);
}
int displaySongs()
{
	if (saSList.getLength() != 0)
	{
		displaySASongs(saSList);
		displayUASongs(usaSList);
		displayUPSongs(upSList);
		combiningPerformanceLists();
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

void removeSASongs(SortedArrayList& saSList, int input)
{
	SIZE_T bM, aM, tM;
	std::clock_t start;
	double duration;

	start = std::clock();//SAList: Add start clock here.
	bM = getMem();
	saSList.remove(input,aM);
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;
	tM = (aM - bM) /1024;

	Performance p(2, 1, saSList.getLength(), duration, tM);
	pStorage.push_back(p);
	//store performance
}
void removeUASongs(UnsortedArrayList& usaSList, int input)
{
	SIZE_T bM, aM, tM;
	std::clock_t start;
	double duration;
	start = std::clock();
	bM = getMem();

	usaSList.remove(input, aM);
	
	duration = double (std::clock() - start) / CLOCKS_PER_SEC;
	
	tM = (aM - bM) / 1024;
	//store performance
	Performance p(2, 2, usaSList.getLength(), duration, tM);
	pStorage.push_back(p);
}
void removeUPSongs(UnsortedPointerList& upSList, int input)
{
	SIZE_T bM , aM, tM;
	std::clock_t start;
	double duration;

	start = std::clock();//UPList: Add start clock here.
	bM = getMem();

	upSList.remove(input, aM);
	
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;

	tM = (aM - bM) / 1024;
	//store performance
	Performance p(2, 3, upSList.getLength(), duration, tM);
	pStorage.push_back(p);
}
int removeSongs()
{
	int input2 = -1, input = -1;//default
	if (saSList.getLength() != 0)
	{
		cout << "There are " << saSList.getLength() << " songs in the lists." << endl;
		cout << "Note for Sorted and Unsorted Array List" << endl;
		cout << "For Best-Case Scenario, remove song index: " << (saSList.getLength() - 1) << endl;
		cout << "For Average-Case Scenario, remove song index: " << ((saSList.getLength() - 1) / 2)<< endl;
		cout << "For Worst-Case Scenario, remove song index: 0" << endl;
		cout << "" << endl;
		cout << "Note for Unsorted Pointer List" << endl;
		cout << "For Best-Case Scenario, remove song index: 0"<< endl;
		cout << "For Average-Case Scenario, remove song index: " << ((saSList.getLength() - 1) / 2) << endl;
		cout << "For Worst-Case Scenario, remove song index: " << (saSList.getLength() - 1) << endl;
		cout << "" << endl;
		cout << "For Sorted and Unsorted Array Lists: " << endl;
		cout << "State the song index that you would like to remove: ";
		cin >> input;
		cout << "" << endl;
		cout << "For Unsorted Pointer List: " << endl;
		cout << "State the song index that you would like to remove: ";
		cin >> input2;
		if (input >= 0 && input < saSList.getLength())
		{
			removeSASongs(saSList, input);
			removeUASongs(usaSList, input);
			removeUPSongs(upSList, input2);
			combiningPerformanceLists();
			cout << "Successfully removed song." << endl;
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
	SIZE_T aM;
	std::clock_t start;
	double duration;
	string input;
	int mid = (saSList.getLength()-1) / 2;
	int fquarter = saSList.getLength() / 4; //25%
	int squarter = (saSList.getLength() / 4) * 3; //75%
	int last = saSList.getLength() - 1; 
	Song s, t, u, v, w;
	s = saSList.get(mid);
	t = saSList.get(fquarter);
	u = saSList.get(squarter);
	v = saSList.get(last);
	w = saSList.get(0);
	cout << "Note: " << endl;
	cout << "For Best-Case Scenario, search for: " << s.getTID() <<endl;
	cout << "For Average-Case Scenario, search for: " << t.getTID() << " OR " << u.getTID() << endl;
	cout << "For Worst-Case Scenario, search for: " << w.getTID() << " OR " << v.getTID() << endl;
	start = std::clock(); //start timer
	aM = getMem();
	if (saSList.getLength() != 0)
	{
		cout << "Search for Track ID [Case-Sensitive]: ";
		cin >> input;
		

		int check = saSList.binSearch(input,aM);
		if (check != -1)
		{
			cout << "Track ID found!" << endl;
			saSList.display(check);
		}
		else
			cout << "Track ID cannot be Found in Sorted Array List!" << endl;
		duration = double(std::clock() - start) /CLOCKS_PER_SEC;//end;
		Performance p1(5, 1, saSList.getLength(), duration, aM / 1024);
		pStorage.push_back(p1);
		cout << "" << endl;
		usaSList.binSearch();
		Performance p2(5, 2, saSList.getLength(), NULL, NULL);
		pStorage.push_back(p2);
		cout << "" << endl;
		upSList.binSearch();
		Performance p3(5, 3, saSList.getLength(), NULL, NULL);
		pStorage.push_back(p3);
		combiningPerformanceLists();
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	//store performance
	return 0;
}

void SASqSearch(SortedArrayList& sasList)
{
	SIZE_T aM;
	std::clock_t start;
	double duration;
	string input;
	int mid = (sasList.getLength() - 1) / 2, last = sasList.getLength() - 1;
	Song s, t, u;
	s = sasList.get(0);
	t = sasList.get(mid);
	u = sasList.get(last);
	cout << "Note for Sorted Array List: " << endl;
	cout << "For Best-Case Scenario, search for: " << s.getTID() << endl;
	cout << "For Average-Case Scenario, search for: " << t.getTID() << endl;
	cout << "For Worst-Case Scenario, search for: " << u.getTID() << endl;
	cout << "[Sorted Array List] Search for Track ID [Case-Sensitive]: ";
	cin >> input;
	start = std::clock();//start timer
	aM = getMem();

	int check1 = saSList.sqSearch(input, aM);
	if (check1 != -1)
	{
		cout << "Track ID found in Sorted Array List!" << endl;
		saSList.display(check1);
	}
	else
		cout << "Track ID cannot be Found in Sorted Array List!" << endl;
	duration = double(std::clock() - start) /CLOCKS_PER_SEC; //end

	//store performance
	Performance p(4, 1, saSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);
}
void UASqSearch(UnsortedArrayList& usasList, string input)
{
	SIZE_T aM;
	std::clock_t start;
	double duration;
	
	start = std::clock();//start timer
	aM = getMem();

	int check2 = usaSList.sqSearch(input,aM);
	if (check2 != -1)
	{
		cout << "Track ID found in Unsorted Array List" << endl;
		usaSList.display(check2);
	}
	else
		cout << "Track ID cannot be Found in Unsorted Array List!" << endl;

	duration = double(std::clock() - start)/CLOCKS_PER_SEC;//end

	Performance p(4, 2, usaSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);

}
void UPSqSearch(UnsortedPointerList& upsList, string input)
{
	SIZE_T aM;
	std::clock_t start;
	double duration;
	
	cout << "" << endl;
	start = std::clock(); //start timer
	aM = getMem();

	int check3 = upSList.sqSearch(input, aM);
	if (check3 != -1)
	{

		cout << "Track ID found in Unsorted Pointer List" << endl;
		upSList.display(check3);
	}
	else
		cout << "Track ID cannot be Found in Pointer Array List!" << endl;
	duration = double(std::clock() - start) /CLOCKS_PER_SEC;//end
	//store performance
	Performance p(4, 3, upSList.getLength(), duration, aM/1024);
	pStorage.push_back(p);
}
int SequentialSearch()
{
	string input;
	if (saSList.getLength() != 0)
	{
		SASqSearch(saSList);
		cout << "" << endl;
		int mid = (usaSList.getLength() - 1) / 2, last = usaSList.getLength() - 1;
		Song s, t, u;
		s = usaSList.get(0);
		t = usaSList.get(mid);
		u = usaSList.get(last);
		cout << "Note for Unsorted Array & Pointer List: " << endl;
		cout << "For Best-Case Scenario, search for: " << s.getTID() << endl;
		cout << "For Average-Case Scenario, search for: " << t.getTID() << endl;
		cout << "For Worst-Case Scenario, search for: " << u.getTID() << endl;
		cout << "[Sorted Array List] Search for Track ID [Case-Sensitive]: ";
		cout << "[Unsorted Array & Pointer List] Search for Track ID [Case-Sensitive]: ";
		cin >> input;
		UASqSearch(usaSList, input);
		UPSqSearch(upSList, input);
		combiningPerformanceLists();
	}
	else
		cout << "You may have not imported or added the songs to the list yet." << endl;
	return 0;
}

//Table related
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
string prd(const double x, const int decDigits, const int width, int choice) 
{
	stringstream ss;
	if (choice == 5)
	{
		if (x == NULL)
			return "  NULL  ";
		else
		{
			ss << fixed << right;
			ss.fill(' ');        // fill space around displayed #
			ss.width(width);     // set  width around displayed #
			ss.precision(decDigits); // set # places after decimal
			ss << x;
			return ss.str();
		}
	}
	else
	{
		ss << fixed << right;
		ss.fill(' ');        // fill space around displayed #
		ss.width(width);     // set  width around displayed #
		ss.precision(decDigits); // set # places after decimal
		ss << x;
		return ss.str();
	}
}
void Table(int choice)
{
	GP gp;
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
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << center("", 5) << " | "
		<< center("Sorted Arr", 19) << " | "
		<< center("Unsorted Arr", 19) << " | "
		<< center("Unsorted Ptr", 19) << " | " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << center("  n", 5) << " | "
		<< center("Time[s]", 8) << " | "
		<< center("RAM[KB]", 8) << " | "
		<< center("Time[s]", 8) << " | "
		<< center("RAM[KB]", 8) << " | "
		<< center("Time[s]", 8) << " | "
		<< center("RAM[KB]", 8) << " | "
		<< endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	double temp;
	for (SIZE_T i = 0; i < gpStorage.size(); i++)
	{
		gp = gpStorage[i];
		if (gp.getOperation() == choice)
		{
			temp = (double)gp.getSize();
			cout << prd(temp, 0, 5, choice) << " | "
				<< prd(gp.getATime(), 2, 8, choice) << " | " //sorted array
				<< prd(gp.getAMem(), 2, 8, choice) << " | "
				<< prd(gp.getBTime(), 2, 8, choice) << " | " //unsorted array
				<< prd(gp.getBMem(), 2, 8, choice) << " | "
				<< prd(gp.getCTime(), 2, 8, choice) << " | " //unsorted pointer
				<< prd(gp.getCMem(), 2, 8, choice) << " | "
				<< endl;
		}
	}
}
void ViewPerformance()
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
			cout << "Invalid Option! Please choose again." << endl;
	}
}

void clearLists(SortedArrayList& saSList, UnsortedArrayList& usaSList, UnsortedPointerList& upSList)
{
	int input = -1;
	cout << "Are you sure that you want to delete existing song lists? [1 - Yes, 0 - No] ";
	cin >> input;
	switch (input)
	{
	case 0:
		cout << "Returning to Main Menu." << endl;
		break;
	case 1:
		saSList.clear();
		usaSList.clear();
		upSList.clear();
		input = 1;
		break;
	default:
		cout << "Incorrect choice." << endl;
		break;
	}
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
		cout << "[3] Display list of songs" << endl;
		cout << "[4] Search a song using Sequential Search" << endl;
		cout << "[5] Search a song using Binary Search" << endl;
		cout << "[6] Remove a song" << endl;
		cout << "[7] View Performance of Lists" << endl;
		cout << "[8] Clear existing Song Lists" << endl;
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
			cout << "Successfully imported songs." << endl;
			break;
		case 2:
			//Add songs
			addSongs();
			break;
		case 3:
			//Display songs
			displaySongs();
			break;
		
		case 4:
			//Searching using sequential search
			SequentialSearch();
			break;
		case 5:
			//Search using binary search
			BinarySearch(saSList, usaSList, upSList);
			break;
		case 6:
			//Remove songs
			removeSongs();
			break;
		case 7:
			ViewPerformance();
			break;
		case 8:
			clearLists(saSList, usaSList, upSList);
			break;
		default:
			cout << "Invalid Option! Please choose again." << endl;
			break;
		}
	}
}