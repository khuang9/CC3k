CMP=g++20
EXTRA= -Wall -O -g 
CCFILES= $(wildcard *.cc)
OFILES= ${CCFILES:.cc=.o}

cc3k: $(OFILES)
	$(CMP) $(EXTRA) $(OFILES) -o cc3k

%.o: %.cc
	$(CMP) $(EXTRA) -c -o $@ $< 
