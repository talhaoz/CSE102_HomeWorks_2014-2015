/*----------------------------------------------------------------------------*/
/* */
/* HW05_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 03/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*This program is a simple chess simulator,it performs some simple operations */
/*---------------------______Inputs__________---------------------------------*/
/*-Get a command from user                                                    */
/*-Get source position and target position and then check is piece movable    */
/*----------------------____Outputs_________----------------------------------*/
/*-If piece movable print YES,otherwise NO                                    */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*--------Fucntion Prototypes------------*/
void initBoard(char *board);

void getPosition(char *col,int *row);

int isValidCell(char col,int row);

int isValidCell2(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);

void printBoard(char *board);

int isPieceMovable(char *board);

int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);



void emptyBuffer()
{
	while ( getchar() != '\n' );
}

int main()
{	
	char board [64];
	
	int initComplete = 0;
	
	char empty;

	int command;

	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}

/*Initializing the board with this function*/
void initBoard(char *board)
{

	int i;

	char temparr[64]={' ',' ',' ',' ',' ',' ',' ',' ',
					  ' ',' ',' ',' ',' ',' ',' ',' ',
					  ' ',' ',' ',' ',' ',' ',' ',' ',
					  ' ',' ',' ',' ',' ',' ',' ',' ',
					  ' ',' ','p',' ',' ',' ',' ',' ',
					  'p',' ','P','p',' ',' ',' ',' ',
					  ' ','P',' ',' ',' ',' ',' ',' ',
					  ' ',' ',' ',' ',' ',' ',' ',' ',};

	for(i=0;i<64;i++)
	{
		board[i]=temparr[i];
	}
}

/*Print the initialized board with this function*/
void printBoard(char *board)
{
	int i,j,k;

	printf("  a b c d e f g h\n  - - - - - - - -\n");
	
	i=8;
	for(k=0;4*k+7<64;k+=2)
	{
		printf("%d|", i);
		for(j=4*k;j<=4*k+7;j++)
		{
			printf("%c", board[j]);
			if(j!=4*k+7)
			{
				printf(" ");
			}
		}
		printf("|\n");
		i--;
	}
	printf("  - - - - - - - -\n");
}

/*This func will get the column and row from user*/
void getPosition(char *col,int *row)
{
	scanf("%c%d",col,row);
}

/*This func check the col and row is valid according to board sizes*/
int isValidCell(char col,int row)
{
	if(col>='a'&&col<='h'&&row>=1&&row<=8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*  This func check the target piece white or black.If the user is black one, */
/*	then target cell can not be black.if its black ,cant move the target cell */
/*		   	       	 So returns 0, other wise return 1                        */
int isValidCell2(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcepiece,targetpos;

	sourcepiece=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpos=(int)((targetCol-'a')+(8-targetRow)*8);


		if(board[sourcepiece]>='a'&&board[sourcepiece]<='z')
		{
			if(board[targetpos]>='a'&&board[targetpos]<='z')
			{
				return 0;
			}
		}
		else if(board[sourcepiece]>='A'&&board[sourcepiece]<='Z')
		{
			if(board[targetpos]>='A'&&board[targetpos]<='Z')
			{
				return 0;
			}
		}
	
	return 1;
}

/*This function get source and target position and check them are they movable*/

int isPieceMovable(char *board)
{
	int sourceRow,targetRow,check1,check2,piece,exitt;

	char sourceCol,targetCol,empty;

	getPosition(&sourceCol,&sourceRow);

	scanf("%c", &empty);

	getPosition(&targetCol,&targetRow);


/*Calling the validcell func to confirm target and source pos in the board*/
	check1=0;
	check1=isValidCell(sourceCol,sourceRow);

	check2=0;
	check2=isValidCell(targetCol,targetRow);;


	if(check1&&check2)

	{	/*Find the index of source cell*/
		piece=(int)((sourceCol-'a')+(8-sourceRow)*8);

		switch(board[piece])
		{
			case 'P':
			case 'p':
					exitt=isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			case 'R':
			case 'r':
					exitt=isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			case 'N':
			case 'n':
					exitt=isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			case 'B':
			case 'b':
					exitt=isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			case 'Q':
			case 'q':
					exitt=isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			case 'K':
			case 'k':
					exitt=isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow);
					break;
			default:
					printf("NO\n");
					return 0;
		}
		return exitt;
	}
	else
	{
		printf("NO\n");
		return 0;
	}
		return 0;
}


/*This func check the rook is movable according to rules*/
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int piece,i,check,targetpos;


	/*Find the index of source and target cells for array using*/
	piece=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpos=(int)((targetCol-'a')+(8-targetRow)*8);


	check=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);
	
	if(check)
	{
    /*According to the game rules, rook can move only the column changed or  */
	    	/*          only the row was changed not both of it         */
		if(sourceRow!=targetRow&&sourceCol==targetCol)
		{
			/*Loop for checking every cell one by one until the target cell*/
			for(i=1;i<=abs(targetRow-sourceRow);i++)
			{
				if(abs(targetRow-sourceRow)==i)
				{
				   /*if the enemy piece in the target cell,rook can move there*/
					if(board[piece]>='a'&&board[piece]<='z')
					{
						if(board[targetpos]>='A'&&board[targetpos]<='Z')
						{
							return 1;
						}
					}
					else if(board[piece]>='A'&&board[piece]<='Z')
					{
						if(board[targetpos]>='a'&&board[targetpos]<='z')
						{
							return 1;
						}
					}
				}
			/*if the target row greater than source row we re going to the up*/
			/*       So our index should decrease                  */
				if(sourceRow<targetRow)
				{
					if(board[piece-8*i]!=' ')
					{
						return 0;
					}
				}
				else if(targetRow<sourceRow)
				{
					if(board[piece+8*i]!=' ')
					{
						return 0;
					}
				}
			}
		}
		else if(sourceCol!=targetCol&&sourceRow==targetRow)
		{
			for(i=1;i<=abs((int)(targetCol-sourceCol));i++)
			{
				if(abs(targetCol-sourceCol)==i)
				{

					if(board[piece]>='a'&&board[piece]<='z')
					{
						if(board[targetpos]>='A'&&board[targetpos]<='Z')
						{
							return 1;
						}
					}
					else if(board[piece]>='A'&&board[piece]<='Z')
					{
						if(board[targetpos]>='a'&&board[targetpos]<='z')
						{
							return 1;
						}
					}
				}

				if(sourceCol<targetCol)
				{
					if(board[piece+i]!=' ')
					{
						return 0;
					}
				}
				else if(targetCol<sourceCol)
				{
					if(board[piece-i])
					{
						return 0;
					}
				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

/*This func check the knight is movable according to rules*/
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int check,targetpos,sourcepos;
	/*Check the validness*/
	check=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);

	sourcepos=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpos=(int)((targetCol-'a')+(8-targetRow)*8);

	/*Knight can move everywhere but only like a 'L' letter.
                     						So there re four possibilities*/
	if(check)
	{
		if(abs(targetpos-sourcepos)==15||abs(targetpos-sourcepos)==6
			||abs(targetpos-sourcepos)==10||abs(targetpos-sourcepos)==17)
		{
			return 1;
		}
	}
	
	return 0;
}

/*This func check the pawn is movable according to rules*/
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int check,sourcepos,targetpos;

	check=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);
	/*Check the validness*/
	sourcepos=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpos=(int)((targetCol-'a')+(8-targetRow)*8);

	/*The pawn move only 1 cell in our rules,so there re 3 possibilities*/
	if(check)
	{
		if(abs(sourcepos-targetpos)==8)
		{
			return 1;
		}
		else if(abs(sourcepos-targetpos)==7||abs(sourcepos-targetpos)==9)
		{
				if(board[sourcepos]>='a'&&board[sourcepos]<='z')
				{
					if(board[targetpos]>='A'&&board[targetpos]<='Z')
					{
						return 1;
					}
				}
				else if(board[sourcepos]>='A'&&board[sourcepos]<='Z')
				{
					if(board[targetpos]>='a'&&board[targetpos]<='z')
					{
						return 1;
					}
				}		    
		}
		else
		{
		    return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

/*This func check the bishop is movable according to rules*/
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int check,piece,i,targetpos;

	piece=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpos=(int)((targetCol-'a')+(8-targetRow)*8);
	/*Check the validness*/
	check=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);

	if(check)
	{	/*Loop for checking every cell one by one until the target cell*/
		for(i=1;i<=abs(targetRow-sourceRow);i++)
		{
			if(abs(targetRow-sourceRow)==i)
			{
				/*if the enemy piece in the target cell,rook can move there*/
				if(board[piece]>='a'&&board[piece]<='z')
				{
					if(board[targetpos]>='A'&&board[targetpos]<='Z')
					{
						return 1;
					}
				}
				else if(board[piece]>='A'&&board[piece]<='Z')
				{
					if(board[targetpos]>='a'&&board[targetpos]<='z')
					{
						return 1;
					}
				}
			}
	/*For checking the bishop movabeleness we can think our board 
						like four equal pieces,so we have four possibilities*/	
			if(sourceRow<targetRow&&targetCol>sourceCol)
			{
				if(board[piece-7*i]!=' ')
				{
					return 0;
				}
			}
			else if(targetRow<sourceRow&&targetCol>sourceCol)
			{
				if(board[piece+7*i]!=' ')
				{
					return 0;
				}
			}
			else if(sourceRow<targetRow&&targetCol<sourceCol)
			{
				if(board[piece-9*i]!=' ')
				{
					return 0;
				}
			}
			else if(targetRow<sourceRow&&targetCol<sourceCol)
			{
				if(board[piece+9*i]!=' ')
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

/*This func check the queen is movable according to rules*/
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int checkTarget,checkReturn;

	checkTarget=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);
 /*The queen movable func is much more simple because the queen move like
           													bishop and rook*/
	if(checkTarget)
	{

	/*if The target at the same col but in different row we call the rook func*/
		if((sourceRow!=targetRow&&sourceCol==targetCol)
								||(sourceCol!=targetCol&&sourceRow==targetRow))
		{
			checkReturn=isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
		}
		else if(targetRow!=sourceRow&&targetCol!=sourceCol)
		{
			checkReturn=isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	return checkReturn;
}

/*This func check the king is movable according to rules*/
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int checkTarget,checkReturn,sourcepiece,targetpiece;

	sourcepiece=(int)((sourceCol-'a')+(8-sourceRow)*8);
	targetpiece=(int)((targetCol-'a')+(8-targetRow)*8);

	checkTarget=isValidCell2(board,sourceCol,sourceRow,targetCol,targetRow);

	if(checkTarget)
	{
		/*The king can move only one piece around so we have 4 possibilities*/
		
		if(abs(sourcepiece-targetpiece)==1||abs(sourcepiece-targetpiece)==7||
			abs(sourcepiece-targetpiece)==8||abs(sourcepiece-targetpiece)==9)
		{
			
				if((sourceRow!=targetRow&&sourceCol==targetCol)
								||(sourceCol!=targetCol&&sourceRow==targetRow))
				{
					checkReturn=isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
				}
				else if(targetRow!=sourceRow&&targetCol!=sourceCol)
				{
					checkReturn=isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
				}
				else
				{
					return 0;
				}

		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	return checkReturn;
}


/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/








