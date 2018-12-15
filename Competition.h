#pragma once
#include <string>
#include <map>
#include <vector>
#include "Student.h"
using std::vector;
using std::string;
class Competition {
public:
	 struct Date {
		int day;
		int month;
		int year;
		Date() {
			this->day = 1;
			this->month = 1;
			this->year = 1980;
		}
		Date(int day, int month, int year) {
			if(month > 12 || month < 0){
				this->day = 1;
			}
			else{
				this->day = day;
			}
			if(month > 12 || month < 0){
				this->month = 1;
			}
			else{
				this->month = month;
			}
			if(year > 2018 || year < 1980){
				this->year = 2018;
			}
			else {
				this->year = year;
			}
		}

		bool operator<(Date right) {
			if (year < right.year) {
				return true;
			}
			else if (year == right.year) {
				if (month < right.month) {
					return true;
				}
				else if (month == right.month) {
					if (day < right.day) {
						return true;
					}
					return false;
				}
				return false;
			}
			return false;
		}
	};
private:
	static vector<Competition *> archive;
	string name;
	string type;
	//static  map< string, int> typeToInt;
	vector< string> skills;
	vector<int> weights;
	Date date;
	vector<Student*> students;
	int deviation;
public:
	Competition(string name, string type, vector<string> skills, vector<int> weights,
		Date *date, int deviation);
	~Competition();
	void print();
	Date getDate();
	void compete();
	void addStudent(Student *student);
	void insertIntoResult(int index, int total, vector<std::pair<int, int>> &resultTable);
	static vector<Competition *> findBetweenDates(Date *firstDate, Date *secondDate);
	static vector<Competition *> findBySkills(vector<string> findSkills);
};
