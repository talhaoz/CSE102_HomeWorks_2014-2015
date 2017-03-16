/*----------------------------------------------------------------------------*/
/* */
/* HW012_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* ---------------------------------------------------------------------------*/
/* Created on 21/05/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/*This program takes player scores from text file and write them              */
/*              into a binary file in descending order                        */
/*---------------------______Inputs__________---------------------------------*/
/*-A text file */
/*----------------------____Outputs_________----------------------------------*/
/*-Output binary file                                                         */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <stdlib.h>

/*For keep the player data in this struct*/
typedef struct player_scores{

	char * name;
	double *scores;
	int size;
	double average;	

} PlayerScores;

/*For make a linked list with this struct*/
struct node{

	PlayerScores data;
	struct node *next;
};



/*Prototypes od the functions*/
void readTextFile(struct node *root, FILE *input);

double averageFind(struct node *root);

void sortAverage(struct node *root);


/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main()
{

	struct node *root;

	FILE *inp,
		 *outp;

	/*Allocate memory size of node to make a linked list header*/
	root=(struct node *)malloc(sizeof(struct node));

	root -> next=NULL;

	inp=fopen("input.txt","r");
	outp=fopen("output.dat","wb");

	/*if the file is empty or not found print a error message*/
	if(inp==NULL)
	{
		printf("FILE OPEN ERROR !\n");
		return 0;
	}

	/*call the read func to read datas into the struct*/
	readTextFile(root,inp);

	/*Sort the read datas in descending order*/
	sortAverage(root);

	/*Print whole datas into the binary file*/
	while(root!=NULL)
	{
		fwrite(&(root-> data),sizeof(PlayerScores),1,outp);

		root=root-> next;

	}


	fclose(inp);

	fclose(outp);



	return 0;
}




/*This func read the info s from text file and put them into struct*/
void readTextFile(struct node *root, FILE *input)
{
	char c,empty;
	int countOfChar = 0;
	int i,j,count,spacecounter,numOfplayers;
	int k=0;
	numOfplayers=0;


   /*Loop for find the number of the players with count the newline characters*/
	for(c=getc(input); c!=EOF; c=getc(input))
	{
		if(c=='\n')
		{
			numOfplayers++;
		}
	}

	/*go to the start of the file*/
	rewind(input);
	count=0;

	for(i=0; i<numOfplayers; i++)
	{	

		spacecounter=0;

		/* The reason we initialize the variable countOfChar with -i is,   */
		/*    in every line ending there is a newline character            */
		/* If we initialize countOfChar with zero,               	 	   */
		/* then in every single line program will read one less character. */
		countOfChar= -1 *i;

		/*Loop for find the number of spaces in a line 
										(it equals to number of double scores)*/
		for(c=getc(input); c!='\n'; c=getc(input))
		{
			if(c==' ')
			{
				spacecounter++;
			}
			count++;
			countOfChar++;
		}

		/*go to the start of the file*/
		rewind(input);

		/*Loop for move the marker*/
		for(k=0; k < count - countOfChar; k++)
		{
			getc(input);
		}

		/*Allocate the memory for get the name of the player*/
		root -> data.name=(char *)malloc(sizeof(char)*30);

		
		/* Get the player name*/
		fscanf(input,"%s", (root -> data.name));

		/* Allocate the memory for player scores*/
		root -> data.scores = (double *)calloc(spacecounter, sizeof(double));

		
		/*Read player scores as doubles*/
		for(j=0; j<spacecounter; j++)
		{	
			
			fscanf(input,"%lf" ,&(root -> data.scores[j]));
			
		}

		root -> data.size=spacecounter;

		/*Find average of player scores*/
		root -> data.average=averageFind(root);

		

		/*------------------------------------*/
		/*Allocate new memory for next datas*/
		root -> next=(struct node *)malloc(sizeof(struct node));

		/*make the old pointer refer to the next one */
		root=root -> next;

		/*Assign the new root next as Null*/
		root -> next=NULL;

		/*Read the newline character*/
		fscanf(input,"%c", &empty);


	}
	
}


/*This func find the average of the player scores*/
double averageFind(struct node *root)
{
	double avg;

	int numOfscores,i;

	/*Assign the size of double array for easyness*/
	numOfscores= root -> data.size;

	avg=0.0;

	for(i=0; i<numOfscores; i++)
	{
		avg+=root -> data.scores[i];
	}

	return avg/numOfscores;

}


/*This func sort the datas in descending order according to average of players*/
void sortAverage(struct node *root)
{
	/*Declarating two new node pointer to compare the averages*/
	struct node *iter1,*iter2;

	PlayerScores temp;

	for(iter1=root; iter1-> next!=NULL; iter1=iter1-> next)
	{
		for(iter2=iter1-> next; iter2!=NULL; iter2=iter2-> next)
		{
			if(iter1-> data.average < iter2-> data.average)
			{
				temp=iter1-> data;
				iter1-> data=iter2-> data;
				iter2-> data=temp;
			}
		}
	}

	return;
}


/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/
