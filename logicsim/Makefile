CXX=g++
CXXFLAGS=-g -Wall -std=c++11

OBJS=wire.o gate.o circuit.o logicsim.o

all: logicsim

logicsim: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

logicsim.o: logicsim.cpp wire.h gate.h circuit.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c logicsim.cpp
wire.o: wire.cpp wire.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c wire.cpp
gate.o: gate.cpp wire.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c gate.cpp
circuit.o: circuit.cpp wire.h gate.h event.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c circuit.cpp

myGates:
	./logicsim single_and.txt > my_and.uml 
	java -jar plantuml.jar my_and.uml
	
	./logicsim single_or.txt > my_or.uml 
	java -jar plantuml.jar my_or.uml
	

	./logicsim single_not.txt > my_not.uml 
	java -jar plantuml.jar my_not.uml

	./logicsim exclusive_or.txt > my_xor.uml 
	java -jar plantuml.jar my_xor.uml

clean:
	rm -f *.o logicsim
