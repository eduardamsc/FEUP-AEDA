/*
 * Season.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#include "Season.h"

Season::Season(vector<Mentor*> mentors, vector<Contestant*> contestants, vector<Song*> songs){

	this->mentors = mentors;
	this->contestants = contestants;
	this->songs = songs;
}

void Season::showMentors() {

	cout << setw(18) << " MENTORS " << endl;
	cout << setw(18) << "__________________" << endl;
	for (unsigned int i = 0; i < mentors.size(); i++) {
		cout << setw(18) << mentors.at(i)->getName() << endl;
	}
}

void Season::showContestants()
{
	int contador = 0;

	cout << setw(18) << " CONTESTANTS " << endl;
	cout << setw(18) << "__________________" << endl;

	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		for (unsigned int a = 0; a < n_turned.at(i).size(); a++)
		{


			if (n_turned.at(i).at(a) == 1) {
				contador++;

			}
		}
		cout << contestants.at(i)->getName() << "    turned :" << contador << "chair(s)" << endl;


	}
}
	

Song* Season::SongsUsed()
{
	int r = rand() % songs.size();
	songsUsed.push_back(songs.at(r));
	songs.erase(songs.begin() + r);
	return songsUsed.back();
}

void Season::addteamBlind() {

	///////////////CODIGO PARA TESTES////////////////////
	
	int i = 0;
	for (int i = 0; i < 56; i++) {
		if (i < 14)
		{
			mentors.at(0)->addTeamBlind(contestants.at(i));
		}
		else if (i < 28)
		{
			mentors.at(1)->addTeamBlind(contestants.at(i));
		}
		else if (i < 42)
		{
			mentors.at(2)->addTeamBlind(contestants.at(i));
		}
		else
		{
			mentors.at(3)->addTeamBlind(contestants.at(i));
		}
	}

	

	///////////////////CODIGO NORMAL////////////////////////
	/*
	int i = 0;
	while (i < 56)
	{
		cout << endl << "Contestant: " << contestants.at(i)->getName() << endl;
		SongsUsed();
		cout << songsUsed.back()->getName() << " - " << songsUsed.back()->getArtist() << endl;
		char tmp;

		while (1)
		{

			vector<int> mentorsTurned;
			if (mentors.at(0)->getTeamBlind().size() < 14)
			{
				cout << mentors.at(0)->getName() << ", do you want to turn your chair? (y/n)" << endl;
				cin >> tmp;
				if (tmp == 'y')
				{
					mentorsTurned.push_back(1);
				}
				else
				{
					mentorsTurned.push_back(0);
				}
			}
			else
			{
				cout << mentors.at(0)->getName() << "'s team is full" << endl;
				mentorsTurned.push_back(0);
			}

			if (mentors.at(1)->getTeamBlind().size() < 14)
			{
				cout << mentors.at(1)->getName() << ", do you want to turn your chair? (y/n)" << endl;

				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
				{
					mentorsTurned.push_back(1);
				}
				else
				{
					mentorsTurned.push_back(0);
				}
			}
			else
			{
				cout << mentors.at(1)->getName() << "'s team is full" << endl;
				mentorsTurned.push_back(0);
			}
			if (mentors.at(2)->getTeamBlind().size() < 14) {


				cout << mentors.at(2)->getName() << ", do you want to  turn your chair? (y/n)" << endl;
				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
				{
					mentorsTurned.push_back(1);
				}
				else
				{
					mentorsTurned.push_back(0);
				}
			}
			else
			{
				cout << mentors.at(2)->getName() << "'s  team is full" << endl;
				mentorsTurned.push_back(0);
			}
			if (mentors.at(3)->getTeamBlind().size() < 14) {

				cout << mentors.at(3)->getName() << ", do you want to turn your chair? (y/n)" << endl;
				char tmp;
				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
				{
					mentorsTurned.push_back(1);
				}
				else
				{
					mentorsTurned.push_back(0);
				}
			}
			else
			{
				cout << mentors.at(3)->getName() << "'s team is full" << endl;
				mentorsTurned.push_back(0);
			}

			if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[2] + mentorsTurned[3] == 0)
			{
				cout << "Are you sure? This contestant is really good! Give" << contestants.at(i)->getName() << "another shot" << endl;
				mentorsTurned.clear();
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] == 1)
			{
				cout << "Congratulations contestant you go into ";
				if (mentorsTurned[0] == 1)
				{
					cout << mentors.at(0)->getName() << endl;
					mentors.at(0)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[1] == 1)
				{
					cout << mentors.at(1)->getName() << endl;
					mentors.at(1)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[2] == 1)
				{
					cout << mentors.at(2)->getName() << endl;
					mentors.at(2)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[3] == 1)
				{
					cout << mentors.at(3)->getName() << endl;
					mentors.at(3)->addTeamBlind(contestants.at(i));
				}
				break;
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] >= 2)
			{
				while (true)
				{
					cout << "Contestant, please pick your new Coach : " << endl;
					if (mentorsTurned[0] == 1)
						cout << mentors.at(0)->getName() << endl << "Press a " << endl;
					if (mentorsTurned[1] == 1)
						cout << mentors.at(1)->getName() << endl << "Press b" << endl;
					if (mentorsTurned[2] == 1)
						cout << mentors.at(2)->getName() << endl << "Press c" << endl;
					if (mentorsTurned[3] == 1)
						cout << mentors.at(3)->getName() << endl << "Press d" << endl;

					cin.clear();
					cin >> tmp;
					if (tmp == 'a' && mentors.at(0)->getTeamBlind().size() < 14)
					{
						cout << "Congratulations " << mentors.at(0)->getName() << ", the contestant choose your team" << endl;
						mentors.at(0)->addTeamBlind(contestants.at(i));
						break;
					}
					else if (tmp == 'b' && mentors.at(1)->getTeamBlind().size() < 14)
					{
						cout << "Congratulations " << mentors.at(1)->getName() << ", the contestant choose your team" << endl;;
						mentors.at(1)->addTeamBlind(contestants.at(i));
						break;
					}
					else if (tmp == 'c' && mentors.at(2)->getTeamBlind().size() < 14)
					{
						cout << "Congratulations " << mentors.at(2)->getName() << ", the contestant choose your team" << endl;
						mentors.at(2)->addTeamBlind(contestants.at(i));
						break;
					}
					else if (tmp == 'd' && mentors.at(3)->getTeamBlind().size() < 14)
					{
						cout << "Congratulations " << mentors.at(3)->getName() << ", the contestant choose your team" << endl;
						mentors.at(3)->addTeamBlind(contestants.at(i));
						break;
					}
					else
					{
						cout << "Wrong button, try again" << endl;
					}
				}
				break;
			}
			n_turned.push_back(mentorsTurned);
		}


		i++;
	}*/
/*	cout << "Do you want to see how manny chairs each contester turned?(y/n)" << endl;
	char op;
	cin >> op;
	if (op == 'y') {
		showContestants();
	}*/
}


vector<vector<Contestant *>> Season::teamBattleFase(int a) {

	vector<Contestant *> tmp = mentors.at(a)->getTeamBlind();
	vector<vector<Contestant *>> battle;

	int option1, option2;

	while (1)
	{
		if (tmp.size() == 0)
			break;

		for (int i = 0; i < tmp.size(); i++)
		{
			cout << i + 1 << " : " << tmp.at(i)->getName() << endl;
		}

		while (1)
		{
			cout << "Please choose contestant 1 for the battle:" << endl;
			cin.clear();

			while (!(cin >> option1))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Not a number, try again" << endl;
			}
			option1--;
			cout << "Please choose contestant 2 for the battle:" << endl;
			cin.clear();

			while (!(cin >> option2))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Not a number, try again" << endl;
			}
			option2--;

			if (option1 < (tmp.size()))
			{
				if  (option2 < (tmp.size()))
				{
					if (option1 != option2)
					{
						break;
					}
				}
			}
				cout << endl << "Failed options, try again " << endl;
			}

		if (option1 != option2 && option1 < tmp.size() && option2 < tmp.size())
		{
			vector<Contestant *> btmp;
			btmp.push_back(tmp.at(option1));
			btmp.push_back(tmp.at(option2));
			if (option1 < option2)
			{
				tmp.erase(tmp.begin() + option2);
				tmp.erase(tmp.begin() + option1);
			}
			else
			{
				tmp.erase(tmp.begin() + option1);
				tmp.erase(tmp.begin() + option2);
			}

			battle.push_back(btmp);
		}
	}
	return battle;
}

vector<Song *> Season::teamBattleSongs()
{
	vector<Song *> tmp;
	for (int i = 0; i < 7; i++)
	{
		tmp.push_back(SongsUsed());
	}
	return tmp;
}

void Season::BattleFase()
{
	vector<Song *> mentor1, mentor2, mentor3, mentor4;
	vector<vector<Contestant *>> mentor1b, mentor2b, mentor3b, mentor4b;
	vector<int> option;
	while (1) {
		int a;
		bool valido = true;
		if (option.size() == 4)
			break;
		cout << "Choose your mentor(1/2/3/4): " << endl;
	
		////////////////////////////////
		///MODIFICADO//
		
	
			cout << "1. " << mentors.at(0)->getName() << endl;
			cout << "2. " << mentors.at(1)->getName() << endl;
			cout << "3. " << mentors.at(2)->getName() << endl;
			cout << "4. " << mentors.at(3)->getName() << endl;
	
		
		///////////////////////////////////
		
		
		while (!(cin >> a))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number, try again" << endl;
		}
		cout << a << endl;
		if (a < 0 && a > 4)
			valido = false;
		for (int i = 0; i < option.size(); i++)
		{
			if (a == option[i])
				valido = false;
		}
		if (valido)
		{
			option.push_back(a);
			switch (a) {
			case 1:
				mentor1b = teamBattleFase(0);
				mentor1 = teamBattleSongs();

				cout << mentors.at(0)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor1.size(); i++)
				{
					int b;
					cout << "1-" << mentor1b.at(i).at(0)->getName() << " VS " << "2- " << mentor1b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor1.at(i)->getName() << " - " << mentor1.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor1b.at(i).at(0)->getName() << endl;
						
						mentors.at(0)->addTeamBattle(mentor1b.at(i).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor1b.at(i).at(1)->getName() << endl;

						mentors.at(0)->addTeamBattle(mentor1b.at(i).at(1));
					}
				}
				cin.clear();
				break;
			case 2:
				mentor2b = teamBattleFase(1);
				mentor2 = teamBattleSongs();

				cout << endl << mentors.at(1)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor2.size(); i++)
				{
					int b;
					cout << "Contestants: "<< endl << mentor2b.at(i).at(0)->getName() << " VS " << mentor2b.at(i).at(1)->getName() << endl;
					cout << "Singing: "<< endl << mentor2.at(i)->getName() << " - " << mentor2.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					
					if (b == 1) {
						cout << "The winner is " << mentor2b.at(i).at(0)->getName() << endl;

						mentors.at(1)->addTeamBattle(mentor2b.at(i).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor2b.at(i).at(1)->getName() << endl;

						mentors.at(1)->addTeamBattle(mentor2b.at(i).at(1));
					}
					
				
				}
				cin.clear();
				break;
			case 3:
				mentor3b = teamBattleFase(2);
				mentor3 = teamBattleSongs();

				cout << "Contestants: " << endl <<  mentors.at(2)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor3.size(); i++)
				{
					int b;
					cout << "Contestants: " << endl << mentor3b.at(i).at(0)->getName() << " VS " << mentor3b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor3.at(i)->getName() << " - " << mentor3.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor3b.at(i).at(0)->getName() << endl;

						mentors.at(2)->addTeamBattle(mentor3b.at(i).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor3b.at(i).at(1)->getName() << endl;

						mentors.at(2)->addTeamBattle(mentor3b.at(i).at(1));
					}
				
				}
				cin.clear();
				break;
			case 4:

				mentor4b = teamBattleFase(3);
				mentor4 = teamBattleSongs();

				cout << mentors.at(3)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor4.size(); i++)
				{
					int b;
					cout << "Contestants: " << endl << mentor4b.at(i).at(0)->getName() << " VS " << mentor4b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor4.at(i)->getName() << " - " << mentor4.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor4b.at(i).at(0)->getName() << endl;

						mentors.at(3)->addTeamBattle(mentor4b.at(i).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor4b.at(i).at(1)->getName() << endl;

						mentors.at(3)->addTeamBattle(mentor4b.at(i).at(1));
					}
				
				}
				cin.clear();
				break;
			}
		}
			

	}
	
}

void Season::showFase() {
	vector<Contestant *> teamBattleTotal;
	bool random;
	vector<int> tmp;
	vector <float> pontuacoes;

	for (int i = 0; i < mentors.size(); i++)
	{
		vector<Contestant *> ctmp;
		ctmp = mentors[i]->getTeamBattle();
		for (int j = 0; j < ctmp.size(); j++)
		{
			teamBattleTotal.push_back(ctmp[j]);
		}
	}


	for (int i = 0; i < 14; i++)
	{
		while (1)
		{
			int r = rand() % 27;
			random = true;
			for (int j = 0; j < tmp.size(); j++)
			{
				if (r == tmp[j])
				{
					random = false;
				}
			}
			if (random)
			{
				tmp.push_back(r);
				break;
			}
		}
	}
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		gala1.push_back(teamBattleTotal[tmp[i]]);

	}
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		
		teamBattleTotal.erase(teamBattleTotal.begin() + tmp[i]);
	}

	
	////////////////////////// GALA 1 ////////////////////////////

	for (int i = 0; i < gala1.size(); i++)

	{
	
				
		songsgala.push_back(SongsUsed());

		cout << "Contestant " << gala1.at(i)->getName() << " is singing " << songsgala.at(i)->getName() << " - " << songsgala.at(i)->getArtist() << endl;
		cout << endl << "The pontuation of the mentors is (from 0 to 100):" << endl;
		float s = rand() % 99;
		cout << s;
		cout << endl << "The pontuation of the public is (from 0 to 100):" << endl;
		float q = rand() % 99;
		cout << q << endl;
		float total;
		total = ((q + s) / 2)/10;
		cout << "The final pontuation of (from 0 to 10):" << gala1.at(i)->getName() << "is..." << endl << "is..." << endl << "IS..." << total << endl;
		
		gala1.at(i)->setclassifications(total);
		pontuacoes.push_back(total);
		

	}

	vector<float>pontuacoes2 = pontuacoes;
	sort(pontuacoes2.begin(), pontuacoes2.end());

	for (int i = 0; i < 5; i++)
	{
		bool added = false;
		float batata = pontuacoes2.at(pontuacoes2.size() - (i + 1));
		for (int j = 0; j < pontuacoes.size(); j++)
		{	
			if (!added)
			{
				if (batata == pontuacoes.at(j) && winners.size() == 0)
				{
					winners.push_back(gala1.at(j));
					added = true;
				}
				else if (batata == pontuacoes.at(j))
				{
					bool frango = true;
					for (int k = 0; k < winners.size(); k++)
					{
						if (winners.at(k)->getName() == gala1.at(j)->getName())
						{
							frango = false;
							break;
						}
					}
					if (frango)
					{
						added = true;
						winners.push_back(gala1.at(j));
					}
				}
			}
		}
	}
	
	
	cout << endl << "TOP FIVE GALA1:" << endl;

	for (unsigned int k = 0; k < winners.size(); k++) {
		cout << endl <<  winners.at(k)->getName() << " - " << winners.at(k)->getclassifications() << endl;
		
	}

	char option;

	cout << "PRESS ANY LETTER TO CONTINUE" << endl;
	cin >> option;
	

	/////////////// GALA 2 ///////////////////
	vector <float> pontuacoesG2;

	gala2 = teamBattleTotal;


	for (int i = 0; i < gala2.size(); i++)

	{


		songsgala.push_back(SongsUsed());

		cout << "Contestant " << gala2.at(i)->getName() << " is singing " << songsgala.at(i + 13)->getName() << " - " << songsgala.at(i + 13)->getArtist() << endl;
		cout << endl << "The pontuation of the mentors is (from 0 to 100):" << endl;
		float s = rand() % 99;
		cout << s;
		cout << endl << "The pontuation of the public is (from 0 to 100):" << endl;
		float q = rand() % 99;
		cout << q << endl;
		float total;
		total = ((q*0.3) + (s*0.7)) / 10;
		cout << "The final pontuation of (from 0 to 10):" << gala2.at(i)->getName() << "is..." << endl << "is..." << endl << "IS..." << total << endl;

		gala2.at(i)->setclassifications(total);
		pontuacoesG2.push_back(total);


	}

	vector<float>pontuacoes3 = pontuacoesG2;
	sort(pontuacoes3.begin(), pontuacoes3.end());

	for (int i = 0; i < 5; i++)
	{
		bool added = false;
		float batata = pontuacoes3.at(pontuacoes3.size() - (i + 1));
		for (int j = 0; j < pontuacoesG2.size(); j++)
		{
			if (!added)
			{
				if (batata == pontuacoesG2.at(j) && winners2.size() == 0)
				{
					winners2.push_back(gala2.at(j));
					added = true;
				}
				else if (batata == pontuacoesG2.at(j))
				{
					bool frango = true;
					for (int k = 0; k < winners2.size(); k++)
					{
						if (winners2.at(k)->getName() == gala2.at(j)->getName())
						{
							frango = false;
							break;
						}
					}
					if (frango)
					{
						added = true;
						winners2.push_back(gala2.at(j));
					}
				}
			}
		}
	}


	cout << endl << "TOP FIVE GALA2:" << endl;

	for (unsigned int k = 0; k < winners2.size(); k++) {
		cout << endl << winners2.at(k)->getName() << " - " << winners2.at(k)->getclassifications() << endl;

	}

	//PASSA PARA O VETOR TEAMFINAL DE CADA MENTOR OS CONTESTANTS Q CHEGAM à FINAL DE CADA MENTOR


	for (unsigned int j = 0; j < mentors.size(); j++)
	{
		vector<Contestant *> mentorsTeamBattle = mentors.at(j)->getTeamBattle();
		for (unsigned int i = 0; i < winners.size(); i++)
		{
			for (unsigned int k = 0; k < mentorsTeamBattle.size(); k++)
			{
				if (winners.at(i)->getName() == mentorsTeamBattle.at(k)->getName())
				{
					mentors.at(j)->addTeamFinal(winners.at(i));
					break;
				}
			}
		}
	}

	for (unsigned int j = 0; j < mentors.size(); j++)
	{
		vector<Contestant *> mentorsTeamBattle = mentors.at(j)->getTeamBattle();
		for (unsigned int i = 0; i < winners2.size(); i++)
		{
			for (unsigned int k = 0; k < mentorsTeamBattle.size(); k++)
			{
				if (winners2.at(i)->getName() == mentorsTeamBattle.at(k)->getName())
				{
					mentors.at(j)->addTeamFinal(winners2.at(i));
					break;
				}
			}
		}
	}
		
}




void Season::FinalFase() {

	vector< Contestant*> last10;
	vector <float> pontuacao;

	for (int i = 0; i < winners.size(); i++) {
		last10.push_back(winners.at(i));
	}
	for (int j = 0; j < winners2.size(); j++) {
		last10.push_back(winners2.at(j));
	}

	for (int k = 0; k < last10.size(); k++) {

		songsgala.push_back(SongsUsed());

		cout << "Contestant " << last10.at(k)->getName() << " is singing " << songsgala.at(k + 27)->getName() << " - " << songsgala.at(k + 27)->getArtist() << endl;
		cout << endl << "The pontuation of the mentors is (from 0 to 100):" << endl;
		float s = rand() % 99;
		cout << s;
		cout << endl << "The pontuation of the public is (from 0 to 100):" << endl;
		float q = rand() % 99;
		cout << q << endl;
		float total;
		total = ((q + s) / 2) / 10;
		cout << "The final pontuation of (from 0 to 10):" << last10.at(k)->getName() << "is..." << endl << "is..." << endl << "IS..." << total << endl;

		last10.at(k)->setclassifications(total);
		pontuacao.push_back(total);

		char option;

		cin.clear();
		cout << "PRESS ANY LETTER TO CONTINUE" << endl;
		cin >> option;


	}


	vector<float> pontuacoesO = pontuacao;
	sort(pontuacoesO.begin(), pontuacoesO.end());


	vector <Contestant * > w;

	for (int z = 0; z < pontuacoesO.size(); z++)
	{
		if (pontuacao.at(z) == pontuacoesO.back())
		{
			w.push_back(last10.at(z));
		}
	}

	if (w.size() > 1)
	{
		int p = rand() % (w.size() - 1);
		winnerFinal = w.at(p);
	}
	else
	{
		winnerFinal = w.back();
	}
	for (int i = 0; i < mentors.size(); i++)
	{
		vector<Contestant* > mentorsTeamFinal = mentors.at(i)->getTeamFinal();
		for (int j = 0; j < mentorsTeamFinal.size(); j++)
		{
			if (winnerFinal->getName() == mentorsTeamFinal.at(j)->getName())
			{
				mentors.at(i)->setFinal(winnerFinal);
				i = mentors.size();
				break;
			}

		}
	}


	cout << endl;
	cout << "AND ... " << endl << "THE ... " << endl << "WINNER IS ..." << winnerFinal->getName() << endl;

	char option2;

	cout << "PRESS ANY LETTER TO CONTINUE" << endl;
	cin >> option2;

}

