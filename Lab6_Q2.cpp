// C++ program to Implement a stack
// using singly linked list
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// creating a linked list;
class Node {
public:
	int data;
	Node* link;
	
	// Constructor
	Node(int n)
	{
		this->data = n;
		this->link = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack() { top = NULL; }

	void Push(int data)
	{

		// Create new node temp and allocate memory in heap
		Node* temp = new Node(data);

		// Check if stack (heap) is full.
		// Then inserting an element would
		// lead to stack overflow
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}

		// Initialize data into temp data field
		temp->data = data;

		// Put top pointer reference into temp link
		temp->link = top;

		// Make temp as top of Stack
		top = temp;
	}

	// Utility function to check if
	// the stack is empty or not
	bool isEmpty()
	{
		// If top is NULL it means that
		// there are no elements are in stack
		return top == NULL;
	}

	// Utility function to return top element in a stack
	int Peek()
	{
		// If stack is not empty , return the top element
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

	// Function to remove
	// a key from given queue q
	void Pop()
	{
		Node* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {

			// Assign top to temp
			temp = top;

			// Assign second node to top
			top = top->link;

			// This will automatically destroy
			// the link between first node and second node

			// Release memory of top node
			// i.e delete the node
			free(temp);
		}
	}

	// Function to print all the
	// elements of the stack
	void Display()
	{
		Node* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout << temp->data;

				// Assign temp link to temp
				temp = temp->link;
				if (temp != NULL)
					cout << " -> ";
			}
			cout << "\n\n";
		}
	}
};

// Driven Program
int main()
{
    // start measuring time
    auto start = high_resolution_clock::now();
    
	// Creating a stack
	Stack S;

	S.Push(8);
    S.Push(10);
    S.Push(5);
    S.Push(11);
    S.Push(15);
    S.Push(23);
    S.Push(6);
    S.Push(18);
    S.Push(20);
    S.Push(17);
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display();
    S.Push(4);
    S.Push(30);
    S.Push(3);
    S.Push(1);
    S.Display();

    // stop measuring time
    auto stop = high_resolution_clock::now();

    // calculate the time taken and print it in milliseconds
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by code: " << duration.count() << " microseconds" << endl;

	return 0;
}
