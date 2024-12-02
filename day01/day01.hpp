#ifndef DAY01_HPP
#define DAY01_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "../globals/input_handler.hpp"

bool comp(int a, int b)
{
  return a <= b;
}

class Day01
{
private:
  std::string filepath;
  INPUT_HANDLER_HPP::InputRaw<std::string> *lines;
  std::vector<int> left_list;
  std::vector<int> right_list;

public:
  Day01()
  {
    filepath = "input";
    lines = new INPUT_HANDLER_HPP::InputRaw<std::string>(filepath);
    for (int i = 0; i < lines->len(); i++)
    {
      std::string line = lines->get(i);
      std::stringstream ss(line);
      int num;
      std::vector<int> nums;
      while (ss >> num)
      {
        nums.push_back(num);
      }
      left_list.push_back(nums.at(0));
      right_list.push_back(nums.at(1));
    }
  };

  Day01(std::string fp)
  {
    filepath = fp;
    lines = new INPUT_HANDLER_HPP::InputRaw<std::string>(filepath);
    for (int i = 0; i < lines->len(); i++)
    {
      std::string line = lines->get(i);
      std::stringstream ss(line);
      int num;
      std::vector<int> nums;
      while (ss >> num)
      {
        nums.push_back(num);
      }
      left_list.push_back(nums.at(0));
      right_list.push_back(nums.at(1));
    }
  };

  ~Day01()
  {
    delete lines;
    lines = nullptr;
  };

  void sort_left() {
    std::sort(left_list.begin(), left_list.end(), comp);
  }

  void sort_right() {
    std::sort(right_list.begin(), right_list.end(), comp);
  }

  void vector_sort()
  {
    sort_left();
    sort_right();
  }

  int len() {
    return lines->len();
  }

  int get_left(int index) {
    return left_list.at(index);
  }

  int get_right (int index) {
    return right_list.at(index);
  }
};

#endif