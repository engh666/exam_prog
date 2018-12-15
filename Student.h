#pragma once
#include "Skill.h"
#include <string>
#include <vector>
class Skill;
class Student {
private:
	std::string name;
	std::string surname;
	std::vector<Skill*> skills;
	int fear;		// coef of fear before competition
	int experience; // coef of exp
public:
	Student(std::string name, std::string surname, std::vector<int> skills, int fear);
	~Student();
	void print();
	void addSkill(Skill *newSkill);
	int getLevelOfSkill(std::string skillName);
	void changeLevelOfSkill(std::string skillName, int upgrade);
	int getFear();
	int getExp();
	void setFear(int newFear);
	void setExp(int newExp);
};
