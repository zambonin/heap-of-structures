CXXFLAGS = -Wall -Wextra -march=native -O2 -I include
SIMDIR = "src/traffic-lights-sim"
SOURCES = $(basename $(wildcard src/*.hpp))

default: $(SOURCES) traffic

%: %.hpp
	@$(CXX) $(CXXFLAGS) $^ -o $@

traffic:
	@$(MAKE) -s -C $(SIMDIR)

clean:
	@$(MAKE) -s -C $(SIMDIR) clean
	@rm $(SOURCES)
