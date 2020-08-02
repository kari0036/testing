#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class directoryContent {
public:
  directoryContent();
  directoryContent(char dir[]);
  std::vector<fs::path> getFilesInDirectory() const;
  std::map<std::string, std::vector<std::string>> getFileNameAndContentMap() const;
private:
  fs::path directory_;
  std::vector<fs::path> filesInDirectory;
  void searchFilesInDirectory();
  void sortFilesInVector();
  void readFiles();
  std::map<std::string, std::vector<std::string>> fileNameAndContentMap;
};
