// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <CinderImGui.h>
#include <cinder/app/App.h>
#include <cinder/gl/wrapper.h>
#include <mylibrary/icesolver.h>

using namespace ci;

struct Object {

  vec2 getPosition() const { return mPosition; }
  void setPosition( const ci::vec2& position ) { mPosition = position; }

  std::string mName;
  Color	mColor;
  vec2	mPosition;
  float	mSize;
};

namespace myapp {

using cinder::app::KeyEvent;

mylibrary::IceSolver sample_problem("HNO3 -> NO3 + H+");


MyApp::MyApp() { }

void MyApp::setup() {
  ui::initialize();
  ImGui::initialize();
  sample_problem.Solve("");
  double c = sample_problem.SolveQuadratic("x^2+-10x+21");
  std::cout << c;
}

void MyApp::update() {


}

void MyApp::draw() {
  cinder::gl::clear();

  ImGui::InputText("Eq","Enter equation", 50);
  ui::Button("Submit", vec2( 100.0f ));
  std::string eq = sample_problem.GetEquation();
  ImGui::Text(eq.c_str());
  //ui::InputText()
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
