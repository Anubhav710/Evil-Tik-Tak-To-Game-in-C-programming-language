#include<stdio.h>
#include<conio.h>
char board[3][3]={'1','2','3','4','5','6','7','8','9'};
int square[3][3]={2,2,2,2,2,2,2,2,2};
int isEvilMarked=0;
int evilEnter=0;

char player=1;
void displayBoard();
char selectPlayer();
void fillMarks();
int checkWinner();
int isEmpty(int row,int col);
int findComputerMove();
int list();
void reset();
void system();

int main()
{
    int isGameOver=0,computerMove=1,end=0;

    while(!end)
    {system("cls");
    switch (list())
    {
    case 1:
    while(!isGameOver)
    {   system("cls");
        displayBoard();
        fillMarks();
        findComputerMove();
        isGameOver=checkWinner();
    }
    if(isGameOver==1)
    {
    printf("Player - %d won \n",player+1);
    printf("Do you want to play again..Press Enter");
    isGameOver=0;
    reset();
    getch();
    }
    break;

    case 2:
    while(!isGameOver)
    {   system("cls");
        isEvilMarked=1;
        displayBoard();
        fillMarks();
        findComputerMove();
        isGameOver=checkWinner();
    }
    if(isGameOver==1)
    {
    printf("Player -%d won \n",player+1);
    printf("Do you want to play again..Press Enter");
    isGameOver=0;
    reset();
    getch();
    }

    break;

    case 3:
    while(!isGameOver)
    {   system("cls");
        displayBoard();
        fillMarks();
        isGameOver= checkWinner();
    }
     if(isGameOver==1)
    {
    printf("Player -%d won \n",player+1);
    printf("Do you want to play again..Press Enter");
    isGameOver=0;
    reset();
    getch();
    }
    break;

     case 4:
        end=1;
        break;
        
    
    default:
        printf("Wrong Choice try again..");
        break;
    }
    }
   
}


// Display Board...
void displayBoard()           
{   
    int i=0; 

    printf("\n\nTik Tak Toe\n\n\n");
    printf("Player 1(X) - Player 2(O)\n\n\n");

    while(i<3)
    {
    printf("     |     | \n");
    printf("  %c  |  %c  |  %c \n",board[i][0],board[i][1],board[i][2]);
    printf("_____|_____|____\n");
    i++;
    }
}

//Player Turn...
char selectPlayer()
{
    char mark[2]={'X','O'};

    if(evilEnter==1)
    {

        return mark[0];
    }

    if(player==0)
    {
        player=1;
        return mark[player];
    }
    if(player==1)
    {
        player=0;
        return mark[player];
    }
    
}

// Fill Marks(x,o)....
void fillMarks()
{
    int row,col,flag=0;
    char mark;
    printf("Enter Marking place: ");
    scanf("%c",&mark);
    
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(mark==board[row][col])
            {
                board[row][col]=selectPlayer();
                square[row][col]=1;
            }

        }
    }    
    fflush(stdin);
}

int isEmpty(int row,int col)
{
    if(board[row][col]!='X' || board[row][col]!='O')
    return 0;
    else
    return 1;
}


// Winner Check...
int checkWinner()
{
    int row,col,count=0;
    char playAgian;
    //Horizontal Win
    for(row=0;row<3;row++)
    {
        if(board[row][0]==board[row][1] && board[row][1]==board[row][2])
        {
            return 1;
        } 
    }

    //Vertical win
    for(col=0;col<3;col++)
    {
        if(board[0][col]==board[1][col] && board[1][col]==board[2][col])
        {
            return 1;
        } 
    }

    // Left side Digonal Wins
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return 1;
    }

    // Right Side Digonal Win
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        return 1;
    }


    //Draw Case
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(board[row][col]=='X' || board[row][col]=='O')
            {
                count++;
            }
        }
     if(count==9)
    {
        printf("Game is Draw.. Do You want to play again Y/N\n");
        scanf("%c",&playAgian);
        if(playAgian=='y' || playAgian=='Y')
        {
        reset();
        return 0;
        }
        if(playAgian=='n' || playAgian=='N')
        {
            reset();
            return -1;
        }
    }
    }
   
    return 0;
}


//Computer Move .....

int findComputerMove()
{
    int row,col,mul=1,maxMul=1,selectedRow,selectedCol;
    int check=0;
    isEvilMarked=1;
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
         if(square[row][col]==2)
         {
            square[row][col]=3;
            
            //Horizonatal Condition
            mul=square[row][0]*square[row][1]*square[row][2]; 
            if(mul==27)
            {
                board[row][col]=selectPlayer();
                return 1;
            }
            else if(maxMul<mul)
            {
                maxMul=mul;
                selectedRow=row;
                selectedCol=col;
            }

            //Vertical Condition
            mul=square[0][col]*square[1][col]*square[2][col]; 
            if(mul==27)
            {
                board[row][col]=selectPlayer();

                return 1;

            }
            else if(maxMul<mul)
            {
                maxMul=mul;
                selectedRow=row;
                selectedCol=col;
            }

            //Diagonal Condition
            if(row==col)
            {
            mul=square[0][0]*square[1][1]*square[2][2];
            if(mul==27)
            {
                board[row][col]=selectPlayer();
                return 1;
            }
            else if(maxMul<mul)
            {
                maxMul=mul;
                selectedRow=row;
                selectedCol=col;
            }
            }
           
           if((row==0 && col==2) || (row==1 && col==1) ||(row==2 && col==0))
           {
            mul=square[0][2]*square[1][1]*square[2][0];
              if(mul==27)
            {
                board[row][col]=selectPlayer();
                return 1;
            }
            else if(maxMul<mul)
            {
                maxMul=mul;
                selectedRow=row;
                selectedCol=col;
            }   
           } 
            square[row][col]=2;    
         }   
        
        }
        
    }
   for (row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(square[row][col]==2)
            {
                square[row][col]=3;
                   //Horizontal condition
                 mul=square[row][0]*square[row][1]*square[row][2];
                if(mul==3)
                {
                    board[row][col]=selectPlayer();
                    if(isEvilMarked==1)
                    {
                        evilEnter=1;
                        check=1;
                        row=0;
                        break;
                    }
                    return 1;
                }

                 //Vertical Condition
                 mul=square[0][col]*square[1][col]*square[2][col]; 
                 if(mul==3)
                {
                    board[row][col]=selectPlayer();
                     if(isEvilMarked==1)
                    {
                        evilEnter=1;
                        check=1;
                        row=0;
                        break;
                    }
                    return 1;
                }

                //Diagonal Condition
                 if(row==col)
                 {
                 mul=square[0][0]*square[1][1]*square[2][2];
                   if(mul==3)
                     {
                         board[row][col]=selectPlayer();
                          if(isEvilMarked==1)
                        {
                            evilEnter=1;
                            check=1;
                            row=0;
                            break;
                        }
                         return 1;
                     }
                 }
                  //Right Digonal condition
                 if((row==0 && col==2) || (row==1 && col==1) ||(row==2 && col==0))
                {
                 mul=square[0][2]*square[1][1]*square[2][0];
                  if(mul==3)
                     {
                         board[row][col]=selectPlayer();
                          if(isEvilMarked==1)
                    {
                        evilEnter=1;
                        check=1;
                        row=0;
                        break;
                    }
                         return 1;
                     }
                }
                square[row][col]=2;
            }
        }
        
    }
    evilEnter=0;
    if(check==0)
    {
    board[selectedRow][selectedCol]=selectPlayer();
    square[selectedRow][selectedCol]=3;
    }
    return 1;
}

int list()
{
    int choice;
    printf("Enter Your Choice \n");
    printf("1. Want to play with Smart Computer\n");
    printf("2. Want to play with Evil Computer\n");
    printf("3. Want to play with player\n");
    printf("4. Exit\n");
    scanf("%d",&choice);

    return choice;

}


void reset()
{ 
    int i,j;
    char alpha='1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++,alpha++)
        {
            board[i][j]=alpha;
            square[i][j]=2;
        }
    }

int isEvilMarked=0;
int evilEnter=0;

char player=0;
}