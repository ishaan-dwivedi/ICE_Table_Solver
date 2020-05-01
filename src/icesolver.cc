// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/icesolver.h>

#include <cmath>
#include <iostream>
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
}  // namespace mylibrary
