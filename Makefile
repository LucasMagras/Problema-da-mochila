TARGET = mochila
CXX = g++
LIBS = -lm
CXXFLAGS = -g -Wall
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo 'Linking binary: $@'
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo 'Finished building binary: $@'
	@echo ' '

%.o: %.cpp %.h
	@echo 'Compiling: $<'
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo ' '

clean:
	@echo 'Cleaning project...'
	rm -f $(TARGET) $(OBJECTS)
	@echo 'Done.'
