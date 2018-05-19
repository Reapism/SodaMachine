/*
Drink.cpp implementation file.
Author: Anthony Jaghab
*/

#include <iostream>
#include "Drink.h"
#include <string>
#include <windows.h>
using namespace std;

COORD c = { 0,0 };

/*
Go to the x, y coordinate on the console.
Code reused from BCS120.
*/
void DrinkMachine::gotoxy(int x, int y) {
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*
Input money window and validates the input.
*/
double DrinkMachine::inputMoney() {
	system("CLS");
	system("Color 80");
	
	gotoxy(30, 9);
	cout << "==========================================";
	gotoxy(30, 10);
	cout << "      INPUT MONEY INTO THE MACHINE";
	gotoxy(30, 11);
	cout << "==========================================";
	
	gotoxy(30, 13);
	double d;
	cout << "Please enter the amount of money to input (min: $1.00): ";
	cin >> d;

	if (d < 1.0)
		return -1.0;
	else { 
		money += d;
		return d;
	}
}

/*
Displays a menu for showing all the choices.
*/
void DrinkMachine::displayChoices() {
	system("CLS");
	system("Color 81");

	gotoxy(30, 9);
	cout << "==========================================";
	gotoxy(30, 10);
	cout << "DRINK MACHINE SIMULATOR: by Anthony Jaghab";
	gotoxy(30, 11);
	cout << "==========================================";
	gotoxy(30, 13);
	cout << "Current funds: $" << money << ".";

	int prev = 15; // changed for the y coord.

	for (int i = 0; i < 5; i++) {
		gotoxy(30, prev);
		cout << (i + 1) << ".) " << drks[i].drinkName << endl;
		prev += 1;
		gotoxy(30, prev);
		cout << std::string(5, ' ') << "Price: $" << drks[i].drinkPrice << endl;
		prev += 1;
		gotoxy(30, prev);
		cout << std::string(5, ' ') << "Quantity: " << drks[i].numOfDrinks << endl;
		prev += 1;
	}
	gotoxy(30, prev);
	cout << "6.) Insert more money" << endl;

	int choice = 0;
	gotoxy(30, prev + 2);
	cout << "Please enter your selection (-1 to quit): ";
	cin >> choice;

	switch (choice) {
	case 1:
		buyDrink(0);
		break;
	case 2:
		buyDrink(1);
		break;
	case 3:
		buyDrink(2);
		break;
	case 4:
		buyDrink(3);
		break;
	case 5:
		buyDrink(4);
		break;
	case 6:
		if (inputMoney() == -1.0)
			cout << "Minimum $1.00";
		else
			displayChoices();
		break;
	case -1:
		quit();
		break;
	default:
		cout << "Invalid selection!\n";
		displayChoices();
		break;
	}

}

bool DrinkMachine::buyDrink(int i) {
	system("CLS");
	system("Color 80");

	double amt;
	if (money < 1)
		amt = inputMoney();
	else
		amt = money;
	// checks if the current money is >= the drink your buying and checking if amt is not -1, and 
	if (drks[i].numOfDrinks == 0) {
		cout << "The " << drks[i].drinkName << " is unavailable, please select another drink.\n";
		system("pause");
		displayChoices();
		return false;
}
	if (amt >= drks[i].drinkPrice && amt != -1.0) {
		money -= drks[i].drinkPrice;
		profit += drks[i].drinkPrice;
		drks[i].numOfDrinks -= 1;
		soldMenu(drks[i].drinkName);
		return true;
	} else {
		cout << "Insuffient funds!\n";
		system("pause");
		displayChoices();
		return false;
	}
}

void DrinkMachine::quit() {
	system("CLS");
	system("Color 80");

	gotoxy(20, 10);
	
	if (money > 0) {
		cout << "Thank you for your purchase(s).\n";
		gotoxy(20, 12);
		cout << "Dispensing $" << money << ".\n";
	} else {
		cout << "Thank you for your purchase(s).\n";
		gotoxy(20, 12);
		cout << "Please visit again!\n";
	}
	system("pause");
	exit;
}

/*
When a transaction is complete, this menu shows up.
*/
void DrinkMachine::soldMenu(string item) {
	system("CLS");
	system("Color 80");

	gotoxy(20, 10);
	cout << "The " << item << " has been purchased!\n";
	system("pause");
	displayChoices();
}

void DrinkMachine::dailyReport() {
	system("CLS");
	system("Color 84");
	
	gotoxy(30, 9);
	cout << "==========================================";
	gotoxy(30, 10);
	cout << "              DAILY REPORT";
	gotoxy(30, 11);
	cout << "==========================================";
	gotoxy(30, 13);

	int prev = 15;

	for (int i = 0; i < 5; i++) {
		gotoxy(30, prev);
		cout << (i + 1) << ".) " << drks[i].drinkName << endl;
		prev += 1;
		gotoxy(30, prev);
		cout << std::string(5, ' ') << "Quantity: " << drks[i].numOfDrinks << endl;
		prev += 1;
	}

	gotoxy(30, prev + 1);
	cout << "Amount of money collect: $" << profit << endl;
}