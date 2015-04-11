CXX = g++
TARGET = main
CXXFLAGS = -O2 -std=c++11 -I . -MMD -MP
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
