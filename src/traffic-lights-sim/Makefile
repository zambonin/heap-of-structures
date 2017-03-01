CXXFLAGS = -Wall -Wextra -std=c++11 -I include -I .. -I ../../include
OUTPUT = simulator

default:
	@$(CXX) $(CXXFLAGS) $(wildcard src/*.cpp) -o $(OUTPUT)

debug:
	@$(CXX) -g $(CXXFLAGS) $(wildcard src/*.cpp) -o $(OUTPUT)

clean:
	@rm $(OUTPUT)
