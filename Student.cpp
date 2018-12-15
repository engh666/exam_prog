#include "Student.h"
#include "Skill.h"
#include <iostream>

Student::Student(std::string name, std::string surname, std::vector<int> skills, int fear) {
	this->name = name;
	this->surname = surname;
	this->fear = fear;
	this->experience = 0;
	for (int i = 0; i < skills.size(); i++) {
		this->skills.push_back(new Skill(Skill::skills[i], skills[i]));
	}
}

Student::~Student() {
	for (int i = 0; i < skills.size(); i++) {
		delete skills[i];
	}
}

void Student::print() {
	std::cout << "\tName: " << name << " Surname: " << surname << std::endl;
	for (size_t i = 0; i < skills.size(); i++) {
		skills[i]->print();
	}
}

void Student::addSkill(Skill *newSkill){
	skills.push_back(newSkill);
}

int Student::getLevelOfSkill(std::string skillName)
{
	int skillsSize = skills.size();
	for (int i = 0; i < skillsSize; i++) {
		if (!skillName.compare(skills[i]->getName())) {
			return skills[i]->getLevel();
		}
	}
	return 0;
}

void Student::changeLevelOfSkill(std::string skillName, int upgrade){
	int skillsSize = skills.size();
	for (int i = 0; i < skillsSize; i++) {
		if (!skillName.compare(skills[i]->getName())) {
			int level = skills[i]->getLevel();
			skills[i]->setLevel(level + upgrade);
		}
	}
}

int Student::getFear(){
	return fear;
}

int Student::getExp(){
	return experience;
}

void Student::setFear(int newFear){
	fear = newFear;
	if (fear < 0) {
		fear = 0;
	}
}

void Student::setExp(int newExp){
	experience = newExp;
}
