#include "directoryContent.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
char dir[] = "../scores";
directoryContent ScoresFolder(dir); 

  return 0;
}

