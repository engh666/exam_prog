#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Olimpiads/Competition.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Skill::skills.push_back("math");
			Skill::skills.push_back("phy");
			Skill::skills.push_back("info");
			Skill::skills.push_back("speaking");

			std::vector<int> skills = { 3, 5, 2, 8 };
			Student *s1 = new Student("John", "Snow", skills, 4);
			skills = { 1, 1, 7, 4 };
			Student *s2 = new Student("Andrew", "Hack", skills, 2);
			skills = { 4, 4, 2, 3 };
			Student *s3 = new Student("Anna", "Fearless", skills, 20);
			skills = { 9, 1, 2, 7 };
			Student *s4 = new Student("Walter", "White", skills, 2);
			skills = { 7, 0, 0, 16 };
			Student *s5 = new Student("Sokrates", "Greece", skills, 5);
			skills = { 9, 2, 15, 13 };
			Student *s6 = new Student("Elon", "Mask", skills, 1);

			vector<string> compskills = { "math", "phy", "speaking" };
			vector<int> weights = { 1, 4, 2 };

			Competition *phyOlimpic = new Competition("IPO", "phy", compskills, weights, new Competition::Date(21, 12, 2017), 2);
			phyOlimpic->addStudent(s1);
			phyOlimpic->addStudent(s2);
			phyOlimpic->addStudent(s3);
			phyOlimpic->addStudent(s5);
			phyOlimpic->addStudent(s6);


			compskills = { "math", "speaking" };
			weights = { 3, 1 };
			Competition *mathOlimpic = new Competition("IMO", "math", compskills, weights, new Competition::Date(14, 4, 2018), 3);
			mathOlimpic->addStudent(s2);
			mathOlimpic->addStudent(s4);
			mathOlimpic->addStudent(s5);

			compskills = { "math", "info", "speaking" };
			weights = { 1, 4, 2 };
			Competition *infoOlimpic = new Competition("IIO", "info", compskills, weights, new Competition::Date(21, 12, 2018), 1);
			infoOlimpic->addStudent(s1);
			infoOlimpic->addStudent(s2);
			infoOlimpic->addStudent(s3);
			infoOlimpic->addStudent(s4);
			infoOlimpic->addStudent(s5);

			phyOlimpic->compete();
			mathOlimpic->compete();
			infoOlimpic->compete();
			vector<Competition *> btwComp = Competition::findBetweenDates(new Competition::Date(1, 1, 2018), new Competition::Date(20, 12, 2018));
			int sizebtw = btwComp.size();
			Assert::AreEqual(sizebtw, 1);
			compskills = { "math", "speaking" };

			vector<Competition *> skillComp = Competition::findBySkills(compskills);
		
			int sizesk = skillComp.size();

			Assert::AreEqual(sizesk, 3);
		}
		

	};
}