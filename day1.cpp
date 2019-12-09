#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "functions.h"

int main() {

	std::string line;
	std::ifstream myfile ("D:/c++/adventofcode/files/day1.txt");

	if (myfile.is_open()) {

		int mod_mass;
		int mod_fuel;
		int total_fuel = 0;
		int extra_fuel;
		int sum_fuel = 0;

		while (getline(myfile,line))
		{
			mod_mass = stoi(line);
			mod_fuel = fuelCalculator(mod_mass);
			total_fuel = mod_fuel;

			extra_fuel = fuelCalculator(mod_fuel);

			while (extra_fuel > 0) {

				std::cout << total_fuel << " and " << extra_fuel << std::endl;
				total_fuel += extra_fuel;
				extra_fuel = fuelCalculator(extra_fuel);  //calculate fuel needed for extra fuel instance

			}

			std::cout << "Module fuel: " << mod_fuel << " and Extra Fuel: " << total_fuel - mod_fuel << std::endl;

			sum_fuel += total_fuel;	//add total fuel for each module to summed fuel.

			std::cout << "Fuel needed so far: " << sum_fuel << std::endl;
		}

		myfile.close();
	}

	else
	{
		std::cout << "Unable to open file..." << std::endl;
	}

	return 0;
}
