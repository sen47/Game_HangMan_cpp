#include<iostream>
#include<cstdint>
#include<Windows.h>

#include"CheckAnswer.h"
#include"GameNumbers.h"
#include"GameWords.h"

int main()
{
	const std::int16_t MAX_TRYES(7);

	std::srand(static_cast<size_t>(time(NULL)));

	std::int16_t variation{ checkAnswer<std::int16_t>("Enter \"1\", to play with words,\nenter \"2\", to play with numbers: ", 1, 2) };
	system("cls");

	std::int16_t length{ checkAnswer<std::int16_t>("Enter length of guess, \"4\", \"5\" or \"6\": ", 4, 6) };
	system("cls");

	std::int16_t level{ checkAnswer<std::int16_t>("Enter \"1\", to choose easy level,\nenter \"2\", to choose medium level,\nenter \"3\", to choose hard level: ", 1, 3) };
	level += 3;
	system("cls");

	GameBase* game{ nullptr };

	switch (variation)
	{
	case GameVariation::WORDS:
	{
		game = new GameWords(level, length);
		break;
	}
	case GameVariation::NUMBERS:
	{
		game = new GameNumbers(level, length);
		break;
	}
	}

	std::int16_t tryes(0);
	std::string answer;

	do
	{
		game->printImage(tryes);

		std::cout << "\n\n";

		std::int16_t onPlaces{ game->onTheirPlaces(answer) };
		game->printMask();

		// Fall-throght used knowlingly
		switch (level)
		{
		case HardLevel::EASY:
			std::cout << "   On their plases : " << onPlaces;
		case HardLevel::MEDIUM:
			std::cout << "   Right symbols: " << game->rightSymbols(answer);
		}

		std::cout << "   You have " << MAX_TRYES - tryes << " tryes";
		std::cout << "\n\n";

		while (!checkAnswer<std::string>("Try to guess: ", answer, length))
		{
			std::cout << "Error, try again!\n";
		}

		system("cls");
		++tryes;
	} while (!game->isGuess(answer) && tryes < MAX_TRYES);

	system("cls");

	if (game->isGuess(answer))
		std::cout << "Congratulation! You win, for now...\n";
	else
	{
		std::cout << "What else to exprct from a losel like you, you lose!";
		game->printImage(MAX_TRYES);
	}

	return 0;
}

