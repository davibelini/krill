#include "../include/vm.h"

int main() {
  krillvm vm;
  vector<i32> prog{
    3, 4, 0x4000001, 0x4000000
  };
  vm.loadprogram(prog);
  vm.run();
};