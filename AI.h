#pragma once

#include <vector>
#include "Card.h"
#include <string>
using namespace std;

class AI
{
public:
	virtual void onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor) = 0;
	virtual void onOtherPlayerDraw(int playerNumber) = 0;
	virtual string getName()=0;
	virtual int makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction) = 0; //the returned int refers to the index of which card is played in your hand.
	virtual Color getNewColor() = 0;
	AI(int num);

	int getNum() { return myPlayerNumber; }
	void setNum(int x) { myPlayerNumber = x; }
protected:
	int myPlayerNumber;

	vector<Card> getPlayableCardsInHand(Card justPlayed, Color choosenCardColor, vector<Card> cardsInHand);
};