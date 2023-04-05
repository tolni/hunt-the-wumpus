#ifndef HUNTTHEWUMPUS_H
#define HUNTTHEWUMPUS_H
#include <string>
#include <sstream>
#include "Location.h"
#include "Player.h"

class WumpusGame : virtual public Location, public Player {
private:
	bool isGameOver;
	int turnCounter;


public:
	void intro();
	void quitGame();
	void resetGame();
	void playGame();
	string showEndGameStats();
	void gameOver();
	bool checkGameOver();
	void moveWumpusEvery5turns();
	void moveBanditCheckVamp();
	void moveStartledWumpus();
	void checkCurrentRoom();
	string showBanner();






};

#endif /* HUNTTHEWUMPUS_H */
