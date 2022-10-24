#include "GameNumbers.h"

GameNumbers::GameNumbers(const std::int16_t hardLevel, const std::int16_t lenght)
	:GameBase(hardLevel, lenght)
{
	for (int i = 0; i < m_lenght; ++i)
		m_guess += std::to_string(rand() % 10);
}
