#include <iostream>
#include "day01.hpp"
#include <string>
#include <cmath>

int main()
{
  std::string filepath = "input";

  DAY01_HPP::Day01 part_one(filepath);
  part_one.vector_sort();
  int results_pt1 = 0;
  for (int i = 0; i < part_one.len(); i++)
  {
    int left = part_one.get_left(i);
    int right = part_one.get_right(i);
    // std::cout << "difference: " << left << " - " << right << " = " << left - right << std::endl;
    results_pt1 += std::abs(left - right);
  }

  std::cout << "Results for Part One: " << results_pt1 << std::endl;

  DAY01_HPP::Day01 part_two(filepath);

  part_two.sort_right();

  int results_pt2 = 0;

  for (int i = 0; i < part_two.len(); i++)
  {
    int left = part_two.get_left(i);
    int incr = 0;
    for (int j = 0; j < part_two.len(); j++) {
      int right = part_two.get_right(j);
      if (left == right) {
        incr++;
      }
      else if (left < right) {
        break;
      }
    }

    results_pt2 += left * incr;
  }

  std::cout << "Results for Part Two: " << results_pt2 << std::endl;
}