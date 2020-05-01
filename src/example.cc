// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/example.h>

#include <iostream>
#include <string>

namespace mylibrary {

using std::string;


  void example::get_equation() {
    std::cout << example::equation;
  }
  void example::print(string input) {
    std::cout << "Text: " << input << std::endl;
  }

  void example::solve(std::string given_equation) {

  }
}  // namespace mylibrary
