/*
 * Song.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_SONG_H_
#define SRC_SONG_H_

#include "Libraries.h"

class Song {
private:
	string name;
	string artist;
public:
	Song(string name, string artist) {this->name = name; this->artist = artist;}
	string getName() {return name;}
	string getArtist() {return artist;}
};



#endif /* SRC_SONG_H_ */
