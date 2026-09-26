#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Usage ./btc [input-file]" << NC << std::endl;
		return (1);
	}
	BitcoinExchange bit;
	bit.chargeData("data.csv");
	bit.checkFile(argv[1]);
	return (0);
}