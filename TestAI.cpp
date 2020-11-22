#include "TestAI.h"

#include <iostream>
using namespace std;

TestAI::TestAI(int playerNumber) : AI(playerNumber)
{

}

void TestAI::onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor)
{

}

void TestAI::onOtherPlayerDraw(int playerNumber)
{

}

//returns the index of the card to play
int TestAI::makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand,int direction)
{
	/*for (int i = 0; i < cardAmountsByPlayer.size(); i++)
	{
		cout << cardAmountsByPlayer[i] <<"\n";
	}*/


	vector<Card> cards = getPlayableCardsInHand(justPlayed, choosenCardColor, cardsInHand);

	if (cards.size() == 0)
	{
		return -1; //draw
	}

	//special card key
	//reverse = 12, skip = 10, and draw2 = 11 of any of red/blue/green/yellow.
	//wild is black 0, draw4 is black 1

	savedColor = YELLOW; //if I am playing a draw4 or wild, i set this variable to set the new color i am picking; yellow is the perfect color to choose every time i play a draw4/wild for this ai! I guess?


	//choose random card and map from possible cards to hand cards
	Card c = cards[rand() % cards.size()];
	for (int i = 0; i < cardsInHand.size(); i++)
	{
		if (c == cardsInHand[i])
		{
			return i;
		}
	}

	//should not get here in my AI???
	cerr << "bbaaaad happeeeened\n";
	return -1;
}

string TestAI::getName()
{
	return "TestAI";
}



Color TestAI::getNewColor()
{
	return savedColor;
}

