#include "RpgHeader.h"
using namespace std;
void DropExpAndGold(Player& mainCharacter, Monster& monster)
{

	int randomExp = randomNumberGenerator(10, 25);
	int randomGold = randomNumberGenerator(5, 20);
	int exp = 0;  
	int gold = 0;

	if (monster.getDifficulty() == 1)
	{
		exp = (randomExp + monster.getLevel());
		gold = (randomGold + monster.getLevel());
	}

	else
	{
		exp = (randomExp + monster.getLevel()) * monster.getDifficulty();
		gold = (randomGold + monster.getLevel()) * monster.getDifficulty();
	}

	mainCharacter.setExperience(mainCharacter.getExperience() + exp);
	mainCharacter.setGold(mainCharacter.getGold() + gold);

	int dropChance = randomNumberGenerator(1, 100);

	if (dropChance <= 80)
	{
		int randomItem = randomNumberGenerator(1, 100);

		if ((randomItem <= 10) && (randomItem > 5))
		{
			pickRandomArmor(mainCharacter);
		}
		else if (randomItem <= 5)
		{
			pickRandomWeapon(mainCharacter);
		}
		else
		{
			pickRandomConsumable(mainCharacter);
		}
	}
	else
	{
		cout << CENTRALIZE << "No items dropped!" << endl;
	}
	
	printDrops(exp, gold);
}

void printDrops(int exp, int gold)
{
	cout << CENTRALIZE << "You gained " << exp << " experience" << endl;
	cout << CENTRALIZE << "You gained " << gold << " gold" << endl;
}

void Inventory::addItem(const Item& item)
{
	if (itemExists(item.getId()))
	{
		increaseQuantity(item.getId(), item.getQuantity());
	}
	else
	{
		items.push_back(item);
	} 

	if (item.getRarity() == "Common")
	{
		cout << CENTRALIZE << "You have found a " << GREEN << item.getName() << " X" << item.getQuantity() << RESET << "!" << endl;
	}
	else if (item.getRarity() == "Uncommon")
	{
		cout << CENTRALIZE << "You have found a " << BLUE << item.getName() << " X" << item.getQuantity() << RESET << "!" << endl;
	}
	else if (item.getRarity() == "Epic")
	{
		cout << CENTRALIZE << "You have found a " << BOLDPURPLE << item.getName() << " X" << item.getQuantity() << RESET << "!" << endl;
	}
	else if (item.getRarity() == "Legendary")
	{
		cout << CENTRALIZE << "You have found a " << BOLDYELLOW << item.getName() << " X" << item.getQuantity() << RESET << "!" << endl;
	}
	else if (item.getRarity() == "Mythical")
	{
		string rainbow = getRainbowText(item.getName());
		cout << CENTRALIZE << "You have found a " << RED << rainbow << " X" << item.getQuantity() << RESET << "!" << endl;
	}
}

void Inventory::removeItem(int itemId)
{
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (it->getId() == itemId)
		{
			items.erase(it);
			cout << CENTRALIZE << "Item removed!" << endl;
			break;
		}
	}
}

void Inventory::listItems() const
{
	system("CLS");
	string proceed;
	cout << CENTRALIZE << "Consumables: " << endl;
	listConsumables();
	cout << "\n\n\n";
	cout << CENTRALIZE << "Armors: " << endl;
	listArmors();
	cout << "\n\n\n";
	cout << CENTRALIZE << "Melee Weapons: " << endl;
	listWeapons();
	cout << "\n\n\n";
	cout << CENTRALIZE << "Magic Weapons: " << endl;
	listMagicWeapons();
	cout << "\n\n\n";
	cout << CENTRALIZE << "Press any key to continue... ";
	proceed = _getch();
	system("CLS");
}

void Inventory::listConsumables() const
{
	int i = 1;
	for (const auto& item : items)
	{
		if (item.getType() == "Consumable")
		{
			if (item.getRarity() == "Common")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << GREEN << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}	
			else if (item.getRarity() == "Uncommon")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BLUE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Epic")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDPURPLE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Legendary")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDYELLOW << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Mythical")
			{
				string rainbow = getRainbowText(item.getName());
				cout << CENTRALIZE << i << ". " << "Name:" << RED << rainbow << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
		}
	}
}

void Inventory::listArmors() const
{
	int i = 1;
	for (const auto& item : items)
	{
		if (item.getType() == "Armor")
		{
			if (item.getRarity() == "Common")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << GREEN << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Uncommon")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BLUE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Epic")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDPURPLE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Legendary")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDYELLOW << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Mythical")
			{
				string rainbow = getRainbowText(item.getName());
				cout << CENTRALIZE << i << ". " << "Name:" << rainbow << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
		}
	}

}

void Inventory::listWeapons() const
{
	int i = 1;
	for (const auto& item : items)
	{
		if (item.getType() == "Melee Weapon")
		{
			if (item.getRarity() == "Common")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << GREEN << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Uncommon")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BLUE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Epic")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDPURPLE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Legendary")
			{
				cout << CENTRALIZE << i << ". " << "Name:" << BOLDYELLOW << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Mythical")
			{
				string rainbow = getRainbowText(item.getName());
				cout << CENTRALIZE << i << ". " << "Name:" << RED << rainbow << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
		}
	}
}

void Inventory::listMagicWeapons() const
{
	int i = 0;
	for (const auto& item : items)
	{
		if (item.getType() == "Magic Weapon")
		{
			if (item.getRarity() == "Common")
			{
				cout << CENTRALIZE << i+1 << ". " << "Name:" << GREEN << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Uncommon")
			{
				cout << CENTRALIZE << i+1 << ". " << "Name:" << BLUE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Epic")
			{
				cout << CENTRALIZE << i+1 << ". " << "Name:" << BOLDPURPLE << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Legendary")
			{
				cout << CENTRALIZE << i+1 << ". " << "Name:" << BOLDYELLOW << item.getName() << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
			else if (item.getRarity() == "Mythical")
			{
				string rainbow = getRainbowText(item.getName());
				cout << CENTRALIZE << i+1 << ". " << "Name:" << RED << rainbow << RESET << ", Description : " << item.getDescription() << ", Quantity : " << item.getQuantity() << std::endl;
				cout << CENTRALIZE << "==================================================================\n" << endl;
				i++;
			}
		}
	}
}


bool Inventory::itemExists(int itemId) const
{
	for (const auto& item : items)
	{
		if (item.getId() == itemId)
		{
			return true;
		}
	}
	return false;
}

void Inventory::increaseQuantity(int itemId, int quantity)
{
	for (auto& item : items)
	{
		if (item.getId() == itemId)
		{
			item.setQuantity(item.getQuantity() + quantity);
			break;
		}
	}
}

void gamble(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	int moneyInput;
	cout << CENTRALIZE << "Welcome To The Cassino!!\n" << endl;
	cout << CENTRALIZE << "You have " << mainCharacter.getGold() << " gold." << endl;

	cout << CENTRALIZE << "Enter amount: ";
	cin >> moneyInput;

	if (moneyInput > mainCharacter.getGold())
	{
		cout << CENTRALIZE << "You do not have enough gold to gamble that amount!" << endl;
	}
	else
	{
		if (randomChance <= 60)
		{
			cout << CENTRALIZE << "You won " << moneyInput << " gold!" << endl;
			mainCharacter.setGold(mainCharacter.getGold() + moneyInput);
		}
		else
		{
			cout << CENTRALIZE << "You lost " << moneyInput << " gold!" << endl;
			mainCharacter.setGold(mainCharacter.getGold() - moneyInput);
		}
	}
}

void pickRandomConsumable(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 50)
	{
		dropCommonConsumable(mainCharacter);
	}
	else if (randomChance > 50 && randomChance <= 75)
	{
		dropUncommonConsumables(mainCharacter);
	}
	else if (randomChance > 75 && randomChance <= 90)
	{
		dropEpicConsumables(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropLegendaryConsumables(mainCharacter);
	}
	else
	{
		dropMythicalConsumable(mainCharacter);
	}
}

void pickRandomArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 50)
	{
		dropCommonArmor(mainCharacter);
	}
	else if (randomChance > 50 && randomChance <= 75)
	{
		dropUncommonArmor(mainCharacter);
	}
	else if (randomChance > 75 && randomChance <= 90)
	{
		dropEpicArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropLegendaryArmor(mainCharacter);
	}
	else
	{
		dropMythicalArmor(mainCharacter);
	}
}

void pickRandomWeapon(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);
	int itemType = randomNumberGenerator(1, 2);
	if (itemType == 1)
	{
		if (randomChance <= 50)
		{
			dropCommonMeleeWeapons(mainCharacter);
		}
		else if (randomChance > 50 && randomChance <= 75)
		{
			dropUncommonMeleeWeapons(mainCharacter);
		}
		else if (randomChance > 75 && randomChance <= 90)
		{
			dropEpicMeleeWeapons(mainCharacter);
		}
		else if (randomChance > 90 && randomChance <= 95)
		{
			dropLegendaryMeleeWeapons(mainCharacter);
		}
		else
		{
			dropMythicalMeleeWeapons(mainCharacter);
		}
	}
	else
	{
		if (randomChance <= 50)
		{
			dropCommonMagicWeapons(mainCharacter);
		}
		else if (randomChance > 50 && randomChance <= 75)
		{
			dropUncommonMagicWeapons(mainCharacter);
		}
		else if (randomChance > 75 && randomChance <= 90)
		{
			dropEpicMagicWeapons(mainCharacter);
		}
		else if (randomChance > 90 && randomChance <= 95)
		{
			dropLegendaryMagicWeapons(mainCharacter);
		}
		else
		{
			dropMythicalMagicWeapons(mainCharacter);
		}
	}
}

void Inventory::equipArmor(bool& itemEquiped, double& multiplier, int& id) const
{
	int itemSelection;
	int equip = 0;
	cout << "\n" << CENTRALIZE << "Your armors\n";
	int i = 0;
	listArmors();
	cout << "\n" << CENTRALIZE << "Pick an armor to use: ";
	cin >> itemSelection;
	handleInvalidInput();
	for (auto& item : items)
	{
		if (item.getType() == "Armor")
		{
			i++;

			if (i == itemSelection)
			{
				cout << CENTRALIZE << "You have equipped " << item.getName() << "!" << endl;
				equip = 1;
				multiplier = item.getStatMultiplier();
				id = item.getId();
				
				break;
			}
		}
	}
	if (equip == 0)
	{
		cout << CENTRALIZE << "Invalid selection!" << endl;
	}
}

void Inventory::equipWeapon(bool& itemEquiped, double& multiplier, int& id) const
{
	int itemSelection;
	int equip = 0;
	
	cout << "\n" << CENTRALIZE << "Your weapons\n";
	int i = 0;
	listWeapons();
	cout << "\n" << CENTRALIZE << "Pick a weapon to use: ";
	cin >> itemSelection;
	handleInvalidInput();
	for (auto& item : items)
	{
		if (item.getType() == "Melee Weapon")
		{
			i++;

			if (i == itemSelection)
			{
				cout << CENTRALIZE << "You have equipped " << item.getName() << "!" << endl;
				equip = 1;
				multiplier = item.getStatMultiplier();
				id = item.getId();
				break;
			}
		}
	}
	if (equip == 0)
	{
		cout << CENTRALIZE << "Invalid selection!" << endl;
	}
}

void Inventory::equipMagic(bool& itemEquiped, double& multiplier, int& id) const
{
	int itemSelection;
	int equip = 0;
	cout << "\n" << CENTRALIZE << "Your weapons\n";
	int i = 0;
	listMagicWeapons();
	cout << "\n" << CENTRALIZE << "Pick a weapon to use: ";
	cin >> itemSelection;
	handleInvalidInput();
	for (auto& item : items)
	{
		if (item.getType() == "Magic Weapon")
		{
			i++;

			if (i == itemSelection)
			{
				cout << CENTRALIZE << "You have equipped " << item.getName() << "!" << endl;
				equip = 1;
				multiplier = item.getStatMultiplier();
				id = item.getId();
				break;
			}
		}
	}
	if (equip == 0)
	{
		cout << CENTRALIZE << "Invalid selection!" << endl;
	}
}

void applyArmorMultiplier(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 101) && (id <= 150))
	{
		double newLife = mainCharacter.getMaxHealth() * multiplier;
		mainCharacter.setMaxHealth(newLife);
	}
}

void takeArmorMultiplierOff(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 101) && (id <= 150))
	{
		double newLife = mainCharacter.getMaxHealth() / multiplier;
		mainCharacter.setMaxHealth(newLife);
		if (mainCharacter.getHealth() > mainCharacter.getMaxHealth())
		{
			mainCharacter.setHealth(mainCharacter.getMaxHealth());
		}
	}
}

void applyMeleeWeaponMultiplier(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 151) && (id <= 200))
	{
		double newDamage = mainCharacter.getAttack() * multiplier;
		mainCharacter.setAttack(newDamage);
	}
}

void takeMeleeWeaponMultiplierOff(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 151) && (id <= 200))
	{
		double newDamage = mainCharacter.getAttack() / multiplier;
		mainCharacter.setAttack(newDamage);
	}
}

void applyMagicWeaponMultiplier(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 201) && (id <= 250))
	{
		double newDamage = mainCharacter.getMagic() * multiplier;
		mainCharacter.setMagic(newDamage);
	}
}

void takeMagicWeaponMultiplierOff(Player& mainCharacter, double& multiplier, int& id)
{
	if ((id >= 201) && (id <= 250))
	{
		double newDamage = mainCharacter.getMagic() / multiplier;
		mainCharacter.setMagic(newDamage);
	}
}

void randomCommonDrop(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 85)
	{
		dropCommonConsumable(mainCharacter);
	}
	else if (randomChance > 85 && randomChance <= 90)
	{
		dropCommonArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropCommonMeleeWeapons(mainCharacter);
	}
	else if (randomChance > 95 && randomChance <= 100)
	{
		dropCommonMagicWeapons(mainCharacter);
	}
	else
	{
		dropCommonConsumable(mainCharacter);
	}
}

void randomUncommonDrop(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 85)
	{
		dropUncommonConsumables(mainCharacter);
	}
	else if (randomChance > 85 && randomChance <= 90)
	{
		dropUncommonArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropUncommonMeleeWeapons(mainCharacter);
	}
	else if (randomChance > 95 && randomChance <= 100)
	{
		dropUncommonMagicWeapons(mainCharacter);
	}
	else
	{
		dropUncommonConsumables(mainCharacter);
	}
}

void randomEpicDrop(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 85)
	{
		dropEpicConsumables(mainCharacter);
	}
	else if (randomChance > 85 && randomChance <= 90)
	{
		dropEpicArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropEpicMeleeWeapons(mainCharacter);
	}
	else if (randomChance > 95 && randomChance <= 100)
	{
		dropEpicMagicWeapons(mainCharacter);
	}
	else
	{
		dropEpicConsumables(mainCharacter);
	}
}

void randomLegendaryDrop(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 85)
	{
		dropLegendaryConsumables(mainCharacter);
	}
	else if (randomChance > 85 && randomChance <= 90)
	{
		dropLegendaryArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropLegendaryMeleeWeapons(mainCharacter);
	}
	else if (randomChance > 95 && randomChance <= 100)
	{
		dropLegendaryMagicWeapons(mainCharacter);
	}
	else
	{
		dropLegendaryConsumables(mainCharacter);
	}
}

void randomMythicalDrop(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 100);

	if (randomChance <= 85)
	{
		dropMythicalConsumable(mainCharacter);
	}
	else if (randomChance > 85 && randomChance <= 90)
	{
		dropMythicalArmor(mainCharacter);
	}
	else if (randomChance > 90 && randomChance <= 95)
	{
		dropMythicalMeleeWeapons(mainCharacter);
	}
	else if (randomChance > 95 && randomChance <= 100)
	{
		dropMythicalMagicWeapons(mainCharacter);
	}
	else
	{
		dropMythicalConsumable(mainCharacter);
	}
}
