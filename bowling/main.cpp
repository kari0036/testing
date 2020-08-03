#include "DirectoryContent.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
char dir[] = "../scores";
DirectoryContent ScoresFolder(dir); 

  return 0;
}

