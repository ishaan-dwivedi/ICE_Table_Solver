// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/example.h>

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

namespace mylibrary {

using std::string;


  std::string example::GetEquation() {
    return example::equation;
  }

  void example::Print(string input) {
    std::cout << "Text: " << input << std::endl;
  }

  void example::Solve(std::string given_equation) {
    // Vector that contains the reactant concentrations
    std::vector<double> reactant_concentrations;
    reactant_concentrations = {0.20};

    // Vector that contains the product concentrations
    std::vector<double> product_concentrations;
    product_concentrations = {0.0, 0.0};

    // Represents the value x shown in the Ice Table, also
    // the change in concentration
    double change;




  }
}  // namespace mylibrary
