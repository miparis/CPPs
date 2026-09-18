#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (this != &copy)
		this->dates_values == copy.dates_values;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		this->dates_values == copy.dates_values;
	return (*this);
}
	
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::check_file(const std::string& file)
{
	
}
	void insertData(int argc);
	std::ostream& pairValues(int file, int dataBase);