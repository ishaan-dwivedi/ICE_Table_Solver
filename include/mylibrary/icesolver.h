// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <string>
namespace mylibrary {
  class IceSolver {
    private: std::string problem_data;

    // Should read in an equation as well as initial concentrations and a Ka
    // value in order to solve an Ice Table problem.
    public:
     IceSolver(std::string set_problem_data) {
      problem_data = set_problem_data;
    }

    public:
      /**
       * Generate a string with the solved problem in the proper format that
       * can be displayed on a GUI.
       * @return - String that represents a displayable solved Ice Table
       */
      std::string GenerateDisplay();

      /**
       * Should properly populate the class variables with the given equation
       * data
       * @param given_data - String containing equation data
       * @return - A vector with all the information parsed in its own index
       */
      std::vector<std::string> PopulateEquationData(std::string given_data);

      /**
       * Should return a possible root that satisfies a quadratic equation and
       * the Ice Table
       * @param given_equation - Quadratic equation given
       * @return - A possible root
       */
      double SolveQuadratic(std::string given_equation);


      /**
       * Should output a solved ice table
       *
       * ICE Table icesolver:
       *
       * Equation: HC2H3O2 -> H+ + C2H3O2-
       * This icesolver uses an acid so a Ka expression is needed
       * Ka should be given or can be looked up
       *
       * Ka = ([H+][C2H3O2-]) / [HC2H3O2] = 1.8 * 10^-5
       *
       *                [HC2H3O2]       [H+]        [C2H3O2-]
       * Initial          0.20          0.0            0.0
       *
       * Change            -x           +x             +x
       *
       * Equilibrium    0.20 - x        x              x
       *
       * Solve for x to find equilibrium concentrations
       *
       * @param given_equation - Equation to solve
       * @return - The change in concentration
       */
      double SolveIceTable(std::string given_equation);

      std::string GetProblemData();

  };


}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
