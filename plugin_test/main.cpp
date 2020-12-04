#include <iostream>
#include <dlfcn.h>
#include "plugin_header.hpp"

int main(int argc, char **argv) {
  const auto addlib = dlopen("./libSharedAdd.dylib", RTLD_LAZY);
  const auto sublib = dlopen("./libSharedSub.dylib", RTLD_LAZY);

  auto addfunc = (PluginInterfaceCreateFunction*)(dlsym(addlib, "Create"));
  auto subfunc = (PluginInterfaceCreateFunction*)(dlsym(sublib, "Create"));

  double a =  100;
  double b =  30;
  {
    const auto& add = addfunc();
    std::cout << "lib = " << add->libID() << std::endl;
    std::cout << "a+b = " << add->calculation(a,b) << std::endl;
  }
  {
    const auto& sub = subfunc();
    std::cout << "lib = " << sub->libID() << std::endl;
    std::cout << "a-b = " << sub->calculation(a,b) << std::endl;
  }
  dlclose(addlib);
  dlclose(sublib);
}