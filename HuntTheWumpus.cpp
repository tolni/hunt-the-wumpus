#include <iostream>
#include "HuntTheWumpus.h"
#include "Player.h"
#include "Location.h"
using namespace std;








int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	
	WumpusGame game;
	Location location;
	Player player;
	
	game.playGame();
	
	
	cout << endl;
	system ("pause");
	return 0;
}















void WumpusGame::intro() {
	askForPlayerName();
	
	cout<<"***********************************************************************";
	cout<<"\n\t\t\t\t\tWumpus Hunter Orientation\t\t\t\t\t";
	cout<<"\n***********************************************************************";
	cout<<"\nYou have been training for this for as long as you can remember.";
	cout<<"\nFinally, as the shadowy caves appear in front of you, a vile stench";
	cout<<"\ncrawls up your nose.";
	cout<<"\nYou ready yourself one last time as you prepare to descend into the";
	cout<<"\ndark complex of caverns, ready to hunt for the notorious Wumpus";
	cout<<"\nand Vlad the Vampire that have terrorized the villagers for generations.";
	cout<<"\nIn exchange for the beast’s head, the elders have offered the village’s";
	cout<<"\nriches as a reward."<<endl<<endl;
	
	cout<<"\nEnter any key to continue...";
	char playerInput='a';
	cin>>playerInput;
	
	
	cout<<"\n\nAs you walk, you review the plan once again:";
	cout<<"\n\t• You will move through caves by inputting N, S, E, or W.";
	cout<<"\n\t• The Wumpus is asleep in one of the 20 caves. It wakes up and moves to another cave to sleep every 5 turns. It is too massive to be bothered by the Superbats and has sucker feet.";
	cout<<"\n\t• Each cave has 3 tunnels leading from it to other caves.";
	cout<<"\n\t\t• Two of the caves are bottomless pits: if you enter, you die… Unless bats are in that room too, then you're in luck: they'll lift you away from the bottomless abyss.";
	cout<<"\n\t\t• Two other caves have super bats: if you enter, they will carry you to another random cave. ";
	cout<<"\n\t\t• There is a cave bandit living in these caverns. This bandit preys on distracted adventurers looking for the Wumpus, stealing their valuables from them to sell (20 oil from your lantern). The bandit has developed exceptional night vision from living here for years and thus is able to avoid hazardous caves, and dodges your arrows before you can hit him. The bandit moves from cave to cave every 2 turns. Due to his extensive knowledge of the caves, he is able to move to caves that are not connected to each other via the caverns' secret tunnels.";
	cout<<"\n\t\t• The elders of the village also asked for a favour to hunt a legendary vampire named Vald that lives in one of the caves. They couldn't tell you much as no one has ever made it back from the caverns alive, but from stories passed down from their ancestors, in order to kill one, you must enter its cave and use wooden arrows to weaken it, then set it on fire with oil. It stays within the darkness of one cave and never moves so as to avoid sunlight. They specifically asked for one of its fangs as proof of its death and are willing to double the reward for this.";
	cout<<"\n\t• The Wumpus only wakes up if you wander into its lair or if you shoot your weapon and miss your shot.";
	cout<<"\n\t\t• If you manage to wake a Wumpus, there is a 75% chance it moves to an adjacent cave, and a 25% chance it goes back to sleep where it is.";
	cout<<"\n\t\t• If it moves into the same cave you are in, you die…";
	cout<<"\n\t• In your leather pouch, you have a map, a lantern with a limited amount of oil (starting from 100), and a bow with 5 arrows.";
	cout<<"\n\t• Each time you may move to an adjacent cave, in one of the 4 standard compass direction (N, S, E, W).";
	cout<<"\n\t• You can also choose to shoot an arrow into a cave [shoot] to hopefully kill the Wumpus.";
	cout<<"\n\t\t• Moving or shooting will reduce the amount of oil you have (by a random value between 2 and 4 each time).";
	cout<<"\n\t• You also brought your secret weapon with you: an Environmental Sensor, which allows you to look at the location of the Wumpus, bandit, pits, and super bats by entering 'Z' to cheat.";
	cout<<"\n\t\t• When you are one cave away from a hazard, it will vibrate and give you a clue what lies ahead but not its direction.";
	cout<<"\n\t• You can quit the game by entering 'Q' to QUIT.";
	cout<<"\n\t• You win only if you can successfully kill both the Wumpus and Vlad the Vampire.";
	cout<<"\n\t• You lose if your lantern runs out of oil, or if you run out of arrows, or if you fall into a pit, or if you end up in the same cave as the Wumpus."<<endl;
	cout<<"\nQuite simple isn't it? Once you are ready, press any key to start your descend into darkness...";
	char userInput2='a';
	cin>>userInput2;
}

void WumpusGame::quitGame() {
	playerAlive=false;
	isGameOver=true;
	cout<<"\nGoodbye. Come back when you're ready again... The village needs you!!"<<endl;
}

void WumpusGame::resetGame() {
	Player::setNoOfArrows(5);
	Player::setAmountOfOil(100);
	Player::setPlayerIndex(1);
	playerAlive=true;
	wumpusAlive=true;
	isGameOver=false;
	turnCounter=1;
	createLocationsArray();
	setCaveNumber(playerIndex);
	setPit();
	setBats();
	setWumpus();
	setBandit();
	setArrowRoom();
	setOilRoom();
	setVampRoom();
	vampAlive=true;
}


void WumpusGame::playGame() {
	
	intro();
	
	resetGame();
		
	cout<<showBanner();
	
	cout<<getCaveInfo(playerIndex);
	
	while (isGameOver==false) {
		
		checkGameOver();
		
		checkCurrentRoom();
		
		if(playerAlive==true) {
			
			cout<<getAllPlayerDetails();
			
			bool loop=true;
			
			while (loop==true) {
				
				cout<<"\nPlease enter one of the following: N for North, S for South, W for West, E for East, A for shoot, Z to cheat, Q for quit.";
				cout<<"\nWhat now, "<<getPlayerName()<<"?";
				char userInput='a';
				cin>>userInput;
				
				switch (userInput) {
					case 'N':
					case 'n':
						movePlayer(playerIndex, 'N');
						deductOil();
						turnCounter++;
						moveWumpusEvery5turns();
						moveBanditCheckVamp();
						checkGameOver();
						loop=false;
						break;
						
					case 'S':
					case 's':
						movePlayer(playerIndex, 'S');
						deductOil();
						turnCounter++;
						moveWumpusEvery5turns();
						moveBanditCheckVamp();
						checkGameOver();
						loop=false;
						break;
						
					case 'W':
					case 'w':
						movePlayer(playerIndex, 'W');
						deductOil();
						turnCounter++;
						moveWumpusEvery5turns();
						moveBanditCheckVamp();
						checkGameOver();
						loop=false;
						break;
						
					case 'E':
					case 'e':
						movePlayer(playerIndex, 'E');
						deductOil();
						turnCounter++;
						moveWumpusEvery5turns();
						moveBanditCheckVamp();
						checkGameOver();
						loop=false;
						break;
					
					case 'A':
					case 'a':
					{
						bool loop2=true;
						while (loop2==true) {
							cout<<"Which Direction?: ";
							char userDirection='a';
							cin>>userDirection;
							
							switch (userDirection) {
								case 'N':
								case 'n':
									shootArrow('N');
									deductOil();
									turnCounter++;
									checkGameOver();
									moveWumpusEvery5turns();
									moveStartledWumpus();
									moveBanditCheckVamp();
									loop2=false;
									break;
							
								case 'S':
								case 's':
									shootArrow('S');
									deductOil();
									turnCounter++;
									checkGameOver();
									moveWumpusEvery5turns();
									moveStartledWumpus();
									moveBanditCheckVamp();
									loop2=false;
									break;
							
								case 'W':
								case 'w':
									shootArrow('W');
									deductOil();
									turnCounter++;
									checkGameOver();
									moveWumpusEvery5turns();
									moveStartledWumpus();
									moveBanditCheckVamp();
									loop2=false;
									break;
								
								case 'E':
								case 'e':
									shootArrow('E');
									deductOil();
									turnCounter++;
									checkGameOver();
									moveWumpusEvery5turns();
									moveStartledWumpus();
									moveBanditCheckVamp();
									loop2=false;
									break;
								
								default:
									cout<<"That's not a direction... Are you sure you passed the basic navigation course in the Wumpus Hunter Certification Trial??"<<endl;
									loop2=true;
							}
						}
						loop=false;
						break;
					}
					case 'Z':
					case 'z':
						cout<<cheatGame();
						loop=true;
						break;
						
					case 'Q':
					case 'q':
						quitGame();
						loop=false;
						break;
						
					default:
						cout<<"I don't know how to do that."<<endl;
						loop=true;
				}
				isGameOver=checkGameOver();
			}
		}
		
		
		
	}
	gameOver();
}
	
	
	
	



string WumpusGame::showEndGameStats() {
	stringstream endGameStats;
	
	endGameStats<<"\n\n\n+ + + + + + + + + + + + + + + + + + + + + + + + + + +";
	endGameStats<<"\n\t\t\t\t"<<getPlayerName()<<"'s "<<"Performance\t\t\t\t";
	endGameStats<<"\n+ + + + + + + + + + + + + + + + + + + + + + + + + + +";
	if (wumpusAlive==false&&vampAlive==false) {
		endGameStats<<"\n\t\t\t\t\tYOU WON!!!\t\t\t\t\t"<<endl;
	}
	else {
		endGameStats<<"\n\t\t\t\t\tYOU LOST...\t\t\t\t\t"<<endl;
	}
	endGameStats<<"\nNumber of arrows left: "<<getNoOfArrows();
	endGameStats<<"\nAmount of oil left: "<<getAmountOfOil();
	endGameStats<<"\nNumber of turns taken: "<<turnCounter;
	endGameStats<<"\n+ + + + + + + + + + + + + + + + + + + + + + + + + + +";
	int score=0;
	score=noOfArrows+amountOfOil-turnCounter;
	endGameStats<<"\nSCORE: "<<score;
	if (score>=70&&wumpusAlive==false&&vampAlive==false) {
		endGameStats<<"\nGRADE: EXCEPTIONAL";
	}
	if (score<70&&score>=40&&wumpusAlive==false&&vampAlive==false) {
		endGameStats<<"\nGRADE: NOT BAD";
	}
	if (score<40||wumpusAlive==true||vampAlive==true) {
		endGameStats<<"\nGRADE: LETS NOT TALK ABOUT THAT...";
	}
	endGameStats<<"\n+ + + + + + + + + + + + + + + + + + + + + + + + + + +"<<endl;
	
	return endGameStats.str();
}


void WumpusGame::gameOver() {
	isGameOver=true;
	cout<<showEndGameStats();
}


bool WumpusGame::checkGameOver() {
	bool gameOver=false;
	
	if (isGameOver==true) {
		gameOver=true;
	}
	if (noOfArrows==0) {
		gameOver=true;
	}
	else if (amountOfOil<=0) {
		gameOver=true;
	}
	else if (playerAlive==false) {
		gameOver=true;
	}
	else if (wumpusAlive==false&&vampAlive==false) {
		gameOver=true;
	}
	else {
		gameOver=false;
	}
	return gameOver;
}


void WumpusGame::moveWumpusEvery5turns() {
	if (wumpusAlive==true) {
		if (turnCounter%5==0) {
			int random=rand()%3;
			bool validRoom=false;
			while (validRoom==false) {
				wumpusRoom=caveConnections[wumpusRoom][random];
				if (wumpusRoom!=batsRoom1&&wumpusRoom!=batsRoom2) {
					validRoom=true;
				}
			}
		}
	}
	else {
	}
}


void WumpusGame::moveBanditCheckVamp() {
	
	bool validRoom=false;
	int oldBanditRoom=banditRoom;
	if (turnCounter%2==0) {
		while (validRoom==false) {
			banditRoom=rand()%20+1;
			if (banditRoom!=oldBanditRoom && banditRoom!=wumpusRoom && banditRoom!=batsRoom1 && banditRoom!=batsRoom2 && banditRoom!=pitRoom1 && banditRoom!=pitRoom2) {
				validRoom=true;
			}
		}
	}
	
	if (playerIndex==vampRoom) {
		int randArrow=rand()%2+2;
		noOfArrows=noOfArrows-randArrow;
		int randOil=rand()%11+30;
		amountOfOil=amountOfOil-randOil;
		cout<<"\nVAMPIRE!!! He tried to bite your arm before you used "<<randArrow<<" arrows and "<<randOil<<" oil to kill it. You pry off one of his fangs to bring back to the village elders."<<endl;
		vampAlive=false;
		if (wumpusAlive==false) {
			isGameOver=true;
		}
		
		
		vampRoom=caveConnections[0][0];
		
	}
}



void WumpusGame::moveStartledWumpus() {
	if (wumpusAlive==true) {
		int random=rand()%4;
		if (random!=3) {
			int random2=rand()%3;
			bool validRoom=false;
			while (validRoom==false) {
				wumpusRoom=caveConnections[wumpusRoom][random2];
				if (wumpusRoom!=batsRoom1&&wumpusRoom!=batsRoom2) {
					validRoom=true;
				}
			}
		cout<<"\nShhh...listen... Its the sound of a Wumpus moving about..."<<endl;
		}
	}
	else {
	}
}


void WumpusGame::checkCurrentRoom() {
	
	if (playerIndex==arrowRoom) {
		noOfArrows=noOfArrows+5;
		cout<<"\nYou pick up an old abandoned quiver from the ground."<<endl;
	}
	
	if (playerIndex==oilRoom) {
		amountOfOil=amountOfOil+20;
		cout<<"\nYou stumble upon an old jerry can containing some oil."<<endl;
	}
	
	if (playerIndex==banditRoom) {
		amountOfOil=amountOfOil-20;
		cout<<"\nYou check your bag and realised the bandit stole some of your oil... (oil-20)"<<endl;
	}
	
	if (playerIndex==wumpusRoom) {
		playerAlive=false;
		isGameOver=true;
		cout<<"\nYOU BECAME THE WUMPUS'S LUNCH!!!"<<endl;
		
	}
	else if (playerIndex==pitRoom1||playerIndex==pitRoom2) {
		cout<<"\nYOU FELL TO YOUR DEATH!!!"<<endl;
		playerAlive=false;
		isGameOver=true;
		
	}
	else if (playerIndex==batsRoom1||playerIndex==batsRoom2) {
		cout<<"\nSNATCHED BY SUPERBATS!!!"<<endl;
		bool newRoom=false;
		bool newBatRoom=false;
		int oldPlayerIndex=playerIndex;
		if (playerIndex==pitRoom1||playerIndex==pitRoom2) {
			cout<<"\nWhat luck... The Superbats just saved you from falling to your death into a bottomless pit!!!"<<endl;
		}
		while (!newRoom) {
			playerIndex=rand()%20+1;
			pointAtCave(playerIndex);
			if (playerIndex!=batsRoom1 && playerIndex!=batsRoom2 && playerIndex!=wumpusRoom && playerIndex!=pitRoom1 && playerIndex!=pitRoom2 && playerIndex!=oldPlayerIndex) {
				newRoom=true;
			}
		}
		cout<<"\nThe Superbats snatched you to room ";
		cout<<playerIndex<<endl;
		
		checkCurrentRoom();
		
		
			while (!newBatRoom) {
				batsRoom1=rand()%20+1;
				
				batsRoom2=rand()%20+1;
				
				if (batsRoom1!=wumpusRoom && batsRoom1!=playerIndex && batsRoom1!=oldPlayerIndex && batsRoom2!=wumpusRoom && batsRoom2!=playerIndex && batsRoom2!=oldPlayerIndex && batsRoom1!= batsRoom2) {
					newBatRoom=true;
				}
			}
		
	}
	
	else {
		bool nothing=true;
		
		if (isHazardAdjacent(playerIndex, vampRoom)) {
			cout<<"\nYou see drops of human blood across the ground."<<endl;
			nothing=false;
		}
		
		if (isHazardAdjacent(playerIndex, banditRoom)) {
			cout<<"\nYou see many human footprints in the dirt..."<<endl;
			nothing=false;
		}
		if (isHazardAdjacent(playerIndex, wumpusRoom)) {
			cout<<"\nYou smell the stench of a Wumpus..."<<endl;
			nothing=false;
		}
		if (isHazardAdjacent(playerIndex, batsRoom1)||isHazardAdjacent(playerIndex, batsRoom2)) {
			cout<<"\nYou hear the flapping of wings..."<<endl;
			nothing=false;
		}
		if (isHazardAdjacent(playerIndex, pitRoom1)||isHazardAdjacent(playerIndex, pitRoom2)) {
			cout<<"\nYou feel a chilling breeze..."<<endl;
			nothing=false;
		}
		else if (nothing==true) {
			cout<<"\nAll seems perfectly normal here."<<endl;
		}
	}
	checkGameOver();
}



string WumpusGame::showBanner() {
	stringstream banner;
	
	banner<<"\n==================================================================================================================";
	banner<<"\n\t\t\t\t\t\t\t\t\t\tSomwhere in the Wumpus Caverns...\t\t\t\t\t\t\t\t\t\t";
	banner<<"\n==================================================================================================================";
	
	return banner.str();
}
