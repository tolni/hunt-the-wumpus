#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "Location.h"
using namespace std;



class Player : virtual public Location {
protected:
	string playerName;
	int noOfArrows;
	int amountOfOil;
	int playerIndex;
	bool playerAlive;
	
	
    
	
public:
	Player();
	Player(string, int, int);
	
	~Player();
	
	string getPlayerName();
	int getNoOfArrows();
	int getAmountOfOil();
	int getPlayerIndex();
	
	void setPlayerName(string);
	void setNoOfArrows(int);
	void setAmountOfOil(int);
	void setPlayerIndex(int);
	
	string getAllPlayerDetails();
	string cheatGame();
	
	void askForPlayerName();
	void shootArrow(char);
	void deductOil();
	void die();
	bool checkIfPlayerAlive();
	void movePlayer(int, char);
	void teleportPlayer(int);
	
	

	
};


#endif /* PLAYER_H */
