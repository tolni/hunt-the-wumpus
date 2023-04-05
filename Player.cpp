#include <iostream>
#include "Player.h"
using namespace std;


Player::Player() : Location() {
	
}

Player::Player(string newName, int newNoOfArrows, int newAmountOfOil) : Location() {
	playerName=newName;
	noOfArrows=newNoOfArrows;
	amountOfOil=newAmountOfOil;
}

Player::~Player() {
	
}

string Player::getPlayerName() {
	return playerName;
}

int Player::getNoOfArrows() {
	return noOfArrows;
}

int Player::getAmountOfOil() {
	return amountOfOil;
}

int Player::getPlayerIndex() {
	return playerIndex;
}

void Player::setPlayerName(string newName) {
	playerName=newName;
}

void Player::setNoOfArrows(int newNoOfArrows) {
	noOfArrows=newNoOfArrows;
}

void Player::setAmountOfOil(int newAmountOfOil) {
	amountOfOil=newAmountOfOil;
}

void Player::setPlayerIndex(int newPlayerIndex) {
	playerIndex=newPlayerIndex;
}

string Player::getAllPlayerDetails() {
	stringstream playerDetails;
	
	playerDetails<<"\nNumber of arrows left: "<<getNoOfArrows();
	playerDetails<<"\nAmount of oil left (number of turns): "<<getAmountOfOil()<<endl;
	
	return playerDetails.str();
}


string Player::cheatGame() {
	
	stringstream hazardIndex;
	if (vampAlive==true&&wumpusAlive==true) {
		hazardIndex<<"\n+ + + + + + + + + + + + +";
		hazardIndex<<"\nWUMPUS is in: "<<Location::getWumpus();
		hazardIndex<<"\nBANDIT is in: "<<Location::getBandit();
		hazardIndex<<"\nVAMPIRE is in: "<<Location::getVampRoom();
		hazardIndex<<"\nPITS are in: "<<Location::getPit1()<<", "<<Location::getPit2();
		hazardIndex<<"\nBATS are in: "<<Location::getBats1()<<", "<<Location::getBats2();
		hazardIndex<<"\nROOM WITH ARROWS is in: "<<Location::getArrowRoom();
		hazardIndex<<"\nROOM WITH OIL is in: "<<Location::getOilRoom();
		hazardIndex<<"\n+ + + + + + + + + + + + +"<<endl;
	}
	if (vampAlive==false&&wumpusAlive==true) {
		hazardIndex<<"\n+ + + + + + + + + + + + +";
		hazardIndex<<"\nWUMPUS is in: "<<Location::getWumpus();
		hazardIndex<<"\nBANDIT is in: "<<Location::getBandit();
		hazardIndex<<"\nPITS are in: "<<Location::getPit1()<<", "<<Location::getPit2();
		hazardIndex<<"\nBATS are in: "<<Location::getBats1()<<", "<<Location::getBats2();
		hazardIndex<<"\nROOM WITH ARROWS is in: "<<Location::getArrowRoom();
		hazardIndex<<"\nROOM WITH OIL is in: "<<Location::getOilRoom();
		hazardIndex<<"\n+ + + + + + + + + + + + +"<<endl;
	}
	if (wumpusAlive==false&&vampAlive==true) {
		hazardIndex<<"\n+ + + + + + + + + + + + +";
		hazardIndex<<"\nBANDIT is in: "<<Location::getBandit();
		hazardIndex<<"\nVAMPIRE is in: "<<Location::getVampRoom();
		hazardIndex<<"\nPITS are in: "<<Location::getPit1()<<", "<<Location::getPit2();
		hazardIndex<<"\nBATS are in: "<<Location::getBats1()<<", "<<Location::getBats2();
		hazardIndex<<"\nROOM WITH ARROWS is in: "<<Location::getArrowRoom();
		hazardIndex<<"\nROOM WITH OIL is in: "<<Location::getOilRoom();
		hazardIndex<<"\n+ + + + + + + + + + + + +"<<endl;
	}
	if (wumpusAlive==false&&vampAlive==false) {
		hazardIndex<<"\n+ + + + + + + + + + + + +";
		hazardIndex<<"\nBANDIT is in: "<<Location::getBandit();
		hazardIndex<<"\nPITS are in: "<<Location::getPit1()<<", "<<Location::getPit2();
		hazardIndex<<"\nBATS are in: "<<Location::getBats1()<<", "<<Location::getBats2();
		hazardIndex<<"\nROOM WITH ARROWS is in: "<<Location::getArrowRoom();
		hazardIndex<<"\nROOM WITH OIL is in: "<<Location::getOilRoom();
		hazardIndex<<"\n+ + + + + + + + + + + + +"<<endl;
	}

	return hazardIndex.str();
}


void Player::askForPlayerName() {
	cout<<"Before we begin, what is your name, brave adventurer?: ";
	cin>>playerName;
}



void Player::shootArrow(char direction) {
	cout<<"\nYou listen expectantly for the sound of a large beast crying out in agony to echo throughout the caverns..."<<endl;
	
	int directionIndex=0;
	while (directionIndex<3) {
		if (ConnectionDirections[playerIndex][directionIndex]==direction) {
			break;
		}
		directionIndex++;
	}
	

	
	if (caveConnections[playerIndex][directionIndex]==wumpusRoom) {
		wumpusAlive=false;
		wumpusRoom=-1;
		cout<<"\nYou hear the piercing roar of a Wumpus, followed by pin-drop silence. You head carefully into the dark cave where the noise came from and you could not believe your eyes... The corpse of a Wumpus lies in front of you!!!"<<endl;
	}
	else {
		cout<<"\nHmm... after a minute you suspect that something is amiss (probably your aim) as there are no echoing screams... only pin-drop silence...no nothing! So, are you gonna sit around and contemplate your navel or what?!"<<endl;
	}
	noOfArrows--;
	
	if (noOfArrows==0) {
		playerAlive=false;
	}
	else {
		playerAlive=true;
	}
}

void Player::deductOil() {
	int randInt=0;
	randInt=rand()%3 + 2;
	
	amountOfOil=amountOfOil-randInt;
}


void Player::die() {
	playerAlive=false;
}

bool Player::checkIfPlayerAlive() {
	return playerAlive;
}


void Player::movePlayer(int currentCave, char direction) {
	
	bool validMove=false;
	
	
	while (validMove==false) {
		if (ConnectionDirections[currentCave][0]==direction||ConnectionDirections[currentCave][1]==direction||ConnectionDirections[currentCave][2]==direction) {
					//gets index of direction entered in connectiondirection array
					int directionIndex=0;
					while (directionIndex<3) {
						if (ConnectionDirections[currentCave][directionIndex]==direction) {
							break;
						}
						directionIndex++;
					}
			
					int newCaveNumber=caveConnections[currentCave][directionIndex];
			
					setPlayerIndex(newCaveNumber);
			
					string temp;
					temp=getCaveInfo(newCaveNumber);
					cout<< temp;
					validMove=true;
		}
		else {
			cout<<"\nYou do not see an exit in that direction.";
			cout<<"\nEnter a new direction: ";
			cin>>direction;
		}
	}
}




void Player::teleportPlayer(int newCaveNumber) {
	cavesPointer=locations;
	string newCave;
	newCave=*(cavesPointer+newCaveNumber);
	
	cout<<newCave;
}




