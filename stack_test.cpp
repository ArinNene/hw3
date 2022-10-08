#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int>* stack = new Stack<int>();
	stack->push(2);
	stack->push(5);
	cout << stack->size() << endl;
	cout << boolalpha << stack->empty() << endl;
	stack->pop();
	cout << stack->top() << endl;
	stack->pop();
	cout << boolalpha << stack->empty() << endl;
	cout << stack->size() << endl;
}