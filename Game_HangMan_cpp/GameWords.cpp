#include "GameWords.h"

GameWords::GameWords(const std::int16_t hardLevel, const std::int16_t lenght)
	:GameBase(hardLevel, lenght), m_seleckArray{ lenght - MIN_COUNT }, arraysCount{ 3 }, arraysLenght{ 3 }
{
	words = new std::string * [arraysCount];
	for (int i = 0; i < arraysCount; ++i)
		words[i] = new std::string[arraysLenght];

	words[0][0] = "Game";
	words[0][1] = "Book";
	words[0][2] = "Disk";

	words[1][0] = "Mouse";
	words[1][1] = "Glass";
	words[1][2] = "Chair";

	words[2][0] = "Dagger";
	words[2][1] = "Coffee";
	words[2][2] = "Pencil";

	m_guess = words[m_seleckArray][rand() % 3];
}

GameWords::~GameWords()
{
	for (int i = 0; i < arraysCount; ++i)
		delete[] * words;
	delete[]words;
}
