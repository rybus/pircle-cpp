CXX = g++
CXXFLAGS = -lSDL2

all: pircle

pircle: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o pircle $(OBJS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
