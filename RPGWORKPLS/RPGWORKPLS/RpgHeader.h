#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;

#pragma warning(disable : 4244)

#define SquareString "[#]"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define PURPLE "\033[35m"
#define CYAN "\033[1m\033[36m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDPURPLE  "\033[1m\033[35m"
#define CENTRALIZE "\t\t\t\t\t"

#define DAMAGE_REDUCTION 10
#define GRIDSIZE 15 

enum Move
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
    TOGGLEMAP
};

enum PlayerClasses
{
    WARRIOR = 1,
    MAGE,
    NECROMANCER,
    ASSASSIN,
    PALADIN,
};

enum PlayerRaces
{
    HUMAN = 1,
    ELF,
    TIEFLING,
    ORC,
    HALF_INSECT
};

enum npcProfessions
{
    BLACKSMITH = 1,
    ENCHANTER,
    ALCHEMY,
    HERBALIST,
    ARMORER,
    WEAPONSMITH,
    POTION_MAKER,
    HEALER,
};

enum fightOptions
{
    ATTACK = 1,
    BLOCK,
    ITEMS,
    RUN,
};

class Item
{
private:
    std::string name;
    int id;
    std::string description;
    std::string rarity;
    std::string type;
    int quantity;
    int buffs;
    int debuffs;
    int value;
    double statMultiplier;

public:
    Item(const std::string& name, int id, const std::string& description, const std::string& rarity, const std::string& type, int quantity, int buffs, int debuffs, int value, double statMultiplier)
        : name(name), id(id), description(description), rarity(rarity), type(type), quantity(quantity), buffs(buffs), debuffs(debuffs), value(value), statMultiplier(statMultiplier) {}

    std::string getName() const { return name; }
    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getRarity() const { return rarity; }
    std::string getType() const { return type; }
    int getQuantity() const { return quantity; }
	int getBuffs() const { return buffs; }
	int getDebuffs() const { return debuffs; }
	int getValue() const { return value; }
	double getStatMultiplier() const { return statMultiplier; }

    void setQuantity(int quantity) { this->quantity = quantity; }
};

class Inventory
{
public:
    void addItem(const Item& item);
    void removeItem(int itemId);
    void listItems() const;
    void listConsumables() const;
    int useItem(int& id);
    void listArmors() const;
    void equipArmor(bool& itemEquiped, double& multiplier, int& id) const;
	void listWeapons() const;
    void equipWeapon(bool& itemEquiped, double& multiplier, int& id) const;
    void listMagicWeapons() const;
    void equipMagic(bool& itemEquiped, double& multiplier, int& id) const;
private:
    std::vector<Item> items;

    bool itemExists(int itemId) const;
    void increaseQuantity(int itemId, int quantity);
};


class Player
{
private:
    double health;
    double attack;
    double magic;
    int mana;
    int stamina;
    int charisma;
    std::string playerClass;
    std::string playerRace;
    int level;
    int previousLevel;
    int experience;
    int gold;
    double statusMultiplier;

    int howManySpells;
    int howManyAbilities;
    double maxHealth; // Changed to double
    int maxMana;
    int maxStamina;
    bool armorEquipped;
    bool weaponEquipped;
    bool magicEquipped;

    Inventory inventory;

public:
    Player(double health, double attack, double magic, int mana, int stamina, int charisma, std::string playerClass,
        std::string playerRace, int level, int experience, int gold, double statusMultiplier, int previousLevel,
        double maxHealth, int maxAttack, int maxMagic, int maxMana, int maxStamina, int howManySpells, int howManyAbilities, bool armorEquipped, bool weaponEquipped, bool magicEquipped)
        : health(health), attack(attack), magic(magic), mana(mana), stamina(stamina), charisma(charisma), playerClass(playerClass), playerRace(playerRace),
        level(level), experience(experience), gold(gold), statusMultiplier(statusMultiplier), previousLevel(previousLevel), maxHealth(maxHealth),
        maxMana(maxMana), maxStamina(maxStamina), howManySpells(howManySpells), howManyAbilities(howManyAbilities), armorEquipped(armorEquipped), weaponEquipped(weaponEquipped), magicEquipped(magicEquipped) {}

    void setPlayerAttributes(double health, double attack, double magic, int mana, int stamina, int charisma);
    void setPlayerClassBuffs(double health, double attack, double magic, int mana, int stamina, int charisma);
    void setHealth(double health) { this->health = health; }
    void setAttack(double attack) { this->attack = attack; }
    void setMagic(double magic) { this->magic = magic; }
    void setMana(int mana) { this->mana = mana; }
    void setStamina(int stamina) { this->stamina = stamina; }
    void setCharisma(int charisma) { this->charisma = charisma; }
    void setPlayerClass(const std::string playerClass) { this->playerClass = playerClass; }
    void setPlayerRace(const std::string playerRace) { this->playerRace = playerRace; }
    void pickRace(Player& player);
    void pickClass(Player& player);
    void setLevel(int level) { this->level = level; }
    void setExperience(int experience) { this->experience = experience; }
    void setGold(int gold) { this->gold = gold; }
    void setStatusMultiplier(double statusMultiplier) { this->statusMultiplier = statusMultiplier; }
    void setPreviousLevel(int previousLevel) { this->previousLevel = previousLevel; }
    void setMaxHealth(double maxHealth) { this->maxHealth = maxHealth; } // Changed to double
    void setMaxMana(int maxMana) { this->maxMana = maxMana; }
    void setMaxStamina(int maxStamina) { this->maxStamina = maxStamina; }
    void setHowManySpells(int howManySpells) { this->howManySpells = howManySpells; }
    void setHowManyAbilities(int howManyAbilities) { this->howManyAbilities = howManyAbilities; }
    void setArmorEquipped(bool armorEquipped) { this->armorEquipped = armorEquipped; }
    void setWeaponEquipped(bool weaponEquipped) { this->weaponEquipped = weaponEquipped; }
    void setMagicEquipped(bool magicEquipped) { this->magicEquipped = magicEquipped; }

    double getHealth() const { return health; }
    double getAttack() const { return attack; }
    double getMagic() const { return magic; }
    int getMana() const { return mana; }
    int getStamina() const { return stamina; }
    int getCharisma() const { return charisma; }
    std::string getPlayerClass() const { return playerClass; }
    std::string getPlayerRace() const { return playerRace; }
    int getLevel() const { return level; }
    int getExperience() const { return experience; }
    int getGold() const { return gold; }
    double getStatusMultiplier() const { return statusMultiplier; }
    int getPreviousLevel() const { return previousLevel; }
    double getMaxHealth() const { return maxHealth; } // Changed to double
    int getMaxMana() const { return maxMana; }
    int getMaxStamina() const { return maxStamina; }
    int getHowManySpells() const { return howManySpells; }
    int getHowManyAbilities() const { return howManyAbilities; }
    bool getArmorEquipped() const { return armorEquipped; }
    bool getWeaponEquipped() const { return weaponEquipped; }
    bool getMagicEquipped() const { return magicEquipped; }
    Inventory& getInventory() { return inventory; }
};


class Monster
{
private:
    std::string name;
    int health;
    int attack;
    int magic;
    int mana;
    int stamina;
    int level;
    int difficulty;

public:
    Monster(std::string monsterName, int monsterHealth, int monsterAttack, int monsterMagic, int monsterMana, int monsterStamina, int monsterLevel, int difficulty)
        : name(monsterName), health(monsterHealth), attack(monsterAttack), magic(monsterMagic), mana(monsterMana), stamina(monsterStamina), level(monsterLevel), difficulty(difficulty) {}

    void scaleStats()
    {
        health += level * 7;
        attack += level * 2;
        magic += level * 3;
        mana += level * 5;
        stamina += level * 10;
    }

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    int getMagic() const { return magic; }
    int getMana() const { return mana; }
    int getStamina() const { return stamina; }
    int getLevel() const { return level; }
    int getDifficulty() const { return difficulty; }

    void setName(std::string monsterName) { name = monsterName; }
    void setHealth(int monsterHealth) { health = monsterHealth; }
    void setAttack(int monsterAttack) { attack = monsterAttack; }
    void setMagic(int monsterMagic) { magic = monsterMagic; }
    void setMana(int monsterMana) { mana = monsterMana; }
    void setStamina(int monsterStamina) { stamina = monsterStamina; }
    void setLevel(int monsterLevel) { level = monsterLevel; }
};

class Ability
{
public:
    std::string name;
    std::string description;
    int damage;
    int minimumCost;

    Ability() : name(""), description(""), damage(0), minimumCost(0) {}
    Ability(std::string n, std::string d, int dmg, int mana) : name(n), description(d), damage(dmg), minimumCost(mana) {}
};

class Abilities
{
public:
    static const int NUM_ABILITIES = 15;

    Ability warriorBasicAttacks[NUM_ABILITIES];
    Ability mageBasicAttacks[NUM_ABILITIES];
    Ability necromancerBasicAttacks[NUM_ABILITIES];
    Ability assassinBasicAttacks[NUM_ABILITIES];
    Ability paladinBasicAttacks[NUM_ABILITIES];

    Ability warriorMagicSpells[NUM_ABILITIES];
    Ability mageMagicSpells[NUM_ABILITIES];
    Ability necromancerMagicSpells[NUM_ABILITIES];
    Ability assassinMagicSpells[NUM_ABILITIES];
    Ability paladinMagicSpells[NUM_ABILITIES];

    Ability legendaryAbilities[NUM_ABILITIES];

    Abilities()
    {
        initializeAbilities();
    }

private:
    void initializeAbilities()
    {
        // Basic Attacks for each class
        warriorBasicAttacks[0] = Ability("Punch", "A powerful punch.", 5, 1);
        warriorBasicAttacks[1] = Ability("Kick", "A strong kick.", 6, 8);
        warriorBasicAttacks[2] = Ability("Shield Bash", "Bash the enemy with a shield.", 8, 10);
        warriorBasicAttacks[3] = Ability("Slash", "A quick slash with a sword.", 10, 60);
        warriorBasicAttacks[4] = Ability("Cleave", "A wide, sweeping attack.", 12, 50);
        warriorBasicAttacks[5] = Ability("Piercing Thrust", "A precise thrust aiming to pierce armor.", 14, 75);
        warriorBasicAttacks[6] = Ability("Power Strike", "A powerful strike with a sword.", 15, 85);
        warriorBasicAttacks[7] = Ability("Double Strike", "Two quick consecutive strikes.", 18, 70);
        warriorBasicAttacks[8] = Ability("Heavy Slam", "A heavy slam with a weapon.", 20, 90);
        warriorBasicAttacks[9] = Ability("Whirlwind", "A spinning attack that hits multiple enemies.", 25, 50);
        warriorBasicAttacks[10] = Ability("Raging Blow", "A furious, unrestrained attack.", 30, 95);
        warriorBasicAttacks[11] = Ability("Savage Strike", "A brutal, devastating strike.", 35, 80);
        warriorBasicAttacks[12] = Ability("Overhead Smash", "A crushing downward smash.", 40, 85);
        warriorBasicAttacks[13] = Ability("Berserker's Wrath", "An all-out attack in a rage.", 45, 90);
        warriorBasicAttacks[14] = Ability("Titan's Crush", "A colossal, overwhelming blow.", 50, 100);

        // Mage Basic Attacks
        mageBasicAttacks[0] = Ability("Punch", "A basic punch.", 5, 1);
        mageBasicAttacks[1] = Ability("Kick", "A basic kick.", 7, 10);
        mageBasicAttacks[2] = Ability("Staff Strike", "Strike with a staff.", 8, 15);
        mageBasicAttacks[3] = Ability("Arcane Strike", "A strike infused with arcane energy.", 10, 70);
        mageBasicAttacks[4] = Ability("Magic Blast", "A blast of magical energy.", 12, 90);
        mageBasicAttacks[5] = Ability("Firebolt", "A small bolt of fire.", 14, 60);
        mageBasicAttacks[6] = Ability("Ice Shard", "A shard of ice that pierces the enemy.", 16, 75);
        mageBasicAttacks[7] = Ability("Lightning Jolt", "A quick jolt of lightning.", 18, 80);
        mageBasicAttacks[8] = Ability("Wind Slash", "A sharp slash of wind.", 20, 65);
        mageBasicAttacks[9] = Ability("Earth Spike", "A spike of earth erupts under the enemy.", 22, 85);
        mageBasicAttacks[10] = Ability("Water Blast", "A powerful blast of water.", 24, 90);
        mageBasicAttacks[11] = Ability("Shadow Strike", "A strike from the shadows.", 26, 70);
        mageBasicAttacks[12] = Ability("Light Beam", "A concentrated beam of light.", 28, 95);
        mageBasicAttacks[13] = Ability("Arcane Barrage", "A barrage of arcane missiles.", 30, 100);
        mageBasicAttacks[14] = Ability("Meteor Strike", "Summons a meteor to strike the enemy.", 35, 120);


        // Necromancer Basic Attacks
        necromancerBasicAttacks[0] = Ability("Punch", "A basic punch.", 5, 1);
        necromancerBasicAttacks[1] = Ability("Kick", "A basic kick.", 7, 10);
        necromancerBasicAttacks[2] = Ability("Bone Strike", "Strike with a bone.", 8, 20);
        necromancerBasicAttacks[3] = Ability("Dark Slash", "A slash with dark energy.", 10, 50);
        necromancerBasicAttacks[4] = Ability("Necrotic Touch", "A touch that drains life.", 12, 70);
        necromancerBasicAttacks[5] = Ability("Shadow Punch", "A punch infused with shadow energy.", 14, 30);
        necromancerBasicAttacks[6] = Ability("Soul Strike", "A strike that targets the soul.", 16, 40);
        necromancerBasicAttacks[7] = Ability("Plague Swipe", "A swipe that infects with plague.", 18, 60);
        necromancerBasicAttacks[8] = Ability("Bone Spear", "A spear made of bone is hurled at the enemy.", 20, 80);
        necromancerBasicAttacks[9] = Ability("Deathly Grip", "A grip that saps the enemy's strength.", 22, 90);
        necromancerBasicAttacks[10] = Ability("Wraith's Touch", "A touch that invokes wraith's curse.", 24, 70);
        necromancerBasicAttacks[11] = Ability("Spectral Slash", "A slash that cuts through the spirit.", 26, 85);
        necromancerBasicAttacks[12] = Ability("Corpse Explosion", "Explodes a corpse to damage enemies.", 28, 100);
        necromancerBasicAttacks[13] = Ability("Reaper's Scythe", "A devastating strike with a scythe.", 30, 110);
        necromancerBasicAttacks[14] = Ability("Dark Pulse", "A pulse of dark energy.", 32, 120);

        // Assassin Basic Attacks
        assassinBasicAttacks[0] = Ability("Punch", "A basic punch.", 5, 1);
        assassinBasicAttacks[1] = Ability("Kick", "A basic kick.", 7, 10);
        assassinBasicAttacks[2] = Ability("Garrote", "Strangles the enemy.", 8, 30);
        assassinBasicAttacks[3] = Ability("Shadow Strike", "A strike from the shadows.", 12, 60);
        assassinBasicAttacks[4] = Ability("Backstab", "A deadly backstab.", 15, 90);
        assassinBasicAttacks[5] = Ability("Poison Dart", "A dart laced with poison.", 10, 40);
        assassinBasicAttacks[6] = Ability("Silent Slash", "A silent, swift slash.", 14, 70);
        assassinBasicAttacks[7] = Ability("Vanish Strike", "A strike that follows a vanishing act.", 16, 80);
        assassinBasicAttacks[8] = Ability("Throat Cut", "A quick, lethal cut to the throat.", 18, 100);
        assassinBasicAttacks[9] = Ability("Ambush", "A sudden, unexpected attack.", 20, 110);
        assassinBasicAttacks[10] = Ability("Eviscerate", "A brutal disembowelment.", 22, 120);
        assassinBasicAttacks[11] = Ability("Shuriken Throw", "Throws a shuriken with deadly accuracy.", 25, 90);
        assassinBasicAttacks[12] = Ability("Venom Blade", "A blade coated with venom.", 28, 100);
        assassinBasicAttacks[13] = Ability("Assassinate", "An assassination attempt.", 30, 130);
        assassinBasicAttacks[14] = Ability("Deadly Flurry", "A rapid flurry of deadly strikes.", 35, 140);

        // Paladin Basic Attacks
        paladinBasicAttacks[0] = Ability("Punch", "A basic punch.", 5, 1);
        paladinBasicAttacks[1] = Ability("Kick", "A basic kick.", 7, 10);
        paladinBasicAttacks[2] = Ability("Shield Bash", "Bash the enemy with a shield.", 8, 20);
        paladinBasicAttacks[3] = Ability("Hammer Strike", "A hammer strike.", 10, 60);
        paladinBasicAttacks[4] = Ability("Smite", "A holy smite.", 12, 75);
        paladinBasicAttacks[5] = Ability("Holy Strike", "A strike infused with holy energy.", 14, 50);
        paladinBasicAttacks[6] = Ability("Divine Slash", "A slash blessed with divine power.", 16, 80);
        paladinBasicAttacks[7] = Ability("Radiant Burst", "A burst of radiant energy.", 18, 90);
        paladinBasicAttacks[8] = Ability("Consecrated Blow", "A blow that consecrates the ground.", 20, 70);
        paladinBasicAttacks[9] = Ability("Blessed Hammer", "A strike with a blessed hammer.", 22, 85);
        paladinBasicAttacks[10] = Ability("Crusader's Strike", "A strike of a crusader.", 24, 100);
        paladinBasicAttacks[11] = Ability("Judgment", "A powerful judgment.", 26, 110);
        paladinBasicAttacks[12] = Ability("Avenger's Shield", "Throws a shield that ricochets between enemies.", 28, 120);
        paladinBasicAttacks[13] = Ability("Light's Wrath", "Unleashes the wrath of the Light.", 30, 130);
        paladinBasicAttacks[14] = Ability("Divine Storm", "A storm of divine power.", 32, 140);

        // Magic Spells for each class
        warriorMagicSpells[0] = Ability("Sand Rage", "Basic sand spell.", 1, 5);
        warriorMagicSpells[1] = Ability("Earth Shatter", "Intimidates the enemy.", 2, 10);
        warriorMagicSpells[2] = Ability("Berserk", "Quick super strength.", 5, 20);
        warriorMagicSpells[3] = Ability("Charge", "Charges at the enemy.", 6, 30);
        warriorMagicSpells[4] = Ability("Warrior's Light", "Burns the enemy.", 7, 40);
        warriorMagicSpells[5] = Ability("Flame Strike", "A strike with fiery power.", 8, 50);
        warriorMagicSpells[6] = Ability("Stone Skin", "Increases defense temporarily.", 10, 60);
        warriorMagicSpells[7] = Ability("Thunder Clap", "A clap of thunderous force.", 12, 70);
        warriorMagicSpells[8] = Ability("Whirlwind Fury", "A whirlwind of magical energy.", 14, 80);
        warriorMagicSpells[9] = Ability("Iron Will", "Temporarily increases strength and defense.", 16, 90);
        warriorMagicSpells[10] = Ability("Dragon's Roar", "A roar that instills fear and deals damage.", 18, 100);
        warriorMagicSpells[11] = Ability("Meteor Crash", "Summons a meteor to crash into the enemy.", 20, 110);
        warriorMagicSpells[12] = Ability("Blazing Charge", "A fiery charge at the enemy.", 22, 120);
        warriorMagicSpells[13] = Ability("Lightning Spear", "Hurls a spear of lightning.", 24, 130);
        warriorMagicSpells[14] = Ability("Elemental Rage", "Unleashes the power of all elements.", 26, 140);

        mageMagicSpells[0] = Ability("Ice Spike", "A spike of ice that pierces the enemy.", 8, 65);
        mageMagicSpells[1] = Ability("Fireball", "A ball of fire that burns the enemy.", 10, 60);
        mageMagicSpells[2] = Ability("Lightning Bolt", "A bolt of lightning that shocks the enemy.", 12, 70);
        mageMagicSpells[3] = Ability("Arcane Blast", "A blast of arcane energy.", 15, 75);
        mageMagicSpells[4] = Ability("Wind Gust", "A gust of wind that knocks back enemies.", 5, 40);
        mageMagicSpells[5] = Ability("Stone Fist", "A fist made of stone that strikes the enemy.", 7, 50);
        mageMagicSpells[6] = Ability("Water Jet", "A jet of water that pushes back the enemy.", 9, 55);
        mageMagicSpells[7] = Ability("Shadow Bolt", "A bolt of shadow energy.", 11, 70);
        mageMagicSpells[8] = Ability("Solar Flare", "A flare of solar energy.", 13, 80);
        mageMagicSpells[9] = Ability("Meteor Shower", "Summons meteors to rain down on the enemy.", 16, 90);
        mageMagicSpells[10] = Ability("Frost Nova", "A burst of frost that freezes enemies.", 18, 95);
        mageMagicSpells[11] = Ability("Thunderstorm", "Summons a storm of lightning.", 20, 100);
        mageMagicSpells[12] = Ability("Earthquake", "Shakes the ground to damage enemies.", 22, 110);
        mageMagicSpells[13] = Ability("Blizzard", "Summons a blizzard to freeze and damage enemies.", 24, 120);
        mageMagicSpells[14] = Ability("Phoenix Fire", "Summons a phoenix made of fire.", 26, 130);

        necromancerMagicSpells[0] = Ability("Raise Dead", "Raises a dead enemy to fight for you.", 5, 30);
        necromancerMagicSpells[1] = Ability("Dark Pact", "Sells your enemy vitality.", 8, 30);
        necromancerMagicSpells[2] = Ability("Bone Spear", "Throws a spear made of bone.", 10, 65);
        necromancerMagicSpells[3] = Ability("Soul Drain", "Drains the soul of the enemy.", 15, 80);
        necromancerMagicSpells[4] = Ability("Necrotic Plague", "Inflicts a deadly plague.", 18, 100);
        necromancerMagicSpells[5] = Ability("Shadow Grasp", "Grasps the enemy with shadowy hands.", 7, 40);
        necromancerMagicSpells[6] = Ability("Death Coil", "A coil of deathly energy.", 9, 50);
        necromancerMagicSpells[7] = Ability("Spectral Strike", "A strike from the spectral realm.", 11, 70);
        necromancerMagicSpells[8] = Ability("Corpse Explosion", "Explodes a corpse to damage enemies.", 13, 75);
        necromancerMagicSpells[9] = Ability("Wraith's Touch", "A touch that siphons life.", 14, 85);
        necromancerMagicSpells[10] = Ability("Grave Chill", "Chills the enemy with grave cold.", 16, 90);
        necromancerMagicSpells[11] = Ability("Deathly Howl", "A howl that frightens and harms.", 17, 95);
        necromancerMagicSpells[12] = Ability("Spirit Leech", "Leeches life from the spirit.", 21, 110);
        necromancerMagicSpells[13] = Ability("Curse of Agony", "Curses the enemy with agony.", 23, 120);
        necromancerMagicSpells[14] = Ability("Death Mark", "Marks an enemy for death.", 25, 130);

        assassinMagicSpells[0] = Ability("Vanish", "Quick attack.", 5, 10);
        assassinMagicSpells[1] = Ability("Assassin's Mark", "Marks an enemy for blindspot damage.", 10, 60);
        assassinMagicSpells[2] = Ability("Poison Dagger", "Coats your dagger with poison.", 10, 65);
        assassinMagicSpells[3] = Ability("Shadow Step", "Teleport behind the enemy and stabs.", 12, 70);
        assassinMagicSpells[4] = Ability("Blind", "Blinds the enemy and does a critical damage!", 15, 100);
        assassinMagicSpells[5] = Ability("Silent Step", "Moves silently to avoid detection.", 6, 20);
        assassinMagicSpells[6] = Ability("Smoke Bomb", "Throws a smoke bomb to obscure vision.", 8, 30);
        assassinMagicSpells[7] = Ability("Shadow Cloak", "Cloaks in shadows to increase evasion.", 9, 40);
        assassinMagicSpells[8] = Ability("Envenom", "Enhances poison damage temporarily.", 11, 50);
        assassinMagicSpells[9] = Ability("Nightmare Strike", "A strike that induces fear.", 13, 75);
        assassinMagicSpells[10] = Ability("Silent Kill", "A silent, lethal attack.", 16, 85);
        assassinMagicSpells[11] = Ability("Crippling Poison", "A poison that cripples the enemy.", 18, 90);
        assassinMagicSpells[12] = Ability("Ambush", "A surprise attack from stealth.", 20, 95);
        assassinMagicSpells[13] = Ability("Dark Whisper", "Whispers that cause confusion.", 22, 100);
        assassinMagicSpells[14] = Ability("Phantom Strike", "An ethereal strike that ignores armor.", 24, 110);

        paladinMagicSpells[0] = Ability("Divine Justice", "Your Shield sends a light beam.", 2, 0);
        paladinMagicSpells[1] = Ability("Lay on Hands", "Covers your hands with holy energy, powerful right hook!.", 8, 50);
        paladinMagicSpells[2] = Ability("Holy Light", "A beam of holy light that destroys monsters.", 9, 60);
        paladinMagicSpells[3] = Ability("Consecrate", "Consecrates the ground, damaging enemies.", 10, 65);
        paladinMagicSpells[4] = Ability("Judgment", "Judges the enemy, dealing damage.", 12, 75);
        paladinMagicSpells[5] = Ability("Divine Strike", "Strikes with divine power.", 11, 70);
        paladinMagicSpells[6] = Ability("Sacred Flame", "Engulfs the enemy in sacred fire.", 13, 80);
        paladinMagicSpells[7] = Ability("Holy Wrath", "Unleashes holy wrath upon enemies.", 15, 85);
        paladinMagicSpells[8] = Ability("Radiant Shield", "Creates a shield of radiant energy.", 17, 90);
        paladinMagicSpells[9] = Ability("Light's Blessing", "Blesses allies, damaging enemies.", 18, 95);
        paladinMagicSpells[10] = Ability("Purifying Light", "Purifies the area with holy light.", 20, 100);
        paladinMagicSpells[11] = Ability("Sanctified Ground", "Sanctifies the ground, harming foes.", 22, 105);
        paladinMagicSpells[12] = Ability("Divine Storm", "Summons a storm of divine power.", 24, 110);
        paladinMagicSpells[13] = Ability("Blessed Hammer", "Throws a blessed hammer at enemies.", 26, 115);
        paladinMagicSpells[14] = Ability("Celestial Strike", "Strikes with celestial energy.", 28, 120);

        // Legendary Abilities
        legendaryAbilities[0] = Ability("EXCALIBUR", "Summons the legendary sword Excalibur.", 30, 20);
        legendaryAbilities[1] = Ability("Deadly Sun Strike", "Calls down a deadly sun strike.", 35, 30);
        legendaryAbilities[2] = Ability("Reaper's Scythe", "Summons a scythe that reaps souls.", 32, 25);
        legendaryAbilities[3] = Ability("Dark Skin Knife", "Summons a knife that steals life.", 28, 20);
        legendaryAbilities[4] = Ability("Phoenix Rebirth", "Revives from death with full health.", 0, 30);
    }
};

struct takeOffArmorBuffs
{
    double multiplier;
    int id;
    bool itemEquiped;

};

struct takeOffWeaponBuffs
{
	double multiplier;
	int id;
	bool itemEquiped;
};

struct takeOffMagicBuffs
{
	double multiplier;
	int id;
	bool itemEquiped;
};


int randomNumberGenerator(int minimum, int size);
void printEverything(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB);
void printGrid(char grid[GRIDSIZE][GRIDSIZE]);
void checkGrid(char grid[GRIDSIZE][GRIDSIZE], int Y, int X, Player& mainCharacter);
void characterInForest(Player& mainCharacter);
void printOptionsMenuStart(Player& mainCharacter);
void menuSelectOptions(Player& mainCharacter);
void setRandomGridElements(char grid[GRIDSIZE][GRIDSIZE]);
bool checkExperience(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB);
void MonsterFight(Player& mainCharacter, Monster& monster);
void checkClassLevel(Player& mainCharacter, takeOffArmorBuffs& aB, takeOffWeaponBuffs& Wb, takeOffMagicBuffs& MB);
void makeMonsters(Player& mainCharacter);
int checkWhichClass(Player& mainCharacter);
void turnAttack(Player& mainCharacter, Monster& monster);
void warriorBasicAbility(Player& mainCharacter, Monster& monster, Abilities& warriorAbilities);
void warriorSpellAbility(Player& mainCharacter, Monster& monster, Abilities& warriorAbilities);
void mageSpecialAbility(Player& mainCharacter, Monster& monster, Abilities& mageAbilities);
void mageBasicAbility(Player& mainCharacter, Monster& monster, Abilities& mageAbilities);
void necromancerBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& necromancerAbilities);
void necromancerSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& necromancerAbilities);
void assassinBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& assassinAbilities);
void assassinSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& assassinAbilities);
void paladinBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& paladinAbilities);
void paladinSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& paladinAbilities);
void checkIfStatMax(Player& mainCharacter);
void handleBasicAttack(Player& mainCharacter, Monster& monster);
void handleSpellAttack(Player& mainCharacter, Monster& monster);
void setMonsterLevelstats(Player& mainCharacter, Monster& monster);
void monsterAttack(Player& mainCharacter, Monster& monster, bool isBlocking);
void printMonsterStats(Monster& monster, Player& mainCharacter);
void DropExpAndGold(Player& mainCharacter, Monster& monster);
void printDrops(int exp, int gold);
void clearInputBuffer();
void dropCommonConsumable(Player& mainCharacter);
void dropUncommonConsumables(Player& mainCharacter);
void dropEpicConsumables(Player& mainCharacter);
void dropLegendaryConsumables(Player& mainCharacter);
void dropMythicalConsumable(Player& mainCharacter);
void printNerfedGrid(char grid[GRIDSIZE][GRIDSIZE]);
void gamble(Player& mainCharacter);
void pickRandomConsumable(Player& mainCharacter);
void handleConsumableGeneral(Player& mainCharacter, int& id, int& healAmount);
void dropCommonArmor(Player& mainCharacter);
void dropUncommonArmor(Player& mainCharacter);
void dropEpicArmor(Player& mainCharacter);
void dropLegendaryArmor(Player& mainCharacter);
void dropMythicalArmor(Player& mainCharacter);
void pickRandomArmor(Player& mainCharacter);
void takeArmorMultiplierOff(Player& mainCharacter, double& multiplier, int& id);
void applyArmorMultiplier(Player& mainCharacter, double& multiplier, int& id);
string getRainbowText(const string& text);
void handleInvalidInput();
void dropCommonMeleeWeapons(Player& mainCharacter);
void dropUncommonMeleeWeapons(Player& mainCharacter);
void dropEpicMeleeWeapons(Player& mainCharacter);
void dropLegendaryMeleeWeapons(Player& mainCharacter);
void dropMythicalMeleeWeapons(Player& mainCharacter);
void pickRandomWeapon(Player& mainCharacter);
void applyMeleeWeaponMultiplier(Player& mainCharacter, double& multiplier, int& id);
void takeMeleeWeaponMultiplierOff(Player& mainCharacter, double& multiplier, int& id);
void equipItems(Player& mainCharacter, takeOffArmorBuffs& defaultArmor, takeOffWeaponBuffs& defaultWeapon);
void takeMagicWeaponMultiplierOff(Player& mainCharacter, double& multiplier, int& id);
void applyMagicWeaponMultiplier(Player& mainCharacter, double& multiplier, int& id);
void dropMythicalMagicWeapons(Player& mainCharacter);
void dropLegendaryMagicWeapons(Player& mainCharacter);
void dropEpicMagicWeapons(Player& mainCharacter);
void dropUncommonMagicWeapons(Player& mainCharacter);
void dropCommonMagicWeapons(Player& mainCharacter);
void easyDungeon(Player& mainCharacter);
void DungeonTime(Player& mainCharacter);
void mediumDungeon(Player& mainCharacter);
void largeDungeon(Player& mainCharacter);
void legendaryDungeon(Player& mainCharacter);
void randomCommonDrop(Player& mainCharacter);
void randomUncommonDrop(Player& mainCharacter);
void randomEpicDrop(Player& mainCharacter);
void randomLegendaryDrop(Player& mainCharacter);
void randomMythicalDrop(Player& mainCharacter);
void strangerMysteryBox(Player& mainCharacter);
void commonMysteryBox(Player& mainCharacter);
void uncommonMysteryBox(Player& mainCharacter);
void epicMysteryBox(Player& mainCharacter);
void legendaryMysteryBox(Player& mainCharacter);
void mythicMysteryBox(Player& mainCharacter);
void mysteryBox(Player& mainCharacter);
void handleMysteriousCave(Player& mainCharacter);
void randomEvent(Player& mainCharacter);
void handleBlackWater(Player& mainCharacter);


#endif

