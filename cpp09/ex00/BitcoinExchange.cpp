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

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	//checking the amount of chars till | and the correct separation
	size_t length = date.length();
	if (length != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)//the rest are numbers
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	//basic ranges for dates
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	// as some months have 31 and others dont,
	// we create an array to check them one by one
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// leaps years have 29 days in march
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;

	//we return the difference to see if its valid
	return (day <= daysInMonth[month]);
}

void BitcoinExchange::chargeData(const std::string& data_file)
{
	std::ifstream file(data_file.c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Error: could not open database file." << std::endl;
		throw(std::exception());
	}

	std::string line;
	std::getline(file, line); //"date,exchange_rate"

	while (std::getline(file, line))
	{
		size_t delim = line.find(',');
		if (delim != std::string::npos)
		{
			std::string date = line.substr(0, delim);
			float value = std::atof(line.substr(delim + 1).c_str());
			
			//map container use make_pair to insert in it the actual values
			this->dates_values.insert(std::make_pair(date, value));
		}
	}
	file.close();
}

void BitcoinExchange::checkFile(const std::string& input_file)
{
	std::ifstream file(input_file.c_str());
	if (!file.is_open())
	{
		std::cout << RED <<  "Error: could not open file." << std::endl;
		throw(std::exception());
	}

	std::string line;
	std::getline(file, line);//"date | value"

	while (std::getline(file, line))
	{
		size_t delim = line.find(" | ");
		if (delim == std::string::npos)// checking for correct separator
		{
			std::cerr << RED << "Error: bad input => " << NC << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		std::string value_str = line.substr(delim + 3);

		if (!this->isValidDate(date))// check date
		{
			std::cerr << RED << "Error: bad input => " << NC << date << std::endl;
			continue;
		}

		float value = std::atof(value_str.c_str());//extracting the nmb as a float
		if (value < 0)
		{
			std::cerr << RED << "Error: not a positive number => " << NC << line << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << RED << "Error: too large a number => " << NC << line << std::endl;
			continue;
		}
		this->calculate(date, value);
	}
	file.close();
}

void BitcoinExchange::calculate(const std::string& date, float value)
{
    if (this->dates_values.empty())
		return;

    // ws create an iterator an save the lowest pair according to the date
    std::map<std::string, float>::iterator it = this->dates_values.lower_bound(date);

    if (it == this->dates_values.end() || it->first != date)
	{
        if (it == this->dates_values.begin())
		{
            std::cerr << RED << "Error: no valid older date found for => " << date << NC << std::endl;
            return;
        }
        --it;//we continue looking for the lowest date
    }

    std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}