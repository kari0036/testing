#define CATCH_CONFIG_MAIN
#include "../directoryContent.hpp"
#include "catch.hpp"
#include <iostream>
namespace fs = std::filesystem;

SCENARIO("SearchingFilesAndFileContentInDirectory") {

  GIVEN("Created directoryContent object and fake vector just for comparison") {
    char dir[] = "../scores";
    directoryContent scores(dir);
    std::vector<fs::path> expectedDirectoryContent;
    fs::path dir1("../scores/lane1");
    fs::path dir2("../scores/lane2");
    fs::path dir3("../scores/lane3");
    expectedDirectoryContent.emplace_back(dir1);
    expectedDirectoryContent.emplace_back(dir2);
    expectedDirectoryContent.emplace_back(dir3);
    std::map<std::string, std::vector<std::string>> const expectedMap{
        {"lane1", {"Name1:X|4-|3", "Name2:34|X|0-", ":X|22|33"}},
        {"lane2", {}},
        {"lane3",
         {"Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81",
          "Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"}}};
    WHEN("Iterate through directory") {
      THEN("Check if function found all files") {
        REQUIRE_THAT(expectedDirectoryContent,
                     Catch::Matchers::Equals(scores.getFilesInDirectory()));
      }
    }
    WHEN("ReadFiles") {
      THEN("MapWithFileNameAndFileContentFilled") {
        auto originalMap = scores.getFileNameAndContentMap();
/*         for (const auto &[k, v] : expectedMap) {
          std::cout << "Expected Map: " << k << '\n';
          std::cout << "Expected Vector: \n";
          for (auto &string : v) {
            std::cout << string << '\n';
          }
          std::cout << "Original Map: " << originalMap.find(k)->first << '\n';
          std::cout << "Original Vector: \n";
          for (auto &string : originalMap.find(k)->second) {
            std::cout << string << '\n';
          }
        } */
        REQUIRE(expectedMap == scores.getFileNameAndContentMap());
      }
    }
  }
}
