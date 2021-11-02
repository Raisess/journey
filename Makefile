CXX = g++

BUILD_DIR = ./build
SOURCE_DIR = ./src
LIBENG_DIR = /Lib/Engine

ENGINE_FILES = $(SOURCE_DIR)$(LIBENG_DIR)/Utils/Debugger.cpp \
							 $(SOURCE_DIR)$(LIBENG_DIR)/Helpers/EntityManager.cpp \
							 $(SOURCE_DIR)$(LIBENG_DIR)/Entity.cpp \
							 $(SOURCE_DIR)$(LIBENG_DIR)/Physics.cpp \
							 $(SOURCE_DIR)$(LIBENG_DIR)/Scene.cpp

build:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(ENGINE_FILES) ./src/main.cpp -o $(BUILD_DIR)/main

clean:
	rm -r $(BUILD_DIR)
