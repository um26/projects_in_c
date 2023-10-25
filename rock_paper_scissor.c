#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int game(char user, char computer) {
    if (user == computer) return 0;

    if (user == 'r' && computer == 's') return 1;
    else if (user == 's' && computer == 'r') return -1;

    if (user == 'r' && computer == 'p') return -1;
    else if (user == 'p' && computer == 'r') return 1;

    if (user == 'p' && computer == 's') return -1;
    else if (user == 's' && computer == 'p') return 1;
}

int main() {
    int n;
    int user_win = 0, computer_win = 0, draw = 0;
    char user, computer, result;

    srand(time(NULL));

    printf("\n\t\tWELCOME TO THE GAME OF ROCK-PAPER-SCISSORS\n");

    int play = 1;
    while (play != 0) {
        n = rand() % 100;

        if (n < 33) computer = 'p';
        else if (n > 66) computer = 's';
        else computer = 'r';

        do {
            printf("\n\t\tENTER 'r' FOR ROCK, 's' FOR SCISSORS, AND 'p' FOR PAPER\n");
            scanf(" %c", &user);
            user = tolower(user);

            if (user != 's' && user != 'r' && user != 'p') {
                printf("\nINVALID CHOICE, PLEASE ENTER 'r', 's', or 'p'.\n");
            }
        } while (user != 's' && user != 'r' && user != 'p');

        result = game(user, computer);

        if (result == -1) {
            printf("\nOH! YOU HAVE LOST THE GAME!\n");
            computer_win++;
        } else if (result == 0) {
            printf("\nGAME DRAW!\n");
            draw++;
        } else {
            printf("\nCONGRATULATIONS! YOU HAVE WON THE GAME!\n");
            user_win++;
        }

        printf("\nYOU CHOSE: %c AND COMPUTER CHOSE: %c\n TO CONTINUE: PRESS ANY NUMBER OTHER THAN 0 \n TO EXIT: PRESS 0\n", user, computer);
        scanf("%d", &play);
    }

    printf("user_wins:%d, computer_wins:%d, Draw:%d\n", user_win, computer_win, draw);
    return 0;
}
