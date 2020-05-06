// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/icesolver.h>

#include <catch2/catch.hpp>

// Received problem from this site
// https://openstax.org/books/chemistry-2e/pages/13-4-equilibrium-calculations
mylibrary::IceSolver test_solver(
    "PCl5:->:PCl3:+:Cl2, 1.0, 0.00, 0.00, 0.0211");
std::vector<std::string> test_equation_data;

TEST_CASE("Quadratic solver test", "[quadratic]") {
  double positive_root = test_solver.SolveQuadratic("x^2+6x+-27");
  REQUIRE(positive_root == 3);
}

TEST_CASE("Get problem test", "[get-problem]") {
  std::string test_problem = test_solver.GetProblemData();
  REQUIRE(test_problem == "PCl5:->:PCl3:+:Cl2, 1.0, 0.00, 0.00, 0.0211");
}

TEST_CASE("Populate equation data test", "[populate-equation-data]") {
  test_equation_data.push_back("PCl5:->:PCl3:+:Cl2");
  test_equation_data.push_back("1.0");
  test_equation_data.push_back("0.00");
  test_equation_data.push_back("0.00");
  test_equation_data.push_back("0.0211");

  REQUIRE(test_equation_data ==
  test_solver.PopulateEquationData(test_solver.GetProblemData()));
}