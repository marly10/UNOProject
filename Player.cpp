
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(int num, int whichAI)
{

	for (int i = 0; i < 5; i++)
	{
		games.push_back(0);
		diff.push_back(0);
		handSizes.push_back(0);
		pointsPerHand.resize(25);
	}

	playerNumber = num;
	switch (whichAI)
	{
	case 0:
        theAI = new FireAI(num);
		break;
	case 1:
		theAI = new TestAI(num);
		break;
		//... imagine there are 19 more rows here for yall's AIs
	}
}

//if you desire to keep track of what cards other people played...
void Player::onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor)
{
	theAI->onOtherPlayerMove(playerNumber, justPlayed, choosenCardColor);
}
void Player::onOtherPlayerDraw(int playerNumber)
{
	theAI->onOtherPlayerDraw(playerNumber);
}

bool Player::validPlay(int index, Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand)
{
	//cout << index << " " << hand.size() << "\n";

	if (index < -1 || index > hand.size() - 1)
		return false;

	if (getNewColor() == BLACK || getNewColor() == NONE)
	{
		return false;
	}

	if (index == -1)
	{
		return true;
	}

	Card c = hand[index];

	if (choosenCardColor == c.getColor())
	{
		return true; //same color
	}
	else if (c.getColor() != BLACK && justPlayed.getNumber() == c.getNumber() && justPlayed.getColor() != BLACK)
	{
		return true; //same number
	}
	else if (c.getColor() == BLACK && c.getNumber() == 0) //wild
	{
		return true; //wild
	}
	else if (c.getColor() == BLACK && c.getNumber() == 1) //draw four
	{
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
			return true;
		}
	}

	return false;
}

//calls the function on player's AI.
int Player::makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer,int direction) //the returned int refers to the index of which card is played in your hand.
{
	int index = theAI->makeMove(justPlayed, choosenCardColor, justDrew, scores, cardAmountsByPlayer, hand, direction);

	if (!validPlay(index, justPlayed, choosenCardColor, justDrew, scores, cardAmountsByPlayer, hand))
	{
		//cout << "bad play detected by AI; card not allowed to be played: print out on player.cpp line  83\n";
		//while (true); //pause program execution!
		return -1;
	}

	return index;
}

Color Player::getNewColor()
{
	return theAI->getNewColor();
}

void Player::clearHand()
{
	hand.clear();
}


void Player::addToHand(Card c)
{
	hand.push_back(c);
}

void Player::removeCardFromHand(int indexOfCard)
{
	hand.erase(hand.begin() + indexOfCard);
}

vector<Card> Player::getHandCopy()
{ 
	return hand; 
}



int Player::updateStats(vector<Player*> thePlayers)
{

	for (int i = 0; i < 5; i++)
	{
		handSizes[thePlayers[i]->playerNumber] += hand.size();
	}

	int points = 0;
	for (int i = 0; i < hand.size(); i++)
	{

		points += hand[i].getPoints();
	}

	for (int j = 0; j < 5; j++)
	{
		pointsPerHand[thePlayers[j]->playerNumber].push_back(points);
	}

	for (int i = 0; i < 5; i++)
	{
		games[thePlayers[i]->playerNumber] ++;
	}

	mostRecent = points;
	return points;
}
void Player::printStats(vector<Player*> thePlayers)
{

	cout << "Player: " << playerNumber << "\n";
	cout << "AI: " << theAI->getName() << "\n";

	cout << "handsize on game end, ";
	for (int i = 0; i < 1; i++)
	{
		cout << handSizes[i] * 1.0f / games[i] << ",";
	}
	cout << "\n";

	cout << "medium points per game, ";
	for (int i = 0; i < 1; i++)
	{
		sort(pointsPerHand[i].begin(), pointsPerHand[i].end());
		if (pointsPerHand[i].size() == 0)
		{
			cout << 0 << ",";
		}
		else
		{
			cout << pointsPerHand[i][pointsPerHand[i].size() / 2] << ",";
		}
	}
	cout << "\n";

	cout << "average points (lower is better), ";

	for (int j = 0; j < 1; j++)
	{
		int points = 0;
		for (int i = 0; i < pointsPerHand[j].size(); i++)
		{
			points += pointsPerHand[j][i];
		}


		cout << points * 1.0f / games[j] << ",";
	}
	cout << "\n";

	cout << "avg difference between players (lower is better), ";
	for (int i = 0; i < 1; i++)
	{
		cout << diff[i] * 1.0f / games[i] << ",";
	}
	cout << "\n";
}


