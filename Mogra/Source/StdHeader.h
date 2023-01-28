#pragma once

/// include Lib 
#pragma comment (lib, "glfw3.lib")
#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glew32s.lib")
//#pragma comment (lib, "assimp.lib")
//#pragma comment (lib, "freetype.lib")
//#pragma comment (lib, "")
//assimp - vc142 - mtd.lib

#define WINDOW_TITLE  "Mogra Editor"
#define WIN_WIDTH_HD 1920
#define WIN_HEIGTH_HD 1080
#define WIN_WIDTH 800
#define WIN_HEIGTH 600

// Windows Header Files:
#include <windows.h>

// standard header -----------
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>

// OpenGL related 
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

