#pragma once

#include "AI.h"

class TestAI : public AI
{

private:
	Color savedColor = RED;

public:
	TestAI(int playerNumber);

	void onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor);

	void onOtherPlayerDraw(int playerNumber);

	//returns the index of the card to play
	int makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction);

	string getName();



	Color getNewColor();

};