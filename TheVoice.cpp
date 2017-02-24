 /*
 * TheVoice.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */
#include "TheVoice.h"



void TheVoice::newSeason()
{

	vector<int> tmp;
	vector<Mentor *> mentorsTmp;
	vector<Contestant *> contestantsTmp;
	vector<Contestant *> teamBlindTmp;
	vector<Song*> songsTmp;
	bool random = true;

	//Load dos concorrentes para o vetor

	for(int i = 0; i < 56; i++)
	{
		while(1)
		{
			int r = rand() %199;
			random = true;
			for (int j = 0; j < tmp.size(); j++)
			{
				if(r == tmp[j])
				{
					random = false;
				}
			}
			if(random)
			{
				tmp.push_back(r);
				break;
			}

		}
	}
	for(unsigned int i = 0; i < tmp.size(); i++)
	{
		contestantsTmp.push_back(contestants[tmp[i]]);
	}
	tmp.clear();


	// Load dos mentores para o vetor
	for(int i = 0; i < 4; i++)
	{
		while(1)
		{
			int r = rand() %9;
			random = true;
			for(int j = 0; j < tmp.size(); j++)
			{
				if(r == tmp[j])
				{
					random = false;
				}
			}
			if(random)
			{
				tmp.push_back(r);
				break;
			}
		}
	}
	for(unsigned int i = 0; i < tmp.size(); i++)
	{
		mentorsTmp.push_back(mentors[tmp[i]]);
	}

	Season a1 (mentorsTmp, contestantsTmp, songs);
	seasons.push_back(a1);
}


void TheVoice::MentorSuccess() {


	vector<Contestant *> winners1 = mentors.at(0)->getWinner();
	vector<Contestant *> winners2 = mentors.at(1)->getWinner();
	vector<Contestant *> winners3 = mentors.at(2)->getWinner();
	vector<Contestant *> winners4 = mentors.at(3)->getWinner();
	vector <int> tmp;
	vector<int> tmpO;


	tmp.push_back(winners1.size());
	tmp.push_back(winners2.size());
	tmp.push_back(winners3.size());
	tmp.push_back(winners4.size());
	
	tmpO = tmp;

	sort(tmpO.begin(), tmpO.end());

	for (int i = 0; i < tmp.size(); i++)
		if (tmp.at(i) == tmpO.back()) {
			cout << " The most successful mentor is: " << mentors.at(i)->getName() << endl;
		}
}

/*
bool TheVoice::inputCharCorrect(char c)
{
	char tmp;
	while (1)
	{
		cin >> tmp;
		if (c == tmp)
		{
			return true;
		}
		else
		{
			cout << "Wrong input, try again" << endl;
		}
	}
}
*/