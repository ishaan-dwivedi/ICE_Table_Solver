// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/icesolver.h>

#include <catch2/catch.hpp>

TEST_CASE("Quadratic solver test", "[quadratic]") {
  mylibrary::IceSolver test_solver("");
  double positive_root = test_solver.SolveQuadratic("x^2+6x+-27");
  REQUIRE(positive_root == 3);
}