#include <iostream>
#include <vector>
#include <fstream>
#include "functions.h"

//test
int test(std::vector<std::vector<int> > &layout){
  int counter = 0;
  for (unsigned i=0; i<layout.size(); ++i) {
    for (unsigned j=0; j<layout[i].size(); ++j) {
      if (layout[i][j] == 2) {
        ++counter;
      }
    }
  }
  return counter;
}

int main() {


  int count = 0;  //to count number of instruction sets
  int left1=0, left2=0, right1=0, right2=0, up1=0, up2=0, down1=0, down2=0;
  int left, right, up, down, x_size, y_size; //for final vector
  std::string line;
  std::ifstream fin("D:/c++/adventofcode/files/day3.txt");
  std::vector<std::string> instructions;

  //open file, read contents
  while(getline(fin,line)) {
    count++;
    instructions = makeInstr(line);
    std::cout << "Instruction set: " << count << std::endl;
    int *x_axis = getSize(instructions, "x"); //pointer to point first value of array result
    int *y_axis = getSize(instructions, "y");

    //auto mporw na to allaksw me ena dynamic array x seirwn, opou kathe collumn tha einai
    //sizes of each axis from cartesian point (0,0) --> [left, right, up, down]
    if (count == 1) {
      left1 = x_axis[1];
      right1 = x_axis[0] - x_axis[1];
      up1 = y_axis[0] - y_axis[1];
      down1 = y_axis[1];
    }
    else if (count == 2) {
      left2 = x_axis[1];
      right2 = x_axis[0] - x_axis[1];
      up2 = y_axis[0] - y_axis[1];
      down2 = y_axis[1];
    }

    std::cout << "Size of x axis: " << x_axis[0] << " start point: " << x_axis[1] << std::endl;
    std::cout << "Size of y axis: " << y_axis[0] << " start point: " << y_axis[1] << std::endl;

  }

  //take biggest distances for each axis direction
  //compare each direction size and take the largest
  //(here stupidly done only for two sets, can be improved to include X number of sets)
  left = (left1 > left2) ? left1 : left2 ;  //x_start point
  right = (right1 > right2) ? right1 : right2;
  up = (up1 > up2) ? up1 : up2;
  down = (down1 > down2) ? down1 : down2; //y_start point

  //determine final size
  //add the largest directions together, for each axis
  x_size = left+right;  //collumns
  y_size = up+down; //rows

  std::cout << x_size << " and " << y_size << std::endl;

  //construct vector
  std::vector<std::vector<int> > layout(y_size, std::vector<int>(x_size, 0));


  //test for non zero values
  std::cout << "number of occurences: " << test(layout) << std::endl;
  //draw
  // fin.clear();             //clear the buffer
  // fin.seekg(0, std::ios::beg);  //reset the reading position to beginning
  fin.close();

  std::ifstream fin2("D:/c++/adventofcode/files/day3_test.txt");

  instructions = makeInstr(line);
  std::cout << instructions[0] << std::endl;
  drawCable(instructions, layout, left, down);  // <-- this doesnt work...
  //try with smaller vector.
  //only one cable, cable intersects with itself...???
  std::cout << "number of intersections: " << test(layout) << std::endl;
  // fin.clear();
  // fin.seekg(0);
  // getline(fin,line);
  // std::cout << line << std::endl;
  // // instructions.erase(instructions.begin(), instructions.end());
  // //instructions = (makeInstr(line)); //PROBLEM HERE... why doesn't it let me to assign new values at vector here?
  // //it's the same as done beforein the while loop.
  // drawCable(instructions, layout, left, down);
  // std::cout << test(layout) << std::endl;

}
