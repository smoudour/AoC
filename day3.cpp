#include <iostream>
#include <vector>
#include <fstream>
#include "functions.h"

int main() {

  //open file, read contents
  std::string line;
  std::ifstream fin("D:/c++/adventofcode/files/day3.txt");
  std::vector<std::string> instructions;

  while(getline(fin,line)) {

    instructions = (makeInstr(line));
    for (int i=0; i != instructions.size(); ++i) {
      std::cout << instructions[i].size() << std::endl;
    }
    std::cout << line << " kai kourada" << std::endl;
  }

  fin.close();
}
