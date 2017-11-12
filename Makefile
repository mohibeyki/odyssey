APP=odyssey
CXX=g++
CXXFLAGS= -std=c++11 -g -Wall
LDFLAGS = -lpthread -pthread
OBJDIR=.obj

SRC=$(wildcard **/*.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
OOBJ=$(addprefix $(OBJDIR)/, $(OBJ))

all: $(APP)

$(APP): main.cpp $(OOBJ)
	$(CXX) $(CXXFLAGS) main.cpp -o $(APP) $(OOBJ) $(LDFLAGS)
	./$(APP)

$(OBJDIR)/%.o: %.cpp %.h
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJDIR)/**/*.o
	rm -f $(APP)
