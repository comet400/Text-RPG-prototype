#include "RpgHeader.h"
#include "gamble.h"
using namespace std;
void Player::setPlayerAttributes(double health, double attack, double magic, int mana, int stamina, int charisma)
{
	this->health = health;
    this->attack = attack;
	this->magic = magic;
	this->mana = mana;
	this->stamina = stamina;
	this->charisma = charisma;
}

void Player::setPlayerClassBuffs(double health, double attack, double magic, int mana, int stamina, int charisma)
{
	this->health += health;
	this->attack += attack;
	this->magic += magic;
	this->mana += mana;
	this->stamina += stamina;
	this->charisma += charisma;
}

int randomNumberGenerator(int minimum, int size)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}
	return rand() % size + minimum;
}

void Player::pickRace(Player& player)
{
	int Race = 10;
	cout << CENTRALIZE << " ================================" << endl;
	cout << CENTRALIZE << "|        Choose Your Race        |" << endl;
	cout << CENTRALIZE << " ================================" << endl;
	cout << CENTRALIZE << "| 1. Human                       |" << endl;
	cout << CENTRALIZE << "| 2. Elf                         |" << endl;
	cout << CENTRALIZE << "| 3. Tiefling                    |" << endl;
	cout << CENTRALIZE << "| 4. Orc                         |" << endl;
	cout << CENTRALIZE << "| 5. Half Insect                 |" << endl;
	cout << CENTRALIZE << " ================================\n" << endl;
	cout << CENTRALIZE << "Pick a Race: ";


	Race = _getch() - '0';
	while (Race > 5 || Race < 1)
	{
		Race = _getch() - '0';

	}
	//(int health, int attack, int magic, int mana, int stamina, int charisma)
	switch (Race)
	{
	case (HUMAN):
		player.setPlayerAttributes(85, 15, 15, 90, 90, 50); // Balanced
		player.setPlayerRace("Human");
		break;
	case (ELF):
		player.setPlayerAttributes(70, 6, 25, 120, 50, 100); // High magic and mana, lower attack and health
		player.setPlayerRace("Elf");
		break;
	case (TIEFLING):
		player.setPlayerAttributes(65, 7, 28, 110, 40, 75); // High health and attack, lower magic and mana
		player.setPlayerRace("Tiefling");
		break;
	case (ORC):
		player.setPlayerAttributes(130, 23, 5, 45, 150, 20); // Very high health and attack, very low magic and mana
		player.setPlayerRace("Orc");
		break;
	case (HALF_INSECT):
		player.setPlayerAttributes(150, 25, 0, 20, 180, 10); // High stamina, decent health and mana, lower charisma
		player.setPlayerRace("Half Insect");
		break;
	}
}

void Player::pickClass(Player& player)
{
	int playerClass = 10;

	cout << CENTRALIZE << " ===============================" << endl;
	cout << CENTRALIZE << "|        Choose Your Class      |" << endl;
	cout << CENTRALIZE << " ===============================" << endl;
	cout << CENTRALIZE << "| 1. Warrior                    |" << endl;
	cout << CENTRALIZE << "| 2. Mage                       |" << endl;
	cout << CENTRALIZE << "| 3. Necromancer                |" << endl;
	cout << CENTRALIZE << "| 4. Assassin                   |" << endl;
	cout << CENTRALIZE << "| 5. Paladin                    |" << endl;
	cout << CENTRALIZE << " ===============================\n" << endl;
	cout << CENTRALIZE << "Pick a Class: ";

	playerClass = _getch() - '0';
	while (playerClass > 5 || playerClass < 1)
	{
		playerClass = _getch() - '0';
	}
	switch
		(playerClass)
	{
	case (WARRIOR):
		player.setPlayerClassBuffs(20, 7, 0, 0, 20, 0); // High health and attack, low magic and mana
		player.setPlayerClass("Warrior");
		player.setStatusMultiplier(2.5);
		break;
	case (MAGE):
		player.setPlayerClassBuffs(0, 0, 8, 25, 0, 40); // High magic and mana, low health and attack
		player.setPlayerClass("Mage");
		player.setStatusMultiplier(3);
		break;
	case (NECROMANCER):
		player.setPlayerClassBuffs(-20, -6, 35, 10, -20, -10); // High magic and mana, low health and attack, decent stamina
		player.setPlayerClass("Necromancer");
		player.setStatusMultiplier(4);
		break;
	case (ASSASSIN):
		player.setPlayerClassBuffs(10, 8, 0, 0, 10, 45); // High attack and stamina, low health and magic
		player.setPlayerClass("Assassin");
		player.setStatusMultiplier(2.5);
		break;
	case (PALADIN):
		player.setPlayerClassBuffs(10, 5, 5, 5, 10, 5); // High health and stamina, low magic and mana
		player.setPlayerClass("Paladin");
		player.setStatusMultiplier(3);
		break;
	}
}



void printEverything(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB)
{
	system("CLS");
	bool leveledUp = checkExperience(mainCharacter,aB,Wb, MB);
	string statSkip;
	cout << fixed << setprecision(0);
	cout << CENTRALIZE << "========================================" << endl;
	cout << CENTRALIZE << "               Character Stats          " << endl;
	cout << CENTRALIZE << "========================================" << endl;
	cout << CENTRALIZE << "Health     : " << mainCharacter.getHealth() << " / " << mainCharacter.getMaxHealth() << endl;
	cout << CENTRALIZE << "Attack     : " << mainCharacter.getAttack() << endl;
	cout << CENTRALIZE << "Magic      : " << mainCharacter.getMagic() << endl;
	cout << CENTRALIZE << "Mana       : " << mainCharacter.getMana() << " / " << mainCharacter.getMaxMana() << endl;
	cout << CENTRALIZE << "Stamina    : " << mainCharacter.getStamina() << " / " << mainCharacter.getMaxStamina() << endl;
	cout << CENTRALIZE << "Charisma   : " << mainCharacter.getCharisma() << endl;
	cout << CENTRALIZE << "Player Race: " << mainCharacter.getPlayerRace() << endl;
	cout << CENTRALIZE << "Player Class: " << mainCharacter.getPlayerClass() << endl;
	cout << CENTRALIZE << "Level      : " << mainCharacter.getLevel() << endl;
	cout << CENTRALIZE << "Gold       : " << mainCharacter.getGold() << endl;
	cout << CENTRALIZE << fixed << setprecision(0) << "Experience: " << mainCharacter.getExperience() << " / " << 100 * (mainCharacter.getLevel() / 1.53) << endl;

	cout << CENTRALIZE << "========================================\n" << endl;
	
	cout << CENTRALIZE << "Press any key to continue..." ;
	statSkip = _getch();
	system("CLS");
}

void printGrid(char grid[GRIDSIZE][GRIDSIZE])
{
	for (int i = 0; i < GRIDSIZE; i++)
	{
		cout << CENTRALIZE;
		for (int j = 0; j < GRIDSIZE; j++)
		{
			if (grid[i][j] == 'O')
			{
				cout << GREEN << grid[i][j] << RESET << "   ";
			}


			else if (grid[i][j] == 'E')
			{
				cout << RED << grid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'X')
			{
				cout << YELLOW << grid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'I')
			{
				cout << BLUE << grid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'S')
			{
				cout << CYAN << grid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'N')
			{
				cout << PURPLE << grid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'B')
			{
				cout << BOLDYELLOW << grid[i][j] << RESET << "   ";
			}

		}
		cout << "\n" << endl;
	}
}

void printNerfedGrid(char grid[GRIDSIZE][GRIDSIZE])
{
	char nerfedGrid[GRIDSIZE][GRIDSIZE];

	for (int i = 0; i < GRIDSIZE; i++)
	{
		for (int j = 0; j < GRIDSIZE; j++)
		{
			nerfedGrid[i][j] = 'O';
		}
	}

	for (int i = 0; i < GRIDSIZE; i++)
	{
		cout << CENTRALIZE;
		for (int j = 0; j < GRIDSIZE; j++)
		{
			if (grid[i][j] != 'X')
			{
				cout << GREEN << nerfedGrid[i][j] << RESET << "   ";
			}

			else if (grid[i][j] == 'X')
			{
				cout << YELLOW << grid[i][j] << RESET << "   ";
			}

		}
		cout << "\n" << endl;
	}
}

void checkGrid(char grid[GRIDSIZE][GRIDSIZE], int Y, int X, Player& mainCharacter)
{
	if (grid[Y][X] == 'E')
	{
		makeMonsters(mainCharacter);
	}

	else if (grid[Y][X] == 'I')
	{
		int randomItem = randomNumberGenerator(1, 100);
		if (randomItem <= 5)
		{
			int armorOrWeapon = randomNumberGenerator(1, 2);
			if (armorOrWeapon == 1)
			{
				pickRandomArmor(mainCharacter);
			}
			else
			{
				pickRandomWeapon(mainCharacter);
			}
		}
		else
		{
			pickRandomConsumable(mainCharacter);
		}
	}

	else if (grid[Y][X] == 'S')
	{
		if (mainCharacter.getHowManySpells() != 15)
		{
			cout << CENTRALIZE << "You found a spell!" << endl;
			mainCharacter.setHowManySpells(mainCharacter.getHowManySpells() + 1);
		}
		else
		{
			cout << CENTRALIZE << "You already have all the spells! You can't carry anymore!" << endl;
		}
	}
}

void characterInForest(Player& mainCharacter)
{
	int X = GRIDSIZE / 2;
	int Y = GRIDSIZE - 1;
	bool mapOn = false;
	int playerMove = 10;
	char playerMoveChar = '0';
	char YX[GRIDSIZE][GRIDSIZE];
	bool alreadyPrinted = false;
	for (int i = 0; i < GRIDSIZE; i++)
	{
		for (int j = 0; j < GRIDSIZE; j++)
		{
			YX[i][j] = 'O';
		}
	}

	setRandomGridElements(YX);
	YX[GRIDSIZE - 1][GRIDSIZE / 2] = 'X';
	cout << CENTRALIZE << RESET << "Press a key (W = UP, S = DOWN, A = LEFT, D = RIGHT, 5 = TOGGLE MAP): \n";
	cout << CENTRALIZE << "In order to exit the forest you must reach where you started and go down!\n";
	while (playerMove != 0)
	{
		alreadyPrinted = true;
		if (mainCharacter.getHealth() <= 0)
		{
			cout << CENTRALIZE << "You are dead!" << endl;
			exit(0);
		}
		cout << CENTRALIZE;
		playerMoveChar = _getch();

		switch (playerMoveChar)
		{
		case 'W':
		case 'w':
			playerMove = UP;
			break;
		case 'S':
		case 's':
			playerMove = DOWN;
			break;
		case 'A':
		case 'a':
			playerMove = LEFT;
			break;
		case 'D':
		case 'd':
			playerMove = RIGHT;
			break;
		case '5':
			playerMove = TOGGLEMAP;
			break;
		default:
			continue; // Ignore invalid input
		}

		system("CLS");

		if (Y == 0 && playerMove == UP)
		{
			cout << CENTRALIZE << "You can't move up!" << endl;
			continue;
		}
		else if (YX[GRIDSIZE - 1][GRIDSIZE / 2] == 'X' && playerMove == DOWN)
		{
			cout << CENTRALIZE << "You exited the forest!" << endl;
			break;
		}
		else if (Y == GRIDSIZE - 1 && playerMove == DOWN)
		{
			cout << CENTRALIZE << "You can't move down!" << endl;
			continue;
		}
		else if (X == 0 && playerMove == LEFT)
		{
			cout << CENTRALIZE << "You can't move left!" << endl;
			continue;
		}
		else if (X == GRIDSIZE - 1 && playerMove == RIGHT)
		{
			cout << CENTRALIZE << "You can't move right!" << endl;
			continue;
		}
		else
		{
			switch (playerMove)
			{
			case UP:
				YX[Y][X] = 'O';
				Y -= 1;
				checkGrid(YX, Y, X, mainCharacter);
				YX[Y][X] = 'X';
				break;
			case DOWN:
				YX[Y][X] = 'O';
				Y += 1;
				checkGrid(YX, Y, X, mainCharacter);
				YX[Y][X] = 'X';
				break;
			case LEFT:
				YX[Y][X] = 'O';
				X -= 1;
				checkGrid(YX, Y, X, mainCharacter);
				YX[Y][X] = 'X';
				break;
			case RIGHT:
				YX[Y][X] = 'O';
				X += 1;
				checkGrid(YX, Y, X, mainCharacter);
				YX[Y][X] = 'X';
				break;
			case TOGGLEMAP:
				mapOn = !mapOn;
				cout << CENTRALIZE << (mapOn ? "Map is on!" : "Map is off!") << endl;
				break;
			}
		}
		
		cout << "\n\n" << endl;
		if (playerMove == UP || playerMove == DOWN || playerMove == LEFT || playerMove == RIGHT)
		{
			int randomEventChance = randomNumberGenerator(1, 100);
			if (randomEventChance >= 95)
			{
				system("CLS");
				randomEvent(mainCharacter);
			}
		}
		if (mapOn)
		{
			printGrid(YX);
		}
		else
		{
			printNerfedGrid(YX);
		}
		
	}
}

void printOptionsMenuStart(Player& mainCharacter)
{
	cout << "\n" << CENTRALIZE << "========================================" << endl;
	cout << CENTRALIZE << "                Main Menu                " << endl;
	cout << CENTRALIZE << "========================================" << endl;
	cout << CENTRALIZE << "1. Talk" << endl;
	cout << CENTRALIZE << "2. Equip Items" << endl;
	cout << CENTRALIZE << "3. Explore" << endl;
	cout << CENTRALIZE << "4. Check Inventory" << endl;
	cout << CENTRALIZE << "5. Check Stats" << endl;
	cout << CENTRALIZE << "6. Rest" << endl;
	cout << CENTRALIZE << "7. Gamble" << endl;
	cout << CENTRALIZE << "8. Dungeon" << endl;
	cout << CENTRALIZE << "9. Exit" << endl;
	if (mainCharacter.getExperience() >= 100 * (mainCharacter.getLevel() / 1.53))
	{
		cout << CENTRALIZE << "\nYou have enough experience to level up! Check your stats!!" << endl;
	}
	cout << CENTRALIZE << "========================================\n" << endl;

}

void menuSelectOptions(Player& mainCharacter)
{
	int menuChoice = 0;
	takeOffArmorBuffs defaultArmor;
	takeOffWeaponBuffs defaultWeapon;
	takeOffMagicBuffs defaultMagic;
	int itemTypeChoice = 0;
	while (menuChoice != 9)
	{
		printOptionsMenuStart(mainCharacter);
		cout << CENTRALIZE;
		menuChoice = _getch() - '0';
		system("CLS");
		if (mainCharacter.getHealth() <= 0)
		{
			cout << CENTRALIZE << "You are dead!" << endl;
			exit(0);
		}

		if (menuChoice == 1)
		{
			mainCharacter.setExperience(mainCharacter.getExperience() + 10);
			mainCharacter.setGold(mainCharacter.getGold() + 10);
		}
		else if (menuChoice == 2)
		{
			
			double multiplier = 0;
			int id = 0;
			bool itemArmorEquipped = mainCharacter.getArmorEquipped();
			bool itemWeaponEquipped = mainCharacter.getWeaponEquipped();
			bool itemMagicEquipped = mainCharacter.getMagicEquipped();

			cout << CENTRALIZE << "=======================================" << endl;
			cout << CENTRALIZE << "                Equip Menu               " << endl;
			cout << CENTRALIZE << "========================================" << endl;
			cout << "\n\n";
			cout << CENTRALIZE << "What would you like to equip?" << endl;
			cout << CENTRALIZE << "1. Armor" << endl;
			cout << CENTRALIZE << "2. Melee Weapon" << endl;
			cout << CENTRALIZE << "3. Magic Weapon" << endl;
			cout << CENTRALIZE << "4. Exit" << endl;
			cout << CENTRALIZE;
			cin >> itemTypeChoice;
			handleInvalidInput();
			system("CLS");

			if (itemTypeChoice == 1) 
			{
				
				mainCharacter.getInventory().equipArmor(itemArmorEquipped, multiplier, id);

				if (mainCharacter.getArmorEquipped() == true)
				{
					takeArmorMultiplierOff(mainCharacter, defaultArmor.multiplier, defaultArmor.id);
					mainCharacter.setArmorEquipped(false);
				}
			
				if (mainCharacter.getArmorEquipped() == false)
				{
					applyArmorMultiplier(mainCharacter, multiplier, id);
					defaultArmor.multiplier = multiplier;
					defaultArmor.id = id;
					mainCharacter.setArmorEquipped(true);
				}
				
			}
			
			else if (itemTypeChoice == 2) 
			{
				mainCharacter.getInventory().equipWeapon(itemWeaponEquipped, multiplier, id);

				if (mainCharacter.getWeaponEquipped() == true)
				{
					takeMeleeWeaponMultiplierOff(mainCharacter, defaultWeapon.multiplier, defaultWeapon.id);
					mainCharacter.setWeaponEquipped(false);
				}

				if (mainCharacter.getWeaponEquipped() == false)
				{
					applyMeleeWeaponMultiplier(mainCharacter, multiplier, id);
					defaultWeapon.multiplier = multiplier;
					defaultWeapon.id = id;
					mainCharacter.setWeaponEquipped(true);
				}
			}
			else if (itemTypeChoice == 3) 
			{
				mainCharacter.getInventory().equipMagic(itemMagicEquipped, multiplier, id);

				if (mainCharacter.getMagicEquipped() == true)
				{
					takeMagicWeaponMultiplierOff(mainCharacter, defaultMagic.multiplier, defaultMagic.id);
					mainCharacter.setMagicEquipped(false);
				}

				if (mainCharacter.getMagicEquipped() == false)
				{
					applyMagicWeaponMultiplier(mainCharacter, multiplier, id);
					defaultMagic.multiplier = multiplier;
					defaultMagic.id = id;
					mainCharacter.setMagicEquipped(true);
				}
			}
			else if (itemTypeChoice == 4)
			{
				continue;
			}
			else 
			{
				cout << CENTRALIZE << "Invalid input!" << endl;
				return;
			}
		}
		else if (menuChoice == 3)
		{
			characterInForest(mainCharacter);
		}
		else if (menuChoice == 4)
		{
			mainCharacter.getInventory().listItems();
		}
		else if (menuChoice == 5)
		{
			printEverything(mainCharacter, defaultArmor, defaultWeapon, defaultMagic);
		}
		else if (menuChoice == 6)
		{
			mainCharacter.setHealth(mainCharacter.getMaxHealth());
			mainCharacter.setMana(mainCharacter.getMaxMana());
			mainCharacter.setStamina(mainCharacter.getMaxStamina());
		}
		else if (menuChoice == 7)
		{
			gamble(mainCharacter);
		}
		else if (menuChoice == 8)
		{
			DungeonTime(mainCharacter);
		}
	}
}

void setRandomGridElements(char grid[GRIDSIZE][GRIDSIZE])
{
	int randomX = 0;
	int randomY = 0;

	grid[randomNumberGenerator(0, GRIDSIZE - 1)][randomNumberGenerator(0, GRIDSIZE - 1)] = 'S';
	grid[randomNumberGenerator(0, GRIDSIZE - 1)][randomNumberGenerator(0, GRIDSIZE - 1)] = 'B';

	for (int i = 0; i < 6; i++)
	{
		grid[randomNumberGenerator(0, GRIDSIZE - 1)][randomNumberGenerator(0, GRIDSIZE - 1)] = 'I';
	}

	for (int i = 0; i < 12; i++)
	{
		grid[randomNumberGenerator(0, GRIDSIZE - 1)][randomNumberGenerator(0, GRIDSIZE - 1)] = 'N';
	}

	for (int i = 0; i < 50; i++)
	{
		grid[randomNumberGenerator(0, GRIDSIZE - 1)][randomNumberGenerator(0, GRIDSIZE - 1)] = 'E';
	}
}

bool checkExperience(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB)
{
	int maxExperience = 100 * (mainCharacter.getLevel() / 1.53);
	
	if (mainCharacter.getExperience() >= maxExperience)
	{
		mainCharacter.setLevel(mainCharacter.getLevel() + 1);
		mainCharacter.setExperience(0);
		checkClassLevel(mainCharacter,aB,Wb,MB);
		cout << CENTRALIZE << "You entered the mystical fountain and leveled up!" << endl;
		cout << CENTRALIZE << "Your equipaments have been unequiped!" << endl;
		cout << CENTRALIZE << "Make sure to equip them again!\n" << endl;
	}
	return mainCharacter.getExperience() >= maxExperience;
}

void checkClassLevel(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB)
{
	int currentLevel = mainCharacter.getLevel();
	int previousLevel = mainCharacter.getPreviousLevel();
	takeArmorMultiplierOff(mainCharacter, aB.multiplier, aB.id);
	takeMeleeWeaponMultiplierOff(mainCharacter, Wb.multiplier, Wb.id);
	takeMagicWeaponMultiplierOff(mainCharacter, MB.multiplier, MB.id);
	if (currentLevel > previousLevel)
	{
			if (mainCharacter.getPlayerClass() == "Warrior")
			{
				mainCharacter.setHealth(mainCharacter.getHealth() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setAttack(mainCharacter.getAttack() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMagic(mainCharacter.getMagic() + 5);
				mainCharacter.setMana(mainCharacter.getMana() + 5);
				mainCharacter.setStamina(mainCharacter.getStamina() + 5 * mainCharacter.getStatusMultiplier());
			}
			else if (mainCharacter.getPlayerClass() == "Mage")
			{
				mainCharacter.setHealth(mainCharacter.getHealth() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setAttack(mainCharacter.getAttack() + 5);
				mainCharacter.setMagic(mainCharacter.getMagic() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMana(mainCharacter.getMana() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setStamina(mainCharacter.getStamina() + 5);
			}
			else if (mainCharacter.getPlayerClass() == "Necromancer")
			{
				mainCharacter.setHealth(mainCharacter.getHealth() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setAttack(mainCharacter.getAttack() + 5);
				mainCharacter.setMagic(mainCharacter.getMagic() + 8 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMana(mainCharacter.getMana() + 5);
				mainCharacter.setStamina(mainCharacter.getStamina() + 5);
			}
			else if (mainCharacter.getPlayerClass() == "Assassin")
			{
				mainCharacter.setHealth(mainCharacter.getHealth() + 3 * mainCharacter.getStatusMultiplier());
				mainCharacter.setAttack(mainCharacter.getAttack() + 7 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMagic(mainCharacter.getMagic() + 5);
				mainCharacter.setMana(mainCharacter.getMana() + 5);
				mainCharacter.setStamina(mainCharacter.getStamina() + 5 * mainCharacter.getStatusMultiplier());
			}
			else if (mainCharacter.getPlayerClass() == "Paladin")
			{
				mainCharacter.setHealth(mainCharacter.getHealth() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setAttack(mainCharacter.getAttack() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMagic(mainCharacter.getMagic() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setMana(mainCharacter.getMana() + 5 * mainCharacter.getStatusMultiplier());
				mainCharacter.setStamina(mainCharacter.getStamina() + 5 * mainCharacter.getStatusMultiplier());
			}
		
	}
	mainCharacter.setPreviousLevel(currentLevel);
	mainCharacter.setMaxHealth(mainCharacter.getHealth());
	mainCharacter.setMaxMana(mainCharacter.getMana());
	mainCharacter.setMaxStamina(mainCharacter.getStamina());
	mainCharacter.setArmorEquipped(false);
	mainCharacter.setWeaponEquipped(false);
	mainCharacter.setMagicEquipped(false);
}

void makeMonsters(Player& mainCharacter)
{
	Monster spirit("spirit", 50, 10, 5, 20, 30, 1, 1);
	Monster rottenRat("Rotten Rat", 45, 8, 4, 15, 25, 1, 1);
	Monster possessedHorse("Possessed Horse", 60, 12, 6, 20, 35, 1, 1);
	Monster nightStalker("Night Stalker", 70, 14, 7, 25, 40, 1, 1);
	Monster shadow("Shadow", 80, 16, 8, 30, 45, 1, 1);


	Monster dreadboneLurker("Dreadbone Lurker", 150, 30, 20, 40, 60, 1, 1);
	Monster twistedHellhound("Twisted Hellhound", 170, 34, 22, 45, 65, 1, 1);
	Monster cursedFlesh("Cursed Flesh", 190, 38, 24, 50, 70, 1, 1);
	Monster wendingo("Wendingo", 210, 42, 26, 55, 75, 1, 1);
	Monster bloodRevenant("Blood Revenant", 230, 46, 28, 60, 80, 1, 1);


	Monster ancientLich("Ancient Lich", 300, 60, 40, 70, 90, 1, 2);
	Monster abyssalDeathbringer("Abyssal Deathbringer", 320, 64, 42, 75, 95, 1, 2);
	Monster voidCarnage("Void Carnage", 340, 68, 44, 80, 100, 1, 2);
	Monster darkBehemoth("Dark Behemoth", 360, 72, 46, 85, 105, 1, 2);
	Monster skinWalker("Skin Walker", 380, 76, 48, 90, 110, 1, 2);


	Monster headlessHorseman("Headless Horseman", 450, 90, 60, 100, 120, 1, 3);
	Monster theGreatReaper("The Great Reaper", 480, 96, 64, 105, 125, 1, 3);
	Monster krampus("Krampus", 510, 102, 68, 110, 130, 1, 3);
	Monster banshee("Banshee", 540, 108, 72, 115, 135, 1, 3);
	Monster primordialMadness("Primordial Madness", 570, 114, 76, 120, 140, 1, 3);

	Monster weakMonsters[5] = { spirit, rottenRat, possessedHorse, nightStalker, shadow };
	Monster mediumMonsters[5] = { dreadboneLurker, twistedHellhound, cursedFlesh, wendingo, bloodRevenant };
	Monster strongMonsters[5] = { ancientLich, abyssalDeathbringer, voidCarnage, darkBehemoth, skinWalker };
	Monster legendaryMonsters[5] = { headlessHorseman, theGreatReaper, krampus, banshee, primordialMadness };

	int monsterDifficulty = randomNumberGenerator(0, 100);
	Monster randomWeakMonster = weakMonsters[randomNumberGenerator(0, 4)];
	Monster randomMediumMonster = mediumMonsters[randomNumberGenerator(0, 4)];
	Monster randomStrongMonster = strongMonsters[randomNumberGenerator(0, 4)];
	Monster randomLegendaryMonster = legendaryMonsters[randomNumberGenerator(0, 4)];

	if (monsterDifficulty <= 60)
	{
		MonsterFight(mainCharacter, randomWeakMonster);
	}
	else if (monsterDifficulty > 60 && monsterDifficulty <= 90)
	{
		MonsterFight(mainCharacter, randomMediumMonster);
	}

	if (mainCharacter.getLevel() >= 10)
	{

		if (monsterDifficulty > 90 && monsterDifficulty <= 95)
		{
			MonsterFight(mainCharacter, randomStrongMonster);
		}
		else if (monsterDifficulty > 95 && monsterDifficulty <= 100)
		{
			MonsterFight(mainCharacter, randomLegendaryMonster);
		}
	}
	else
	{
		if (monsterDifficulty <= 95)
		{
			MonsterFight(mainCharacter, randomWeakMonster);
		}
		else if (monsterDifficulty > 95 && monsterDifficulty <= 100)
		{
			MonsterFight(mainCharacter, randomMediumMonster);
		}
	}
}

