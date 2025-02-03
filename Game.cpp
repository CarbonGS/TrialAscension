//#include "Game.h"
//#include <chrono> 
//#include <thread>
//
//void Level::difficulty(int level)
//{
//	switch (level)
//	{
//	case 1:
//		levelNumber = 1;
//		name = "Laverna: Goddess of Thieves";
//		health = 65;
//		mana = 0;
//		damage = 10;
//		defense = 10;
//		crit = 1;
//		break;
//	case 2:
//		levelNumber = 2;
//		name = "Furiae: Dieties of Vengence";
//		health = 75;
//		mana = 0;
//		damage = 20;
//		crit = 2;
//		break;
//	case 3:
//		levelNumber = 3;
//		name = "Lemures: Spirits of the Dead";
//		health = 85;
//		mana = 0;
//		damage = 20;
//		crit = 2;
//		break;
//	case 4:
//		levelNumber = 4;
//		name = "Pluto: God of Hades";
//		health = 100;
//		mana = 0;
//		damage = 30;
//		defense = 10;
//		crit = 5;
//		break;
//	}
//}
//
//void Game::startGame()
//{
//
//	// Initialize boss data for each difficulty level
//	Level level;
//	bosses.resize(4);
//	for (int lvl = 1; lvl < bosses.size() + 1; lvl++) 
//	{ 
//		level.difficulty(lvl);
//		
//		bosses[lvl - 1] = level;
//	}
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	SetConsoleTextAttribute(hConsole, 12);
//	std::cout << "Welcome to Trail: Ascension!" << std::endl;
//
//	SetConsoleTextAttribute(hConsole, 14);
//	std::cout << "\nPLEASE READ ALL ELEMENTS THOROUGHLY! SCREENS WILL BE CLEARED AND YOU WILL NOT BE ABLE TO RETURN TO PREVIOUS SCREENS." << std::endl;
//	SetConsoleTextAttribute(hConsole, 15);
//
//	// Initialize player data to base values
//	Player player = Player(3);
//	player.setHealth(100);
//	player.setMana(100);
//	player.startingSkill();
//	player.startingWeapon();
//	player.setDefense(10);
//	player.setStatPoints(0);
//
//	// Start at level 1
//	level.difficulty(0);
//	level.setLevelNumber(0); 
//
//	// Initial game state
//	SetConsoleTextAttribute(hConsole, 7);
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//	system("cls");
//	int lvl = level.getLevelNumber();
//	level.difficulty(lvl);
//	// First boss message
//	SetConsoleTextAttribute(hConsole, 4);
//	std::cout << "You have encountered a dungeon guardian - " << bosses[level.getLevelNumber()].getName() << "\n" << std::endl;
//
//	// Main game loop
//	while (player.getHealth() != 0 || bosses[3].getHealth() != 0) {
//		
//		if (player.getHealth() != 0)
//		{
//			int weapon = player.chooseAttackWeapon();
//			player.attack(weapon, bosses[lvl]);
//		}
//		if (bosses[lvl].getHealth() > 0) {
//			bosses[lvl].attack(player);
//		}
//		if (player.getHealth() == 0) // End Game Condition
//		{
//			SetConsoleTextAttribute(hConsole, 4);
//			std::cout << "You have been defeated by " << bosses[level.getLevelNumber()].getName() << std::endl;
//			std::cout << "Game Over!" << std::endl;
//			SetConsoleTextAttribute(hConsole, 15);
//			break; // End game
//		}
//		if (bosses[lvl].getHealth() <= 0 && level.getLevelNumber() == 3) // Win Game Condition
//		{
//			SetConsoleTextAttribute(hConsole, 9);
//			std::cout << "Congratulations! You have defeated the final boss " << bosses[level.getLevelNumber()].getName() << std::endl;
//			std::cout << "You have ascended through the final trial!" << std::endl;
//			SetConsoleTextAttribute(hConsole, 15);
//			std::cout << "\nThank you for playing Trial: Ascension!" << std::endl;
//			std::this_thread::sleep_for(std::chrono::seconds(7));
//			break; // End game
//		}
//		else if (bosses[lvl].getHealth() <= 0) // Level up condition
//		{
//			// Level up message
//			system("cls");
//			SetConsoleTextAttribute(hConsole, 9);
//			std::cout << "You have defeated " << bosses[lvl].getName() << std::endl;
//			std::cout << "Congratulations on Beating level: " << level.getLevelNumber() + 1 << std::endl;
//			std::cout << "You have ascended to the next level!" << std::endl;
//			SetConsoleTextAttribute(hConsole, 10);
//			std::cout << "You have gained a stat point!\n" << std::endl;
//			SetConsoleTextAttribute(hConsole, 15);
//
//			// Change to next level
//			level.setLevelNumber(level.getLevelNumber() + 1);
//			lvl = level.getLevelNumber();
//			player.setStatPoints(player.getStatPoints() + 1);
//
//			// New boss message
//			SetConsoleTextAttribute(hConsole, 4);
//			std::cout << "You have encountered a new floor guardian - " << bosses[level.getLevelNumber()].getName() << "\n" << std::endl;
//
//			// Reset player health and mana for next level
//			switch (player.getSkill())
//			{
//			case offensive:
//				player.setHealth(90);
//				player.setMana(100);
//				break;
//			case defensive:
//				player.setHealth(100);
//				player.setDefense(20);
//				player.setMana(80);
//				break;
//			}
//			SetConsoleTextAttribute(hConsole, 15);
//			std::cout << "Your stats have been reset for the next level!" << std::endl << "(";
//			SetConsoleTextAttribute(hConsole, 10);
//			std::cout << "Health: " << player.getHealth();
//			SetConsoleTextAttribute(hConsole, 9);
//			std::cout << " Mana: " << player.getMana() << "/100";
//			SetConsoleTextAttribute(hConsole, 8);
//			std::cout << " Defense: " << player.getDefense();
//			SetConsoleTextAttribute(hConsole, 15);
//			std::cout << ")" << "\n" << std::endl;
//			
//		}
//		
//	}
//	
//}
