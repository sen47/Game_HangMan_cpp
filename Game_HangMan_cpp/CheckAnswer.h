#pragma once

#include<iostream>
#include<string>
#include<Windows.h>

template<typename T>
T checkAnswer(const std::string& output)
{
	while (true)
	{
		std::cout << output;
		T input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("cls");
			std::cout << "Error, try again!\n";
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount())
		{
			system("cls");
			std::cout << "Error, try again!\n";
			continue;
		}

		return input;
	}
}

template<typename T>
T checkAnswer(const std::string& output, const std::int32_t min, const std::int32_t max)
{
	while (true)
	{
		std::cout << output;
		T input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("cls");
			std::cout << "Error, try again!\n";
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			system("cls");
			std::cout << "Error, try again!\n";
			continue;
		}

		if (input < min || input > max)
		{
			system("cls");
			std::cout << "Error, try again!\n";
			continue;
		}

		return input;
	}
}

template<typename T>
bool checkAnswer(const std::string& output, std::string& answer, const std::int16_t length) {}

template<>
bool checkAnswer<std::string>(const std::string& output, std::string& answer, const std::int16_t length)
{
	while (true)
	{
		std::cout << output;
		std::getline(std::cin, answer);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			return false;
		}

		if (answer.length() != length)
		{
			return false;
		}

		return true;
	}
}