#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	srand(time(NULL));	

	char guessWords[][16] = 
	{
	"god",
	 "creep",
	 "avenged",
	 "circus",
	 "ghost"
	};

// Index for random word
 
	int randomIndex = rand () % 6;
	
	int numlives = 5;
	int numcorrect = 0;
	int oldcorrect = 0;

	int lengthofword = strlen(guessWords[randomIndex]);
	int letterguessed[8] = { 0,0,0,0,0,0,0 };
	
	int quit = 0;
	
	int loopIndex = 0;
	
	char guess[16];
	char letterentered;


		printf("guessWords: %s  randomIndex: %d lengthofword:%d\n\n", guessWords[randomIndex], randomIndex, lengthofword);
 //game loop

	while (numcorrect < lengthofword)
	{

		printf("\n\nNew turn...\nhangman word:");
		for(loopIndex = 0; loopIndex < lengthofword; loopIndex++)
                {
                        if(letterguessed[loopIndex] == 1)
                        {
                        printf("%c", guessWords[randomIndex][loopIndex]);
                        } else {
				printf("-");
				}
	
			}
			printf("\n");


                        if(letterentered == guessWords[randomIndex][loopIndex])
                        {
                                letterguessed[loopIndex] = 1;
                                numcorrect++;
                        }


		printf("Number correct so far:%d ", numcorrect);
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		
		if(strncmp(guess, "quit", 4) == 0) 
		{
			quit = 1;
			break;
		}

		letterentered = guess[0];
		
		printf("letterentered:%c\n", letterentered);
	
		oldcorrect = numcorrect;
			


		for(loopIndex = 0; loopIndex < lengthofword; loopIndex++)
		{
			if(letterguessed[loopIndex] == 1) 
			{
			continue;
			}

			if(letterentered == guessWords[randomIndex][loopIndex]) 
			{
				letterguessed[loopIndex] = 1;
				numcorrect++;
			}

		}

	if(oldcorrect == numcorrect);
	{
		numlives--;
		printf("Sorry wrong guess\n");
		if (numlives == 0)
		{
		 	break;			
		}	

	}
 

	}
//while loop

	if(quit == 1) 
	{
		printf("\nThe user quit early\n");
	} else if (numlives == 0) {printf("\nSorry you lose, the word was: %s\n", guessWords[randomIndex]); 
		} else { printf("You win\n");}

return 0;
}
