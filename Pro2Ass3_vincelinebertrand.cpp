//file name: Pro2Ass3_vincelinebertrand.cpp
// Author: Vinceline Bertrand
// email address: bertrandvinceline@gmail.com
// assignment number: 3
// date: 07/03/2023
// description: a program that calculates and displays grades for a student
// and calculates grades with bonus added (if any)

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

// check if znumber is correct length and if user omitted the 'z'
bool isValidZNumber(string znum_str)
{
	if (znum_str.length() != 8)
		return false;

	for (char c : znum_str) {
		if (!isdigit(c))
			return false;
	}

	return true;
}
// parent class
class COP3014
{
public:
	// using constructor to intialize variables
	COP3014() {
		fname = "";
		lname = "";
		znum = 0;
		quiz1 = 0.0;
		quiz2 = 0.0;
		quiz3 = 0.0;
		midterm = 0.0;
		final = 0.0;
		totalgrade = 0.0;
		lettergrade = '\0';
}
COP3014(string f_name, string l_name, int z_num, float quiz_1, float quiz_2, float quiz_3, float mid_term, float fi_nal, float to_talgrade, char let_tergrade)
{
	fname = f_name;
	lname = l_name;
	znum = z_num;
	quiz1 = quiz_1;
	quiz2 = quiz_2;
	quiz3 = quiz_3;
	midterm = mid_term;
	final = fi_nal;
	totalgrade = to_talgrade;
	lettergrade = let_tergrade;

}
void userinput()
{
	// temp string variable to store Z-number and validate with isValidZNumber function
	string znum_str;

	// prompting user input and if invalid, program exits
	cout << "please enter first name" << endl;
	cin >> fname;
	if (cin.fail()) {
		cout << "Sorry, you have entered an invalid name, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter last name" << endl;
	cin >> lname;
	if (cin.fail()) {
		cout << "Sorry, you have entered an invalid name, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter Z number omitting the 'Z' (8 digits)" << endl;
	cin >> znum_str;
	//calling function to validate user input
	if (isValidZNumber(znum_str)) {
		znum = stoi(znum_str);
	}
	else {
		cout << "Sorry, you have entered an invalid Znumber, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter quiz 1 grade" << endl;
	cin >> quiz1;
	if (cin.fail() || quiz1 > 20 || quiz1 < 0) {
		cout << "Sorry, you have entered an invalid grade, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter quiz 2 grade" << endl;
	cin >> quiz2;
	if (cin.fail() || quiz2 > 20 || quiz2 < 0) {
		cout << "Sorry, you have entered an invalid grade, exiting program..." << endl;
		exit(1);
	}
	cout << "please enter quiz 3 grade" << endl;
	cin >> quiz3;
	if (cin.fail() || quiz3 > 20 || quiz3 < 0) {
		cout << "Sorry, you have entered an invalid grade, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter midterm grade" << endl;
	cin >> midterm;
	if (cin.fail() || midterm > 100 || midterm < 0) {
		cout << "Sorry, you have entered an invalid grade, exiting program..." << endl;
		exit(1);
	}

	cout << "please enter final grade" << endl;
	cin >> final;
	if (cin.fail() || final > 100 || final < 0) {
		cout << "Sorry, you have entered an invalid grade, exiting program..." << endl;
		exit(1);
	}
}
//total_grade function to compute total grade and store it in member variable
float total_grade()  
{
	totalgrade = ((quiz1 + quiz2 + quiz3) / 3.0f) + (midterm * .30f) + (final * .50f);
	return totalgrade;
}
//using total_grade function to give student a letter grade
char letter_grade()
{
	if (total_grade() > 90)
		lettergrade = 'A';
	else if (total_grade() < 90 && total_grade() >= 80)
		lettergrade = 'B';
	else if (total_grade() < 80 && total_grade() >= 70)
		lettergrade = 'C';
	else if (total_grade() < 70 && total_grade() >= 60)
		lettergrade = 'D';
	else if (total_grade() < 60 && total_grade() >= 0)
		lettergrade = 'F';
	if (final == 0 || midterm == 0)
		lettergrade = 'F';
	return lettergrade;
}
// output function to display all grades
// if student has a bonus, it's automatically implemented in total grade and letter grade
void outputfunc()
{
	//fixed decimal places
	cout << fixed << setprecision(2);
	cout << fname << " " << lname << " - Z" << znum << endl;
	cout << "        Quiz 1: " << quiz1 << endl;
	cout << "        Quiz 2: " << quiz2 << endl;
	cout << "        Quiz 3: " << quiz3 << endl;
	cout << "        Midterm: " << midterm << endl;
	cout << "        Final: " << final << endl;
	cout << "        Total grade: " << totalgrade << endl;
	cout << "        Final grade: " << lettergrade << endl;
}
// setter functions for member variables to update values as needed
void set_fname( string fname)
{
	this->fname = fname;
}
void set_lname( string lname)
{
	this->lname = lname;
}
void set_znum(int znum)
{
	this->znum = znum;
}
void set_quiz1(float quiz1)
{
	this->quiz1 = quiz1;
}
void set_quiz2(float quiz2)
{
	this->quiz2 = quiz2;
}
void set_quiz3(float quiz3)
{
	this->quiz3 = quiz3;
}
void set_midterm(float midterm)
{
	this->midterm = midterm;
}
void set_final(float final)
{
	this->final = final;
}
void set_totalgrade(float totalgrade)
{
	this->totalgrade = totalgrade;
}
void set_lettergrade(char lettergrade)
{
	this->lettergrade = lettergrade;
}
// getter functions to be able to access private member variable values
string get_fname()
{
	return fname;
}
string get_lname()
{
	return lname;
}
int get_znum()
{
	return znum;
}
float get_quiz1()
{
	return quiz1;
}
float get_quiz2()
{
	return quiz2;
}
float get_quiz3()
{
	return quiz3;
}
float get_midterm()
{
	return midterm;
}
float get_final()
{
	return final;
}
float get_totalgrade()
	{
		return totalgrade;
	}
char get_lettergrade()
	{
		return lettergrade;
	}

//member variables
private:
	string fname;
	string lname;
	int znum;
	float quiz1;
	float quiz2;
	float quiz3;
	float midterm;
	float final;
	float totalgrade;
	char lettergrade;
};

class summer23 : public COP3014 {
public:
	// constructor for summer23 class
	// initializing 'bonus'
	summer23() : COP3014() {
		bonus = 0.0;
	}
void userinput2() {
		// Prompting user to input bonus
		// Bonus can't be negative
		cout << "please enter total bonus accumulated (in %)" << endl;
		cin >> bonus;
		if (cin.fail() || bonus < 0) {
			cout << "sorry invalid input, exiting program..." << endl;
			exit(1);
		}
	}
//redefining total grade function for summer class
float total_grade() {
	float base_total_grade = COP3014::total_grade(); 
	// Apply the bonus
	return base_total_grade + (base_total_grade * bonus / 100);
}
char letter_grade()  {
	return COP3014::letter_grade(); 
}

void output2()
{
	// making grades have 2 decimal places
	cout << fixed << setprecision(2);
	cout << "        bonus: " << bonus << "%" << endl;
	cout << "        grade with bonus: " << total_grade() << endl;
	cout << "        new letter grade: " << letter_grade() << endl;
	
}
void set_bonus(float bonus)
{
	this->bonus = bonus;
}
float get_bonus()
{
	return bonus;
}
private:
	float bonus;
};
int main()
{
	// sample student 1:
	summer23 student1;
	student1.set_fname("Frank");
	student1.set_lname("Fabulous");
	student1.set_znum(12345678);
	student1.set_quiz1(20);
	student1.set_quiz2(20);
	student1.set_quiz3(10);
	student1.set_midterm(0);
	student1.set_final(90);
	student1.set_totalgrade(61.67);
	student1.set_bonus(2);

	student1.letter_grade();
	student1.outputfunc();
	student1.total_grade();
	student1.output2();
	cout << "---------------------------------------------------" << endl;

	// sample student2:
	summer23 student2;
	student2.set_fname("Gina");
	student2.set_lname("Genius");
	student2.set_znum(98765432);
	student2.set_quiz1(20);
	student2.set_quiz2(20);
	student2.set_quiz3(20);
	student2.set_midterm(98);
	student2.set_final(95);
	student2.set_totalgrade(96.9);
	student2.set_bonus(3); 

	student2.letter_grade();
	student2.outputfunc();
	student2.total_grade();
	student2.output2();
	cout << "---------------------------------------------------" << endl;
	cout << "---------------------------------------------------" << endl;

	char testgrade;
	char choice;
	cout << "please input y or Y to display a student's grades." << endl;
	cin >> testgrade;
	if (cin.fail() || testgrade != 'y' && testgrade != 'Y')
	{
		exit(1);
	}
	// loop to give user option to try as many test cases as desired
	do {
		summer23 teststudent;
		// user is asked to enter all grades and bonus first
		teststudent.userinput();
		teststudent.userinput2();
		teststudent.letter_grade();
		// displaying output function from base class and summer23
		teststudent.outputfunc();
		teststudent.total_grade();
		teststudent.output2();
		cout << "---------------------------------------------------" << endl;

		cout << "Do you want to continue (Y/N)?  " << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n') {
			break; // Exit the loop if user chooses to exit
		}
		cout << "---------------------------------------------------" << endl;
	} while (testgrade == 'y' || testgrade == 'Y');

	return 0;
}