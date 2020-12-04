
#include <iostream>
#include <memory>

extern "C" {
  double calculation(double a, double b)  {
    return a+b;
  }
}