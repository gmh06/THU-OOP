CXX ?= g++
CXXFLAGS ?= -std=c++17 -I.
VERSION ?= 1

game_skill: main.cpp GameSkill.h LegacySkill.cpp LegacySkill.h variants/GameSkill_rollout_$(VERSION).cpp
	$(CXX) $(CXXFLAGS) main.cpp LegacySkill.cpp variants/GameSkill_rollout_$(VERSION).cpp -o $@

.PHONY: game_skill clean
clean:
	rm -f game_skill *.o
