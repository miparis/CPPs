#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange bit;
	if (argc != 1)
		std::cout << "Error: Usage ./btc [input-file]" << std::endl;
	check_file();

	return (0);
}