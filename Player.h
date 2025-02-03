#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>

enum WeaponType
{
	SWORD,	// 0
	SHIELD, // 1
	WAND,	// 2
	BOW,	// 3
};

enum Skills
{
	offensive, // 0
	defensive, // 1
};

class Player : public Entity
{
private:
	int lives;
	std::vector<int> weapons;
	int skills[1];

public:
	Player(int lv = 3, std::vector<int> weapons = { 0,0 }, int skill = 0) : Entity("Player"), lives(lv), weapons{ weapons }, skills{ skill } {}

	std::vector<int> startingWeapon();
	int startingSkill();
	void attack(int weapon, Entity& target);

	int chooseAttackWeapon() const;
	int getSkill() const;
};

#endif // !PLAYER_H

