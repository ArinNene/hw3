#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int>* stack = new Stack<int>();
	stack->push(2);
	stack->push(5);
	cout << stack->size() << endl; //should return 2
	cout << boolalpha << stack->empty() << endl; //should return false
	stack->pop();
	cout << stack->top() << endl; //should return 2
	stack->pop();
	cout << boolalpha << stack->empty() << endl; //should return true
	cout << stack->size() << endl; //should return 0
	delete stack;
}