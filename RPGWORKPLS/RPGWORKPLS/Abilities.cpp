#include "RpgHeader.h"
using namespace std;

void handleInvalidInput() 
{
    if (cin.fail())
    {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
}

void warriorBasicAbility(Player& mainCharacter, Monster& monster, Abilities& warriorAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int staminaUsage;

    for (i = 0; i < mainCharacter.getHowManyAbilities(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << warriorAbilities.warriorBasicAttacks[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << warriorAbilities.warriorBasicAttacks[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> staminaUsage;
    handleInvalidInput();

    if (staminaUsage > mainCharacter.getStamina())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (staminaUsage < warriorAbilities.warriorBasicAttacks[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);
        return;
    }

    mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);

    int totalDamage = mainCharacter.getAttack() + warriorAbilities.warriorBasicAttacks[abilitySelection - 1].damage + staminaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void warriorSpellAbility(Player& mainCharacter, Monster& monster, Abilities& warriorAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int manaUsage;

    for (i = 0; i < mainCharacter.getHowManySpells(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << warriorAbilities.warriorMagicSpells[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << warriorAbilities.warriorMagicSpells[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much mana do you want to use? ";
    cin >> manaUsage;
    handleInvalidInput();

    if (manaUsage > mainCharacter.getMana())
    {
        cout << CENTRALIZE << "You don't have enough mana!\n" << endl;
        return;
    }

    if (manaUsage < warriorAbilities.warriorMagicSpells[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setMana(mainCharacter.getMana() - manaUsage);
        return;
    }

    mainCharacter.setMana(mainCharacter.getMana() - manaUsage);

    int totalDamage = mainCharacter.getMagic() + warriorAbilities.warriorMagicSpells[abilitySelection - 1].damage + manaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void mageBasicAbility(Player& mainCharacter, Monster& monster, Abilities& mageAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int staminaUsage;

    for (i = 0; i < mainCharacter.getHowManyAbilities(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << mageAbilities.mageBasicAttacks[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << mageAbilities.mageBasicAttacks[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> staminaUsage;
    handleInvalidInput();

    if (staminaUsage > mainCharacter.getStamina())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (staminaUsage < mageAbilities.mageBasicAttacks[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);
        return;
    }

    mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);

    int totalDamage = mainCharacter.getAttack() + mageAbilities.mageBasicAttacks[abilitySelection - 1].damage + staminaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void mageSpecialAbility(Player& mainCharacter, Monster& monster, Abilities& mageAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int manaUsage;

    for (i = 0; i < mainCharacter.getHowManySpells(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << mageAbilities.mageMagicSpells[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << mageAbilities.mageMagicSpells[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much mana do you want to use? ";
    cin >> manaUsage;
    handleInvalidInput();

    if (manaUsage > mainCharacter.getMana())
    {
        cout << CENTRALIZE << "You don't have enough mana!\n" << endl;
        return;
    }

    if (manaUsage < mageAbilities.mageMagicSpells[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setMana(mainCharacter.getMana() - manaUsage);
        return;
    }

    mainCharacter.setMana(mainCharacter.getMana() - manaUsage);

    int totalDamage = mainCharacter.getMagic() + mageAbilities.mageMagicSpells[abilitySelection - 1].damage + manaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void necromancerBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& necromancerAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int staminaUsage;

    for (i = 0; i < mainCharacter.getHowManyAbilities(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << necromancerAbilities.necromancerBasicAttacks[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << necromancerAbilities.necromancerBasicAttacks[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> staminaUsage;
    handleInvalidInput();

    if (staminaUsage > mainCharacter.getStamina())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (staminaUsage < necromancerAbilities.necromancerBasicAttacks[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);
        return;
    }

    mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);

    int totalDamage = mainCharacter.getAttack() + necromancerAbilities.necromancerBasicAttacks[abilitySelection - 1].damage + staminaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void necromancerSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& necromancerAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int manaUsage;

    for (i = 0; i < mainCharacter.getHowManySpells(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << necromancerAbilities.necromancerMagicSpells[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << necromancerAbilities.necromancerMagicSpells[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much mana do you want to use? ";
    cin >> manaUsage;
    handleInvalidInput();

    if (manaUsage > mainCharacter.getMana())
    {
        cout << CENTRALIZE << "You don't have enough mana!\n" << endl;
        return;
    }

    if (manaUsage < necromancerAbilities.necromancerMagicSpells[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setMana(mainCharacter.getMana() - manaUsage);
        return;
    }

    mainCharacter.setMana(mainCharacter.getMana() - manaUsage);

    int totalDamage = mainCharacter.getMagic() + necromancerAbilities.necromancerMagicSpells[abilitySelection - 1].damage + manaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void assassinBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& assassinAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int staminaUsage;

    for (i = 0; i < mainCharacter.getHowManyAbilities(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << assassinAbilities.assassinBasicAttacks[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << assassinAbilities.assassinBasicAttacks[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> staminaUsage;
    handleInvalidInput();

    if (staminaUsage > mainCharacter.getStamina())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (staminaUsage < assassinAbilities.assassinBasicAttacks[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);
        return;
    }

    mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);

    int totalDamage = mainCharacter.getAttack() + assassinAbilities.assassinBasicAttacks[abilitySelection - 1].damage + staminaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void assassinSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& assassinAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int manaUsage;

    for (i = 0; i < mainCharacter.getHowManySpells(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << assassinAbilities.assassinMagicSpells[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << assassinAbilities.assassinMagicSpells[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> manaUsage;
    handleInvalidInput();

    if (manaUsage > mainCharacter.getMana())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (manaUsage < assassinAbilities.assassinMagicSpells[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setMana(mainCharacter.getMana() - manaUsage);
        return;
    }

    mainCharacter.setMana(mainCharacter.getMana() - manaUsage);

    int totalDamage = mainCharacter.getAttack() + assassinAbilities.assassinMagicSpells[abilitySelection - 1].damage + manaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void paladinBasicAbilities(Player& mainCharacter, Monster& monster, Abilities& paladinAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int staminaUsage;

    for (i = 0; i < mainCharacter.getHowManyAbilities(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << paladinAbilities.paladinBasicAttacks[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate\n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << paladinAbilities.paladinBasicAttacks[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much stamina do you want to use? ";
    cin >> staminaUsage;
    handleInvalidInput();

    if (staminaUsage > mainCharacter.getStamina())
    {
        cout << CENTRALIZE << "You don't have enough stamina!\n" << endl;
        return;
    }

    if (staminaUsage < paladinAbilities.paladinBasicAttacks[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);
        return;
    }

    mainCharacter.setStamina(mainCharacter.getStamina() - staminaUsage);

    int totalDamage = mainCharacter.getAttack() + paladinAbilities.paladinBasicAttacks[abilitySelection - 1].damage + staminaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!" << endl;
}

void paladinSpecialAbilities(Player& mainCharacter, Monster& monster, Abilities& paladinAbilities)
{
    int abilitySelection = 0;
    int i = 0;
    int manaUsage;

    for (i = 0; i < mainCharacter.getHowManySpells(); i++)
    {
        cout << CENTRALIZE << i + 1 << ". " << paladinAbilities.paladinMagicSpells[i].name << endl;
    }
    cout << CENTRALIZE << i + 1 << ". Hesitate \n" << endl;
    cout << CENTRALIZE << "Choose an ability: ";
    cin >> abilitySelection;
    handleInvalidInput();

    while (abilitySelection > i + 1 || abilitySelection < 1)
    {
        cout << CENTRALIZE << "Invalid selection. Choose an ability: ";
        cin >> abilitySelection;
        handleInvalidInput();
    }

    if (abilitySelection == i + 1)
    {
        system("CLS");
        return;
    }

    cout << CENTRALIZE << "You used " << paladinAbilities.paladinMagicSpells[abilitySelection - 1].name << "!" << endl;
    cout << CENTRALIZE << "How much mana do you want to use? ";
    cin >> manaUsage;
    handleInvalidInput();

    if (manaUsage > mainCharacter.getMana())
    {
        cout << CENTRALIZE << "You don't have enough mana!\n" << endl;
        return;
    }

    if (manaUsage < paladinAbilities.paladinMagicSpells[abilitySelection - 1].minimumCost)
    {
        cout << CENTRALIZE << "You Failed!\n" << endl;
        mainCharacter.setMana(mainCharacter.getMana() - manaUsage);
        return;
    }

    mainCharacter.setMana(mainCharacter.getMana() - manaUsage);

    int totalDamage = mainCharacter.getMagic() + paladinAbilities.paladinMagicSpells[abilitySelection - 1].damage + manaUsage - DAMAGE_REDUCTION;
    monster.setHealth(monster.getHealth() - totalDamage);

    cout << CENTRALIZE << "You dealt " << totalDamage << " damage!\n" << endl;
}
