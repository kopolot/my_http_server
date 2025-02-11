CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build.bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET = server

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
