//
// Created by IshimotoKiko on 2020/11/30.
//
#include <iostream>
#include <memory>

extern "C" {
  double calculation(double a, double b)  {
    return a+b;
  }
}