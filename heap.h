#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T>//using 0-index heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : std::vector<T>::vector(),m_(m),p_(c) {};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

	void trickleDown(int loc);
	void trickleUp(int loc);

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> items_;
	int m_;
	PComparator p_;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return items_.size() == 0; //is size of member items_ zero?
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
	return items_.size(); //return size_t size of items vector
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc) { //implemented as per slides on bytes, adjusted for m-ary heaps
	int parent = (loc-1)/m_; 
	while(parent >= 0 && p_(items_[loc],items_[parent])) {  //while parent index is valid, make comparison. Swap if true, stop otherwise.
		std::swap(items_[parent], items_[loc]);
		loc = parent;
		parent = (loc-1)/m_; //integer division for parent
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc) { //implemented as per slides on bytes, adjusted for m-ary heaps
	if ((unsigned int)(loc*m_+1) >= items_.size()) { //if loc*m_+1 (first child) location is greater than vector size, it means the current loc is a leaf node.
    return;
  }
  int mostChildLoc = loc*m_+1; //use a running variable which tracks the "-est" value between all m_ children of a node (e.g. smallest, largest, etc.)
  for (int i = 1; i < m_+1; i++) {
    if ((unsigned int)(loc*m_+i) >= 0 && (unsigned int)(loc*m_+i) < items_.size()) {
      if (p_(items_[loc*m_+i],items_[mostChildLoc])) {
        mostChildLoc = loc*m_+i;
      }
    }
  }
  if (p_(items_[mostChildLoc],items_[loc])) { //if p_ true, swap parent down, and make recursive call for new index
    std::swap(items_[mostChildLoc],items_[loc]);
    trickleDown(mostChildLoc);
  }

}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::out_of_range("Attempted to access top of empty list");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return items_[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Attempted to pop from empty list");

  }
	std::swap(items_[0],items_[items_.size()-1]);
  items_.pop_back(); //vector::pop_back
	trickleDown(0); //trickleDown

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
	//call trickleup() -> divide by m instead of 2.
	items_.push_back(item); //vector::push_back
	trickleUp(items_.size()-1);
}


#endif

