APP=odyssey
CXX=g++
CXXFLAGS= -std=c++11 -g
OBJDIR=.obj

SRC=$(wildcard **/*.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
OOBJ=$(addprefix $(OBJDIR)/, $(OBJ))

all: $(APP)

$(APP): main.cpp $(OOBJ)
	$(CXX) $(CXXFLAGS) main.cpp -o $(APP) $(OOBJ)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/**/*.o
	rm -f $(APP)

