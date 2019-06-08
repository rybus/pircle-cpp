CXX=g++
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
CXXFLAGS = -Wall -std=c++11 -pedantic $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
RM=rm -f
SRCS=main.cpp store.cpp prime.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

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
