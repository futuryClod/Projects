#include<stdio.h>
#include<stdlib.h>
#define MAX 9

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%c \t", board[i][j]);
        }
        printf("\n");
    }
}

int winLogic(){
    int i;
    for(i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return 1;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return 1;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return 1;
    }

    return 0;
} 

void gameLogic(){
    int count = 1;
    char player;
    int choice;
    int row, col;

    while (count <= 9){
        displayBoard();

        if(count % 2 != 0){
            player = 'X';
        }
        else{
            player = 'O';
        }

        printf("Player %c, Enter Position (1-9): ", player);
        scanf("%d", &choice);

        if(choice > 9 || choice < 1){
            printf("INVALID OPTION\n");
            while (getchar() != '\n');
            continue;
        }

        row = (choice - 1)/3;
        col = (choice - 1)%3;

        if(board[row][col] == 'X' || board[row][col] == 'O'){
            printf("Position is already filled.\n");
            continue;
        }

        board[row][col] = player;
        if(winLogic()){
            printf("%c won the game.\n", player);
            break;
        }
        count++;
    }

    if(!winLogic()){
        printf("DRAW\n");
    }

    displayBoard();
    printf("Game Over\n");
}


int main(){
    gameLogic();
    return 0;
}