#include <iostream>
#include <vector>
#include <fstream>
#include "functions.h"

int main() {


  int count = 0;  //to count number of instruction sets
  unsigned int left1=0, left2=0, right1=0, right2=0, up1=0, up2=0, down1=0, down2=0;
  unsigned int left, right, up, down, x_size, y_size; //for final vector
  std::string line;
  std::ifstream fin("D:/c++/adventofcode/files/day3.txt");
  std::vector<std::string> instructions;

  //open file, read contents
  while(getline(fin,line)) {
    count++;
    instructions = (makeInstr(line));
    std::cout << "Instruction set: " << count << std::endl;
    int *x_axis = getSize(instructions, "x");
    int *y_axis = getSize(instructions, "y");

    if (count == 1) {
      left1 = x_axis[1];
      right1 = x_axis[0] - x_axis[1];
      up1 = y_axis[0] - y_axis[1];
      down1 = y_axis[1];
    }
    else {
      left2 = x_axis[1];
      right2 = x_axis[0] - x_axis[1];
      up2 = y_axis[0] - y_axis[1];
      down2 = y_axis[1];
    }

    std::cout << "Size of x axis: " << x_axis[0] << " start point: " << x_axis[1] << std::endl;
    std::cout << "Size of y axis: " << y_axis[0] << " start point: " << y_axis[1] << std::endl;

  }
  fin.close();

  //take biggest distances for each axis direction
  left = (left1 > left2) ? left1 : left2 ;  //x_start point
  right = (right1 > right2) ? right1 : right2;
  up = (up1 > up2) ? up1 : up2;
  down = (down1 > down2) ? down1 : down2; //y_start point

  //determine final size
  x_size = left+right;
  y_size = up+down;

  std::cout << "final size of vector is\n" << "x axis: " << x_size << "\ny_axis: " << y_size << std::endl;
  std::cout << "starting points\n" << "x: " << left << " and y: " << down << std::endl;

}
