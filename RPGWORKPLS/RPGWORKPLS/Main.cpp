using namespace std;
#include "RpgHeader.h"

int main(void)
{
	Player mainCharacter(0, 0, 0, 0, 0, 0, "", "", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, false, false, false);
	mainCharacter.pickRace(mainCharacter);
	system("CLS");
	mainCharacter.pickClass(mainCharacter);
	system("CLS");
	mainCharacter.setMaxHealth(mainCharacter.getHealth());
	mainCharacter.setMaxMana(mainCharacter.getMana());
	mainCharacter.setMaxStamina(mainCharacter.getStamina());
	menuSelectOptions(mainCharacter);

	return 0;
}

void clearInputBuffer()
{
	char c;
	while ((c = cin.get()) != '\n' && c != EOF);
}

