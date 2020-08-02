#include "directoryContent.hpp"
#include <algorithm>
#include <fstream>
namespace fs = std::filesystem;

directoryContent::directoryContent(char dir[]) {
  fs::path directory(dir);
  directory_ = directory;
  searchFilesInDirectory();
  sortFilesInVector();
  readFiles();
};

void directoryContent::searchFilesInDirectory() {
  if (fs::exists(directory_) && fs::is_directory(directory_)) {
    for (auto const &entry : fs::directory_iterator(directory_)) {
      auto pathName = entry.path();
      if (fs::is_regular_file(entry.status()))
        filesInDirectory.emplace_back(entry.path());
      else if (fs::is_directory(entry.status())) {
        std::cout << "You have some unknow folder named:" << pathName.filename()
                  << std::endl;
      }
    }
  }
}

void directoryContent::sortFilesInVector() {
  std::sort(filesInDirectory.begin(), filesInDirectory.end());
}

std::vector<fs::path> directoryContent::getFilesInDirectory() const {
  return filesInDirectory;
}

std::map<std::string, std::vector<std::string>>
directoryContent::getFileNameAndContentMap() const {
  return fileNameAndContentMap;
}

void directoryContent::readFiles() {
  for (auto &el : filesInDirectory) {
    std::vector<std::string> fileContentVector;
    std::ifstream myFile;
    myFile.open(el);
    if (myFile.is_open() && !fs::is_empty(el)) {
      std::string temporaryLine;
      while (getline(myFile, temporaryLine)){
        if(temporaryLine == " ") break;
        else fileContentVector.emplace_back(temporaryLine);
      }
    }
    fileNameAndContentMap.insert(
        std::pair<std::string, std::vector<std::string>>(el.filename(),
                                                         fileContentVector));
    myFile.close();
  }
  
}
