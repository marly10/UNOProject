//
// Created by Ricky Marly & Jouse on 11/18/20.
//

#include "FireAI.h"
#include <iostream>
using namespace std;

Card c;
int cw = 0;

FireAI::FireAI(int playerNumber):
AI(playerNumber)
{

}

void FireAI::onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor)
{

}

void FireAI::onOtherPlayerDraw(int playerNumber)
{
    playerNumber = c.getNumber();
}

bool sortingCardByNumber(Card i, Card j)
{
    return i.getNumber() > j.getNumber();
}

int FireAI::makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction)
{

    //my playable cards vec
    vector<Card> cards = getPlayableCardsInHand(justPlayed, choosenCardColor, cardsInHand);

    if (cards.size() == 0)
    {
        return -1; //draw & safety code
    }

    //vector to hold sorted cards, since random isn't how the real UNO game is played(Uno King RM)
    vector<Card> cardsSortedByNumberToUse;

    //unsorted card stored into new Vec for sorting, don't want to mess with OG vec(cards)
    cardsSortedByNumberToUse.reserve(cards.size());

    for (auto card : cards)
        {
          cardsSortedByNumberToUse.push_back(card);
        }

    //new vector gets sorted by card int rather than random
    //utilizing the bool function
    //**********VERY IMPORTANT TO SORT************
    //Results(100K G): UNSORTED = 30.53362 FireAI_Gang -> SORTED = 23.855
    sort(cardsSortedByNumberToUse.begin(), cardsSortedByNumberToUse.end(), sortingCardByNumber);

    //cards will be stored by color together,
    //rather than randomly
    vector<int> colorCounterOfWildCards;

    //color counter initialized
    //colors will be counter and stored to ref later
    int  yellowColorQt = 0, blueColorQt = 0, greenColorQt = 0,redColorQt = 0, blackColorQt = 0;

    //goes thru hand of cards and count them,
    //base on the count the,
    // values(yellowColorQt = 0, blueColorQt = 0, greenColorQt = 0,redColorQt = 0),
    //increase for storage
    //RED = 0, BLUE, GREEN, YELLOW, BLACK
    int x = 0;
    for(auto & i : cardsInHand)
    {
        if (i.getColor() == RED)
        {
            redColorQt++;// x red
        }
        else if (i.getColor() == GREEN)
        {
            greenColorQt++;

        }
        else if (i.getColor() == YELLOW)
        {
            yellowColorQt++;

        }
        else if (i.getColor() == BLUE)
        {
            blueColorQt++;

        }
        else if (i.getColor() == BLACK)
        {
            blackColorQt++;
        }
    }

    //colors are in the colorCounterOfWildCards vector
    colorCounterOfWildCards.push_back(redColorQt); //index 0
    colorCounterOfWildCards.push_back(greenColorQt); //index 1
    colorCounterOfWildCards.push_back(yellowColorQt); //index 2
    colorCounterOfWildCards.push_back(blueColorQt); //index 3
    colorCounterOfWildCards.push_back(blackColorQt); //index 4

    //vector for both wild & draw4 -> colorCounterOfWildCards sorted
    //sort(colorCounterOfWildCards.begin(), colorCounterOfWildCards.end());


//100 -> 99
    for(int i = 0; i < colorCounterOfWildCards.size();i++)//losses card & keeps playing its own
    {
        //picks the saved color based on the color with the greatest quantity of cards
        if (colorCounterOfWildCards[i] == redColorQt /*|| redColorQt == blackColorQt*/ )
        {
            //savedColor = BLUE;
            savedColor = RED;
        }
        else if (colorCounterOfWildCards[i] == blueColorQt /*|| blueColorQt == blackColorQt*/ )
        {
            //savedColor = RED;
            savedColor = BLUE;
        }
        else if (colorCounterOfWildCards[i] == yellowColorQt /*|| yellowColorQt == blackColorQt*/)
        {
            //savedColor =  GREEN;
            savedColor = YELLOW;
        }
        else if (colorCounterOfWildCards[i] == greenColorQt /*|| greenColorQt == blackColorQt*/)
        {
            //savedColor = YELLOW;
            savedColor = GREEN;
        }
        else
        {

            //if(colorCounterOfWildCards[i] == blackColorQt)
            if(colorCounterOfWildCards[i] == blackColorQt)
            {
                 int k = i;
                 if((colorCounterOfWildCards[k-1] == yellowColorQt) || (colorCounterOfWildCards[k+1] == yellowColorQt))
                {
                    savedColor = YELLOW;
                    //check the color i have
                    //see what card is on the top
                    //decide the best card to play
                }
                 else if((colorCounterOfWildCards[k-1] == greenColorQt) || (colorCounterOfWildCards[k+1] == greenColorQt))
                {
                    savedColor = YELLOW;
                }
                else if((colorCounterOfWildCards[k-1] == blueColorQt) || (colorCounterOfWildCards[k+1] == blueColorQt))
                {
                    savedColor = YELLOW;
                }
                else if( (colorCounterOfWildCards[k-1] == redColorQt) || (colorCounterOfWildCards[k+1] == redColorQt))
                {
                    savedColor = YELLOW;
                }
            }
        }
    }

        //initializes our card that we will find in our actual hand
        c = cardsSortedByNumberToUse[0];
        //c = cards[rand() % cards.size()];


    //loops through hand until card is found and returns it's index
    for (int i = 0; i < cardsInHand.size(); i++)
    {
        if (c == cardsInHand[i])
        {
            return i;
        }
    }

}

//the name of the AI is defined here
string FireAI::getName()
{
    string d = to_string(cw);
    string first_name = "FireAI_Gang";
    string together = first_name+d;

    return together;
}
//saved first play saved here
Color FireAI::getNewColor()
{
    return savedColor;
}
