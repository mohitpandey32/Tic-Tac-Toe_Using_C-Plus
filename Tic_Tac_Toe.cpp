#include <stdio.h>
#include <string.h>

char board[3][3];  // Tic-Tac-Toe board
char currentPlayer = 'X';  // Player 1 starts with 'X'
char player1[50], player2[50];  // Player names

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j); // Filling with numbers 1-9
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

// Function to check if the board is full (Draw condition)
int isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') return 0; // Empty cell found
        }
    }
    return 1;
}

// Function to make a move
void makeMove() {
    int choice;
    char *currentPlayerName = (currentPlayer == 'X') ? player1 : player2;
    
    printf("%s (%c), enter your move (1-9): ", currentPlayerName, currentPlayer);
    scanf("%d", &choice);

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Try again.\n");
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function
int main() {
    printf("Welcome to Tic-Tac-Toe!\n\n");

    // Getting player names
    printf("Enter Player 1 name (X): ");
    fgets(player1, 50, stdin);
    player1[strcspn(player1, "\n")] = 0;  // Remove newline character

    printf("Enter Player 2 name (O): ");
    fgets(player2, 50, stdin);
    player2[strcspn(player2, "\n")] = 0;  // Remove newline character

    initializeBoard();
    
    while (1) {
        displayBoard();
        makeMove();

        if (checkWin()) {
            displayBoard();
            printf("Congratulations %s! You win!\n", (currentPlayer == 'X') ? player1 : player2);
            break;
        }
        if (isDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
