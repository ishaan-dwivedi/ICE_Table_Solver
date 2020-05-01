//
// Created by Ishaan Dwivedi on 5/1/20.
//

#ifndef FINALPROJECT_INCLUDE_ICESOLVER_H_
#define FINALPROJECT_INCLUDE_ICESOLVER_H_

namespace solver {

class IceSolver {
 private:std::string equation;

  IceSolver(std::string set_equation) {
    equation = set_equation;
  }

  void print();

  void solve();
};
}


#endif  // FINALPROJECT_INCLUDE_ICESOLVER_H_
