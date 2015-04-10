CXX = g++
TARGET = main
#TARGET = main_p
#TARGET = main_e
#CXXFLAGS = -Wall -O2 -std=c++11 -I include -MMD -MP
#CXXFLAGS = -O2 -std=c++11 -I include -MMD -MP
CXXFLAGS = -O2 -std=c++11 -I . -MMD -MP
#OPENCVLIB = `pkg-config --libs opencv`
#BOOSTLIB = -lboost_serialization -lboost_program_options -lboost_filesystem -lboost_system
#OPENCVCFLG = `pkg-config --cflags opencv`
#CXXFLAGS += $(OPENCVCFLG)
#LDFLAGS += $(OPENCVLIB)
#LDFLAGS += $(BOOSTLIB)
#INCLUDES = src src/IO src/PIRF src/PIRF/SimilarityCalc src/Setting
INCLUDES = .
EXCLUDES =
SRCS := $(wildcard $(addsuffix /*.cpp, $(INCLUDES)))
SRCS := $(filter-out $(wildcard $(EXCLUDES)), $(SRCS))
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

.PHONY: all
all: $(TARGET)

-include $(DEPS)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(OBJINCS)

.PHONY: clean list
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

list:
	echo $(SRCS)
