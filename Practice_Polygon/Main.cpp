#include "Polygon.h"

#include<iostream>
#include<fstream>
#include<cmath>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Arguments missing." << std::endl;
		std::cerr << "Usage: VectorOperations <filename>" << std::endl;
		return 1;
	}
	std::ifstream lInput(argv[1], std::ifstream:: in);
	if (!lInput.good())
	{
		std::cerr << "Cannot open input file: " << argv[1] << std::endl;
		return 2;
	}

}