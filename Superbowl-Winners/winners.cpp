#include <iostream>
#include <fstream>
#include <string>
#include "OHProjectTwo.h"
using namespace std;

const int totalyears = 43;

struct WinningTeamInfo
{
	int year[totalyears];
	string teamName;
	int count;
};

int printOutput(WinningTeamInfo wti);

WinningTeamInfo ReadTheFileAndConstructStructure(string inputTeamName);
int main()
{
	string inputTeamName;
	string winningYears;
	//Background information
	cout << "Super Bowl Winners" << endl;
	cout << "This program will tell you how many times and in which years a" << endl;
	cout << "football team won the Super Bowl. Enter a name of 'quit' to exit." << endl;

	// Get user input ( Team Name )
	cout << "Enter the team name: ";
	cin >> inputTeamName;

    // Check Value;
	while (inputTeamName != "quit" || inputTeamName != "q" || inputTeamName != "Quit" || inputTeamName != "Q")
	{
		// Read the file and construct the winning team information 
		WinningTeamInfo Wteam = ReadTheFileAndConstructStructure(inputTeamName);
		// print the outout
		printOutput(Wteam);
		// Read input again
		cout << "Enter the football team's name:";
		cin >> inputTeamName;
		
		if (inputTeamName == "quit" || inputTeamName == "q" || inputTeamName == "Quit" || inputTeamName == "Quit")
		{
			cout << "Thank you." << endl;
			break;
		}
	} // end of while-loop
}

// constructs the string and prints 
int printOutput(WinningTeamInfo Wteam)
{
	string winningYears;
	for (int i = 0; i < Wteam.count; i++)
	{
		if (i < Wteam.count - 1)
		{
			winningYears = winningYears + to_string(Wteam.year[i]) + ", ";
		}
		
		else
		{
			winningYears = winningYears + "and " + to_string(Wteam.year[i]);
		}
	
	}// end of for loop

	if (Wteam.count == 0)
	{
		cout << "The " << Wteam.teamName << " have yet to win the Super Bowl." << endl;
	}
	else if (Wteam.count == 1)
	{
		cout << "The " << Wteam.teamName << " won the Super Bowl once in " << winningYears << "." << endl;
	}
	else
	{
		cout << "The " << Wteam.teamName << " won the Super Bowl " << Wteam.count << " times in " << winningYears << "." << endl;
	}
	return 0;
}

//reads the team name from the file and constructs the structure that contains the teams' winning information
WinningTeamInfo ReadTheFileAndConstructStructure(string inputTeamName)
{
	
	int year = 1967;
	int winningYear[43];
	int WinningCounter = 0;
	WinningTeamInfo winningTeam;
	
	// filestream variable file 
	fstream file;
	string team,  filename;

	// filename of the file 
	filename = "SuperBowlWinners.txt";

	// opening file 
	file.open(filename);//.c_str()

	// extracting words from the file 
	while (file >> team)
	{
		if (team == inputTeamName)
		{
			// increase the counter
			winningTeam.year[WinningCounter] = year;
			WinningCounter++;
		}
		year++; // increment the year
	}

	// assigns the input team name and the number of times won to the members of the structure
	winningTeam.teamName = inputTeamName;
	winningTeam.count = WinningCounter;

	return winningTeam;
}
