#include <iostream>
#include <dlfcn.h>


int main(int argc, char **argv) {
  const auto addlib = dlopen("./libSharedAdd.dylib", RTLD_LAZY);
  const auto sublib = dlopen("./libSharedSub.dylib", RTLD_LAZY);

  auto Add = reinterpret_cast<double(*)(double, double)>(dlsym(addlib, "calculation"));
  auto Sub = reinterpret_cast<double(*)(double, double)>(dlsym(sublib, "calculation"));

  double a =  100;
  double b =  30;
  {
    std::cout << "a+b = "<< Add(a,b) << std::endl;
  }
  {
    std::cout << "a-b = "<< Sub(a,b) << std::endl;
  }
  dlclose(addlib);
  dlclose(sublib);
}