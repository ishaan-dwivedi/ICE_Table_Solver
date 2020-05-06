// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/icesolver.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace mylibrary {

using std::string;

  // Store the initial reactant concentrations
  std::vector<double> initial_reactant_concentrations;

  // Store the final reactant concentrations
  std::vector<double> final_reactant_concentrations;

  // Store the initial product concentrations
  std::vector<double> initial_product_concentrations;

  // Store the final product concentrations
  std::vector<double> final_product_concentrations;

  // Store the chemical equation
  std::string equation;

  // Store the given Ka value
  double ka_value;

  // Change in concentration
  double change_in_concentration;

  std::string IceSolver::GetProblemData() {
      return IceSolver::problem_data;
    }

  std::string IceSolver::GenerateDisplay() {
    std::string problem_to_display;

    // Handles separating the equation by reactant and product
    std::vector<string> equation_data;
    std::replace(equation.begin(), equation.end(), ':',
                 ' ');
    std::stringstream ss(equation);
    std::string temp_str;

    // Stores each expression into an array
    while (ss >> temp_str) {
      equation_data.push_back(temp_str);
    }

    // Displays the equation
    problem_to_display += "\n \n                ";
    for (size_t i = 0; i < equation_data.size(); i++) {
      problem_to_display += equation_data[i] + "       ";
    }

    // Displays the initial reactant and product concentrations
    problem_to_display += "\n \n \nInitial: ";
    for (size_t i = 0; i < initial_reactant_concentrations.size(); i++) {
      problem_to_display += "     " + std::to_string(initial_reactant_concentrations[i])
          + "            ";
    }
    for (size_t i = 0; i < initial_product_concentrations.size(); i++) {
      problem_to_display += std::to_string(initial_product_concentrations[i])
          + "          ";
    }

    // Displays the change in concentration
    problem_to_display += "\n \n \nChange: ";
    problem_to_display += "     -" + std::to_string(change_in_concentration);
    problem_to_display += "           +" +
        std::to_string(change_in_concentration);
    problem_to_display += "         +" + std::to_string(change_in_concentration);

    // Displays the final reactant and product concentrations
    problem_to_display += "\n \n \nEquilibrium: ";
    for (size_t i = 0; i < final_reactant_concentrations.size(); i++) {
      problem_to_display += " " + std::to_string(final_reactant_concentrations[i])
          + "            ";
    }
    for (size_t i = 0; i < final_product_concentrations.size(); i++) {
      problem_to_display += std::to_string(final_product_concentrations[i])
          + "          ";
    }

    return problem_to_display;
  }

  void IceSolver::SolveIceTable(std::string given_equation) {
    // Populate class variables used in solving Ice Tables
    PopulateEquationData(given_equation);

    // Builds quadratic string to be solved
    string quadratic_to_be_solved;
    quadratic_to_be_solved += "x^2+";
    quadratic_to_be_solved += std::to_string(ka_value);
    quadratic_to_be_solved += "x+-";
    double arithmetic_store = ka_value * initial_reactant_concentrations[0];
    quadratic_to_be_solved += std::to_string(arithmetic_store);

    // The change in concentration
    double change = SolveQuadratic(quadratic_to_be_solved);
    change_in_concentration = change;

    // Add the new reactant concentrations after the reaction is at
    // equilibrium.
    for (size_t i = 0; i < initial_reactant_concentrations.size(); i++) {
      double new_concentration = initial_reactant_concentrations[i] - change;
      final_reactant_concentrations.push_back(new_concentration);
    }

    // Add the new product concentrations after the reaction is at
    // equilibirum.
    for (size_t i = 0; i < initial_product_concentrations.size(); i++) {
      double new_concentration = initial_product_concentrations[i] + change;
      final_product_concentrations.push_back(new_concentration);
    }

    std::cout << "Change: " << change << std::endl;
  }

  std::vector<string> IceSolver::PopulateEquationData(std::string given_data) {
    std::vector<string> equation_data;
    std::replace(given_data.begin(), given_data.end(), ',',
                 ' ');
    std::stringstream ss(given_data);
    std::string temp_str;

    // Stores each expression into an array
    while (ss >> temp_str) {
      equation_data.push_back(temp_str);
    }

    // Populate class variables
    for (size_t i = 0; i < equation_data.size(); i++) {
      if (i == 0) {
        equation = equation_data[i];
      } else if (i == 1) {
        initial_reactant_concentrations.push_back(
            atof(equation_data[i].c_str()));
      } else if (i == 2) {
        initial_product_concentrations.push_back(
            atof(equation_data[i].c_str()));
      } else if (i == 3) {
        initial_product_concentrations.push_back(
            atof(equation_data[i].c_str()));
      } else if (i == 4) {
        ka_value = atof(equation_data[i].c_str());
      }
    }

    return equation_data;
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


    // Calculate both roots
    double positive_root = (-b + sqrt((pow((b) , 2) - (4 * a * c))) )
        / (2*a);
    double negative_root = (-b - sqrt((pow((b) , 2) - (4 * a * c))) )
        / (2*a);

    std::cout << "Positive root: " << positive_root << std::endl;
    std::cout << "Negative root: " << negative_root << std::endl;

    return positive_root;
  }
}  // namespace mylibrary
