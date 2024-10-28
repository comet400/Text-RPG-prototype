#include"RpgHeader.h"

void randomEvent(Player& mainCharacter)
{
	int event = randomNumberGenerator(0, 5);
	Monster wildAnimal("Crazy Animal", 25, 7, 3, 16, 10, 1, 1);
	switch (event)
	{
	case 0:
		cout << CENTRALIZE << "You find a hidden treasure chest filled with gold!\n";
		mainCharacter.setGold(mainCharacter.getGold() + randomNumberGenerator(10, 100));
		cout << CENTRALIZE << "You now have " << mainCharacter.getGold() << " gold.\n";
		break;
	case 1:
		cout << CENTRALIZE << "A wild animal appears and attacks you!\n";
		MonsterFight(mainCharacter, wildAnimal);
		break;
	case 2:
		strangerMysteryBox(mainCharacter);
		break;
	case 3:
		handleMysteriousCave(mainCharacter);
		break;
	case 4:
		cout << CENTRALIZE << "You feel like something lurks around you...you feel uneasy...\n";
		cout << CENTRALIZE << "You should turn back...\n";
		mainCharacter.setMana(mainCharacter.getMana() / 2);
		mainCharacter.setStamina(mainCharacter.getStamina() / 2);
		break;
	case 5:
		handleBlackWater(mainCharacter);
		break;
	}
}

void strangerMysteryBox(Player& mainCharacter)
{
	int randomPrice = randomNumberGenerator(10, 1000);
	cout << CENTRALIZE << "He offers you a mystery box for " << randomPrice << " gold.\n";
	cout << CENTRALIZE << "You have " << mainCharacter.getGold() << " gold.\n\n";
	int choice;
	cout << CENTRALIZE << "1. Buy\n" << CENTRALIZE << "2. Ignore\n";
	cout << CENTRALIZE;
	cin >> choice;
	clearInputBuffer();
	handleInvalidInput();
	if (choice == 1)
	{
		if (mainCharacter.getGold() >= randomPrice)
		{
			cout << CENTRALIZE << "You bought the mystery box.\n";
			mainCharacter.setGold(mainCharacter.getGold() - randomPrice);
			cout << CENTRALIZE << "You now have " << mainCharacter.getGold() << " gold.\n";
			if (randomPrice >= 900)
            {
				cout << CENTRALIZE << "You open the mystery box and find a mythical weapon!\n";
				randomLegendaryDrop(mainCharacter);
			}
            else if (randomPrice >= 250)
            {
				cout << CENTRALIZE << "You open the mystery box and find a rare weapon!\n";
				randomEpicDrop(mainCharacter);
			}
            else if (randomPrice >= 150)
            {
				cout << CENTRALIZE << "You open the mystery box and find a common weapon!\n";
				randomUncommonDrop(mainCharacter);
			}
            else
            {
				cout << CENTRALIZE << "You open the mystery box and find a rusty weapon!\n";
				randomCommonDrop(mainCharacter);
			}
		}
		else
		{
			cout << CENTRALIZE << "You don't have enough gold.\n";
		}
	}
	else
	{
		cout << CENTRALIZE << "You ignore the stranger and continue on your journey.\n";
	}
}

void mysteryBox(Player& mainCharacter)
{
	int randomMysteryBox = randomNumberGenerator(0, 100);
	if (randomMysteryBox >= 99)
	{
		mythicMysteryBox(mainCharacter);
	}
	else if (randomMysteryBox >= 70)
	{
		legendaryMysteryBox(mainCharacter);
	}
	else if (randomMysteryBox >= 50)
	{
		epicMysteryBox(mainCharacter);
	}
	else if (randomMysteryBox >= 30)
	{
		uncommonMysteryBox(mainCharacter);
	}
	else
	{
		commonMysteryBox(mainCharacter);
	}

}

void commonMysteryBox(Player& mainCharacter)
{
	randomCommonDrop(mainCharacter);
}

void uncommonMysteryBox(Player& mainCharacter)
{
	randomUncommonDrop(mainCharacter);
}

void epicMysteryBox(Player& mainCharacter)
{
	randomEpicDrop(mainCharacter);
}

void legendaryMysteryBox(Player& mainCharacter)
{
	randomLegendaryDrop(mainCharacter);
}

void mythicMysteryBox(Player& mainCharacter)
{
	randomMythicalDrop(mainCharacter);
}

void handleMysteriousCave(Player& mainCharacter)
{
	cout << CENTRALIZE << "You stumble upon a mysterious cave.\n";
	cout << CENTRALIZE << "Do you want to enter?\n";
	cout << CENTRALIZE << "1. Yes\n" << CENTRALIZE << "2. No\n";
	int choice;
	cout << CENTRALIZE;
	int randomEvent = 0;
	cin >> choice;
	clearInputBuffer();
	handleInvalidInput();
	randomEvent = randomNumberGenerator(1, 3);
	if (choice == 1)
	{
		if (randomEvent == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				makeMonsters(mainCharacter);
				if (mainCharacter.getHealth() <= 0)
				{
					cout << CENTRALIZE << "You are dead!" << endl;
					exit(0);
				}
			}
		}
		else if (randomEvent == 2)
		{
			cout << CENTRALIZE << "You find a chest, a mystery box, and a glowing orb.\n";
			cout << CENTRALIZE << "Which one do you want to open?\n";
			cout << CENTRALIZE << "1. Chest\n" << CENTRALIZE << "2. Mystery Box\n" << CENTRALIZE << "3. Glowing Orb\n";
			int choice;
			cin >> choice;
			clearInputBuffer();
			handleInvalidInput();
			if (choice == 1)
			{
				cout << CENTRALIZE << "You open the chest and find gold!\n";
				mainCharacter.setGold(mainCharacter.getGold() + randomNumberGenerator(10, 1200));
				cout << CENTRALIZE << "You now have " << mainCharacter.getGold() << " gold.\n";
			}
			else if (choice == 2)
			{
				mysteryBox(mainCharacter);
			}
			else
			{
				cout << CENTRALIZE << "You touch the glowing orb and feel a surge of power!\n";
				mainCharacter.setHealth(mainCharacter.getHealth() + 50);
				mainCharacter.setMana(mainCharacter.getMana() + 50);
				mainCharacter.setStamina(mainCharacter.getStamina() + 50);
				mainCharacter.setMaxHealth(mainCharacter.getMaxHealth() + 50);
				mainCharacter.setMaxMana(mainCharacter.getMaxMana() + 50);
				mainCharacter.setMaxStamina(mainCharacter.getMaxStamina() + 50);
				cout << CENTRALIZE << "You now have " << mainCharacter.getHealth() << " health, " << mainCharacter.getMana() << " mana, and " << mainCharacter.getStamina() << " stamina.\n";
			}
		}
		else
		{
			cout << CENTRALIZE << "You Found Nothing...\n";
		}
	}
}

void handleBlackWater(Player& mainCharacter)
{
	cout << CENTRALIZE << "You found water that its pitch black...\n";
		cout << CENTRALIZE << "1. Drink\n" << CENTRALIZE << "2. Touch it\n" << CENTRALIZE << "3. stare at it\n" << CENTRALIZE << "4. Ignore\n";
		int choice;
		int howManySameInput = 0;
		cout << CENTRALIZE;
		cin >> choice;
		clearInputBuffer();
		handleInvalidInput();
		if (choice == 1)
		{
			cout << CENTRALIZE << "You drink the water and feel sick\n";
			mainCharacter.setHealth(mainCharacter.getHealth() - 30);
			mainCharacter.setMana(mainCharacter.getMana() - 30);
			mainCharacter.setStamina(mainCharacter.getStamina() - 30);
		}
		else if (choice == 2)
		{
			cout << CENTRALIZE << "You touch the water and feel a shiver down your spine...\n";
			
		}
		while (howManySameInput < 10 && choice == 3)
		{
		    cout << CENTRALIZE << "You stare at the water...\n";
			cout << CENTRALIZE << "Nothing happens...\n";
			howManySameInput++;
			cin >> choice;
			clearInputBuffer();
			handleInvalidInput();
		}
		if (howManySameInput >= 10)
		{
			cout << CENTRALIZE << "The Darkness Stares Right Back At You....\n";
			char anythingToContinue = '0';
			anythingToContinue = _getch() - '0';

			Monster darknessEmptyDevil("Darkness Dead Man", 1200, 700, 9000, 23, 12, 321, 13);
			MonsterFight(mainCharacter, darknessEmptyDevil);
			if (mainCharacter.getHealth() <= 0)
			{
				system("CLS");
				for (int i = 0; i < 100; i++)
				{
					cout << "$*)($#*)$)(#*()_*#(*$_)*(@*((*@$(*_)*()@_$(*$*()_$)*($*()@(*)@$*(_))$@)($*@_)$_)(*)@(_*)$(@*$@)$@_$)@*(*$@*(@$)(_$@\n";
				}
				exit(0);
			}
		}
		if (choice == 4)
		{
			cout << CENTRALIZE << "You ignore the water and continue on your journey.\n";
		}
}