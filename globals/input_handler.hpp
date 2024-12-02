#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class InputRaw
{
  private:
    std::vector<T> data;

  public:
    InputRaw(std::string filepath) {
      std::ifstream inputFile(filepath);

      if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
      }

      std::string line;
      while (std::getline(inputFile, line)) {
        data.push_back(line);
      }
    };

    T get(int index) {
      return data.at(index);
    };

    int len() {
      return data.size();
    }
};

#endif
