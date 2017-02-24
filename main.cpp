#include <iostream>
#include <string>
#include <vector>
#include "Libraries.h"
#include "TheVoice.h"
#include <ctime>

TheVoice programa;
int main()
{  
	cout << "/$$$$$$$$ /$$                       /$$    /$$          /$$                " << endl <<
		"|__  $$__/| $$                      | $$   | $$         |__/  " << endl <<
		"| $$   | $$$$$$$   /$$$$$$       | $$   | $$ /$$$$$$  /$$  /$$$$$$$  /$$$$$$" << endl <<
		"| $$ | $$__  $$ / $$__  $$ | $$ / $$//$$__  $$| $$ /$$_____/ /$$__  $$" << endl <<
		"| $$ | $$  \ $$ | $$$$$$$$       \  $$ $$ / | $$  \ $$ | $$ | $$ | $$$$$$$$" << endl <<
		"| $$ | $$ | $$ | $$_____ / \  $$$ / | $$ | $$ | $$ | $$ | $$_____ /" << endl <<
		"| $$ | $$ | $$ | $$$$$$$         \  $ / | $$$$$$ / | $$ | $$$$$$$ | $$$$$$$" << endl <<
		"| __ / | __ / | __ / \_______ / \_ / \______ / | __ / \_______ / \_______ / ";

	cout << "The Voice is a competition which intends to find the best unknown voices in the country!" << endl;
	cout << "Four famous musicians search for the best voices and will mentor these singers to become artists... " << endl;
	cout << "             ARE             " << endl << "             YOU             " << endl << "           READY???             " << endl << endl << endl;
	srand((unsigned int)time(NULL));
	programa.loadAll();
	programa.startMenu();
	/*
	cout << "Do you want to see the most successful mentor?(y/n)" << endl;
	char option2;
	cin >> option2;
	if (option2 == 'y') {
		programa.MentorSuccess();
	}
	*/

	cout << "Wait on for the next season \n Auditions will begin next Summer" << endl;
	cout << "All you have to do is register as an Artist Account at www.nbcthevoice.com and the following steps will be provided.";
	cout << endl << endl << endl;
	cout << "Executive Producers \n Carolina Azevedo, Daniela Joao and Eduarda Cunha" << endl;
	cout << endl << "Supervising Producers \n Ana Paula Rocha, Henrique Lopes Cardoso and Rosaldo Rossetti" << endl;
	char option;

	cout << "PRESS ANY LETTER TO CONTINUE" << endl;
	cin >> option;

	return 0;
}
