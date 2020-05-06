// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/icesolver.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace mylibrary {

using std::string;

  std::string IceSolver::GetEquation() {
    return IceSolver::equation;
  }

  void IceSolver::Solve(std::string given_equation) {
    // Vector that contains the reactant concentrations
    std::vector<double> reactant_concentrations;
    reactant_concentrations = {0.20};

    // Vector that contains the product concentrations
    std::vector<double> product_concentrations;
    product_concentrations = {0.0, 0.0};

    double Ka = 0.000018;

    // Can take a shortcut if Ka or Kb is small or big enough
    if (Ka < 0.0001 || Ka > 0.0001) {
      double reactants_multiplied = 1;
      for (size_t i = 0; i < reactant_concentrations.size(); i++) {
        reactants_multiplied *= reactant_concentrations[i];
      }

      // Represents the value x shown in the Ice Table, also
      // the change in concentration
      double change_concentration = sqrt(Ka * reactants_multiplied);

      std::cout << "Change in concentration: " << change_concentration
                << std::endl;
    }

  }

  double IceSolver::SolveQuadratic(std::string given_equation) {
    // https://stackoverflow.com/questions/20755140/split-string-by-a-character
    // Handles splitting the equation around the '+' character and stores each
    // expression into a vector of strings
    std::vector<string> equation_expressions;
    std::replace(given_equation.begin(), given_equation.end(), '+',
        ' ');
    std::stringstream ss(given_equation);
    std::string temp_str;

    // Stores each expression into an array
    while (ss >> temp_str) {
      equation_expressions.push_back(temp_str);
    }

    // Represents the three indexes in equation_expressions
    const size_t kFirstExpression = 0;
    const size_t kSecondExpression = 1;
    const size_t kThirdExpression = 2;
    const double kDefaultCoefficient = 1.0;

    // Variables to help solve quadratic formula
    // Quadratic Formula: (-b + (b^2 - 4ac)^0.5) / 2a
    double a;
    double b;
    double c;

    // Populates variables a,b,c with actual coefficients from the given
    // equation
    if (equation_expressions[kFirstExpression].at(0) == 'x') {
      a = kDefaultCoefficient;
    } else {
      // Set variables to help solve the quadratic equation
      string first_expression = equation_expressions[kFirstExpression];
      a = atof(first_expression.substr(0, first_expression.find(
          'x')).c_str());
    }
    string second_expression = equation_expressions[kSecondExpression];
    b = atof(second_expression.substr(0, second_expression.find(
        'x')).c_str());
    c = atof(equation_expressions[kThirdExpression].c_str());

    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;



    double positive_root = (-b + sqrt((pow((b) , 2) - (4 * a * c))) )
        / (2*a);
    double negative_root = (-b - sqrt((pow((b) , 2) - (4 * a * c))) )
        / (2*a);

    std::cout << "Positive root: " << positive_root << std::endl;
    std::cout << "Negative root: " << negative_root << std::endl;

    return negative_root;
  }
}  // namespace mylibrary
