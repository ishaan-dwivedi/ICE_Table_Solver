// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <string>
namespace mylibrary {
  class example {
    private: std::string equation;

    public: example(std::string set_equation) {
      equation = set_equation;
    }



    public:
      /**
       * Prints the given string
       * @param str
       */
      void print(std::string str);

      /**
       * Should output a solved ice table
       *
       * ICE Table example:
       *
       * Equation: HC2H3O2 -> H+ + C2H3O2-
       * This example uses an acid so a Ka expression is needed
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
       * @param given_equation - equation to solve
       */
      void solve(std::string given_equation);

      void get_equation();

  };


}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
