#include <string>
#include <iostream>
using namespace std;

typedef string;

class UnsortedPointerList
{
private:
	struct Node
	{
		string item;
		Node *next;
	};

	Node *firstNode;
	int size;

public:
	UnsortedPointerList();

	bool add();

	bool remove();

	bool display();


};
