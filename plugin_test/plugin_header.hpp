//
// Created by IshimotoKiko on 2020/11/30.
//

#ifndef PLAGUIN_TEST_PLUGIN_HEADER_HPP
#define PLAGUIN_TEST_PLUGIN_HEADER_HPP

#include <memory>

class PluginInterface{
public:
  virtual ~PluginInterface()= default;
  virtual int libID() =0;
  virtual double calculation(double a, double b) =0;
};

typedef std::unique_ptr<PluginInterface> PluginInterfaceCreateFunction();

#endif // PLAGUIN_TEST_PLUGIN_HEADER_HPP
