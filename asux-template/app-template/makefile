# Output config
TARGET_DIR = bin
MAIN_EXE = $(TARGET_DIR)/main

# Compilator config
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ASUX Framework
ASUX_INCLUDE = -I/usr/local/include/ASUX/
ASUX_LIB = -L/usr/local/lib/ASUX-1.0 -lASUX

# Project dependencies
MAIN_LIBS = $(ASUX_LIB)
MAIN_HEADERS = $(ASUX_INCLUDE)

# Project source files
COMPONENTS_SOURCES = $(wildcard components/*.cpp)
VIEW_SOURCES = $(wildcard views/*.cpp)
SOURCES = main.cpp $(COMPONENTS_SOURCES) $(VIEW_SOURCES)

OBJS = $(patsubst %.cpp,$(TARGET_DIR)/obj/%.o,$(SOURCES))

# Main rule
all: CREATE_OUTPUT_DIRS $(MAIN_EXE)

# Create output directories
CREATE_OUTPUT_DIRS:
	mkdir -p $(TARGET_DIR)
	mkdir -p $(TARGET_DIR)/obj/
	mkdir -p $(TARGET_DIR)/obj/components
	mkdir -p $(TARGET_DIR)/obj/views

# Build the main executable
$(MAIN_EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN_EXE) $(MAIN_LIBS)

# Compilation rule
$(TARGET_DIR)/obj/%.o: %.cpp
	mkdir -p $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(MAIN_HEADERS)

clean:
	rm -rf $(MAIN_EXE) $(OBJS)