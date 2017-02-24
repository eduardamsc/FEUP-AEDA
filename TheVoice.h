/*
 * TheVoice.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_THEVOICE_H_
#define SRC_THEVOICE_H_

#include "Libraries.h"
#include "Person.h"
#include "Season.h"


class TheVoice
{
public:
	//*******************************DATA*********************************

	vector<Contestant*> contestants;
	vector<Mentor*> mentors;
	vector<Song*> songs;
	vector<Season> seasons;

	//***************************FUNCTIONS*********************************
	/**
	 * @brief Gera a temporada em si
	 */
	void newSeason();
	void showMentors();
	void MentorSuccess();


	//*******************************MENUS*********************************
	/**
	 * @brief Menu que permite ao utilizador escolher quantas temporadas quer simular e as cria
	 */
	void startMenu();
	void FirstPhaseMenu();
	void SecondPhaseMenu();
	void ThirdPhaseMenu();
	void FinalPhaseMenu();
		


	//*******************************SAVES & LOADS ***************************
	/**
	 * @brief Faz com que todos os loads se efetuem
	 */
	void loadAll();
	/**
	 * @brief Mete num vetor todas as músicas disponíveis no documento Songs.txt
	 */
	void loadSongs();
	/**
	 * @brief Mete num vetor todos os concorrentes disponíveis no documento contestants.txt
	 */
	void loadContestants();
	/**
	 * @brief Mete num vetor todos os mentores disponíveis no documento mentors.txt
	 */
	void loadMentors();

	//************************************AUXILIAR***********
};


#endif /* SRC_THEVOICE_H_ */
