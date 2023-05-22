#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NAME 15
#define MAX_SURNAME 15
#define MAX_PLAYERS 20

enum category
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    TREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    SMALL_STRAIGHT,
    LARGE_STRAIGHT,
    YATZHEE,
    LUCY
};

typedef struct
{
    int score[14];
    char name[MAX_NAME];
    char surname[MAX_SURNAME];
    int total_score;
} gamer;


void play_yatzhee	 (int num_players, gamer player[]);
int number_calculator(int num, int dice[], int n, gamer player[]);
int tree_of_a_kind   (int num, int dice[], int n, gamer player[]);
int four_of_a_kind	 (int num, int dice[], int n, gamer player[]);
int full_house       (int num, int dice[], int n, gamer player[]);
int small_straight   (int num, int dice[], int n, gamer player[]);
int large_straight   (int num, int dice[], int n, gamer player[]);
int yatzhee		     (int num, int dice[], int n, gamer player[]);
int lucy	 	     (int num, int dice[], int n, gamer player[]);
int pass		     (int num, int dice[], int n, gamer player[]);
int player_entry();
int roll_dice();
int player_entry(gamer *player);


int main(void) {
    srand(time(NULL));
    int player_num = 0;
    gamer player[MAX_PLAYERS];
    player_num = player_entry(player);
    play_yatzhee(player_num, player);
    return 0;
}
int roll_dice()
{
    return rand() % 6 + 1;
}
void play_yatzhee(int num_players, gamer player[])
{
    int (*calculator[])(int, int[], int, gamer[]) = {number_calculator, tree_of_a_kind, four_of_a_kind, full_house, small_straight, large_straight, yatzhee, lucy,pass};
    int i = 0, round = 0, j = 0;
    int choice, check;
    // Initialize player scores
    for (i = 0; i < num_players; i++)
    {
        player[i].total_score = 0;
        for (j = 0; j < 13; j++)
        {
            player[i].score[j] = 0;
        }
    }
    // Start rounds
    for (round = 0; round < 13; round++)
    {
        printf("Round %d started\n", round + 1);
        for (j = 0; j < num_players; j++)
        {
        	// Roll dice
            printf("%s %s's turn \n", player[j].name, player[j].surname);
            int dice[5] = {0}, dice_face[6] = {0};
            for (i = 0; i < 5; i++)
            {
                dice[i] = roll_dice();
            }
            printf("Roll 1:\n%d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
            printf("Which dice do you want to re-roll. Enter 1-5 (separated by spaces)\nif you dont want to roll enter '0' (separated by spaces) ");

            int choice1, choice2, choice3;
            scanf("%d%d%d", &choice1, &choice2, &choice3);
            // Re-roll chosen dice
            for (i = 0; i < 5; i++)
            {
                if (i == choice1 - 1 || i == choice2 - 1 || i == choice3 - 1)
                {
                    dice[i] = roll_dice();
                }
            }
            printf("Roll 2: %d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
            printf("Which dice do you want to re-roll Enter 1-5 (separated by spaces) ");
            scanf("%d%d%d", &choice1, &choice2, &choice3);
            for (i = 0; i < 5; i++)
            {
                if (i == choice1 - 1 || i == choice2 - 1 || i == choice3 - 1)
                {
                    dice[i] = roll_dice();
                }
            }
            printf("Roll 3: %d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);

            for (i = 0; i < 5; i++)
            {
                if (dice[i] == 1)
                {
                    dice_face[0]++;
                }
                else if (dice[i] == 2)
                {
                    dice_face[1]++;
                }
                else if (dice[i] == 3)
                {
                    dice_face[2]++;
                }
                else if (dice[i] == 4)
                {
                    dice_face[3]++;
                }
                else if (dice[i] == 5)
                {
                    dice_face[4]++;
                }
                else if (dice[i] == 6)
                {
                    dice_face[5]++;
                }
            }
			do
			{
			    // Display the last roll of the dice to the player
			    printf("The last roll  %d %d %d %d %d\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
			    
			    // Print the menu of available categories and their corresponding scores
			    printf("Choose a category\n");
			    printf("1) Ones     %3d   07) 3 of a kind        %3d\n", player[j].score[ONES], player[j].score[TREE_OF_A_KIND]);
			    printf("2) Twos     %3d   08) 4 of a kind        %3d\n", player[j].score[TWOS], player[j].score[FOUR_OF_A_KIND]);
			    printf("3) Threes   %3d   09) Full house         %3d\n", player[j].score[THREES], player[j].score[FULL_HOUSE]);
			    printf("4) Fours    %3d   10) Small straight     %3d\n", player[j].score[FOURS], player[j].score[SMALL_STRAIGHT]);
			    printf("5) Fives    %3d   11) Large straight     %3d\n", player[j].score[FIVES], player[j].score[LARGE_STRAIGHT]);
			    printf("6) Sixes    %3d   12) Yatzhee            %3d\n", player[j].score[SIXES], player[j].score[YATZHEE]);
			    printf("Total =>    %3d   13) Lucy               %3d\n", player[j].total_score, player[j].score[LUCY]);
			    printf("  14) Pass :,) \n ");
			    printf("Enter a number==>\n ");
			
			    // Read the player's choice of category
			    scanf("%d", &choice);
			    printf("choice == %d\n ", choice);
			
			    // Call the appropriate scoring calculator function based on the chosen category
			    check = calculator[(choice - 1 < 6) ? 0 : choice - 6](choice, dice_face, j, player);
			
			    if (check != -1)
			    {
			        // Update the player's score for the chosen category
			        player[j].score[choice - 1] = check;
			    }
			    else
			    {
			        // Display an error message for an invalid value
			        printf("Error Invalid value!\n");
			    }
			} while (check == -1 || player[j].score[choice - 1] == 0 && choice != 14);
			
			// Update the player's total score for the round
			player[j].total_score += ((choice == 14) ? player[j].score[choice - 1] : 0);
			
			// Print the player's score for the chosen category and their total score
			printf("%s %s scored %d points this round total score %d\n", player[j].name, player[j].surname, player[j].score[choice - 1], player[j].total_score);
		}
    }
	int winner = 0, total = 0;
	
	// Loop through each player to calculate their total score
	for (i = 1; i < num_players; i++)
	{
	    int total = 0;
	
	    // Calculate the sum of scores for each player's individual categories
	    for (j = 0; j < 6; j++)
	    {
	        total += player[i].score[j];
	    }
	
	    // Add a bonus of 35 points if the total score is greater than or equal to 63
	    player[i].total_score += (total < 63 ? 0 : 35);
	
	    // Check if the current player's total score is higher than the current winner
	    if (player[i].total_score > player[winner].total_score)
	    {
	        // Update the winner index
	        winner = i;
	    }
	}

// Print the name, surname, and total score of the winner
printf("%s %s wins with a score of %d\n", player[winner].name, player[winner].surname, player[winner].total_score);
}


int number_calculator(int choice, int dice_face[], int n, gamer player[])
{
    // Check if the chosen category has not been scored yet
    // If not scored, calculate the score by multiplying the choice with the corresponding dice face value
    // Otherwise, return -1 to indicate an invalid score
    return (player[n].score[choice - 1] == 0 ? choice * dice_face[choice - 1] : -1);
}

int tree_of_a_kind(int choice, int dice_face[], int n, gamer player[])
{
    // Check if there is a three-of-a-kind combination in the dice faces
    // If true, calculate the score by summing up the values of all dice faces
    // Otherwise, return -1 to indicate an invalid score
    if ((dice_face[0] == 3 || dice_face[1] == 3 || dice_face[2] == 3 || dice_face[3] == 3 || dice_face[4] == 3 || dice_face[5] == 3))
    {
        return (player[n].score[choice - 1] == 0 ? 1 * dice_face[0] + 2 * dice_face[1] + 3 * dice_face[2] + dice_face[3] * 4 + 5 * dice_face[4] + 6 * dice_face[5] : -1);
    }
    return -1;
}

int four_of_a_kind(int choice, int dice_face[], int n, gamer player[])
{
    // Check if there is a four-of-a-kind combination in the dice faces
    // If true, calculate the score by summing up the values of all dice faces
    // Otherwise, return -1 to indicate an invalid score
    if ((dice_face[0] >= 1 && dice_face[1] >= 1 && dice_face[2] >= 1 && dice_face[3] >= 1) ||
        (dice_face[1] >= 1 && dice_face[2] >= 1 && dice_face[3] >= 1 && dice_face[4] >= 1) ||
        (dice_face[2] >= 1 && dice_face[3] >= 1 && dice_face[4] >= 1 && dice_face[5] >= 1))
    {
        return (player[n].score[choice - 1] == 0 ? 1 * dice_face[0] + 2 * dice_face[1] + 3 * dice_face[2] + dice_face[3] * 4 + 5 * dice_face[4] + 6 * dice_face[5] : -1);
    }
    return -1;
}

int full_house(int choice, int dice_face[], int n, gamer player[])
{
    // Check if there is a full house combination in the dice faces
    // If true, return a fixed score of 40
    // Otherwise, return -1 to indicate an invalid score
    if ((dice_face[0] == 1 && dice_face[1] == 1 && dice_face[2] == 1 && dice_face[3] == 1 && dice_face[4] == 1) ||
        (dice_face[1] == 1 && dice_face[2] == 1 && dice_face[3] == 1 && dice_face[4] == 1 && dice_face[5] == 1))
    {
        return (player[n].score[choice - 1] == 0 ? 40 : -1);
    }
    else
    {
        return -1;
    }
}

int small_straight(int choice, int dice_face[], int n, gamer player[])
{
    // Check if there is a small straight combination in the dice faces
    // If true, return a fixed score of 30
    // Otherwise, return -1 to indicate an invalid score
    if ((dice_face[0] >= 1 && dice_face[1] >= 1 && dice_face[2] >= 1 && dice_face[3] >= 1) ||
        (dice_face[1] >= 1 && dice_face[2] >= 1 && dice_face[3] >= 1 && dice_face[4] >= 1) ||
        (dice_face[2] >= 1 && dice_face[3] >= 1 && dice_face[4] >= 1 && dice_face[5] >= 1))
    {
        return (player[n].score[choice - 1] == 0 ? 30 : -1);
    }
    else
    {
        return -1;
    }
}

int large_straight(int choice, int dice_face[], int n, gamer player[])
{
    // Check if the dice faces form a large straight (1, 2, 3, 4, 5 or 2, 3, 4, 5, 6)
    if ((dice_face[0] == 1 && dice_face[1] == 1 && dice_face[2] == 1 && dice_face[3] == 1 && dice_face[4] == 1) ||
        (dice_face[1] == 1 && dice_face[2] == 1 && dice_face[3] == 1 && dice_face[4] == 1 && dice_face[5] == 1))
    {
        // If the category hasn't been scored yet, return 40 points, otherwise return -1
        return (player[n].score[choice - 1] == 0 ? 40 : -1);
    }
    else
    {
        return -1;
    }
}

int yatzhee(int choice, int dice_face[], int n, gamer player[])
{
    // Check if all dice faces are the same (Yatzhee)
    if (dice_face[0] == 5 || dice_face[1] == 5 || dice_face[2] == 5 || dice_face[3] == 5 || dice_face[4] == 5 || dice_face[5] == 5)
    {
        // If the category hasn't been scored yet, add 50 or 100 points based on previous Yatzhee, and update the score
        player[n].score[choice - 1] += (player[n].score[choice - 1] == 50 ? 100 : 50);
    }
    else
    {
        return -1;
    }
}

int lucy(int choice, int dice_face[], int n, gamer player[])
{
    // Calculate the score for the Lucy category
    return (player[n].score[choice - 1] == 0 ? 1 * dice_face[0] + 2 * dice_face[1] + 3 * dice_face[2] + dice_face[3] * 4 + 5 * dice_face[4] + 6 * dice_face[5] : -1);
}

int pass(int choice, int dice_face[], int n, gamer player[])
{
    // The pass category does not score any points, so return 0
    return 0;
}

int player_entry(gamer *player)
{
    int player_num = 0, i;
    printf("How many players are playing the game?\n==>");
    scanf("%d", &player_num);
    for (i = 0; i < player_num; i++)
    {
        printf("Enter the name of player %d\n==> ", i + 1);
        getchar();
        fgets(player[i].name, MAX_NAME, stdin);
        printf("Enter the surname of %s \n==> ", player[i].name);
        fgets(player[i].surname, MAX_SURNAME, stdin);
    }
    return player_num;
}


// Made by Anýl Akpýnar
