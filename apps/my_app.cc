// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <CinderImGui.h>
#include <cinder/app/App.h>
#include <cinder/gl/wrapper.h>
#include <mylibrary/icesolver.h>

using namespace ci;

namespace myapp {

using cinder::app::KeyEvent;

//mylibrary::IceSolver example_problem(
//    "HNO3:->:NO3-:+:H+, 0.534, 0.00, 0.00, 1.8e-04");
mylibrary::IceSolver example_problem(
    "HC2H3O2:->:C2H3O2-:+:H+, 0.20, 0.00, 0.00, 1.8e-05");
//mylibrary::IceSolver example_problem(
//    "HA:->:A-:+:H+, 0.150, 0.00, 0.00, 1.6e-02");
//mylibrary::IceSolver example_problem(
//    "PCl5:->:PCl3:+:Cl2, 1.0, 0.00, 0.00, 0.0211");


const char* kScreenTitle = "ICE Table Solver";

MyApp::MyApp() { }

void MyApp::setup() {
  ui::initialize();
  ImGui::initialize();
  example_problem.SolveIceTable(example_problem.GetProblemData());
}

void MyApp::update() {


}

void MyApp::draw() {
  cinder::gl::clear();

  // Display the solved Ice Table
  std::string display = example_problem.GenerateDisplay();
  ImGui::SetWindowFontScale(1.7);
  ImGui::Text(kScreenTitle);
  ImGui::SetWindowFontScale(1.3);
  ImGui::Text(display.c_str());
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
