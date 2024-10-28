#include "RpgHeader.h"
using namespace std;
void MonsterFight(Player& mainCharacter, Monster& monster)
{
	int id = 0;
	int healAmount = 0;
	setMonsterLevelstats(mainCharacter, monster);
	int playerChoice = 0;
	int justFound = 0;
	cout << endl;
	bool runAway = false;
	bool playerBlock = false;
	if (monster.getHealth() <= 0)
	{
		cout << CENTRALIZE << "You defeated the " << monster.getName() << "!" << endl;
		DropExpAndGold(mainCharacter, monster);
		return;
	}
	while (mainCharacter.getHealth() > 0 && monster.getHealth() > 0 && runAway == false)
	{
		if (monster.getHealth() <= 0)
		{
			cout << CENTRALIZE << "You defeated the " << monster.getName() << "!" << endl;
			DropExpAndGold(mainCharacter, monster);
			return;
		}
		
		printMonsterStats(monster, mainCharacter);
		if (justFound == 0)
		{
			cout << CENTRALIZE << "You encountered a " << monster.getName() << "!" << endl;
			justFound++;
		}

		cout << endl;
		playerBlock = false;
		cout << CENTRALIZE << "1. Attack" << endl;
		cout << CENTRALIZE << "2. Block" << endl;
		cout << CENTRALIZE << "3. Items" << endl;
		cout << CENTRALIZE << "4. Run" << endl;
		cout << CENTRALIZE << "Choose an option: ";
		cin >> playerChoice;
		while (playerChoice < 1 || playerChoice > 4)
		{
			cin >> playerChoice;
		}

		switch (playerChoice)
		{
		case ATTACK:
			turnAttack(mainCharacter, monster);
			break;

		case BLOCK:
			playerBlock = true;
			break;

		case ITEMS:
			 id = 0;
			 healAmount = mainCharacter.getInventory().useItem(id);
			handleConsumableGeneral(mainCharacter, id, healAmount);
			break;
		case RUN:
			int runChance = randomNumberGenerator(0, 100);

			if (runChance <= 50)
			{
				cout << CENTRALIZE << "You ran away!" << endl;
				runAway = true;
			}
			else
			{
				cout << CENTRALIZE << "You failed to run away!" << endl;
				runAway = false;
			}
			break;
		}

		if (runAway == false)
		{
			monsterAttack(mainCharacter, monster, playerBlock);
		}
	}
}


void turnAttack(Player& mainCharacter, Monster& monster)
{
	int playerAbility = 0;
	bool legendaryAbility = false;
	int legendary = 3;

	cout << "\n" << CENTRALIZE << "1. Basic Attack" << endl;
	cout << CENTRALIZE << "2. Spell" << endl;
	cout << CENTRALIZE << "3. Hesitate\n" << endl;
	if (legendaryAbility)
	{
		cout << CENTRALIZE << "4. Legendary Ability" << endl;
		legendary = 4;
	}

	cout << CENTRALIZE << "Choose an option: ";
	cin >> playerAbility;
	clearInputBuffer();
	while (playerAbility > legendary || playerAbility < 1)
	{
		cin >> playerAbility;
		clearInputBuffer();
	}

	switch (playerAbility)
	{
	case 1:
		handleBasicAttack(mainCharacter, monster);
		break;
	case 2:
		handleSpellAttack(mainCharacter, monster);
		break;
	case 3:
		system("CLS");
		break;
	}
}

void handleBasicAttack(Player& mainCharacter, Monster& monster)
{
	Abilities abilities;
	switch (checkWhichClass(mainCharacter))
	{
	case WARRIOR:
		warriorBasicAbility(mainCharacter, monster, abilities);
		break;
	case MAGE:
		mageBasicAbility(mainCharacter, monster, abilities);
		break;
	case NECROMANCER:
		necromancerBasicAbilities(mainCharacter, monster, abilities);
		break;
	case ASSASSIN:
		assassinBasicAbilities(mainCharacter, monster, abilities);
		break;
	case PALADIN:
		paladinBasicAbilities(mainCharacter, monster, abilities);
		break;
	}
}

void handleSpellAttack(Player& mainCharacter, Monster& monster)
{
	Abilities abilities;
	switch (checkWhichClass(mainCharacter))
	{
	case WARRIOR:
		warriorSpellAbility(mainCharacter, monster, abilities);
		break;
	case MAGE:
		mageSpecialAbility(mainCharacter, monster, abilities);
		break;
	case NECROMANCER:
		necromancerSpecialAbilities(mainCharacter, monster, abilities);
		break;
	case ASSASSIN:
		assassinSpecialAbilities(mainCharacter, monster, abilities);
		break;
	case PALADIN:
		paladinSpecialAbilities(mainCharacter, monster, abilities);
		break;
	}
}

int checkWhichClass(Player& mainCharacter)
{
	if (mainCharacter.getPlayerClass() == "Warrior")
	{
		return WARRIOR;
	}
	else if (mainCharacter.getPlayerClass() == "Mage")
	{
		return MAGE;
	}
	else if (mainCharacter.getPlayerClass() == "Necromancer")
	{
		return NECROMANCER;
	}
	else if (mainCharacter.getPlayerClass() == "Assassin")
	{
		return ASSASSIN;
	}
	else if (mainCharacter.getPlayerClass() == "Paladin")
	{
		return PALADIN;
	}
	else
	{
		return NULL;
	}
}


void monsterAttack(Player& mainCharacter, Monster& monster, bool isBlocking)
{
	int monsterAbility = randomNumberGenerator(1, 2);
	int totalDamage = 0;
	if (monster.getHealth() <= 0)
	{
		cout << CENTRALIZE << "You defeated the " << monster.getName() << "!" << endl;
		DropExpAndGold(mainCharacter, monster);
		return;
	}
	if (monsterAbility == 1)
	{
		totalDamage = randomNumberGenerator(monster.getAttack() / 2 - 2, monster.getAttack() * 2);
		cout << CENTRALIZE << "The " << monster.getName() << " used a physical attack!\n" << endl;
	}
	else if (monsterAbility == 2)
	{
		totalDamage = randomNumberGenerator(monster.getMagic() / 2 - 2, monster.getMagic() * 2);
		cout << CENTRALIZE << "The " << monster.getName() << " used a magical attack!\n" << endl;
	}

	if (totalDamage < 0)
	{
		totalDamage = 0;
	}

	if (isBlocking)
	{
		totalDamage = totalDamage / 2;
		mainCharacter.setMana(mainCharacter.getMana() + 15);
		mainCharacter.setStamina(mainCharacter.getStamina() + 15);
		checkIfStatMax(mainCharacter);
		cout << CENTRALIZE << "You blocked the attack!\n" << endl;
	}

	mainCharacter.setHealth(mainCharacter.getHealth() - totalDamage);
	system("CLS");
	cout << CENTRALIZE << "The " << monster.getName() << CENTRALIZE << " dealt " << totalDamage << " damage!\n" << endl;
}

void setMonsterLevelstats(Player& mainCharacter, Monster& monster)
{
	monster.setLevel(randomNumberGenerator(mainCharacter.getLevel() - 1, mainCharacter.getLevel() + 1));
	if (monster.getLevel() <= 1)
	{
		monster.setLevel(1);
	}
	monster.scaleStats();

}

void checkIfStatMax(Player& player)
{
	if (player.getHealth() > player.getMaxHealth())
	{
		player.setHealth(player.getMaxHealth());
	}
	if (player.getStamina() > player.getMaxStamina())
	{
		player.setStamina(player.getMaxStamina());
	}
	if (player.getMana() > player.getMaxMana())
	{
		player.setMana(player.getMaxMana());
	}
}

void printMonsterStats(Monster& monster, Player& mainCharacter)
{
	cout << CENTRALIZE << "Monster Stats\t\t" << "Player Stats" << endl;
	cout << CENTRALIZE << "-------------------------------------" << "------------------" << endl;
	cout << CENTRALIZE << "Health: " << monster.getHealth() << "\t\t" << "Health: " << mainCharacter.getHealth() << "/ " << mainCharacter.getMaxHealth() << endl;
	cout << CENTRALIZE << "Attack: " << monster.getAttack() << "\t\t" << "Attack: " << mainCharacter.getAttack() << endl;
	cout << CENTRALIZE << "Magic: " << monster.getMagic() << "\t\t" << "Magic: " << mainCharacter.getMagic() << endl;
	cout << CENTRALIZE << "Mana: " << monster.getMana() << "\t\t" << "Mana: " << mainCharacter.getMana() << "/ " << mainCharacter.getMaxMana() << endl;
	cout << CENTRALIZE << "Stamina: " << monster.getStamina() << "\t\t" << "Stamina: " << mainCharacter.getStamina() << "/ " << mainCharacter.getMaxStamina() << endl;
	cout << CENTRALIZE << "Level: " << monster.getLevel() << "\t\t" << "Level: " << mainCharacter.getLevel() << endl;
	cout << CENTRALIZE << "-------------------------------------" << "------------------" << endl;

}

int Inventory::useItem(int& id) 
{
	int itemSelection;
	cout <<"\n" << CENTRALIZE << "Your items\n";
	int i = 0;
	listConsumables();
	cout << "\n" << CENTRALIZE << "Pick an item to use: ";
	cin >> itemSelection;
	handleInvalidInput();

	for (auto& item : items)
	{
		if (item.getType() == "Consumable")
		{
			i++;

			if (i == itemSelection)
			{
				cout << CENTRALIZE << "select how many you want to use: ";
				int quantity;
				cin >> quantity;
				handleInvalidInput();
				
				if (quantity > item.getQuantity())
				{
					cout << CENTRALIZE << "You don't have that many!" << endl;
					cout << CENTRALIZE << "Your turn is skipped!\n" << endl;
					return 0;
				}
				else
				{
					item.setQuantity(item.getQuantity() - quantity);
					cout << CENTRALIZE << "You used " << quantity << " " << item.getName() << "!" << endl;
					cout << CENTRALIZE << "You have " << item.getQuantity() << " " << item.getName() << " left!" << endl;
					id = item.getId();
					if (item.getQuantity() <= 0)
					{
						removeItem(item.getId());
					}
					return item.getBuffs()*quantity;
				}	

			}
		}
	}
	if (itemSelection != i)
	{
		cout << CENTRALIZE << "You don't have that item!" << endl;
		cout << CENTRALIZE << "Your turn is skipped!" << endl;
		return 0;
	}
	system("CLS");
	return 0;
}

void handleConsumableGeneral(Player& mainCharacter, int& id, int& healAmount)
{
	if (id >= 1 && id <= 3 || id == 21 || id == 22 || id == 23 || id == 41 || id == 42 || id == 43 || id == 61 || id == 62 || id == 63 || id == 81 || id == 82 || id == 83)
	{
		// Restores Health
		mainCharacter.setHealth(mainCharacter.getHealth() + healAmount);
	}
	else if (id == 4 || id >= 24 && id <= 26 || id >= 44 && id <= 46 || id >= 64 && id <= 66 || id >= 84 && id <= 86)
	{
		// Restores Mana
		mainCharacter.setMana(mainCharacter.getMana() + healAmount);
	}
	else if (id == 7 || id >= 27 && id <= 29 || id >= 47 && id <= 49 || id >= 67 && id <= 69 || id >= 87 && id <= 89)
	{
		// Restores Stamina
		mainCharacter.setStamina(mainCharacter.getStamina() + healAmount);
	}
	else if (id == 10 || id == 11 || id == 12 || id == 30 || id == 31 || id == 32 || id == 50 || id == 51 || id == 52 || id == 70 || id == 71 || id == 72 || id == 90 || id == 91 || id == 92)
	{
		// Restores Health and Mana
		mainCharacter.setHealth(mainCharacter.getHealth() + healAmount);
		mainCharacter.setMana(mainCharacter.getMana() + healAmount);
	}
	else if (id == 13 || id == 14 || id == 15 || id == 16 || id == 33 || id == 34 || id == 35 || id == 36 || id == 53 || id == 54 || id == 55 || id == 56 || id == 73 || id == 74 || id == 75 || id == 76 || id == 93 || id == 94 || id == 95 || id == 96)
	{
		// Restores Health and Stamina
		mainCharacter.setHealth(mainCharacter.getHealth() + healAmount);
		mainCharacter.setStamina(mainCharacter.getStamina() + healAmount);
	}
	else if (id == 17 || id == 18 || id == 19 || id == 37 || id == 38 || id == 39 || id == 57 || id == 58 || id == 59 || id == 77 || id == 78 || id == 79 || id == 97 || id == 98 || id == 99)
	{
		// Restores Mana and Stamina
		mainCharacter.setMana(mainCharacter.getMana() + healAmount);
		mainCharacter.setStamina(mainCharacter.getStamina() + healAmount);
	}
	else if (id == 20 || id == 40 || id == 60 || id == 80 || id == 100)
	{
		// Restores Health, Mana, and Stamina
		mainCharacter.setHealth(mainCharacter.getHealth() + healAmount);
		mainCharacter.setMana(mainCharacter.getMana() + healAmount);
		mainCharacter.setStamina(mainCharacter.getStamina() + healAmount);
	}
	checkIfStatMax(mainCharacter);
}

void DungeonTime(Player& mainCharacter)
{
	
	cout << CENTRALIZE << "====================\n";
	cout << CENTRALIZE << "++Dungeon Menu++\n";
	cout << CENTRALIZE << "====================\n";
		int dungeonChoice = 0;
		cout << CENTRALIZE << "1. Small Dungeon" << endl;
		cout << CENTRALIZE << "2. Medium Dungeon" << endl;
		cout << CENTRALIZE << "3. Large Dungeon" << endl;
		cout << CENTRALIZE << "4. Legendary Dungeon" << endl;
		cout << CENTRALIZE << "5. Nightmare Dungeon" << endl;
		cout << CENTRALIZE << "6. Exit" << endl;
		cout << CENTRALIZE << "====================\n\n";
		cout << CENTRALIZE << "Choose an option: ";
		cin >> dungeonChoice;
		clearInputBuffer();
		while (dungeonChoice < 1 || dungeonChoice > 6)
		{
			cin >> dungeonChoice;
			clearInputBuffer();
		}
		if (dungeonChoice == 6)
		{
			return;
		}
		if (dungeonChoice == 1)
		{
				easyDungeon(mainCharacter);
		}
		else if (dungeonChoice == 2)
		{
			mediumDungeon(mainCharacter);
		}
		else if (dungeonChoice == 3)
		{
			largeDungeon(mainCharacter);
		}
		else if (dungeonChoice == 4)
		{
			legendaryDungeon(mainCharacter);
		}
}

void easyDungeon(Player& mainCharacter)
{
	if (mainCharacter.getLevel() >= 3)
	{
		cout << CENTRALIZE << "You have entered the small dungeon!" << endl;
		cout << CENTRALIZE << "You will face three random monsters and you might get a prize in the end!" << endl;
		for (int i = 0; i < 2; i++)
		{
			makeMonsters(mainCharacter);
			if (mainCharacter.getHealth() <= 0)
			{
				cout << CENTRALIZE << "You died in the dungeon!" << endl;
				exit(0);
			}
		}
		int randomPrize = randomNumberGenerator(1, 100);
		int randomType = randomNumberGenerator(1, 3);
		if (randomPrize <= 90)
		{
			if (randomType == 1)
			{
				dropCommonArmor(mainCharacter);
			}
			else if (randomType == 2)
			{
				dropCommonMeleeWeapons(mainCharacter);
			}
			else if (randomType == 3)
			{
				dropCommonMagicWeapons(mainCharacter);
			}
		}
		else
		{
			if (randomType == 1)
			{
				dropUncommonArmor(mainCharacter);
			}
			else if (randomType == 2)
			{
				dropUncommonMeleeWeapons(mainCharacter);
			}
			else if (randomType == 3)
			{
				dropUncommonMagicWeapons(mainCharacter);
			}
		}
	}
	else
	{
		cout << "\n";
		cout << CENTRALIZE << "You dont have enough level to enter this dungeon!" << endl;
		cout << CENTRALIZE << "You must be level 3 or higher!" << endl;
	}
}

void mediumDungeon(Player& mainCharacter)
{
	if (mainCharacter.getLevel() >= 6)
	{
		cout << CENTRALIZE << "You have entered the medium dungeon!" << endl;
		cout << CENTRALIZE << "You will face five random monsters and you might get a prize in the end!" << endl;
		for (int i = 0; i < 3; i++)
		{
			makeMonsters(mainCharacter);
			if (mainCharacter.getHealth() <= 0)
			{
				cout << CENTRALIZE << "You died!" << endl;
				return;
			}
		}
		int randomPrize = randomNumberGenerator(1, 100);
		int randomType = randomNumberGenerator(1, 3);
		if (randomPrize <= 90)
		{
			if (randomType == 1)
			{
				dropUncommonArmor(mainCharacter);
			}
			else if (randomType == 2)
			{
				dropUncommonMeleeWeapons(mainCharacter);
			}
			else if (randomType == 3)
			{
				dropUncommonMagicWeapons(mainCharacter);
			}
		}
		else
		{
			if (randomType == 1)
			{
				dropEpicArmor(mainCharacter);
			}
			else if (randomType == 2)
			{
				dropEpicMeleeWeapons(mainCharacter);
			}
			else if (randomType == 3)
			{
				dropEpicMagicWeapons(mainCharacter);
			}
		}
	}
	else
	{
		cout << "\n";
		cout << CENTRALIZE << "You dont have enough level to enter this dungeon!" << endl;
		cout << CENTRALIZE << "You must be level 6 or higher!" << endl;
	}
}

void largeDungeon(Player& mainCharacter)
{
	if (mainCharacter.getLevel() >= 9)
	{
		cout << CENTRALIZE << "You have entered the large dungeon!" << endl;
		cout << CENTRALIZE << "You will face seven random monsters and you might get a prize in the end!" << endl;
		for (int i = 0; i < 6; i++)
		{
			makeMonsters(mainCharacter);
			if (mainCharacter.getHealth() <= 0)
			{
				cout << "You died!" << endl;
				return;
			}
		}
		
		int randomType = randomNumberGenerator(1, 3);
		
			if (randomType == 1)
			{
				dropEpicArmor(mainCharacter);
			}
			else if (randomType == 2)
			{
				dropEpicMeleeWeapons(mainCharacter);
			}
			else if (randomType == 3)
			{
				dropEpicMagicWeapons(mainCharacter);
			}
	}
	else
	{
		cout << "\n";
		cout << CENTRALIZE << "You dont have enough level to enter this dungeon!" << endl;
		cout << CENTRALIZE << "You must be level 9 or higher!" << endl;
	}
}

void legendaryDungeon(Player& mainCharacter)
{
	if (mainCharacter.getLevel() >= 15)
	{
		cout << CENTRALIZE << "You have entered the legendary dungeon!" << endl;
		cout << CENTRALIZE << "You will face ten random monsters and you might get a prize in the end!" << endl;
		for (int i = 0; i < 9; i++)
		{
			makeMonsters(mainCharacter);
			if (mainCharacter.getHealth() <= 0)
			{
				cout << CENTRALIZE << "You died!" << endl;
				return;
			}
		}

		int randomType = randomNumberGenerator(1, 3);

		if (randomType == 1)
		{
			dropLegendaryArmor(mainCharacter);
		}
		else if (randomType == 2)
		{
			dropLegendaryMeleeWeapons(mainCharacter);
		}
		else if (randomType == 3)
		{
			dropLegendaryMagicWeapons(mainCharacter);
		}
	}
	else
	{
		cout << "\n";
		cout << CENTRALIZE << "You dont have enough level to enter this dungeon!" << endl;
		cout << CENTRALIZE << "You must be level 12 or higher!" << endl;
	}
} 