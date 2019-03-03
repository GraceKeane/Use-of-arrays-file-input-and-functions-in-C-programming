//Grace Keane
//program that lets the user enter the total votes for four candidates for each state in the election
//into an array of int. Program then calculates the each state winner and the new mayor of city.
/// STEPS
//  1| To display vote data in a table format
//  2| Display the winner of the vote in each state. 
//  3| Call a separate function that displays new Mayor of the City, based on the electoral college system.
//  4| Output the table of vote data to a file called votes.txt. 

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/// Function to calculate the mayor given an array of all the statewinners
//// state[0] ===> hold the candidate number of the winner of state 0
void calculateMayor(int state[]);

void main()
{
	//variables
	FILE* outfile;
	int votes[5][4];  //// Hold the votes for each of the 4 candidates in the 5 states
	int statewinner[5]; /// Hold the winner of each state
	int i, j;
	int statewinnercandidate; ///Used to hold the statewinner when calculating the winner of a state
	int statewinnervotes; ///Used to hold the statewinner's votes when calculating the winner of a state
	char candidate[4][1] = { 'A','B','C','D' };

	/// Open file to output results
	outfile = fopen("votes.txt", "a");

	/// Loop through the array getting the votes for each candidate in each state
	for (i = 0; i < 5; i++) //i = rows
	{
		printf("Please Enter the Votes for each candidate in state %d\n", i + 1);
		for (j = 0; j < 4; j++) //j = columns
		{
			//// Populate the vote array
			printf("Please enter the votes for candidate %c\n", candidate[j][0]);
			scanf("%d", &votes[i][j]);
		}
	}

	

	/// Loop through the array printing the votes for each candidate in each state in the table format specified
	printf("State \t\tCandidate A  \tCandidate B \tCandidate C \tCandidate D\n"); //format
	for (i = 0; i < 5; i++) // i = rows
	{
		printf("State %d \t", i + 1);  //plus state + 1
		for (j = 0; j < 4; j++) // j = columns
		{
			printf("%d\t\t", votes[i][j]);
		}
		//new line
		printf("\n");
	}



	/// Loop through the array printing to file the votes 
	/// for each candidate in each state in the table format specified
	if (outfile != NULL)
	{
		fprintf(outfile, "State \t\tCandidate A  \tCandidate B \tCandidate C \tCandidate D\n");

		for (i = 0; i < 5; i++) //i = rows
		{
			fprintf(outfile, "State %d \t", i + 1);
			for (j = 0; j < 4; j++) //j = columns
			{
				//// Populate the vote array
				fprintf(outfile, "%d\t", votes[i][j]);
			}
			//new line - formating the file table
			fprintf(outfile, "\n");
		}
	}


	/// Calculating the winner of each state and storing the winner in an array
	/// Initally the winner is set to the first element of the array and then the
	/// comparison starts from index 1.
	/// The number of votes and candidate need to be tracked
	for (i = 0; i < 5; i++)
	{
		statewinnercandidate = 0;
		statewinnervotes = votes[i][0];

		for (j = 1; j < 4; j++)
		{
			/// If this element is greater than present winner
			/// then update the winner of that state
			if (votes[i][j] > statewinnervotes)
			{
				statewinnercandidate = j;
				statewinnervotes = votes[i][j];
			}
		}

		/// Store the winner of this state in the statewinner array
		statewinner[i] = statewinnercandidate;

		printf("The winner of state %d is candidate %c \n", i, candidate[statewinnercandidate][0]);

	}

	/// Sent the statewinner array to the calculate Mayor function
	calculateMayor(statewinner);

	//close the file if it is open
	if (outfile != NULL)
		fclose(outfile);
	getch();

}


// function to calculate mayor of city
void calculateMayor(int state[]) 
{
	//Declare the function variables
	int candidate_count[4];  /// Array to count the number of states won by each candidate
	int i;

	// winner and winner_numstates are used to track the candidate with the most states
	int winner;
	int winner_numstates;

	char candidate[4][1] = { 'A','B','C','D' };

	//Initialise the candidate counter array
	for (i = 0; i < 4; i++)
	{
		candidate_count[i] = 0;
	}

	// Calculate the number of states won by each candidate
	for (i = 0; i < 5; i++)
	{
		/// If the state[i] is 1 then add one the element 1 of the candidate_count 
		/// If the state[i] is 2 then add one the element 2 of the candidate_count
		candidate_count[state[i]]++;
	}

	//Calculate the candidate with the most states
	winner = 0;
	winner_numstates = candidate_count[0];

	for (i = 1; i < 4; i++)
	{
		/// If this candidate is greater than present max
		/// then update the winner
		if (candidate_count[i] > winner_numstates)
		{
			winner = i;
			winner_numstates = candidate_count[i];
		}
	}

	printf("The new mayor is candidate %c", candidate[winner][0]);
}
