CXX = g++

BUILD_DIR = ./build
SOURCE_DIR = ./src

ENGINE_FILES = $(SOURCE_DIR)/Lib/Engine/Entity.cpp \
							  $(SOURCE_DIR)/Lib/Engine/Scene.cpp

build:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(ENGINE_FILES) ./src/main.cpp -o $(BUILD_DIR)/main

clean:
	rm -r $(BUILD_DIR)
