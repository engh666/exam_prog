#include "Skill.h"
#include <iostream>


std::vector<std::string> Skill::skills;

Skill::Skill(std::string name, int level) {
	this->level = level;
	this->name = name;
}

void Skill::print() {
	std::cout << "\t\tSkill name: " << this->name << " Level: " << level << std::endl;
}

void Skill::addSkill(std::string skillName, std::vector<Student *> &students, std::vector<int> levels){
	skills.push_back(skillName);
	for (int i = 0; i < students.size(); i++) {
		students[i]->addSkill(new Skill(skillName, levels[i]));
	}

}

void Skill::setLevel(int level) {
	this->level = level;
}

int Skill::getLevel()
{
	return level;
}

std::string Skill::getName()
{
	return name;
}
