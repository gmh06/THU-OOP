CXX ?= g++
CXXFLAGS ?= -std=c++17 -I.
VERSION ?= 1

explore_system: main.cpp ExploreSystem.h variants/ExploreSystem_rollout_$(VERSION).cpp
	$(CXX) $(CXXFLAGS) main.cpp variants/ExploreSystem_rollout_$(VERSION).cpp -o $@

.PHONY: explore_system clean
clean:
	rm -f explore_system *.o
