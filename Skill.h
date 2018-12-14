#pragma once
#include "Student.h"
#include <string>
#include <vector>
#include <map>
class Student;

class Skill {
private:
	std::string name;
	int level;
public: 
	static std::vector<std::string> skills;
	Skill(std::string name, int level);
	void print();
	void addSkill(std::string skillName, std::vector<Student *> &students, std::vector<int> levels);
	void setLevel(int level);
	int getLevel();
	std::string getName();
};