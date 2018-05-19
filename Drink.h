/*
Drink.h declaration file.
Author: Anthony Jaghab
*/

#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Drink {
public:	
	
	double drinkPrice;
	int numOfDrinks;
	string drinkName;
};

class DrinkMachine {

private:	
	Drink drks[5];
	double inputMoney(); // called by buyDrink to accept, validate and return to buyDrink the amt of money input
	void dailyReport(); // report remaining drink type in the machine
	double money;
	double profit;

public:

	DrinkMachine() {
		drks[0].drinkName = "Cola";
		drks[0].drinkPrice = 1.00;
		drks[0].numOfDrinks = 20;

		drks[1].drinkName = "Root beer";
		drks[1].drinkPrice = 1.00;
		drks[1].numOfDrinks = 20;

		drks[2].drinkName = "Orange soda";
		drks[2].drinkPrice = 1.00;
		drks[2].numOfDrinks = 20;

		drks[3].drinkName = "Grape soda";
		drks[3].drinkPrice = 1.00;
		drks[3].numOfDrinks = 20;

		drks[4].drinkName = "Bottled water";
		drks[4].drinkPrice = 1.50;
		drks[4].numOfDrinks = 20;
	}

	/*
	Inline accessor for money
	*/
	double getMoney() {
		return money;
	}
	/*
	Inline accessor for profit
	*/
	double getProfit() {
		return profit;
	}

	void gotoxy(int, int); // go to the xy coords on the cmd window
	void displayChoices(); // display various choices of drinks
	bool buyDrink(int); // buy a drink
	void quit(); // display the quit menu
	void soldMenu(string); // sold menu
	
	/*
	Inline Destructor
	*/
	~DrinkMachine() {
		dailyReport();
		system("pause");
	}
};