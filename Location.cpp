#include <iostream>
#include "Location.h"
using namespace std;

Location::Location() {
	
}

Location::~Location() {
	
}

Location::Location(int newCaveNumber) {
	caveNumber=newCaveNumber;
}

int Location::getCaveNumber() {
	return caveNumber;
}

int Location::getPit1() {
	return pitRoom1;
}

int Location::getPit2() {
	return pitRoom2;
}

int Location::getBats1() {
	return batsRoom1;
}

int Location::getBats2() {
	return batsRoom2;
}

int Location::getWumpus() {
	return wumpusRoom;
}

int Location::getBandit() {
	return banditRoom;
}

int Location::getArrowRoom() {
	return arrowRoom;
}

int Location::getOilRoom() {
	return oilRoom;
}

int Location::getVampRoom() {
	return vampRoom;
}


void Location::setCaveNumber(int newCaveNumber) {
	caveNumber=newCaveNumber;
}


void Location::setPit() {
	bool room=false;
	while (room==false) {
		pitRoom1=rand()%19+2;
		pitRoom2=rand()%19+2;
		if (pitRoom1!=pitRoom2) {
			room=true;
		}
	}
	
}



void Location::setBats() {
	bool room=false;
	while (room==false) {
		batsRoom1=rand()%19+2;
		if (batsRoom1!=wumpusRoom) {
			room=true;
		}
	}
	
	room=false;
	while (room==false) {
		batsRoom2=rand()%19+2;
		if (batsRoom2!=wumpusRoom&&batsRoom2!=batsRoom1) {
			room=true;
		}
	}
}

void Location::setWumpus() {
	bool room=false;
	while (room==false) {
		wumpusRoom=rand()%19+2;
		if (wumpusRoom!=batsRoom1&&wumpusRoom!=batsRoom2) {
			room=true;
		}
	}
}

void Location::setBandit() {
	bool room=false;
	while (room==false) {
		banditRoom=rand()%19+2;
		if (banditRoom!=wumpusRoom && banditRoom!=pitRoom1 && banditRoom!=pitRoom2 && banditRoom!=batsRoom1 && banditRoom!=batsRoom2) {
			room=true;
		}
	}
}

void Location::setArrowRoom() {
	bool room=false;
	while (room==false) {
		arrowRoom=rand()%19+2;
		if (arrowRoom!=pitRoom1&&arrowRoom!=pitRoom2) {
			room=true;
		}
	}
}

void Location::setOilRoom() {
	bool room=false;
	while (room==false) {
		oilRoom=rand()%19+2;
		if (oilRoom!=pitRoom1&&oilRoom!=pitRoom2) {
			room=true;
		}
	}
}


void Location::setVampRoom() {
	bool room=false;
	while (room==false) {
		vampRoom=rand()%19+2;
		if (vampRoom!=pitRoom1&&vampRoom!=pitRoom2&&vampRoom!=wumpusRoom&&vampRoom!=banditRoom&& vampRoom!=batsRoom1&&vampRoom!=batsRoom2) {
			room=true;
		}
	}
}


string Location::getCaveInfo(int newCaveNumber) {
	stringstream caveDescription;
	string caveNumberInFile="["+to_string(newCaveNumber)+"]";
	string caveVisibleExits="Cave "+to_string(newCaveNumber)+" Visible exits";
	string line="";
	fstream fileToRead;
	
	fileToRead.open("caves.txt");
	
	if (fileToRead.is_open()) {
		while (getline(fileToRead, line)) {
			if (line.find(caveNumberInFile)!=string::npos) {
				caveDescription<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
				caveDescription<<"\n"+line;
			}
			if (line.find(caveVisibleExits)!=string::npos) {
				caveDescription<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
				caveDescription<<line<<endl;
			}
		}
	}
	else {
		caveDescription<<"ERROR: not found"<<endl;
	}
	fileToRead.close();
	
	
	return caveDescription.str();
}



bool Location::isHazardAdjacent(int room1, int room2) {
	for (int counter=0; counter<3; counter++) {
		if (caveConnections[room1][counter]==room2) {
			return true;
		}
	}
	return false;
}




void Location::createLocationsArray() {
	for (int i=0; i<21; i++) {
		locations[i]=getCaveInfo(i);
	}
}


void Location::pointAtCave(int newCaveNumber) {
	
	cavesPointer=locations;
	string newCave;
	newCave=*(locations+newCaveNumber);
	
	cout<< newCave;
}

