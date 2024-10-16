// Bible Project #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Suppose everyone will live up to 72 years(the average age of a human).Half are male, and the other half are female; everyone will marry, and a couple will have one new baby at 30. 
How many years does it take 13 disciples to make every human in the world a disciple of Jesus ?
It has to be until 18 years old to start training disciples, and a disciple can keep training disciples before he dies.The other conditions are the same in Bible - Related Coding Assignment 1.
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// usually dont like to use global variables, but with its makes keeping track of all the constraints and even changing them so much easier.

int CurrentPopulation = 1000000;
int discipleCount = 13;
int maxAge = 72;
int trainingTime = 3;
int DiscipleTrainingLimit = 2;
int marraigeAge = 30;
int babyMakeAge = 30;
int trainingAge = 18;
int yearCounter = 0;

struct Population
{
	// population is compromised of smaller subsections that change as we cycle year after year
	int totalHumans;
	int trainedDisciples;
	int tooYoung;
	int newborns;

	// constuctor for new Objects
	Population(int humans, int trained, int underaged, int newbs)
	{
		totalHumans = humans;
		trainedDisciples = trained;
		tooYoung = underaged;
		newborns = newbs;
	}

};

// function prototype
int howManyYears(int startingDiscipleCount, int currentPop);

int main()
{
	// running the function
	int answer = howManyYears(discipleCount, CurrentPopulation);

	cout << "The total years needed to covert a population of " << CurrentPopulation << " people to disciples of the Lord is " << answer << " years...";

	cout << endl;

	return 0;
}

// function body
int howManyYears(int startingDiscipleCount, int currentPop)
{
	int years = 0;

	Population pops(CurrentPopulation, discipleCount, 0, 0);

	// loop to get through CurrentPopulation until trained
	while (pops.trainedDisciples < CurrentPopulation)
	{
		// see where we are at in terms of years to determine if we gotta mess with newborns
		if (years % 18 == 0 && years >= babyMakeAge)
		{
			pops.newborns = pops.trainedDisciples / 2;
		}

		// every three years we get more trained disciples
		if (years % trainingTime == 0)
		{
			int newDisciples = pops.trainedDisciples * DiscipleTrainingLimit;
			
			// add them to the trained disciples subpop
			pops.trainedDisciples += newDisciples;

			// set upper limit
			if (pops.trainedDisciples > CurrentPopulation)
			{
				pops.trainedDisciples = currentPop;
			}
		}

		// now we deal with the newborn subpop
		if (years >= trainingAge)
		{
			pops.tooYoung += pops.newborns;
		}

		if (years >= trainingAge)
		{
			int ageGroups = pops.tooYoung;
			pops.trainedDisciples += ageGroups;

			// we gotta reset after shifting ages up 
			pops.tooYoung = 0;

		}

		// increment years
		years++;
	}

	return years;
}