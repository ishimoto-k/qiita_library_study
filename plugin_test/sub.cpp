
#include <iostream>
#include <memory>
#include "plugin_header.hpp"


class Sub : public PluginInterface {
public:
  Sub() {
    std::cout << "Sub was create." << std::endl;
  }
  ~Sub() {
    std::cout << "Sub delete." << std::endl;
  }
  int libID() override {
    return 2;
  }

  double calculation(double a, double b) override {
    return a-b;
  }
};
extern "C" unique_ptr<PluginInterface> Create() {
  return std::unique_ptr<PluginInterface>(new Sub);
}