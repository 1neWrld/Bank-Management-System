CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = bank
SOURCES = main.cpp bankaccount.cpp banksystem.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
