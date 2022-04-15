// Tic-tac-toe (T3) Network Game

//-----------------------------------------------------------------------------
// Compile notes for C99 code
//-----------------------------------------------------------------------------

// gcc -o t3 t3.c udp.c

//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------

#include <stdlib.h>          // EXIT_ codes
#include <stdbool.h>         // bool
#include <stdio.h>           // printf, scanf
#include <string.h>          // strlen, strcmp

#include "udp.h"
//#include "udp.c"

#define CLIENT_PORT 4096
#define SERVER_PORT 4097
bool addMove(char board[3][3], char move[], char xo);
void clearBoard(char board[3][3])
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            board[r][c] = '.';
}

//Display the game board
void showBoard(char board[3][3])
{
    
    
    printf("\n\n");
    for(int i= 0;i<3;i++){
        for(int j =0; j<3;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

// Add code to determine if a winner (xo) has occurred
bool isWinner(char board[3][3], char xo)
{    bool win;
    win =0;
    int i =0, j=0;
    for(i =0; i<3; i++){
        //Checks every row for a win: 
        if(board[i][j] == xo){ 
            if(board[i][j+1] == xo){
                if (board[i][j+2] == xo){
                    win =1;
                    }
                }
            }
        }
        
        //Checks every col for a win:
        for(i=0,j=0; j<3; j++){
            if(board[i][j] == xo){ 
                if(board[i+1][j] == xo){
                    if (board[i+2][j] == xo){
                        win =1;
                        }
                    }
                }
        }
        //Checks for diagonal win:
        if(board[0][0] == xo){ 
            if(board[1][1] == xo){
                if (board[2][2] == xo){
                    win =1;
                    }
                }
            }
        if(board[2][0] == xo){ 
            if(board[1][1] == xo){
                if (board[0][2] == xo){
                    win =1;
                    }
                }
            }

    return win;
}

//  Code to test if an x or o (xo) is a valid move
//  and then record in the game board
bool addMove(char board[3][3], char move[], char xo)
{
    
    
    //int verify1=0;
    //int verify2=0;
    bool ok = strlen(move) == 2;
    //int cmp;
    /*char* token =strtok(move, "1 2 3");
    //char* numTok= strtok(move,"A B C");
    while(token!=NULL){
        if(strcmp(token , "A") == 0){ verify1++;}
        else if(strcmp(token , "B") == 0){ verify1++;}
        else if(strcmp(token , "C") == 0){verify1++;}
        else if(strcmp(token,1)==0){ verify2++;}
        else if(strcmp(token,2)==0){ verify2++;}
        else if(strcmp(token,3)==0){ verify2++;}
    }*/
    int k=0; 
        
        int cmp1 = strcmp(move, "A1");
        int cmp2 = strcmp(move, "B1");
        int cmp3 = strcmp(move, "C1");
        int cmp4 = strcmp(move, "A2");
        int cmp5 = strcmp(move, "B2");
        int cmp6 = strcmp(move, "C2");
        int cmp7 = strcmp(move, "A3");
        int cmp8 = strcmp(move, "B3");
        int cmp9 = strcmp(move, "C3");
        
        if(cmp1==0||cmp2==0||cmp3==0||cmp4==0||cmp5==0||cmp6==0||cmp7==0||cmp8==0||cmp9==0){ k++; }
        
        
        //Check if valid move, and if so, update with the users's move!
        if(cmp1==0){
            if(board[0][0] == '.'){
                board[0][0] = xo; k++;
            }
        }
        else if(cmp2==0){
            if(board[1][0] == '.'){
                board[1][0] = xo; k++;
            }
        }
        else if(cmp3==0){
            if(board[2][0] == '.'){
                board[2][0] = xo; k++;
            }
        }
        else if(cmp4==0){
            if(board[0][1] == '.'){
                board[0][1] = xo; k++;
            }
        }
        else if(cmp5==0){
            if(board[1][1] == '.'){
                board[1][1] = xo; k++;
            }
        }
        else if(cmp6==0){
            if(board[2][1] == '.'){
                board[2][1] = xo; k++;
            }
        }
        else if(cmp7==0){
            if(board[0][2] == '.'){
                board[0][2] = xo; k++;
            }
        }
        else if(cmp8==0){
             if(board[1][2] == '.'){
                 board[1][2] = xo; k++;
            }
        }
        else if(cmp9==0){
            if(board[2][2] == '.'){
                board[2][2] = xo; k++;
            }
        }

    //nothing was a valid move:    
    if(k==0){ printf("Please try again\n\nType in move:\n"); //IF NOT VALID MOVE OR MOVE SET
        scanf("%s", move); return addMove(board, move, xo);
    }
    return ok;
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(int argc, char* argv[]) //arguement, what arguement holds in string
{
    char *remoteIp;
    char *role;
    char str[100], str2[100];
    char board[3][3];
    bool validMove;
    bool winner = false;
    int moveCount = 0;

    bool myTurn;
    char myLetter, opponentLetter;
    int remotePort;

    // Verify arguments are valid
     bool goodArguments;
    // ...
    
    //COMMAND LINE SUPPORT
    bool client;
    
    
    //printf("Type ./t3 192.168.1.x invite (or accept) to become client (or server)\n");
    //scanf("%s %s %s", argv[0], argv[1], argv[2]); //arguement stored.. should == 3 because each break in space creates new argument...
    if(argc == 3){
        //printf("The supplied argument is %s %s %s\n", argv[0],argv[1], argv[2]);
        goodArguments = 1;
        
    // Determine if client or server
    // A server will wait to accept an invitation to play
    // A client will send an invitation to play
    // bool client = _____;
    
    
        int verify_acc = strcmp("accept", argv[2]);
        int verify_inv = strcmp("invite", argv[2]);
        
        
        remoteIp = argv[1]; // User's IP is now stored.
        //printf("%s\n", remoteIp);
        if(verify_acc == 0 ){ //If third arg is accept
            
            //role is now stored as SERVER
            role = (char *)malloc(sizeof(char));
            strcpy(role,"server"); //ROLE STORAGE - server
            client = 0; //not client
        }
        else if(verify_inv == 0){ //if invite, then it IS client
            
            
            role = (char *)malloc(sizeof(char));
            strcpy(role,"client"); //ROLE STORAGE - client
            
            //printf("%s\n", role);
            //role now stores user as client
            client = 1;
        }
        else{
            printf("Third argument has to be either invite or accept\n");
            exit(EXIT_FAILURE);
        }
        
    }
    else if( argc > 3){
        printf("Too many arguments supplied.");
        exit(EXIT_FAILURE);
    }
    else if( argc<3){
        printf("Supply at least 3 arguments.");
        exit(EXIT_FAILURE);
    }
    
    if (goodArguments == 0){ //false
        printf("usage: t3 IPV4_ADDRESS ROLE\n");
        printf("  where:\n");
        printf("  IPV4_ADDRESS is address of the remote machine\n");
        exit(EXIT_FAILURE);
    }


    // Determine remote port that you will send data to
    // If you are server, send to client port, and vice versa
    int num;
    if(client == 0){ //if server
        
        num = CLIENT_PORT;
        openListenerPort(remoteIp, SERVER_PORT);
        //do server stuff (wait to accept invite to play)
        //receiveData(char str[], int str_length); 
        printf("Waiting for an invitation\n");
        receiveData(str, sizeof(str)); //waits until client send the invite string 
        printf("Invitation received\n");
        //Note:similar format, when sending moves we use the other str[200] and will pass it through here
    }
    else{//if client
        
        num=SERVER_PORT;
        openListenerPort(remoteIp, CLIENT_PORT);
        //do client stuff (invite to play and wait for accept)
        printf("Sending an invitation\n");
        sendData(remoteIp,num, "invite"); //IP, port, "invite"
    }
    


    // Setup game
    clearBoard(board);
    //showBoard(board);

    // Determine whether it is your turn or not
    // myTurn = ______;
    if(client ==1){
        myTurn = 0;
        myLetter = 'o';
        opponentLetter = 'x';
    }
    else{
        myTurn = 1; 
        myLetter = 'x';
        opponentLetter = 'o';
    }
    //  Determine your letter (x or o) and your opponent's letter

    //  Add code to send an invite or wait to accept an invite

    // Start game loop, alternating turns
    
    while(!winner && moveCount != 9)
    {
        if(myTurn){
            showBoard(board);
            printf("It's your turn!\nType in desired move:\n");

            //get my move:
            scanf("%s",str2); //str2[100] takes in a 2 letter string.
            // TODO: add code your move here to get the move, validate move,
            //       show board, send move to remote port, and check for a winner
            addMove(board, str2, myLetter);//board, move, if x or o
            moveCount++;
            sendData(remoteIp,num, str2); //send move
            if(isWinner(board, myLetter) ){
                showBoard(board);
                printf("%c wins!\n", myLetter);
                winner=1;
                return EXIT_SUCCESS;
            }
            myTurn = !myTurn;
        }
        
        // get opponent's move
        else if(!myTurn)
        {
            showBoard(board);
            printf("Waiting on opponent...\n");
            //  add code to receive your opponent's move, validate move,
            //  show board, and check for a winner
            receiveData(str, sizeof(str));
            addMove(board, str, opponentLetter);
            printf("Opponent (%c) played to %s", opponentLetter, str);
            if(isWinner(board, opponentLetter) ){
                showBoard(board);
                printf("%c wins!\n", opponentLetter);
                winner=1;
                return EXIT_SUCCESS;
            }
            moveCount++;
            myTurn = !myTurn;
        }
    }
    if (!winner || moveCount>9)
        printf("The game was a draw\n");

    void closeListenerPort(); //releases the socket
    return EXIT_SUCCESS;
}
