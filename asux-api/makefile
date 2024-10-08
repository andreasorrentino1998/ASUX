# ASUX: A lightweight C++ reactive framework for building terminal-based applications. 
#
# Authors:
# © 2024 - Andrea Sorrentino
# 
# ASUX is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#  
# ASUX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along with ASUX.
# If not, see <http://www.gnu.org/licenses/>.

# Output config
TARGET_DIR = bin
ASUX_LIB = $(TARGET_DIR)/libASUX.a

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
	ar rcs $(ASUX_LIB) $(OBJS)

# Compilation rule
$(TARGET_DIR)/obj/%.o: %.cpp %.h
	mkdir -p $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(ASUX_LIB) $(OBJS)