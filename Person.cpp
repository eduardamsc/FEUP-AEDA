/*
 * Person.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#include "Person.h"



Person::Person(string name)
{
	this ->name = name;
}

Contestant::Contestant(string name): Person(name)
{
}


Mentor::Mentor(string name): Person(name)
{
}

string Person::getName() {
	return name;
}

void Mentor::addTeamBlind(Contestant *c) {
	teamBlind.push_back(c);

}

void Mentor::addTeamBattle(Contestant *c) {
	teamBattle.push_back(c);
}

void Contestant::setclassifications(float a) {

	classifications = a;
}

float Contestant::getclassifications() {
	return classifications;
}


void Mentor::addTeamFinal(Contestant *c)
{
	teamFinal.push_back(c);
}
void Mentor::setFinal(Contestant *c)
{
	winner.push_back(c);
}