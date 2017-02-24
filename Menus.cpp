/*
 * Menus.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_MENUS_CPP_
#define SRC_MENUS_CPP_

#include "TheVoice.h"


void TheVoice::startMenu()
{
	cout << "Here, we give you the oportunity to simulate seasons!!" << endl << "How many seasons to simulate? " << endl;
	int n0seasons;
	cin >> n0seasons;
	for (int i = 0; i < n0seasons; i++)
	{
		newSeason();
		FirstPhaseMenu();
		seasons.at(i).addteamBlind();
		SecondPhaseMenu();
		seasons.at(i).BattleFase();
		ThirdPhaseMenu();
		seasons.at(i).showFase();
		FinalPhaseMenu();
		seasons.at(i).FinalFase();

	}

	
	
}

void TheVoice::FirstPhaseMenu() {
	char choice;
	cout << "Be ready for the... " << endl << "FRIST PHASE - The Blind Proof" << endl << endl;
	cout << "You know what The Blind proof is? (y/n)" << endl;
	cin >> choice;
	cout <<  endl;
	if (choice == 'n') {
		cout << "While the contestant shows his talent, the mentors, with their backs turned, " << endl;
		cout << "consider whether or not the vocal talent of the contestant is enough to belong on their team. ";
		cout << endl << "If the mentor decides that the contestant deserves to belong on his team,  " << endl;
		cout << "press the button, which makes the chair rotate." << endl;
		cout << "If  more than one mentor rotate the chair, it is up to the competitor to choose the team." << endl << endl;
		cout << "Blind Proof is now starting... " << endl;
	}
	else {
		cout << "Blind Proof is now starting... " << endl;
	}
}

void TheVoice::SecondPhaseMenu() {
	char choice;
	cout << "Be ready for the... " << endl << "SECOND PHASE - The Battle Proof" << endl << endl;
	cout << "You know what The Battle proof is? (y/n)" << endl;
	cin >> choice;
	if (choice == 'n') {
		cout << "Two competitors of the same team, chosen by the mentor,"<< endl;
		cout << "fight against each other vocally... It's a real battle ring!!! " << endl;
		cout << endl << "At the end of the assignment, it is the mentor who must  " << endl;
		cout << "decide which of the two stays in the program." << endl;
		cout << endl << "Battle Proof is now starting..." << endl;
		
	}
	else {
		
		cout << "What are you waiting for? Let's start !!" << endl << endl << "Battle Proof is now starting..." << endl;
	}
}

void TheVoice::ThirdPhaseMenu() {
	char choice;
	cout << "Be ready for the... " << endl << "THIRD PHASE - The Gala Proof" << endl << endl;
	cout << "You know what The Gala proof is? (y/n)" << endl;
	cin >> choice;
	if (choice == 'n') {
		cout << "In this phase, therefore, there are 28 contestants, who compete against each other in 2 galas. " << endl;
		cout << "On each gala must win only five contestants. " << endl;
		cout << endl << "The public's vote helps to decide who is still in the program and who is eliminated.  " << endl;
		cout << endl << "The Gala 1 is now starting..." << endl;

		


	}
	else {

		cout << endl << "The Gala 1 is now starting..." << endl;
	}

	char option;

	cout << "PRESS ANY LETTER TO CONTINUE" << endl;
	cin >> option;

}

void TheVoice::FinalPhaseMenu() {
	char choice;
	cout << "Be ready for the... " << endl << "FINAL PHASE - The Final Gala" << endl << endl;
	cout << "You know what The Final Gala is? (y/n)" << endl;
	cin >> choice;
	if (choice == 'n') {
		cout << "The 10 contestants, 5 from each previous galas show their skills in one final gala.   " << endl;
		cout << "Only ONE can be the winner and the choice is 50/50 the vote of the " << endl;
		cout << endl << "public and the mentors. " << endl;
		cout << endl << "The Final Gala is now starting..." << endl;

	}
	else {

		cout << endl << "The Final Gala is now starting..." << endl;
	}
}


/*
void Menu()
{
	unsigned int option;

	cout << "Hello and Welcome to The Voice's records" << endl;
	cout << "As a member of the general public, you can access statistics and details on previous editions.";
	cout << endl << "Which option do you want to consult?"<< endl;

	cout << "1 - Who were the mentors?" << endl;
	cout << "2 - Who were the contestants?" << endl;
	cout << "3 - Who won?";

	//AvailableInfo();
}

int chooseSeason()
{
	unsigned int season;

	cout << "Which season?" << endl;
	cin >> season;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> season;
	}

	while (season != 1) //mudar condicao para x temporadas +1
	{
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> season;
	}

	return season;
}

void AvailableInfo()
{
	unsigned int option;

	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;

	}

	while (option != 1 && option != 2 && option != 3)
	{
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> option;
	}


	switch(option)
	{
	case 1: //mentores
		chooseSeason();

		cout << "Which option do you want to consult?" << endl;

		cout << "1 - What was their team?" << endl;
		cout << "2 - Which was the most successful mentor?" << endl;

		cout << "3 - Return to starting menu.";

		break;

	case 2: //concorrentes
		chooseSeason();

		cout << "Which option do you want to consult?"<< endl;

		cout << "1 - Which songs were sung?" << endl;
		cout << "2 - Which chairs were turned?" << endl;
		cout << "3 - In which season were they eliminated?" << endl;

		cout << "4 - Return to starting menu.";
		break;

	case 3: //vencedores
		chooseSeason();

		break;
	}
}

void menuMentors()
{
	unsigned int option;
	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;
	}

	while (option != 1 && option != 2 && option != 3) {
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> option;
	}

	switch (option) {
	case 1: //equipas
		chooseSeason();

		break;
	case 2: //mais bem sucedido

		break;
	case 3:
		Menu();
		break;
	}
}

void menuContestants()
{
	unsigned int option;
	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;
	}

	while (option != 1 && option != 2 && option != 3 && option != 4) {
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2, 3 or 4! Try again." << endl;
		cin >> option;
	}

	switch (option) {
	case 1: //musicas
		chooseSeason();

		break;
	case 2: //cadeiras que virou
		chooseSeason();

		break;
	case 3: //etapa em que foi eliminado
		chooseSeason();

		break;
	case 4:
		Menu();
		break;
	}
}*/

#endif /*  SRC_MENUS_CPP_ */
