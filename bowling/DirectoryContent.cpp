#include "DirectoryContent.hpp"
#include <fstream>
namespace fs = std::filesystem;

DirectoryContent::DirectoryContent(char dir[]) {
  fs::path directory(dir);
  directory_ = directory;
  searchFilesInDirectory();
  sortFilesInVector();
  readFiles();
};

void DirectoryContent::searchFilesInDirectory() {
  if (fs::exists(directory_) && fs::is_directory(directory_)) {
    for (auto const &entry : fs::directory_iterator(directory_)) {
      auto pathName = entry.path();
      if (fs::is_regular_file(entry.status()))
        filesInDirectory_.emplace_back(entry.path());
    }
  }
}

void DirectoryContent::sortFilesInVector() {
  std::sort(filesInDirectory_.begin(), filesInDirectory_.end());
}

std::vector<fs::path> DirectoryContent::getFilesInDirectory() const {
  return filesInDirectory_;
}

std::map<std::string, std::vector<std::string>>
DirectoryContent::getFileNameAndContentMap() const {
  return fileNameAndContentMap_;
}

void DirectoryContent::readFiles() {
  for (auto &el : filesInDirectory_) {
    std::vector<std::string> fileContentVector;
    std::ifstream myFile;
    myFile.open(el);
    if (myFile.is_open() && !fs::is_empty(el)) {
      std::string temporaryLine;
      while (getline(myFile, temporaryLine)) {
        if (temporaryLine == " ")
          break;
        else
          fileContentVector.emplace_back(temporaryLine);
      }
    }
    fileNameAndContentMap_.insert(
        std::pair<std::string, std::vector<std::string>>(el.filename(),
                                                         fileContentVector));
    myFile.close();
  }
}
