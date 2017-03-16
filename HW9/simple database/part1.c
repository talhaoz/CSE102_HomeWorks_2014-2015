/*----------------------------------------------------------------------------*/
/* */
/* HW09_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 28/05/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*This program keep the information about world countries */
/*---------------------______Inputs__________---------------------------------*/
/*-Country name,number of population and soldiers, country area and neighbors */
/*----------------------____Outputs_________----------------------------------*/
/*-B command will find the most powerful country                              */
/*-C command will find the largest country                                    */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/


#include <stdio.h>
#include <string.h>


/*Define a type for keeping the information in it*/
typedef struct{

		char coName[25];/*Country name*/
		int coPop;/*Country population*/
		int coArea;/*Country area*/
		int coArmy;/*Country soldiers*/
		char coNeigh[10][25];/*Country neighbors*/

} coData;



coData addCountry(coData *crr,int flag);

void mostPowCountry(const coData *crr,int flag);/*Prototypes of the func*/

void largestCountry(const coData *crr,int flag);



/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main(void)
{
	coData crr[100];/*Declaration of a struct array*/

	char command;

	int flag;

	flag=0;

	printf("Make your choice:\n");
	scanf(" %c", &command);

	/*Loop for take the new command till user enter 'e' character*/
	do{

		switch(command)
		{
			case 'a':/*Choose 'a' to add a new country*/
			case 'A': crr[flag]=addCountry(crr,flag);
					  flag++;/*This flag increase when user add a new country,
					  			 its make easier to make the loops*/
					 break;

			case 'b':/*Choose 'b' to find most pow country including*/ 
			case 'B': mostPowCountry(crr,flag);				  /* the neighbors*/
					 break;

			case 'c':/*   'c' to find largest country including the neighbors*/
			case 'C': largestCountry(crr,flag);
					 break;

			case 'd':
			case 'D': /*No D function*/
					 break;

			default: printf("Invalid Command !\n");
		}

		printf("Make your choice:\n");
		scanf(" %c", &command);
		
	}while(command!='e');

	printf("Good Bye\n");

	return 0;
}

/*############################################################################*/
/*                                 Helper Functions                           */
/*############################################################################*/


/*The func will take the info of countries and keep it an array an then return*/
coData addCountry(coData *crr,int flag)
{

	int exitt,i;

	int num;


	scanf("%s", (crr[flag].coName) );

	scanf("%d", &(crr[flag].coPop) );/*Get the info from the user via terminal*/
	scanf("%d", &(crr[flag].coArea) );
	scanf("%d", &(crr[flag].coArmy) );

	exitt=0;
	i=0;
	
	/*Loop for get the neighbor countries*/
	do{

		if(scanf("%d",&num) && num==-1)/*When user enter -1 the loop will stop*/
		{
			exitt=1;
		}
		else
		{
			scanf("%s", (crr[flag].coNeigh[i]) );
		}

		i++;
	}while(!exitt && i<10);


	return crr[flag];/*return the array*/
}


/*The func will find the most pow country including the neigbors*/
void mostPowCountry(const coData *crr,int flag)
{
	char mainCo[25],neOfne[25];

	int i,j,k,l;

	int max,exitt,indexOfneofne;

	scanf("%s",mainCo);/*Get the country which we will compare with its neighb*/

	exitt=0;

	/*Loop for find the index of entered country*/
	for(i=0;i<flag && !exitt;i++)
	{
		if(strcmp(mainCo,crr[i].coName)==0)
		{
			exitt=1;
		}
	}
	/*if the entered country didnt record before print a error message*/
	if(exitt==0)
	{
		printf("NO SUCH RECORD!\n");
		return;
	}

	max=i;/*Firstly our country is the most pow country,so we assign,its index*/
	exitt=0;

	/*Loop for compare the country with neighbors and neighbors of neighbors*/
	for(j=0;j<flag;j++)
	{
		/*if the neighbor country more powerful than entered country, 
											assign the new index into the max*/
		if(crr[max].coArmy<crr[j].coArmy)
		{
			max=j;
		}

		/*if neighbor country have neighbors,
									compare them too with the entered country*/
		if(crr[j].coNeigh[0]!='\0')
		{	
			/*There re at most 10 neighbors country,so our loop till 10*/
			for(k=0;k<10;k++)
			{	
				/*Copy the neighbor country name for calculate easyness*/
				strcpy(neOfne,crr[j].coNeigh[k]);

			  /*Loop for find the index neighbor of neighbor country*/
				for(l=0;l<flag && !exitt;l++)
				{
					if(strcmp(neOfne,crr[l].coName)==0)
					{
						exitt=1;
					}

					indexOfneofne=l;
				}

				/*Compare the neigh of neigh country with main country*/
				if(crr[max].coArmy<crr[indexOfneofne].coArmy)
				{
					max=indexOfneofne;
				}

			}
		}
	}
	
	printf("%s\n", crr[max].coName);/*Print the most powerful country*/
	return;
}



/*The func will find the largest country including the neigbors*/

/*This func codes exactly same with mosPowCountry function codes*/
void largestCountry(const coData *crr,int flag)
{
	char mainCo[25],neOfne[25];

	int i,j,k,l;

	int max,exitt,indexOfneofne;

	scanf("%s",mainCo);

	exitt=0;

	for(i=0;i<flag && !exitt;i++)
	{
		if(strcmp(mainCo,crr[i].coName)==0)
		{
			exitt=1;
		}
	}

	if(exitt==0)
	{
		printf("NO SUCH RECORD!\n");
		return;
	}

	max=i;
	exitt=0;

	for(j=0;j<flag;j++)
	{
		if(crr[max].coArea<crr[j].coArea)
		{
			max=j;
		}

		if(crr[j].coNeigh[0]!='\0')
		{
			for(k=0;k<10;k++)
			{
				strcpy(neOfne,crr[j].coNeigh[k]);

				for(l=0;l<flag && !exitt;l++)
				{
					if(strcmp(neOfne,crr[l].coName)==0)
					{
						exitt=1;
					}

					indexOfneofne=l;
				}

				if(crr[max].coArea<crr[indexOfneofne].coArea)
				{
					max=indexOfneofne;
				}

			}
		}
	}

	printf("%s\n", crr[max].coName);

	return;
}


/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/