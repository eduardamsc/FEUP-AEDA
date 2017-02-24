/*
 * Saves.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#include "TheVoice.h"
#include <iomanip>
#include <sstream> 

void TheVoice::loadAll()
{
	loadMentors();
	loadContestants();
	loadSongs();
	//loadSeasons();

}

void TheVoice::loadContestants()
{

	ifstream doc;
	doc.open("contestants.txt");
	string tmp;
	int numOfContestants = 0;
	vector<Contestant*> contestantstmp;

	if(doc.is_open())
	{
		getline(doc, tmp);
		numOfContestants = stoi(tmp.c_str());
		for(int i = 0; i < numOfContestants; i++)
		{
			getline(doc,tmp);
			Contestant *a1 = new Contestant(tmp);
			contestantstmp.push_back(a1);
		}

	}
	doc.close();
	for(int i = 0; i < numOfContestants;i++)
	{
		contestants.push_back(contestantstmp[i]);
	}

}

void TheVoice::loadMentors()
{
	ifstream doc;
	doc.open("mentors.txt");
	string tmp;
	int numOfMentors = 0;
	vector<Mentor*> mentorstmp;
	doc.is_open();
	if(doc.is_open())
	{
		getline(doc,tmp);
		numOfMentors = stoi(tmp.c_str());
		for(int i = 0; i < numOfMentors; i++)
		{
			getline(doc, tmp);
			Mentor *a1 = new Mentor(tmp);
			mentorstmp.push_back(a1);
		}
	}


	doc.close();
	for(int i = 0; i < numOfMentors; i++)
	{
		mentors.push_back(mentorstmp[i]);
	}
}

void TheVoice::loadSongs() {
	ifstream doc;
	doc.open("Songs.txt");
	string tmp;
	int numOfSongs = 0;
	vector<Song *> songstmp;
	string name;
	string artist;


	if (doc.is_open())
	{
		getline(doc, tmp);
		numOfSongs = stoi(tmp.c_str());
		for (int i = 0; i < numOfSongs; i++)
		{
			getline(doc, tmp);
			name = tmp;
			getline(doc, tmp);
			artist = tmp;

			Song *s1 = new Song(name, artist);
			songstmp.push_back(s1);
		}
	}
	doc.close();
	for (int i = 0; i < numOfSongs; i++)
	{
		songs.push_back(songstmp[i]);
	}
}


	
