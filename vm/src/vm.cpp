#include "../include/vm.h"

/*
 *  instruction format:
 *  header: 2 bits
 *  data: 30 bits
 * 
 *  header format: 
 *  0 => positive integer
 *  1 => primitive instruction
 *  2 => negative integer
 *  3 => undefined
 * 
 *  
*/


krillvm::krillvm() {
  memory.reserve(1000000);
};

i32 krillvm::gettype(i32 instruction) {
  i32 type = 0xc0000000; // 4 bytes (32 bits)
  type = (type & instruction) >> 30;
  return type;
};

i32 krillvm::getdata(i32 instruction) {
  i32 data = 0x3fffffff;
  data = data & instruction;
  return data;
};

void krillvm::fetch() {
  pc++;
};

void krillvm::decode() {
  type = gettype(memory[pc]);
  data = getdata(memory[pc]);
};

void krillvm::execute() {
  if(type == 0 || type == 2) {
    sp++;
    memory[sp] = data;
  }
  else {
    primitive();
  };
};

void krillvm::primitive() {
  switch(data) {
    case 0: { // break
      cout << "break" << endl;
      running = 0;
      break;
    }
    
    case 1: { // add
      cout << "add " << memory[sp - 1] << " " << memory[sp] << endl;
      memory[sp - 1] = memory[sp - 1] + memory[sp];
      sp--;
      break;
    };
  };
};

void krillvm::run() {
  pc--;
  while(running == 1) {
    fetch();
    decode();
    execute();
    cout << "top of stack => " << memory[sp] << endl;
    pc++;
  };
};

void krillvm::loadprogram(vector<i32> program) {
  for(i32 i = 0; i < program.size(); i++) {
    memory[pc + i] = program[i];
  };
};