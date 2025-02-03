#include "Player.h"

std::vector<int> Player::startingWeapon()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\nChoose 2 weapons to start with: " << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "1. Sword" << std::endl;
	std::cout << "2. Shield" << std::endl;
	std::cout << "3. Wand" << std::endl;
	std::cout << "4. Bow" << std::endl;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\nSword dmg = 20, Trustworthy and reliable damage against all targets" << std::endl;
	std::cout << "Shield dmg = 5, Increases defense by 7 each use up to 50% (increased defense stays with each new level)" << std::endl;
	std::cout << "Wand dmg = 15, Uses 10 Mana and has 25% chance to do double damage which consumes extra 5 mana" << std::endl;
	std::cout << "Bow dmg = 35, Highest base damage but has 20% chance to miss enemy" << std::endl;

	SetConsoleTextAttribute(hConsole, 6);
	std::cout << "\nNOTE: Attribute points are awarded after each level, 1 point per level" << std::endl;
	std::cout << "attribute points increase weapon damage by 1 per point (max 3)" << std::endl;
	SetConsoleTextAttribute(hConsole, 15);

	int choice1 = -1;
	int choice2 = -1;
	int weaponCount = 0;
	bool sword = false;
	bool shield = false;
	bool wand = false;
	bool bow = false;

	this->weapons.resize(2);

	while (choice1 < 0 || choice1 > 4) {
		std::cout << "\nEnter your 1st choice: ";
		std::cin >> choice1;

		switch (choice1)
		{
		case 1:
			this->weapons[0] = WeaponType::SWORD;
			sword = true;
			++weaponCount;
			break;
		case 2:
			this->weapons[0] = WeaponType::SHIELD;
			shield = true;
			++weaponCount;
			break;
		case 3:
			this->weapons[0] = WeaponType::WAND;
			wand = true;
			++weaponCount;
			break;
		case 4:
			this->weapons[0] = WeaponType::BOW;
			bow = true;
			++weaponCount;
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "Invalid choice, try again" << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	while (choice2 == choice1 || choice2 < 1 || choice2 > 4) {
		std::cout << "Enter your 2nd choice: ";
		std::cin >> choice2;

		switch (choice2)
		{
		case 1:
			if (sword == true) {
				std::cout << "You have already chosen this weapon, choose another" << std::endl;
				break;
			}
			else {
				this->weapons[1] = WeaponType::SWORD;
				sword = true;
				++weaponCount;
				break;
			}
		case 2:
			if (shield == true) {
				std::cout << "You have already chosen this weapon, choose another" << std::endl;
				break;
			}
			else {
				this->weapons[1] = WeaponType::SHIELD;
				shield = true;
				++weaponCount;
				break;
			}
		case 3:
			if (wand == true) {
				std::cout << "You have already chosen this weapon, choose another" << std::endl;
				break;
			}
			else {
				this->weapons[1] = WeaponType::WAND;
				wand = true;
				++weaponCount;
				break;
			}
		case 4:
			if (bow == true) {
				std::cout << "You have already chosen this weapon, choose another" << std::endl;
				break;
			}
			else {
				this->weapons[1] = WeaponType::BOW;
				bow = true;
				++weaponCount;
				break;
			}
		default:
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "Invalid choice, try again" << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	std::cout << "You have chosen: ";

	if (this->weapons[0] == WeaponType::SWORD) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Sword & ";
	}
	else if (this->weapons[0] == WeaponType::SHIELD) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Shield & ";
	}
	else if (this->weapons[0] == WeaponType::WAND) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Wand & ";
	}
	else if (this->weapons[0] == WeaponType::BOW) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Bow & ";
	}

	if (this->weapons[1] == WeaponType::SWORD) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Sword";
	}
	else if (this->weapons[1] == WeaponType::SHIELD) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Shield";
	}
	else if (this->weapons[1] == WeaponType::WAND) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Wand";
	}
	else if (this->weapons[1] == WeaponType::BOW) {
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Bow";
	}
	std::cout << "\n" << std::endl;
	std::vector<int> weaponList = { this->weapons[0], this->weapons[1]};
	return weaponList;
}

int Player::startingSkill()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\nChoose 1 skill to start with: " << std::endl;

	SetConsoleTextAttribute(hConsole, 5);
	std::cout << "1. Higher Power" << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "2. Mana Shield" << std::endl;

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\nHigher Power - Increases all damage by 5 but permanently takes 10 hp off max hp (90/100)" << std::endl;
	std::cout << "Mana Shield - Increases base defense by 10 (10->20) but max mana is now (80/100)" << std::endl;

	int choice = 0;
	int skillCount = 0;

	while (skillCount != 1 || (choice < 1 || choice > 2)) {
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			this->skills[choice - 1] = Skills::offensive;
			std::cout << "You have chosen: ";
			SetConsoleTextAttribute(hConsole, 5);
			std::cout << "Higher Power" << std::endl;
			health-=10;
			skill = this->skills[choice - 1];
			++skillCount;
			return 1;
		case 2:
			this->skills[choice - 1] = Skills::defensive;
			std::cout << "You have chosen: ";
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Mana Shield" << std::endl;
			skill = this->skills[choice - 1];
			mana -= 20;
			defense += 10;
			++skillCount;
			return 2;
		default:
			std::cout << "Invalid choice, try again" << std::endl;
		}
	}
	return choice;
}

void Player::attack(int weapon, Entity& target)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << "\n" << name << " attacks ";
	std::cout << target.getName() << " with ";
	volatile int trueDamage;
	volatile int damage;
	int chance;
	SetConsoleTextAttribute(hConsole, 14);
	switch (weapon)
	{
	case 0:
		std::cout << "SWORD";
		damage = 20; // Base damage
		break;
	case 1:
		std::cout << "SHIELD";
		damage = 5; // Base damage
		// Shield defense increase per use
		if (defense < 50)
		{
			defense += 7;
		}
		if (defense > 50)
		{
			defense = 50;
		}
		break;
	case 2:
		std::cout << "WAND";
		damage = 15; // Base damage

		// Wand effect chance
		chance = rand() % 4;
		if (chance == 2)
		{
			damage *= 2;
			std::cout << "\nAttack was doubled by wand effect" << std::endl;
			mana -= 5;
		}
		mana -= 10;
		break;
	case 3:
		std::cout << "BOW";
		damage = 35; // Base damage
		chance = rand() % 5;
		if (chance == 1)
		{
			damage = 0;
			std::cout << "\nAttack missed target" << std::endl;
			return;
		}
		break;
	}
	trueDamage = damage;
	// Stat point damage scaling
	if (1 == getStatPoints())
	{
		trueDamage = damage + 1;
	}
	if (2 == getStatPoints())
	{
		trueDamage = damage + 2;
	}
	if (3 == getStatPoints())
	{
		trueDamage = damage + 3;
	}
	if (skill == 0)
	{
		trueDamage += 5;
	}

	// defense scaling
	switch (target.getDefense())
	{
	case 10:
		trueDamage -= 2;
		target.setHealth(target.getHealth() - trueDamage);
		break;
	default:
		trueDamage -= 4;
		target.setHealth(target.getHealth() - trueDamage);
		break;
	}
	if (target.getHealth() < 0)
	{
		target.setHealth(0);
	}

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " - Damage Dealt: " << trueDamage << std::endl;
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << " Boss Health: " << target.getHealth() << "\n" << std::endl;
}

int Player::chooseAttackWeapon() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Choose your weapon for attack" << std::endl;
	std::cout << "Your weapons: " << std::endl;
	SetConsoleTextAttribute(hConsole, 14);

	switch (this->weapons[0])
	{
	case 0:
		std::cout << "1. Sword" << std::endl;
		break;
	case 1:
		std::cout << "1. Shield" << std::endl;
		break;
	case 2:
		std::cout << "1. Wand" << std::endl;
		break;
	case 3:
		std::cout << "1. Bow" << std::endl;
		break;
	}
	switch (this->weapons[1])
	{
	case 0:
		std::cout << "2. Sword" << std::endl;
		break;
	case 1:
		std::cout << "2. Shield" << std::endl;
		break;
	case 2:
		std::cout << "2. Wand" << std::endl;
		break;
	case 3:
		std::cout << "2. Bow" << std::endl;
		break;
	}

	int weaponChoice = 10;
	int weapon = 10;
	while (weaponChoice != 1 && weaponChoice != 2) 
	{
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Enter your choice: ";
		std::cin >> weaponChoice;
		if (weapon == 2 && mana < 10)
		{
			std::cout << "Not enough mana to use wand, choose another weapon" << std::endl;
			weaponChoice = 10;
		}
		if (weaponChoice != 1 && weaponChoice != 2)
		{
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "Invalid choice, try again" << std::endl;
		}
	}
	weapon = this->weapons[weaponChoice - 1];
	switch (weapon)
	{
    case WeaponType::SWORD:
        weapon = WeaponType::SWORD;
        break;
    case WeaponType::SHIELD:
        weapon = WeaponType::SHIELD;
        break;
    case WeaponType::WAND:
        weapon = WeaponType::WAND;
        break;
    case WeaponType::BOW:
        weapon = WeaponType::BOW;
        break;
	}
	return weapon;
}

int Player::getSkill() const
{
	return skills[0];
}
