#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() : std::vector<T>::vector() { };;
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

};


template <typename T>
bool Stack<T>::empty() const {
	if (std::vector<T>::size() == 0) return true;
	else return false;
}
template <typename T>
size_t Stack<T>::size() const {
	return std::vector<T>::size();
}
template <typename T>
void Stack<T>::push(const T& item) {
	std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop() {
	if (empty()) {
		throw std::underflow_error("Attempting to pop from empty list.");
	}
	else {
		std::vector<T>::pop_back();
	}
}

template <typename T>
const T& Stack<T>::top() const {
	if (empty()) {
		throw std::underflow_error("Attempting to check top of empty list.");
	}
	else {
		return std::vector<T>::back();
	}

}

#endif