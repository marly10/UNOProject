//
// Created by Ricky Marly & Josue Baragan on 11/18/20.
//
#pragma once

#include "AI.h"
#include "Player.h"


class FireAI: public AI{
private:
    Color savedColor = RED;
public:
    FireAI(int playerNumber);
    void onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor)override;
    void onOtherPlayerDraw(int playerNumber)override;
    //returns the index of the card to play
    int makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction) override;
    string getName() override;
    Color getNewColor()override;

};


