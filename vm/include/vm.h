#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>

using namespace std;

//typedef
typedef int32_t i32;

class krillvm {
  i32 pc = 100;
  i32 sp = 0;
  vector<i32> memory;
  i32 type = 0;
  i32 data = 0;
  i32 running = 1;

  // private
  i32 gettype(i32 token);
  i32 getdata(i32 token);
  void fetch();
  void decode();
  void execute();
  void primitive();
  
  public:
  krillvm();
  void run();
  void loadprogram(vector<i32> prog);
};

#endif // VM_H