#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Location {
protected:
	static const int caves=21; //20 normal caves (in the game) and 1 starting cave (not in the game)
	static const int connections=3;
	int caveNumber;
	string caveInfo;
	bool wumpusAlive;
	int pitRoom1;
	int pitRoom2;
	int batsRoom1;
	int batsRoom2;
	int wumpusRoom;
	int banditRoom;
	int arrowRoom;
	int oilRoom;
	int vampRoom;
	bool vampAlive;
	
	string locations[caves];
	string * cavesPointer;
	
	//hardcoded indexes of room connections & directions using a 2 dimensional array
	int caveConnections [caves][connections]={{0,0,0},{8,2,5},{1,3,10},{12,2,4},{14,3,5},{1,4,6},{7,15,5},{8,17,6},{1,9,7},{8,10,18},{9,11,2},{10,12,19},{11,3,13},{20,12,14},{15,13,4},{6,14,16},{17,20,15},{7,16,18},{9,19,17},{18,20,11},{13,19,16}};
	
	char ConnectionDirections [caves][connections]={{'S','S','S'},{'S','E','W'},{'N','S','W'},{'N','E','W'},{'N','E','W'},{'N','S','E'},{'N','S','W'},{'N','E','W'},{'N','E','W'},{'N','E','W'},{'N','S','E'},{'N','S','W'},{'N','E','W'},{'N','E','W'},{'N','E','W'},{'N','S','E'},{'N','S','W'},{'N','S','E'},{'N','S','W'},{'N','S','E'},{'S','E','W'}};
	

	
	
public:
	Location();
	Location(int);
	
	~Location();
	
	int getCaveNumber();
	int getPit1();
	int getPit2();
	int getBats1();
	int getBats2();
	int getWumpus();
	int getBandit();
	int getArrowRoom();
	int getOilRoom();
	int getVampRoom();
	
	
	void setCaveNumber(int);
	void setPit();
	void setBats();
	void setWumpus();
	void setBandit();
	void setArrowRoom();
	void setOilRoom();
	void setVampRoom();
	
	string getCaveInfo(int);
	bool isHazardAdjacent(int, int);
	
	void createLocationsArray();
	void pointAtCave(int);

	
};

#endif /* LOCATION_H */
