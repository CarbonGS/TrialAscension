#include "Entity.h"

void Entity::attack(Entity& target)
{
	int trueDamage = 0;
	if (target.getDefense() <= 10){
		trueDamage = damage - 2;
		target.health -= trueDamage;
	}
	else if (target.getDefense() > 10 && target.getDefense() <= 20){
		trueDamage = damage - 4;
		target.health -= trueDamage;
	}
	else if (target.getDefense() > 20 && target.getDefense() <= 30){
		trueDamage = damage - 6;
		target.health -= trueDamage;
	}
	else if (target.getDefense() > 30 && target.getDefense() <= 40){
		trueDamage = damage - 8;
		target.health -= trueDamage;
	}
	else if (target.getDefense() > 40 && target.getDefense() <= 50){
		trueDamage = damage - 10;
		target.health -= trueDamage;
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	if (target.health < 0)
	{
		target.setHealth(0);
	}

	std::cout << name << " attacks " << target.getName() << " for " << trueDamage << " damage\n Player (";
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Health: " << target.health;
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << " Mana: " << target.mana << "/100";
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << " Defense: " << target.defense;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << ")" << "\n" << std::endl;
}



void Entity::takeDamage(int damage)
{
	// Crit chance
	int critChance = rand() % 10;
	if (critChance == 1)
	{
		damage += crit;
		health -= damage;
		std::cout << "Critical hit!" << std::endl;
	}
	else {
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		std::cout << name << " takes " << damage << " damage" << std::endl;
	}
}

void Entity::setName(std::string name)
{
	this->name = name;
}

std::string Entity::getName() const
{
	return name;
}

void Entity::setStatPoints(int statPoints)
{
	this->statPoints = statPoints;
}

int Entity::getStatPoints() const
{
	return statPoints;
}

void Entity::setHealth(int finalHealth)
{
	this->health = finalHealth;
}

int Entity::getHealth() const
{
	return health;
}

void Entity::setMana(int mana)
{
	this->mana = mana;
}

int Entity::getMana() const
{
	return mana;
}

void Entity::setDamage(int damage)
{
	this->damage = damage;
}

int Entity::getDamage() const
{
	return damage;
}

void Entity::setDefense(int defense)
{
	this->defense = defense;
}

int Entity::getDefense() const
{
	return defense;
}

void Entity::setCrit(int crit)
{
	this->crit = crit;
}

double Entity::getCrit() const
{
	return crit;
}
