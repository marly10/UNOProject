#include "AI.h"

AI::AI(int num)
{
	myPlayerNumber = num;
}

vector<Card> AI::getPlayableCardsInHand(Card justPlayed, Color choosenCardColor, vector<Card> cardsInHand)
{
	vector<Card> cardsCanPlay;

	for (int i = 0; i < cardsInHand.size(); i++)
	{
		if (choosenCardColor == cardsInHand[i].getColor())
		{
			//cout << "A"<< cardsCanPlay.size() << choosenCardColor << endl;
			cardsCanPlay.push_back(cardsInHand[i]); //same color
		}
		else if (cardsInHand[i].getColor() != BLACK && justPlayed.getNumber() == cardsInHand[i].getNumber() && justPlayed.getColor() != BLACK)
		{
			//cout << "B" << cardsCanPlay.size() << choosenCardColor<< endl;
			cardsCanPlay.push_back(cardsInHand[i]); //same number
		}
		else if (cardsInHand[i].getColor() == BLACK && cardsInHand[i].getNumber() == 0)
		{
			//cout << "C" << cardsCanPlay.size() << choosenCardColor<< endl;
			cardsCanPlay.push_back(cardsInHand[i]); //wild
		}
		else if (cardsInHand[i].getColor() == BLACK && cardsInHand[i].getNumber() == 1) //draw four
		{
			//cout << "D" << cardsCanPlay.size() << choosenCardColor<< endl;
			bool hasColor = false;
			for (int j = 0; j < cardsInHand.size(); j++)
			{
				if (choosenCardColor == cardsInHand[j].getColor())
				{
					hasColor = true;
				}
			}
			if (!hasColor) //can only play draw4 if doesn't have color. 
			{
				cardsCanPlay.push_back(cardsInHand[i]);
			}
		}
	}
	return cardsCanPlay;
}