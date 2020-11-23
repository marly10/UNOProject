#pragma once

#include <vector>
#include <algorithm>
using namespace std;

#include "Card.h"
#include "AI.h"

#include "TestAI.h"
#include "FireAI.h"


class Player
{

protected:
	vector<Card> hand;
	int playerNumber;
	AI * theAI;
	vector<int> handSizes;
	vector<vector<int>> pointsPerHand;
	vector<int> games;

	bool validPlay(int index, Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand);

public:
	Player(int num, int whichAI);

	//if you desire to keep track of what cards other people played...
	void onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor);
	void onOtherPlayerDraw(int playerNumber);

	int makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, int direction) //the returned int refers to the index of which card is played in your hand.
		;

	Color getNewColor();
	void clearHand();
	void addToHand(Card c);
	void removeCardFromHand(int indexOfCard);
	vector<Card> getHandCopy();
	int mostRecent = 0;
	//int whichAI;
	vector<float> diff;

	int updateStats(vector<Player*> thePlayers);

	void printStats(vector<Player*> thePlayers);

	string getName() { return theAI->getName(); }
	int getNum() { return theAI->getNum(); }
};