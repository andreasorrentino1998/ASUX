# Output config
TARGET_DIR = bin
ASUX_LIB = $(TARGET_DIR)/libASUX

# Compilator config
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Project source files
SOURCES = $(wildcard *.cpp) $(wildcard components/*.cpp) $(wildcard components/properties/*.cpp) $(wildcard utility/*.cpp)
OBJS = $(patsubst %.cpp,$(TARGET_DIR)/obj/%.o,$(SOURCES))

# Main rule
all: CREATE_OUTPUT_DIRS ASUX_LIB

# Create output directories
CREATE_OUTPUT_DIRS:
	mkdir -p $(TARGET_DIR)
	mkdir -p $(TARGET_DIR)/obj
	mkdir -p $(TARGET_DIR)/obj/components
	mkdir -p $(TARGET_DIR)/obj/components/properties
	mkdir -p $(TARGET_DIR)/obj/utility

# Build the static library
ASUX_LIB: $(OBJS)
	ar rcs $(TARGET_DIR)/libASUX.a $(OBJS)

# Compilation rule
$(TARGET_DIR)/obj/%.o: %.cpp %.h
	mkdir -p $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(MAIN_EXE) $(OBJS)