#pragma once

#include <iostream>
#include <map>
#include <string>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class BitcoinExchange
{
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	void check_file(const std::string& file);
	void insertData(int argc);
	std::ostream& pairValues(int file, int dataBase);

	private:
	std::map<std::string, float> dates_values;
};