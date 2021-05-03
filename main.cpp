#include<iostream>

using namespace std;

struct Node
{
	int datum;
	Node * pNext;  // 1 Node contains 2 parts : Data and pNext or called Linked component

				   // Open a construct to initialize this NODE at the beginning :

	Node()
	{
		datum = 0;
		pNext = nullptr;
	};

	// Open a construct to take some Arguments as Parameters  :

	Node(int DataPoint, Node *link)    // 1 is data, 1 is the next pointer
	{
		datum = DataPoint;
		pNext = link;
	}
	// to check if the Linked List is empty or not :

};

class SortedLinkedList
{
private:
	Node *pHead;
public:
	SortedLinkedList()        // a constructor
	{
		pHead = nullptr;     // Initialize pHead
	}

	SortedLinkedList(Node * link)     // a Constructor takes parameters
	{
		pHead = link;          // Initialize pHead

	}

	bool isEmpty()
	{
		return(pHead == nullptr);  // Output : 1 - True at the beginning witout any values
	}

	void CreateList()
	{
		cout << " Enter a number of Nodes that you want to have in the LinkedList :" << endl;

		int numberOfNodes;          // Declare a variable of Input from User
		cin >> numberOfNodes;       // To store the entered value from User input

		Node *pCurrentNode;     // Declare a variable for current Pointer
		Node *pNewNode;        //  Declare a variable for next Pointer

		cout << " Enter the value to store in 0th node " << endl;

		int inputValue;          // Declare a variable for this Value
		cin >> inputValue;       // To store this input value

		pNewNode = new Node(inputValue, nullptr);     // this constructor : (this is the first Node) data is the input Value, link is last NODE that pointer should reach - NULL
		pHead = pNewNode;      // pHead copy address of new Node when a value Input for Current Node entered
		pCurrentNode = pHead;   //  Now in pHead contains the addres of CurrentNode

		int count = 0;   // initialize the count at begin = 0

		while (count != (numberOfNodes - 1))  // because, 1 first exists above
		{
			cout << " Enter the value to store in the " << count + 1 << " Node" << endl;

			cin >> inputValue;  // store the address of new Node

			pNewNode = new Node(inputValue, nullptr);

			pCurrentNode->pNext = pNewNode;

			pCurrentNode = pNewNode;       // in PcurrentNode, we store the address of new Node

			count++;
		}
	}

	// A linkedList : pH, 2,5,7,9,14,17
	// We want to insert 11, it will be between 9, 14

	Node * searchLinkedList(Node *pHead, int x)
	{
		Node *pPrevious = nullptr;      // to return the addres of previous Node 9 is NULL
		Node *pCurrent = pHead;        // Assign Pointer of current Node = pHead : pHeat at the beginning is now NULL

		while (pCurrent != nullptr && pCurrent->datum <x)   // x = 11 - Loop go from pHead at the beginning with NULL
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		return pPrevious;
	}

	// use Void to inser number :

	void insertNode(int x)   //  To find the position where we want to insert
	{
		Node * pPrevious = searchLinkedList(pHead, x);
		Node *pCurrent = new Node;
		pCurrent->datum = x;

		if (pPrevious == nullptr)
		{
			pCurrent->pNext = pHead;      // because pHead = NULL
			pHead = pCurrent;
		}
		else
		{
			pCurrent->pNext = pPrevious->pNext;    // Pointer of Current Node contains the Address of previous Node
			pPrevious->pNext = pCurrent;             // Just corrected : added ->pNext
		}
	}

	// Remove a Node :
	// H 2 5 7 9 14 17

	void removeNode(int x)  // Passs datatype- integer of element we want to remove
	{

		Node * pPrevious = searchLinkedList(pHead, x);   // pass pHead and x : element We want to remove

		if (pPrevious != nullptr)
		{
			if (pPrevious->pNext == nullptr || pPrevious->pNext->datum != x)  // ex: if we find 15, not the Node in the element we want to remove, 
																			  //the next is 17

				return;

			Node *pToRemove = pPrevious->pNext;      // Assign the Poiter of the Nodved we remove, it = the pointer in the previous Node
			pPrevious->pNext = pToRemove->pNext;     // Assign the pointer of the previous Node to the pointer of Node remove

			delete pToRemove;

		}
		else
		{
			if (pHead == nullptr || pHead->datum != x)  // the Node we want to remove is at the top of the List

				return;

			Node * pToRemove = pHead;
			pHead = pToRemove->pNext;   // If we remove the First Node(Node 1);  so pHead contain pNext Node (node 2)

			delete pToRemove;        // Remove the First Node ( Node 1)

		}
	}

	// Write a function that determine one element belong to the Linked List or NOT :
	//  after Insert 11, and check if it is member - return 1 -if yes, return 0 after remove

	bool isMember(int x)   // use searchLinkedList to find the address < x
	{
		Node * pPrevious = searchLinkedList(pHead, x); // Pass 2 arguments , return the Address < x

		if (pPrevious != nullptr)     // Previous is not empty, means it is NOT the last NODE, and at least one Element <x
		{
			return pPrevious->pNext != nullptr && pPrevious->pNext->datum == x;     // Previous is not the last NODE and
		}

		else     // pPrevious is now Null Pointer
		{
			return pHead != nullptr && pHead->datum == x;   // return pHead different from NULL Pointer and the pHead has the value x- that is member
		}
	}

// A function to count the elements (Nodes) in the LinkedList :

	int numberOfMembers()
	{
		int length = 0;      // declare a variable at the beginning =0

		for (const Node * p = pHead; p != nullptr; p = p->pNext)
		{
			length++;
		}

		return length;

	}

	void printLinkedList()
	{
		cout << " Our Linked List is as follows : " << endl;

		for (const Node * p = pHead; p != nullptr; p = p->pNext)
		{
			cout << p->datum << endl;     // print value of for each node
		}

		cout << endl;

	}
};


int main()
{

	SortedLinkedList list1;
	list1.CreateList();         // Calling function CreateList
	list1.insertNode(11);           // Calling the function Insert - insert Number 11



	cout << endl;
	cout << list1.isMember(11) << endl;

	cout << endl;

	cout << list1.numberOfMembers() << endl;    // We know 11 is in the list after InsertNode (11), We check if it is member ---it return " 1"
	
	

	cout << endl;
	list1.printLinkedList();      // Calling the function printLinkedList


	cout << endl;
	list1.removeNode(11);         // Calling the function Remove - remove 11 - then It returns " 0 "

	
	cout << endl;
	cout << list1.isMember(11) << endl;    // after REMOVE ---it return 0
	cout << list1.numberOfMembers() << endl;



	cout << endl;
	list1.printLinkedList();



	return 0;
}