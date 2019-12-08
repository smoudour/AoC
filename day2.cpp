#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


int main() {

	std::string line;
	//open the file (?)
	std::ifstream myfile ("D:/c++/adventofcode/files/day2.txt");
	std::vector<int> program;

	if (myfile.is_open()) {
		getline(myfile,line);
		//create vector of input numbers out of string
		//separate numbers by comma
		program = vectorCreator(line);
		//change values of vector at pos 1 and 2
		//0-99 inclusive for both
		std::cout << program[0] << std::endl;

		for(int i=0; i<100; ++i) {
			for(int j=0; j<100; ++j) {

				program[1] = i;
				program[2] = j;
				//run computer
				intCode(program);
				//if desired result
				if (program[0] == 19690720) {
					goto endloop;
				}
				else {
					//reset memory
					program = vectorCreator(line);
				}

			}
		}
			//first part
			// program[1] = 12;
			// program[2] = 2;
			// //run intcode
			// intCode(program);
	}

	//print value, close file
endloop:
	std::cout << 100*program[1] + program[2] << std::endl;
	myfile.close();

	//print value at pos 0 after intCode program runs
	std::cout << program[0] << " " << program[1] << " " << program[2] << std::endl;

	return 0;
}
