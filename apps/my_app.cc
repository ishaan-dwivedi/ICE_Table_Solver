// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <CinderImGui.h>
#include <cinder/app/App.h>
#include <cinder/gl/wrapper.h>
#include <mylibrary/icesolver.h>

using namespace ci;

namespace myapp {

using cinder::app::KeyEvent;

mylibrary::IceSolver sample_problem("HNO3->NO3-+H+, 0.534, 0.00, 0.00, 1.8e-04");


MyApp::MyApp() { }

void MyApp::setup() {
  ui::initialize();
  ImGui::initialize();
  sample_problem.SolveIceTable(sample_problem.GetProblemData());
}

void MyApp::update() {


}

void MyApp::draw() {
  cinder::gl::clear();

  std::string eq = sample_problem.GetProblemData();
  eq += "\n klk ";
  ImGui::Text(eq.c_str());
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
