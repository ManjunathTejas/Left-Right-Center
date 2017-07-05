#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSONS 3
enum die {LEFT, RIGHT, CENTER, PASS};	//represents the dice object

//Globals
typedef struct Person {
	char name[50];			//Name length of the person
	int sum;			//Sum amount they have
}person;	
int numValPlayers = 0;			//Number of players
person list[15];			//array to hold all the possible people
// arguments 5 & 6 of enum is PASS as well
int pot = 0;				//Center pot value
int gameover = MAX_PERSONS;


/**
 * @int action = the type of move(Left, right, center, or pass)
 * @int pos = location in the array
 * */
static void move(int action, int pos){
int max = numValPlayers;		//max represents last element of array
int n = pos;
	switch(action){
	case LEFT:			//Current player passes money to the left
	list[n].sum = list[n].sum - 1;
	if(n == 0){
		list[max-1].sum = list[max-1].sum + 1;
		printf("%s passes left to %s and now has %d\n", list[n].name, list[max-1].name, list[n].sum);	
		break;
	}else{
		list[n-1].sum = list[n-1].sum + 1;
		printf("%s passes left to %s and now has %d\n", list[n].name, list[n-1].name,list[n].sum);	
		break;
	}
	case RIGHT:			//Current player passes money to the right
	list[n].sum = list[n].sum - 1;
	if(n == max-1){
		list[0].sum = list[0].sum + 1;
		printf("%s passes right to %s and now has %d\n",list[n].name,list[0].name, list[n].sum);
		break;
	}else{
		list[n+1].sum = list[n+1].sum + 1;
		printf("%s passes right to %s and now has %d\n",list[n].name,list[n+1].name, list[n].sum);
		break;	
	}
	case CENTER:			//Current player puts money in the pot
	list[n].sum = list[n].sum - 1;
	pot++;
	printf("%s put 1 dollar in the pot, the pot now has %d\n", list[n].name, pot);
	break;
	
	default:
	printf("%s passes\n", list[n].name);
	break;
}
}

//Main code
void main(){
	char name_input[20];		//temp variable to hold the players name


		//User inputs number of players in the game
		printf("How many players? (Enter only up to 14): ");
		scanf("%d",&numValPlayers);
		printf("%d", numValPlayers);

		// if  number = 0 or 1 default to 3 players
		if(numValPlayers == 1 || numValPlayers == 0){
			 numValPlayers = MAX_PERSONS;	
		}
		
		//Fill in the names of the players
		for(int i = 0; i < numValPlayers; i++){
			printf("Enter name: ");
			scanf("%s", name_input);
			strcpy(list[i].name, name_input);
			list[i].sum = 3;
		}
	
		int turn = 0;
		
		//Continue the loop until there is one player remaining
		while(gameover !=  1){
			gameover = numValPlayers;
			if(list[turn].sum > 0){
				int r = rand()%6;
				move(r,turn);
			}
			turn++;
			if(turn== numValPlayers-1){
			turn = 0;
			}
			for(int i = 0; i < numValPlayers; i++){
				if(list[i].sum == 0){
				gameover--;
				}			
			}
			}
			
			//Show the winner
			for(int i = 0; i < numValPlayers;i++){
				if(list[i].sum !=0){
					printf("%s wins the game with %d and the pot value of %d", list[i].name, list[i].sum, pot);
				}
			}
}
