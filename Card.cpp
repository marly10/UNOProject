
#include "Card.h"

Card::Card(int num, Color c)
{
	number = num;
	theColor = c;
	colorChangedTo = c;

	if (theColor == BLACK)
	{
		points = 50;
	}
	else
	{
		if (number >= 10)
		{
			points = 20;
		}
		else
		{
			points = number;
		}
	}
}
Card::Card()
{
}

int Card::getNumber()
{
	return number;
}
Color Card::getColor()
{
	return theColor;
}
Color Card::getColorChange()
{
	return colorChangedTo;
}

void Card::setColorChange(Color newc)
{
	colorChangedTo = newc;
}

int Card::getPoints()
{
	return points;
}

bool Card::operator==(Card& other)
{
	return other.theColor == theColor && other.number == number;
}



string cardTOString(Card c)
{
	string toReturn = "";

	if (c.getColor() == BLUE || c.getColor() == RED || c.getColor() == GREEN || c.getColor() == YELLOW)
	{
		switch (c.getColor())
		{
		case BLUE:
			toReturn += "Blu";
			break;
		case RED:
			toReturn += "Red";
			break;
		case GREEN:
			toReturn += "Gre";
			break;
		case YELLOW:
			toReturn += "Yel";
			break;
		}
		if (c.getNumber() >= 0 && c.getNumber() <= 9)
		{
			if (c.getNumber() == 0)
			{
				toReturn += "0";
			}
			if (c.getNumber() == 1)
			{
				toReturn += "1";
			}
			if (c.getNumber() == 2)
			{
				toReturn += "2";
			}
			if (c.getNumber() == 3)
			{
				toReturn += "3";
			}
			if (c.getNumber() == 4)
			{
				toReturn += "4";
			}
			if (c.getNumber() == 5)
			{
				toReturn += "5";
			}
			if (c.getNumber() == 6)
			{
				toReturn += "6";
			}
			if (c.getNumber() == 7)
			{
				toReturn += "7";
			}
			if (c.getNumber() == 8)
			{
				toReturn += "8";
			}
			if (c.getNumber() == 9)
			{
				toReturn += "9";
			}
		}
		if (c.getNumber() == 10)
		{
			toReturn += 'S';
		}
		if (c.getNumber() == 11)
		{
			toReturn += 'D';
		}
		if (c.getNumber() == 12)
		{
			toReturn += 'R';
		}
	}

	if (c.getColor() == BLACK)
	{
		if (c.getNumber() == 0)
		{
			toReturn += "Wild";
		}
		if (c.getNumber() == 1)
		{
			toReturn += "Dra4";
		}
	}

	return toReturn;
}