#include"GameBase.h"

///////////////////////////////////////////////////////////////////////// Public
//////////////////////////////////////////////////////////// Func
void GameBase::printImage(const std::int16_t mistakes)
{
	if (mistakes >= 0 && mistakes <= 7)
	{
		char rope, head, lArm, body, rArm, lLeg, rLeg;
		rope = head = lArm = body = rArm = lLeg = rLeg = ' ';

		// Fall-through used knowlingly
		switch (mistakes)
		{
		case 7:
			rLeg = '\\';
		case 6:
			lLeg = '/';
		case 5:
			rArm = '\\';
		case 4:
			body = '|';
		case 3:
			lArm = '/';
		case 2:
			head = 'O';
		case 1:
			rope = '|';
		}

		std::cout << "                       \n"
			<< "            _______        \n"
			<< "            " << rope << "     |        \n"
			<< "            " << rope << "     |        \n"
			<< "            " << head << "     |        \n"
			<< "           " << lArm << body << rArm << "    |        \n"
			<< "           " << lLeg << ' ' << rLeg << "    |        \n"
			<< "                 / \\       \n"
			<< "                /   \\      \n";
	}
}

void GameBase::printMask()
{
	for (int i = 0; i < m_lenght; ++i)
		if (m_guessMask[i])
			std::cout << m_guess[i];
		else
			std::cout << '_';
}

std::int16_t GameBase::onTheirPlaces(const std::string& answer)
{
	int count(0);

	if (!answer.empty())
		for (int i = 0; i < m_lenght; ++i)
			if (toupper(m_guess[i]) == toupper(answer[i]))
			{
				++count;
				m_guessMask[i] = true;
			}

	return count;
}

std::int16_t GameBase::rightSymbols(const std::string& answer)
{
	int count(0);

	if (!answer.empty())
		for (int i = 0; i < m_lenght; ++i)
			for (int j = 0; j < m_lenght; ++j)
				if (toupper(answer[j]) == toupper(m_guess[i]))
				{
					++count;
					break;
				}

	return count;
}

bool GameBase::isGuess(const std::string& answer)
{
	for (int i = 0; i < m_guess.length(); ++i)
		if (toupper(m_guess[i]) != toupper(answer[i]))
			return false;
	return true;
}

///////////////////////////////////////////////////////////////////////// Protected
//////////////////////////////////////////////////////////// Ctor & Dtor
GameBase::GameBase(const std::int16_t hardLevel, const std::int16_t lenght)
	:m_hardLevel{ hardLevel }, m_lenght{ lenght }
{
	m_guessMask = new bool[m_lenght] {};
}

const std::int16_t GameBase::MIN_COUNT = 4;

GameBase::~GameBase() { delete[]m_guessMask; }