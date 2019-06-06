#include "Convert.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

void	printOutput(double val) {
	// char ________________________
	try
	{
		std::cout << "char: ";
		char c = Convert::toChar(val);
		std::cout << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Non displayable") << std::endl;
	}
	catch(const Convert::ImpossibleConversion& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// int ________________________
	try
	{
		std::cout << "int: ";
		int i = Convert::toInt(val);
		std::cout << i << std::endl;
	}
	catch(const Convert::ImpossibleConversion& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// float ________________________
	try
	{
		std::cout << "float: ";
		float f = Convert::toFloat(val);
		std::cout << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	}
	catch(const Convert::ImpossibleConversion& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// double ________________________
	try
	{
		std::cout << "double: ";
		double d = val;
		std::cout.precision(1);
		std::cout << std::setprecision(1) << std::fixed << d << std::endl;
	}
	catch(const Convert::ImpossibleConversion& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc > 1) {
		std::string arg = argv[1];

		std::regex floatReg("^[-+]?[0-9]+(\\.[0-9]+)?f$");
		std::regex doubleReg("^[-+]?[0-9]+(\\.[0-9]+)?$");
		std::regex intReg("^[-+]?[0-9]+$");
		std::regex floatInfNanReg("^([-+]?inf|nan)f$");
		std::regex infNanReg("^([-+]?inf|nan)$");

		if (regex_match(arg, floatReg) || regex_match(arg, floatInfNanReg)
			|| regex_match(arg, doubleReg) || regex_match(arg, infNanReg)
			|| regex_match(arg, intReg)
			|| arg.length() == 1)
		{
			if (arg.length() == 1 && !isdigit(argv[1][0]))
				printOutput(static_cast<char>(argv[1][0]));
			else
				printOutput(atof(argv[1]));
		} else {
			std::cerr << "Input does not make sense" << std::endl;
		}
	}
	return 0;
}
