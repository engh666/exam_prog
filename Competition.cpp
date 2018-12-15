#include "Competition.h"
#include <iostream>
#include <algorithm>
#include <ctime>


vector<Competition *> Competition::archive;

Competition::Competition(string name, string type,
	vector<string> skills, vector<int> weights,
	Date *date, int deviation) {
	this->name = name;
	this->type = type;
	this->skills = skills;
	this->date = *date;
	this->weights = weights;
	this->deviation = deviation;
}

Competition::~Competition() {
	for (int i = 0; i < students.size(); i++) {
		delete students[i];
	}
}

void Competition::print(){
	std::cout << "Name: " << name << "Type: " << type 
		<< "\nDate: " << date.day << "/" << date.month << "/" << date.year << std::endl;

	for (size_t i = 0; i < students.size(); i++) {
		students[i]->print();
	}
}

Competition::Date Competition::getDate()
{
	return date;
}

void Competition::compete() {
	int size = students.size();
	vector<std::pair<int, int >> resultTable;
	//vector<int> resultIndexes;
	// clear poitnts
	for (int i = 0; i < size; i++) {
		int totalPoints = 0;
		int skilsSize = skills.size();
		for (size_t j = 0; j < skills.size(); j++) {
			totalPoints += students[i]->getLevelOfSkill(skills[j]) * weights[j];
		}
		totalPoints += students[i]->getExp();
		totalPoints -= students[i]->getFear();
		insertIntoResult(i, totalPoints, resultTable);
	}
	srand(time(0));
	// random intervention
	// if deviaiton is minor and fear of first student less than fear of second swap tham with 50% prob
	for (int i = 0; i < size - 1; i++) {
		if ((resultTable[i].first - resultTable[i + 1].first) < deviation &&
			students[resultTable[i].second]->getFear() < students[resultTable[i + 1].second]->getFear() &&
			rand() % 2) {
			iter_swap(resultTable.begin() + i, resultTable.begin() + i + 1);
			//iter_swap(resultIndexes.begin() + i, resultIndexes.begin() + i + 1);
		}
	}

	vector<Student*> newStudents(size);
	for (int i = 0; i < size; i++) {
		newStudents[i] = students[resultTable[i].second];
	}
	//randomly change fear, exp and skills of students 
	for (int i = 0; i < size; i++) {
		students[i]->setFear(students[i]->getFear() - rand() % 10);
		int diff = resultTable[0].first - resultTable[i].first;
		students[i]->setExp(students[i]->getExp() + (rand() % 100) / (diff + 1));
		for (size_t j = 0; j < skills.size(); j++) {
			students[i]->changeLevelOfSkill(skills[j], rand() % 3);
		}
	}
	archive.push_back(this); // add to archive
}

void Competition::addStudent(Student *student){
	students.push_back(student);
}

void Competition::insertIntoResult(int index, int total, vector<std::pair<int, int>> &resultTable) {
	auto it = upper_bound(resultTable.begin(), resultTable.end(), std::make_pair(total, index),
		[](std::pair<int, int> first, std::pair<int, int> second)->bool {return first.first > second.first; });
	resultTable.insert(it, std::make_pair(total, index));
	
}

vector<Competition*> Competition::findBetweenDates(Date *firstDate, Date *secondDate)
{
	vector<Competition*> btwCompetition;
	int size = archive.size(); // assume that archive sorted by date
	for (int i = 0; i < size; i++) {
		if (*firstDate < archive[i]->getDate()) {
			if ( *secondDate < archive[i]->getDate()) {
				break;
			}
			btwCompetition.push_back(archive[i]);
		}
	}
	return btwCompetition;
}

vector<Competition*> Competition::findBySkills(vector<string> findSkills)
{
	vector<Competition*> skillCompetition;
	int size = archive.size();
	int isFound = 0;
	for (int i = 0; i < size; i++) {
		isFound = 0;
		int findSkillsSize = findSkills.size();
		for (int j = 0; j < findSkillsSize; j++) {
			for (size_t k = 0; k < archive[i]->skills.size(); k++) {
				if (!findSkills[j].compare(archive[i]->skills[k])) {
					isFound++;
					break;
				}
			}
		}
		if (isFound == findSkillsSize) {
			skillCompetition.push_back(archive[i]);
		}
	}
	return skillCompetition;
}


