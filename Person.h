/*
 * Person.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include "Libraries.h"
#include "Song.h"

class Person {
protected:
	string name;

public:
	/**
	 * @brief Destrutor da classe Person
	 */
	~Person();
	/**
	 * @brief Construtor da classe Person
	 * @param name Nome da pessoa
	 */
	Person(string name);
	/**
	 * @brief Torna acesso possível ao atributo protegido name
	 * @return Nome da pessoa (mentor ou concorrente)
	 */
	string getName();
};

class Contestant: public Person {
	vector<Song*> songs;
	float classifications;

public:
	/**
	 * @brief Construtor da classe Contestant
	 * @param name Nome do concorrente (atributo vindo da classe mãe Person)
	 */
	Contestant(string name);
	/**
	 * @brief Mete as pontuações com o valor recebido de a
	 * @param a Pontuação recebida em cada fase aleatoriamente pelo público e/ou mentores
	 */
	void setclassifications(float a);
	/**
	 * @brief Torna acesso possível ao atributo implicitamente privado classifications
	 * @return Pontuações dos concorrentes
	 */
	float getclassifications();
};

class Mentor: public Person { //o valor das equipas � passado por apontador para n�o criar copias da mesma informa��o
	vector<Contestant*> teamBlind; //equipa na fase cega
	vector<Contestant*> teamBattle; //equipa na fase de batalha
	vector<Contestant*> teamFinal; //quem ta final do mentor
	vector<Contestant*> winner; //quem ganhou a final 
	

public:
	/**
	 * @brief Construtor da classe Mentor
	 * @param name Nome do mentor (atributo vindo da classe mãe Person)
	 */
	Mentor(string name);
	/**
	 * @brief Torna acesso possível ao atributo implicitamente privado teamBlind
	 * @return Vetor com equipa do dado mentor na fase Cega
	 */
	vector<Contestant*> getTeamBlind() {return teamBlind;}
	/**
	 * @brief Torna acesso possível ao atributo implicitamente privado teamBattle
	 * @return Vetor com equipa do dado mentor na fase de Batalha
	 */
	vector<Contestant*> getTeamBattle() {return teamBattle;}
	/**
	 * @brief Torna acesso possível ao atributo implicitamente privado teamFinal
	 * @return Vetor com concorrentes na fase Final
	 */
	vector<Contestant*> getTeamFinal() { return teamFinal; }
	/**
	 * @brief Torna acesso possível ao atributo implicitamente privado winner
	 * @return Vetor com vencedor da temporada
	 */
	vector<Contestant*> getWinner() { return winner; }
	/**
	 * @brief Adiciona concorrentes ao vetor da equipa da fase Cega
	 * @param c Apontador para um concorrente
	 */
	void addTeamBlind(Contestant *c);
	/**
	 * @brief Adiciona concorrentes ao vetor da equipa da fase de Batalha
	 * @param c Apontador para um concorrente
	 */
	void addTeamBattle(Contestant *c);
	/**
	 * @brief Adiciona concorrentes ao vetor da fase Final
	 * @param c Apontador para um concorrente
	 */
	void addTeamFinal(Contestant *c);
	/**
	 * @brief Adiciona concorrente ao vetor do Vencedor
	 * @param c Apontador para o concorrente que vai ganhar
	 */
	void setFinal(Contestant *c);

};




#endif /* SRC_PERSON_H_ */
