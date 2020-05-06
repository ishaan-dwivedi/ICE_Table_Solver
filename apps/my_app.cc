// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <CinderImGui.h>
#include <cinder/app/App.h>
#include <cinder/gl/wrapper.h>
#include <mylibrary/icesolver.h>

using namespace ci;

namespace myapp {

using cinder::app::KeyEvent;

mylibrary::IceSolver sample_problem("HNO3 -> NO3 + H+, 0.20, 0.00, 0.00, 0.000018");


MyApp::MyApp() { }

void MyApp::setup() {
  ui::initialize();
  ImGui::initialize();
  sample_problem.SolveIceTable("");
  sample_problem.PopulateEquationData("HNO3->NO3-+H+, 0.20, 0.00, 0.00, 0.000018");
  double c = sample_problem.SolveQuadratic("-2x^2+-8x+100");
  std::cout << c;
}

void MyApp::update() {


}

void MyApp::draw() {
  cinder::gl::clear();

  ImGui::InputText("Eq","Enter equation", 50);
  ui::Button("Submit", vec2( 100.0f ));
  std::string eq = sample_problem.GetProblemData();
  ImGui::Text(eq.c_str());
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
