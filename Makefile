CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack_test

OBJS=llrec-test.o llrec.o

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

stack_test: stack_test.o
	$(CXX) $(CXXFLAGS) -o $@ stack_test.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

stack_test.o: stack_test.cpp stack.h 
	$(CXX) $(CXXFLAGS) -o $@ -c stack_test.cpp

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

valgrindLLREC: 
	$(VALGRIND) ./llrec-test llrec-test1.in

valgrindSTACK:
	$(VALGRIND) ./stack_test

clean:
	rm -f *.o rh llrec-test stack_test *~


.PHONY: clean 