#pragma once

#include "GameBase.h"

class GameWords :public GameBase
{
public:
	GameWords(const std::int16_t hardLevel, const std::int16_t lenght);
	~GameWords() override;

private:
	const std::int16_t m_seleckArray;

	const std::int16_t arraysCount, arraysLenght;
	std::string** words;
};