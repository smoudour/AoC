#include "D:/c++/adventofcode/functions.h"


// -- DAY 1 --

//TEST FOR PRIME NUMBERS

//Simple method. Complexity O(num)
bool is_prime_simple(int num) {

	if (num==2 || num==3) {
		return true;
	}

	else if (num==1) {
		return false;
	}

	else {
		for (int i=2; i<num; ++i) {
			if (num%i == 0) {
				return false;
			}
		}

		return true;

	}

}

//Fermat Method



// -- DAY 2 --
//Vector Constructor
std::vector<int> vectorCreator(std::string input) {

	std::vector<int> program;
	std::stringstream ss(input);

	for (int i; ss >> i;) {
		program.push_back(i);

		if (ss.peek() == ',' || ss.peek() == ' ') {
			ss.ignore();
		}
	}

	return program;
}

//Code solver: 1 for addition, 2 for multipliation, 99 for halt
void intCode(std::vector<int> &code_vector) {

	for (int i=0; i<code_vector.size(); ++i) {
		if (code_vector[i] == 1) {
			code_vector[code_vector[i+3]] = code_vector[code_vector[i+1]] + code_vector[code_vector[i+2]];
			//set position of index to n-1, because it will be incremented in the rerun of the loop
			i = i+3;  //slide position to next quadruplet.

		}

		else if (code_vector[i] == 2) {
			code_vector[code_vector[i+3]] = code_vector[code_vector[i+1]] * code_vector[code_vector[i+2]];
			i = i+3;
		}

		else if (code_vector[i] == 99) {
			break;
		}

		else {
			std::cout << i << " - Oops... Something went wrong.\nInvalid value at opcode position... " << std::endl;
		}
	}
}

// -----

// -- DAY 3 --
//Create Cable Layout
//constructs cable layout based on string instructions into a 2d vector
std::vector<int> cableLayout(std::string &instr) {

  std::string delim = ",";
  size_t pos = 0;
  std::string token;
  std::vector<int> v;

  while ((pos = instr.find(delim)) != std::string::npos) {
    token = instr.substr(0, pos);
    }
    instr.erase(0, pos + delim.length());

  }
