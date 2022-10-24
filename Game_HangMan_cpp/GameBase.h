#pragma once

#include<cstdint>
#include<string>
#include<iostream>

enum GameVariation { WORDS = 1, NUMBERS };
enum HardLevel { EASY = 4, MEDIUM, HARD };

class GameBase
{
public:
	/////////////////////////////////////////////// Func
	void printImage(const std::int16_t mistakes);
	void printMask();
	std::int16_t onTheirPlaces(const std::string& answer);
	std::int16_t rightSymbols(const std::string& answer);

	virtual bool isGuess(const std::string& answer);

protected:
	/////////////////////////////////////////////// Ctor & Dtor
	GameBase(const std::int16_t hardLevel, const std::int16_t lenght);
	virtual ~GameBase();

	const std::int16_t m_lenght, m_hardLevel;
	bool* m_guessMask;
	std::string m_guess;
	const static std::int16_t MIN_COUNT;
};