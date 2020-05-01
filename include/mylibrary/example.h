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
       * Prints the give
       * @param str
       */
      void print(std::string str);

      void solve(std::string given_equation);

      void get_equation();

  };


}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
