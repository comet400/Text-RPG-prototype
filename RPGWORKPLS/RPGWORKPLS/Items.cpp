#include "RpgHeader.h"

void dropCommonConsumable(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 20);
	int randomQuantity = randomNumberGenerator(1, 5);
	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Health Potion", 1, "Heals 20 health", "Common", "Consumable", randomQuantity, 20, 0, 10, 0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Bread", 2, "Heals 5 health", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Berry Juice", 3, "Heals 15 health", "Common", "Consumable", randomQuantity, 15, 0, 5, 0));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Mana Potion", 4, "Heals 20 mana", "Common", "Consumable", randomQuantity, 20, 0, 10, 0));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Water", 5, "Heals 5 mana", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Herbal Tea", 6, "Heals 15 mana", "Common", "Consumable", randomQuantity, 15, 0, 5, 0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Stamina Potion", 7, "Heals 20 stamina", "Common", "Consumable", randomQuantity, 20, 0, 10, 0));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Cheese", 8, "Heals 5 stamina", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Energy Bar", 9, "Heals 15 stamina", "Common", "Consumable", randomQuantity, 15, 0, 5, 0));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Orange", 10, "Heals 10 health and mana", "Common", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 11:
		mainCharacter.getInventory().addItem(Item("Milk", 11, "Heals 5 health and mana", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 12:
		mainCharacter.getInventory().addItem(Item("Soup", 12, "Heals 10 health and mana", "Common", "Consumable", randomQuantity, 10, 0, 5, 0));
		break;
	case 13:
		mainCharacter.getInventory().addItem(Item("Apple", 13, "Heals 10 health and stamina", "Common", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 14:
		mainCharacter.getInventory().addItem(Item("Carrot", 14, "Heals 5 health and stamina", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 15:
		mainCharacter.getInventory().addItem(Item("Smoothie", 15, "Heals 10 health and stamina", "Common", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 16:
		mainCharacter.getInventory().addItem(Item("Granola Bar", 16, "Heals 5 health and stamina", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 17:
		mainCharacter.getInventory().addItem(Item("Banana", 17, "Heals 10 mana and stamina", "Common", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 18:
		mainCharacter.getInventory().addItem(Item("Honey", 18, "Heals 5 mana and stamina", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	case 19:
		mainCharacter.getInventory().addItem(Item("Salad", 19, "Heals 10 mana and stamina", "Common", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 20:
		mainCharacter.getInventory().addItem(Item("Fruit Punch", 20, "Heals 5 health and mana", "Common", "Consumable", randomQuantity, 5, 0, 5, 0));
		break;
	}
}

void dropUncommonConsumables(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 20);
	int randomQuantity = randomNumberGenerator(1, 3);
	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Advanced Health Potion", 21, "Heals 50 health", "Uncommon", "Consumable", randomQuantity, 50, 0, 25, 0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Hearty Bread", 22, "Heals 15 health", "Uncommon", "Consumable", randomQuantity, 15, 0, 10, 0));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Strong Berry Juice", 23, "Heals 30 health", "Uncommon", "Consumable", randomQuantity, 30, 0, 15, 0));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Advanced Mana Potion", 24, "Heals 50 mana", "Uncommon", "Consumable", randomQuantity, 50, 0, 25, 0));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Pure Water", 25, "Heals 15 mana", "Uncommon", "Consumable", randomQuantity, 15, 0, 10, 0));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Strong Herbal Tea", 26, "Heals 30 mana", "Uncommon", "Consumable", randomQuantity, 30, 0, 15, 0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Advanced Stamina Potion", 27, "Heals 50 stamina", "Uncommon", "Consumable", randomQuantity, 50, 0, 25, 0));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Nutritious Cheese", 28, "Heals 15 stamina", "Uncommon", "Consumable", randomQuantity, 15, 0, 10, 0));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Strong Energy Bar", 29, "Heals 30 stamina", "Uncommon", "Consumable", randomQuantity, 30, 0, 15, 0));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Enhanced Orange", 30, "Heals 20 health and mana", "Uncommon", "Consumable", randomQuantity, 20, 0, 15, 0));
		break;
	case 11:
		mainCharacter.getInventory().addItem(Item("Pure Milk", 31, "Heals 10 health and mana", "Uncommon", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 12:
		mainCharacter.getInventory().addItem(Item("Rich Soup", 32, "Heals 20 health and mana", "Uncommon", "Consumable", randomQuantity, 20, 0, 15, 0));
		break;
	case 13:
		mainCharacter.getInventory().addItem(Item("Enhanced Apple", 33, "Heals 20 health and stamina", "Uncommon", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 14:
		mainCharacter.getInventory().addItem(Item("Nutritious Carrot", 34, "Heals 10 health and stamina", "Uncommon", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 15:
		mainCharacter.getInventory().addItem(Item("Strong Smoothie", 35, "Heals 20 health and stamina", "Uncommon", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 16:
		mainCharacter.getInventory().addItem(Item("Enhanced Granola Bar", 36, "Heals 10 health and stamina", "Uncommon", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 17:
		mainCharacter.getInventory().addItem(Item("Enhanced Banana", 37, "Heals 20 mana and stamina", "Uncommon", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 18:
		mainCharacter.getInventory().addItem(Item("Pure Honey", 38, "Heals 10 mana and stamina", "Uncommon", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	case 19:
		mainCharacter.getInventory().addItem(Item("Strong Salad", 39, "Heals 20 mana and stamina", "Uncommon", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 20:
		mainCharacter.getInventory().addItem(Item("Enhanced Fruit Punch", 40, "Heals 10 health and mana", "Uncommon", "Consumable", randomQuantity, 10, 0, 10, 0));
		break;
	}
}

void dropEpicConsumables(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 20);
	int randomQuantity = randomNumberGenerator(1, 2);
	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Epic Health Potion", 41, "Heals 100 health", "Epic", "Consumable", randomQuantity, 100, 0, 50, 0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Golden Bread", 42, "Heals 30 health", "Epic", "Consumable", randomQuantity, 30, 0, 20, 0));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Powerful Berry Juice", 43, "Heals 60 health", "Epic", "Consumable", randomQuantity, 60, 0, 30, 0));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Epic Mana Potion", 44, "Heals 100 mana", "Epic", "Consumable", randomQuantity, 100, 0, 50, 0));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Crystal Water", 45, "Heals 30 mana", "Epic", "Consumable", randomQuantity, 30, 0, 20, 0));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Powerful Herbal Tea", 46, "Heals 60 mana", "Epic", "Consumable", randomQuantity, 60, 0, 30, 0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Epic Stamina Potion", 47, "Heals 100 stamina", "Epic", "Consumable", randomQuantity, 100, 0, 50, 0));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Golden Cheese", 48, "Heals 30 stamina", "Epic", "Consumable", randomQuantity, 30, 0, 20, 0));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Powerful Energy Bar", 49, "Heals 60 stamina", "Epic", "Consumable", randomQuantity, 60, 0, 30, 0));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Mystic Orange", 50, "Heals 40 health and mana", "Epic", "Consumable", randomQuantity, 40, 0, 30, 0));
		break;
	case 11:
		mainCharacter.getInventory().addItem(Item("Crystal Milk", 51, "Heals 20 health and mana", "Epic", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 12:
		mainCharacter.getInventory().addItem(Item("Mystic Soup", 52, "Heals 40 health and mana", "Epic", "Consumable", randomQuantity, 40, 0, 30, 0));
		break;
	case 13:
		mainCharacter.getInventory().addItem(Item("Mystic Apple", 53, "Heals 40 health and stamina", "Epic", "Consumable", randomQuantity, 40, 0, 40, 0));
		break;
	case 14:
		mainCharacter.getInventory().addItem(Item("Golden Carrot", 54, "Heals 20 health and stamina", "Epic", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 15:
		mainCharacter.getInventory().addItem(Item("Powerful Smoothie", 55, "Heals 40 health and stamina", "Epic", "Consumable", randomQuantity, 40, 0, 40, 0));
		break;
	case 16:
		mainCharacter.getInventory().addItem(Item("Mystic Granola Bar", 56, "Heals 20 health and stamina", "Epic", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 17:
		mainCharacter.getInventory().addItem(Item("Mystic Banana", 57, "Heals 40 mana and stamina", "Epic", "Consumable", randomQuantity, 40, 0, 40, 0));
		break;
	case 18:
		mainCharacter.getInventory().addItem(Item("Crystal Honey", 58, "Heals 20 mana and stamina", "Epic", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	case 19:
		mainCharacter.getInventory().addItem(Item("Powerful Salad", 59, "Heals 40 mana and stamina", "Epic", "Consumable", randomQuantity, 40, 0, 40, 0));
		break;
	case 20:
		mainCharacter.getInventory().addItem(Item("Mystic Fruit Punch", 60, "Heals 20 health and mana", "Epic", "Consumable", randomQuantity, 20, 0, 20, 0));
		break;
	}
}

void dropLegendaryConsumables(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 20);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Legendary Health Potion", 61, "Heals 200 health", "Legendary", "Consumable", 1, 200, 0, 100, 0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Divine Bread", 62, "Heals 50 health", "Legendary", "Consumable", 1, 50, 0, 50, 0));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Ethereal Berry Juice", 63, "Heals 120 health", "Legendary", "Consumable", 1, 120, 0, 60, 0));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Legendary Mana Potion", 64, "Heals 200 mana", "Legendary", "Consumable", 1, 200, 0, 100, 0));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Divine Water", 65, "Heals 50 mana", "Legendary", "Consumable", 1, 50, 0, 50, 0));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Ethereal Herbal Tea", 66, "Heals 120 mana", "Legendary", "Consumable", 1, 120, 0, 60, 0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Legendary Stamina Potion", 67, "Heals 200 stamina", "Legendary", "Consumable", 1, 200, 0, 100, 0));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Divine Cheese", 68, "Heals 50 stamina", "Legendary", "Consumable", 1, 50, 0, 50, 0));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Ethereal Energy Bar", 69, "Heals 120 stamina", "Legendary", "Consumable", 1, 120, 0, 60, 0));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Celestial Orange", 70, "Heals 80 health and mana", "Legendary", "Consumable", 1, 80, 0, 60, 0));
		break;
	case 11:
		mainCharacter.getInventory().addItem(Item("Divine Milk", 71, "Heals 40 health and mana", "Legendary", "Consumable", 1, 40, 0, 40, 0));
		break;
	case 12:
		mainCharacter.getInventory().addItem(Item("Celestial Soup", 72, "Heals 80 health and mana", "Legendary", "Consumable", 1, 80, 0, 60, 0));
		break;
	case 13:
		mainCharacter.getInventory().addItem(Item("Celestial Apple", 73, "Heals 80 health and stamina", "Legendary", "Consumable", 1, 80, 0, 80, 0));
		break;
	case 14:
		mainCharacter.getInventory().addItem(Item("Divine Carrot", 74, "Heals 40 health and stamina", "Legendary", "Consumable", 1, 40, 0, 40, 0));
		break;
	case 15:
		mainCharacter.getInventory().addItem(Item("Ethereal Smoothie", 75, "Heals 80 health and stamina", "Legendary", "Consumable", 1, 80, 0, 80, 0));
		break;
	case 16:
		mainCharacter.getInventory().addItem(Item("Celestial Granola Bar", 76, "Heals 40 health and stamina", "Legendary", "Consumable", 1, 40, 0, 40, 0));
		break;
	case 17:
		mainCharacter.getInventory().addItem(Item("Celestial Banana", 77, "Heals 80 mana and stamina", "Legendary", "Consumable", 1, 80, 0, 80, 0));
		break;
	case 18:
		mainCharacter.getInventory().addItem(Item("Divine Honey", 78, "Heals 40 mana and stamina", "Legendary", "Consumable", 1, 40, 0, 40, 0));
		break;
	case 19:
		mainCharacter.getInventory().addItem(Item("Ethereal Salad", 79, "Heals 80 mana and stamina", "Legendary", "Consumable", 1, 80, 0, 80, 0));
		break;
	case 20:
		mainCharacter.getInventory().addItem(Item("Celestial Fruit Punch", 80, "Heals 40 health and mana", "Legendary", "Consumable", 1, 40, 0, 40, 0));
		break;
	}
}


void dropMythicalConsumable(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 20);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Mythical Health Elixir", 81, "Heals 1000 health", "Mythical", "Consumable", 1, 1000, 0, 500, 0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Godly Bread", 82, "Heals 200 health", "Mythical", "Consumable", 1, 200, 0, 200, 0));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Heavenly Berry Juice", 83, "Heals 500 health", "Mythical", "Consumable", 1, 500, 0, 250, 0));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Mythical Mana Elixir", 84, "Heals 1000 mana", "Mythical", "Consumable", 1, 1000, 0, 500, 0));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Godly Water", 85, "Heals 200 mana", "Mythical", "Consumable", 1, 200, 0, 200, 0));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Heavenly Herbal Tea", 86, "Heals 500 mana", "Mythical", "Consumable", 1, 500, 0, 250, 0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Mythical Stamina Elixir", 87, "Heals 1000 stamina", "Mythical", "Consumable", 1, 1000, 0, 500, 0));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Godly Cheese", 88, "Heals 200 stamina", "Mythical", "Consumable", 1, 200, 0, 200, 0));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Heavenly Energy Bar", 89, "Heals 500 stamina", "Mythical", "Consumable", 1, 500, 0, 250, 0));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Celestial Orange", 90, "Heals 1000 health and mana", "Mythical", "Consumable", 1, 1000, 0, 750, 0));
		break;
	case 11:
		mainCharacter.getInventory().addItem(Item("Divine Milk", 91, "Heals 500 health and mana", "Mythical", "Consumable", 1, 500, 0, 500, 0));
		break;
	case 12:
		mainCharacter.getInventory().addItem(Item("Celestial Soup", 92, "Heals 1000 health and mana", "Mythical", "Consumable", 1, 1000, 0, 750, 0));
		break;
	case 13:
		mainCharacter.getInventory().addItem(Item("Celestial Apple", 93, "Heals 1000 health and stamina", "Mythical", "Consumable", 1, 1000, 0, 1000, 0));
		break;
	case 14:
		mainCharacter.getInventory().addItem(Item("Divine Carrot", 94, "Heals 500 health and stamina", "Mythical", "Consumable", 1, 500, 0, 500, 0));
		break;
	case 15:
		mainCharacter.getInventory().addItem(Item("Ethereal Smoothie", 95, "Heals 1000 health and stamina", "Mythical", "Consumable", 1, 1000, 0, 1000, 0));
		break;
	case 16:
		mainCharacter.getInventory().addItem(Item("Celestial Granola Bar", 96, "Heals 500 health and stamina", "Mythical", "Consumable", 1, 500, 0, 500, 0));
		break;
	case 17:
		mainCharacter.getInventory().addItem(Item("Celestial Banana", 97, "Heals 1000 mana and stamina", "Mythical", "Consumable", 1, 1000, 0, 1000, 0));
		break;
	case 18:
		mainCharacter.getInventory().addItem(Item("Divine Honey", 98, "Heals 500 mana and stamina", "Mythical", "Consumable", 1, 500, 0, 500, 0));
		break;
	case 19:
		mainCharacter.getInventory().addItem(Item("Ethereal Salad", 99, "Heals 1000 mana and stamina", "Mythical", "Consumable", 1, 1000, 0, 1000, 0));
		break;
	case 20:
		mainCharacter.getInventory().addItem(Item("Celestial Fruit Punch", 100, "Heals 500 health and mana", "Mythical", "Consumable", 1, 500, 0, 500, 0));
		break;
	}
}

void dropCommonArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Iron Armor", 101, "Full iron armor for solid protection", "Common", "Armor", 1, 0, 0, 60, 1.5));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Steel Armor", 102, "Sturdy steel armor for enhanced defense", "Common", "Armor", 1, 0, 0, 65, 1.4));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Chainmail Armor", 103, "Chainmail armor offering flexible protection", "Common", "Armor", 1, 0, 0, 55, 1.3));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Bronze Armor", 104, "Bronze armor for moderate protection", "Common", "Armor", 1, 0, 0, 50, 1.2));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Leather Armor", 105, "Leather armor providing basic protection", "Common", "Armor", 1, 0, 0, 45, 1.1));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Copper Armor", 106, "Copper armor with decent protection", "Common", "Armor", 1, 0, 0, 40, 1.1));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Wooden Armor", 107, "Wooden armor for light protection", "Common", "Armor", 1, 0, 0, 35, 1.1));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Cloth Armor", 108, "Cloth armor offering minimal protection", "Common", "Armor", 1, 0, 0, 30, 1.1));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Padded Armor", 109, "Padded armor for basic defense", "Common", "Armor", 1, 0, 0, 25, 1));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Straw Armor", 110, "Straw armor for very light protection", "Common", "Armor", 1, 0, 0, 20, 1));
		break;
	}
}

void dropUncommonArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Mithril Armor", 111, "Lightweight and strong mithril armor", "Uncommon", "Armor", 1, 0, 0, 120, 2.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Dragonhide Armor", 112, "Armor made from tough dragon hide", "Uncommon", "Armor", 1, 0, 0, 110, 1.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Adamantine Armor", 113, "Durable adamantine armor for high defense", "Uncommon", "Armor", 1, 0, 0, 100, 1.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Titanium Armor", 114, "Titanium armor offering superior protection", "Uncommon", "Armor", 1, 0, 0, 95, 1.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Darksteel Armor", 115, "Darksteel armor for enhanced defense", "Uncommon", "Armor", 1, 0, 0, 90, 1.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Elven Armor", 116, "Elven-crafted armor with magical properties", "Uncommon", "Armor", 1, 0, 0, 85, 1.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Crystal Armor", 117, "Crystal armor providing excellent protection", "Uncommon", "Armor", 1, 0, 0, 80, 1.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Obsidian Armor", 118, "Obsidian armor offering solid defense", "Uncommon", "Armor", 1, 0, 0, 75, 1.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Dwarven Armor", 119, "Dwarven-crafted armor for high durability", "Uncommon", "Armor", 1, 0, 0, 70, 1.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Scale Armor", 120, "Scale armor providing good protection", "Uncommon", "Armor", 1, 0, 0, 65, 1.1));
		break;
	}
}

void dropEpicArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Dragonbone Armor", 121, "Impenetrable armor made from dragon bones", "Epic", "Armor", 1, 0, 0, 300, 3.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Phoenix Feather Armor", 122, "Armor imbued with the power of the phoenix", "Epic", "Armor", 1, 0, 0, 290, 2.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Armor", 123, "Heavenly armor offering divine protection", "Epic", "Armor", 1, 0, 0, 280, 2.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Voidsteel Armor", 124, "Armor forged from the void, near indestructible", "Epic", "Armor", 1, 0, 0, 270, 2.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Etherium Armor", 125, "Mystical armor with ethereal properties", "Epic", "Armor", 1, 0, 0, 260, 2.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Starforged Armor", 126, "Armor forged from the essence of stars", "Epic", "Armor", 1, 0, 0, 250, 2.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Archangel Armor", 127, "Holy armor blessed by archangels", "Epic", "Armor", 1, 0, 0, 240, 2.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Abyssal Armor", 128, "Dark armor imbued with the power of the abyss", "Epic", "Armor", 1, 0, 0, 230, 2.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Rune Armor", 129, "Armor inscribed with powerful runes", "Epic", "Armor", 1, 0, 0, 220, 2.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Stormweave Armor", 130, "Armor woven with the essence of storms", "Epic", "Armor", 1, 0, 0, 210, 2.1));
		break;
	}
}

void dropLegendaryArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Divinity Armor", 131, "Armor blessed by the gods", "Legendary", "Armor", 1, 0, 0, 500, 5.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Eternal Flame Armor", 132, "Armor imbued with the flames of the phoenix", "Legendary", "Armor", 1, 0, 0, 480, 4.8));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Titansteel Armor", 133, "Armor forged from the mythical titansteel", "Legendary", "Armor", 1, 0, 0, 460, 4.6));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Astral Armor", 134, "Armor crafted from the fabric of the cosmos", "Legendary", "Armor", 1, 0, 0, 440, 4.4));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Seraphim Armor", 135, "Holy armor blessed by the highest order of angels", "Legendary", "Armor", 1, 0, 0, 420, 4.2));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Eldritch Armor", 136, "Armor infused with ancient and forbidden magic", "Legendary", "Armor", 1, 0, 0, 400, 4.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Leviathan Armor", 137, "Armor made from the scales of the mighty Leviathan", "Legendary", "Armor", 1, 0, 0, 380, 3.8));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Sunforged Armor", 138, "Armor forged in the heart of the sun", "Legendary", "Armor", 1, 0, 0, 360, 3.6));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Shadowcraft Armor", 139, "Armor crafted from the essence of shadows", "Legendary", "Armor", 1, 0, 0, 340, 3.4));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Crystalforge Armor", 140, "Armor forged from the purest and hardest crystals", "Legendary", "Armor", 1, 0, 0, 320, 3.2));
		break;
	}
}

void dropMythicalArmor(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Aetherial Armor", 141, "Armor forged from the essence of the Aether", "Mythical", "Armor", 1, 0, 0, 1000, 10.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Primal Elemental Armor", 142, "Armor imbued with the raw power of the elements", "Mythical", "Armor", 1, 0, 0, 960, 9.6));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Radiance Armor", 143, "Armor blessed by heavens, glowing with divine light", "Mythical", "Armor", 1, 0, 0, 920, 9.2));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Eternium Armor", 144, "Armor forged from the timeless metal Eternium", "Mythical", "Armor", 1, 0, 0, 880, 8.8));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Divine Wrath Armor", 145, "Holy armor that channels the wrath of the gods", "Mythical", "Armor", 1, 0, 0, 840, 8.4));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Arcane Infinity Armor", 146, "Armor infused with infinite arcane power", "Mythical", "Armor", 1, 0, 0, 800, 8.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Primordial Chaos Armor", 147, "Armor crafted from the chaotic forces of the universe", "Mythical", "Armor", 1, 0, 0, 760, 7.6));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Phoenix Rebirth Armor", 148, "Armor that have the power of rebirth from the phoenix", "Mythical", "Armor", 1, 0, 0, 720, 7.2));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Leviathan Scale Armor", 149, "Armor made from the scales of the ancient Leviathan", "Mythical", "Armor", 1, 0, 0, 680, 6.8));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Dragonheart Armor", 150, "Armor forged from the heart of an ancient dragon", "Mythical", "Armor", 1, 0, 0, 640, 6.4));
		break;
	}
}

string getRainbowText(const string& text)
{
	vector<string> colors = {
		"\033[31m", // Red
		"\033[33m", // Yellow
		"\033[32m", // Green
		"\033[36m", // Cyan
		"\033[34m", // Blue
		"\033[35m", // Magenta
	};

	string rainbowText;
	for (size_t i = 0; i < text.length(); ++i) 
	{
		rainbowText += colors[i % colors.size()] + text[i];
	}

	// Reset color
	rainbowText += "\033[0m";
	return rainbowText;
}

void dropCommonMeleeWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Iron Sword", 151, "Basic iron sword for close combat", "Common", "Melee Weapon", 1, 0, 0, 30, 1.5));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Steel Sword", 152, "Sturdy steel sword for reliable damage", "Common", "Melee Weapon", 1, 0, 0, 35, 1.5));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Bronze Sword", 153, "Bronze sword for moderate damage", "Common", "Melee Weapon", 1, 0, 0, 25, 1.5));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Copper Sword", 154, "Copper sword with decent damage", "Common", "Melee Weapon", 1, 0, 0, 20, 1.5));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Wooden Sword", 155, "Wooden sword for light damage", "Common", "Melee Weapon", 1, 0, 0, 15, 1.5));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Iron Axe", 156, "Basic iron axe for close combat", "Common", "Melee Weapon", 1, 0, 0, 30, 1.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Steel Axe", 157, "Sturdy steel axe for reliable damage", "Common", "Melee Weapon", 1, 0, 0, 35, 1.5));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Bronze Axe", 158, "Bronze axe for moderate damage", "Common", "Melee Weapon", 1, 0, 0, 25, 1.5));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Copper Axe", 159, "Copper axe with decent damage", "Common", "Melee Weapon", 1, 0, 0, 20, 1.5));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Wooden Axe", 160, "Wooden axe for light damage", "Common", "Melee Weapon", 1, 0, 0, 15, 1.5));
		break;
	}
}

void dropUncommonMeleeWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Mithril Sword", 161, "Lightweight and strong mithril sword", "Uncommon", "Melee Weapon", 1, 0, 0, 120, 2.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Dragonhide Sword", 162, "Sword made from tough dragon hide", "Uncommon", "Melee Weapon", 1, 0, 0, 110, 1.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Adamantine Sword", 163, "Durable adamantine sword for high damage", "Uncommon", "Melee Weapon", 1, 0, 0, 100, 1.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Titanium Sword", 164, "Titanium sword offering superior damage", "Uncommon", "Melee Weapon", 1, 0, 0, 95, 1.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Darksteel Sword", 165, "Darksteel sword for enhanced damage", "Uncommon", "Melee Weapon", 1, 0, 0, 90, 1.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Elven Sword", 166, "Elven-crafted sword with magical properties", "Uncommon", "Melee Weapon", 1, 0, 0, 85, 1.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Crystal Sword", 167, "Crystal sword providing excellent damage", "Uncommon", "Melee Weapon", 1, 0, 0, 80, 1.5));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Obsidian Sword", 168, "Obsidian sword offering solid damage", "Uncommon", "Melee Weapon", 1, 0, 0, 75, 1.5));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Dwarven Sword", 169, "Dwarven-crafted sword for high durability", "Uncommon", "Melee Weapon", 1, 0, 0, 70, 1.5));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Scale Sword", 170, "Scale sword providing good damage", "Uncommon", "Melee Weapon", 1, 0, 0, 65, 1.5));
		break;
	}
}

void dropEpicMeleeWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Dragonbone Sword", 171, "Impenetrable sword made from dragon bones", "Epic", "Melee Weapon", 1, 0, 0, 300, 3.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Phoenix Feather Sword", 172, "Sword imbued with the power of the phoenix", "Epic", "Melee Weapon", 1, 0, 0, 290, 2.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Sword", 173, "Heavenly sword offering divine damage", "Epic", "Melee Weapon", 1, 0, 0, 280, 2.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Voidsteel Sword", 174, "Sword forged from the void, near indestructible", "Epic", "Melee Weapon", 1, 0, 0, 270, 2.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Etherium Sword", 175, "Mystical sword with ethereal properties", "Epic", "Melee Weapon", 1, 0, 0, 260, 2.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Starforged Sword", 176, "Sword forged from the essence of stars", "Epic", "Melee Weapon", 1, 0, 0, 250, 2.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Archangel Sword", 177, "Holy sword blessed by archangels", "Epic", "Melee Weapon", 1, 0, 0, 240, 2.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Abyssal Sword", 178, "Dark sword imbued with the power of the abyss", "Epic", "Melee Weapon", 1, 0, 0, 230, 2.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Rune Sword", 179, "Sword inscribed with powerful runes", "Epic", "Melee Weapon", 1, 0, 0, 220, 2.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Stormweave Sword", 180, "Sword woven with the essence of storms", "Epic", "Melee Weapon", 1, 0, 0, 210, 2.1));
		break;
	}
}

void dropLegendaryMeleeWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Divinity Sword", 181, "Sword blessed by the gods", "Legendary", "Melee Weapon", 1, 0, 0, 500, 5.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Eternal Flame Sword", 182, "Sword imbued with the everlasting flames of the phoenix", "Legendary", "Melee Weapon", 1, 0, 0, 480, 4.8));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Titansteel Sword", 183, "Sword forged from the mythical titansteel", "Legendary", "Melee Weapon", 1, 0, 0, 460, 4.6));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Astral Sword", 184, "Sword crafted from the fabric of the cosmos", "Legendary", "Melee Weapon", 1, 0, 0, 440, 4.4));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Seraphim Sword", 185, "Holy sword blessed by the highest order of angels", "Legendary", "Melee Weapon", 1, 0, 0, 420, 4.2));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Eldritch Sword", 186, "Sword infused with ancient and forbidden magic", "Legendary", "Melee Weapon", 1, 0, 0, 400, 4.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Leviathan Sword", 187, "Sword made from the scales of the mighty Leviathan", "Legendary", "Melee Weapon", 1, 0, 0, 380, 3.8));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Sunforged Sword", 188, "Sword forged in the heart of the sun", "Legendary", "Melee Weapon", 1, 0, 0, 360, 3.6));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Shadowcraft Sword", 189, "Sword crafted from the essence of shadows", "Legendary", "Melee Weapon", 1, 0, 0, 340, 3.4));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Crystalforge Sword", 190, "Sword forged from the purest and hardest crystals", "Legendary", "Melee Weapon", 1, 0, 0, 320, 3.2));
		break;
	}
}

void dropMythicalMeleeWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Aetherial Sword", 191, "Sword forged from the essence of the Aether", "Mythical", "Melee Weapon", 1, 0, 0, 1000, 10.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Primal Elemental Sword", 192, "Sword imbued with the raw power of the elements", "Mythical", "Melee Weapon", 1, 0, 0, 960, 9.6));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Radiance Sword", 193, "Sword blessed by celestial beings", "Mythical", "Melee Weapon", 1, 0, 0, 920, 9.2));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Eternium Sword", 194, "Sword forged from the timeless metal Eternium", "Mythical", "Melee Weapon", 1, 0, 0, 880, 8.8));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Divine Wrath Sword", 195, "Holy sword that channels the wrath of the gods", "Mythical", "Melee Weapon", 1, 0, 0, 840, 8.4));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Arcane Infinity Sword", 196, "Sword infused with infinite arcane power", "Mythical", "Melee Weapon", 1, 0, 0, 800, 8.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Primordial Chaos Sword", 197, "Sword crafted from the chaotic forces of the universe", "Mythical", "Melee Weapon", 1, 0, 0, 760, 7.6));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Phoenix Rebirth Sword", 198, "Sword that took the power of rebirth from the phoenix", "Mythical", "Melee Weapon", 1, 0, 0, 720, 7.2));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Leviathan Scale Sword", 199, "Sword made from the scales of the ancient Leviathan", "Mythical", "Melee Weapon", 1, 0, 0, 680, 6.8));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Dragonheart Sword", 200, "Sword forged from the heart of an ancient dragon", "Mythical", "Melee Weapon", 1, 0, 0, 640, 6.4));
		break;
	}
}

void dropCommonMagicWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Iron Wand", 201, "Basic iron wand for simple spells", "Common", "Magic Weapon", 1, 0, 0, 30, 1.5));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Steel Wand", 202, "Sturdy steel wand for reliable casting", "Common", "Magic Weapon", 1, 0, 0, 35, 1.4));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Bronze Wand", 203, "Bronze wand for moderate spell power", "Common", "Magic Weapon", 1, 0, 0, 25, 1.3));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Copper Wand", 204, "Copper wand with decent spell power", "Common", "Magic Weapon", 1, 0, 0, 20, 1.2));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Wooden Wand", 205, "Wooden wand for light spells", "Common", "Magic Weapon", 1, 0, 0, 15, 1.1));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Iron Staff", 206, "Basic iron staff for simple spells", "Common", "Magic Weapon", 1, 0, 0, 30, 1.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Steel Staff", 207, "Sturdy steel staff for reliable casting", "Common", "Magic Weapon", 1, 0, 0, 35, 1.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Bronze Staff", 208, "Bronze staff for moderate spell power", "Common", "Magic Weapon", 1, 0, 0, 25, 1.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Copper Staff", 209, "Copper staff with decent spell power", "Common", "Magic Weapon", 1, 0, 0, 20, 1.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Wooden Staff", 210, "Wooden staff for light spells", "Common", "Magic Weapon", 1, 0, 0, 15, 1.1));
		break;
	}
}

void dropUncommonMagicWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Mithril Wand", 211, "Lightweight and strong mithril wand", "Uncommon", "Magic Weapon", 1, 0, 0, 120, 2.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Dragonhide Wand", 212, "Wand made from tough dragon hide", "Uncommon", "Magic Weapon", 1, 0, 0, 110, 1.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Adamantine Wand", 213, "Durable adamantine wand for high spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 100, 1.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Titanium Wand", 214, "Titanium wand offering superior spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 95, 1.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Darksteel Wand", 215, "Darksteel wand for enhanced spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 90, 1.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Elven Wand", 216, "Elven-crafted wand with magical properties", "Uncommon", "Magic Weapon", 1, 0, 0, 85, 1.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Crystal Wand", 217, "Crystal wand providing excellent spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 80, 1.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Obsidian Wand", 218, "Obsidian wand offering solid spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 75, 1.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Dwarven Wand", 219, "Dwarven-crafted wand for high durability", "Uncommon", "Magic Weapon", 1, 0, 0, 70, 1.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Scale Wand", 220, "Scale wand providing good spell power", "Uncommon", "Magic Weapon", 1, 0, 0, 65, 1.1));
		break;
	}
}

void dropEpicMagicWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Dragonbone Wand", 221, "Impenetrable wand made from dragon bones", "Epic", "Magic Weapon", 1, 0, 0, 300, 3.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Phoenix Feather Wand", 222, "Wand imbued with the power of the phoenix", "Epic", "Magic Weapon", 1, 0, 0, 290, 2.9));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Wand", 223, "Heavenly wand offering divine spell power", "Epic", "Magic Weapon", 1, 0, 0, 280, 2.8));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Voidsteel Wand", 224, "Wand forged from the void, near indestructible", "Epic", "Magic Weapon", 1, 0, 0, 270, 2.7));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Etherium Wand", 225, "Mystical wand with ethereal properties", "Epic", "Magic Weapon", 1, 0, 0, 260, 2.6));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Starforged Wand", 226, "Wand forged from the essence of stars", "Epic", "Magic Weapon", 1, 0, 0, 250, 2.5));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Archangel Wand", 227, "Holy wand blessed by archangels", "Epic", "Magic Weapon", 1, 0, 0, 240, 2.4));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Abyssal Wand", 228, "Dark wand imbued with the power of the abyss", "Epic", "Magic Weapon", 1, 0, 0, 230, 2.3));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Rune Wand", 229, "Wand inscribed with powerful runes", "Epic", "Magic Weapon", 1, 0, 0, 220, 2.2));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Stormweave Wand", 230, "Wand woven with the essence of storms", "Epic", "Magic Weapon", 1, 0, 0, 210, 2.1));
		break;
	}
}

void dropLegendaryMagicWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Divinity Wand", 231, "Wand blessed by the gods", "Legendary", "Magic Weapon", 1, 0, 0, 500, 5.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Eternal Flame Wand", 232, "Wand imbued with the everlasting flames of the phoenix", "Legendary", "Magic Weapon", 1, 0, 0, 480, 4.8));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Titansteel Wand", 233, "Wand forged from the mythical titansteel", "Legendary", "Magic Weapon", 1, 0, 0, 460, 4.6));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Astral Wand", 234, "Wand crafted from the fabric of the cosmos", "Legendary", "Magic Weapon", 1, 0, 0, 440, 4.4));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Seraphim Wand", 235, "Holy wand blessed by the highest order of angels", "Legendary", "Magic Weapon", 1, 0, 0, 420, 4.2));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Eldritch Wand", 236, "Wand infused with ancient and forbidden magic", "Legendary", "Magic Weapon", 1, 0, 0, 400, 4.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Leviathan Wand", 237, "Wand made from the scales of the mighty Leviathan", "Legendary", "Magic Weapon", 1, 0, 0, 380, 3.8));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Sunforged Wand", 238, "Wand forged in the heart of the sun", "Legendary", "Magic Weapon", 1, 0, 0, 360, 3.6));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Shadowcraft Wand", 239, "Wand crafted from the essence of shadows", "Legendary", "Magic Weapon", 1, 0, 0, 340, 3.4));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Crystalforge Wand", 240, "Wand forged from the purest and hardest crystals", "Legendary", "Magic Weapon", 1, 0, 0, 320, 3.2));
		break;
	}
}

void dropMythicalMagicWeapons(Player& mainCharacter)
{
	int randomChance = randomNumberGenerator(1, 10);

	switch (randomChance)
	{
	case 1:
		mainCharacter.getInventory().addItem(Item("Aetherial Wand", 241, "Wand forged from the essence of the Aether", "Mythical", "Magic Weapon", 1, 0, 0, 1000, 10.0));
		break;
	case 2:
		mainCharacter.getInventory().addItem(Item("Primal Elemental Wand", 242, "Wand imbued with the raw power of the elements", "Mythical", "Magic Weapon", 1, 0, 0, 960, 9.6));
		break;
	case 3:
		mainCharacter.getInventory().addItem(Item("Celestial Radiance Wand", 243, "Wand blessed by celestial beings", "Mythical", "Magic Weapon", 1, 0, 0, 920, 9.2));
		break;
	case 4:
		mainCharacter.getInventory().addItem(Item("Eternium Wand", 244, "Wand forged from the timeless metal Eternium", "Mythical", "Magic Weapon", 1, 0, 0, 880, 8.8));
		break;
	case 5:
		mainCharacter.getInventory().addItem(Item("Divine Wrath Wand", 245, "Holy wand that channels the wrath of the gods", "Mythical", "Magic Weapon", 1, 0, 0, 840, 8.4));
		break;
	case 6:
		mainCharacter.getInventory().addItem(Item("Arcane Infinity Wand", 246, "Wand infused with infinite arcane power", "Mythical", "Magic Weapon", 1, 0, 0, 800, 8.0));
		break;
	case 7:
		mainCharacter.getInventory().addItem(Item("Primordial Chaos Wand", 247, "Wand crafted from the chaotic forces of the universe", "Mythical", "Magic Weapon", 1, 0, 0, 760, 7.6));
		break;
	case 8:
		mainCharacter.getInventory().addItem(Item("Phoenix Rebirth Wand", 248, "Wand that harnesses the power of rebirth from the phoenix", "Mythical", "Magic Weapon", 1, 0, 0, 720, 7.2));
		break;
	case 9:
		mainCharacter.getInventory().addItem(Item("Leviathan Scale Wand", 249, "Wand made from the scales of the ancient Leviathan", "Mythical", "Magic Weapon", 1, 0, 0, 680, 6.8));
		break;
	case 10:
		mainCharacter.getInventory().addItem(Item("Dragonheart Wand", 250, "Wand forged from the heart of an ancient dragon", "Mythical", "Magic Weapon", 1, 0, 0, 640, 6.4));
		break;
	}
}
