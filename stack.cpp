/* There're are lots of plates standing on top of each other, forming a tower with different sizes(from 9-smallest to 1-biggest) and so that all the plates do not collapse, 
they must be placed in order. It does finction sortPlate. Function findPlates helps to find an index of plate with a certain size. Also, it's possible to add new plate. */


#include <iostream>
#include <stack>
using namespace std;

stack <int> sortPlates(stack<int> st1) {
	stack <int> st2;

	while (!st1.empty()) {
		int s1Top = st1.top();
		st1.pop();


		while (!st2.empty() && st2.top() > s1Top) {
			st1.push(st2.top());
			st2.pop();
		}
		st2.push(s1Top);
	}
	return st2;
}

int findPlates(stack<int> st1, int n) {
	int k = 1;

	if (st1.empty()) {
		cout << "There're no plates in a stack " << endl;
	}

	while (!st1.empty() && st1.top() != n)
	{
		k += 1;
		st1.pop();

	}
	return k;
}

int main() {
	stack <int> st1;
	int option;
	int plateIndex;

	st1.push(5);
	st1.push(1);
	st1.push(7);
	st1.push(9);
	st1.push(2);
	st1.push(3);
	st1.push(3);
	st1.push(1);

menu:

	cout << "What do you want to do?\n 1. Add new plate \n 2. Sort plates\n 3.Find exact plate\n";
	cin >> option;

	if (option == 1) {
		int newPlate;
		cout << "\nEnter plate size (from 9 to 1)\n";
		cin >> newPlate;
		st1.push(newPlate);
		cout << "\n New plate was added to stack\n ";
	}

	if (option == 2)
	{
		stack <int> st2 = sortPlates(st1);
		cout << "\nSorted plates are:\n";

		while (!st2.empty())
		{
			cout << st2.top() << endl;
			st2.pop();
		}
	}

	if (option == 3) {

		stack <int> st3 = sortPlates(st1);

		cout << "\nWhich plate do you need?\n ";
		cin >> plateIndex;
		cout << "The index of plate " << plateIndex << " is " << findPlates(st3, plateIndex);
	}

	goto menu;
}
