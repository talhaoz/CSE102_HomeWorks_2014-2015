/*----------------------------------------------------------------------------*/
/* */
/* HW04_131044003_Talha_Oz */
/* */
/*                              part2.c                                       */
/* --------- */
/* Created on 23/03/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program take a positive number,borderwidth and border character*/
/*    and print the positive number with character that user entered          */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers= A positive integer number and width of border                    */
/*-Characters= A character that user want to see                              */
/*----------------------____Outputs_________----------------------------------*/
/*- Entered Number and borders                                                */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <math.h> /*including math library for some mathematical functions*/

/*--------Fucntion Prototypes------------*/
void zerofunc(int line,char borderChar);
void onefunc(int line,char borderChar);
void twofunc(int line,char borderChar);
void threefunc(int line,char borderChar);
void fourfunc(int line,char borderChar);
void fivefunc(int line,char borderChar);
void sixfunc(int line,char borderChar);
void sevenfunc(int line,char borderChar);
void eightfunc(int line,char borderChar);
void ninefunc(int line,char borderChar);


void getInputs(int *num,int *borderWidth, char *borderChar);

int printNumber(int num,int borderWidth, char borderChar);




int main(void)
{
	int intnum,width;

	char charr;



	getInputs(&intnum,&width,&charr);


	printNumber(intnum,width,charr);

	return 0;
}

/*This getinput function scan the number,borderwidth and,borderchar*/
void getInputs(int *num,int *borderWidth, char *borderChar)
{

	scanf("%d%d %c",num,borderWidth,borderChar);
	

}
/*This function take the number ,borderwidth and character as input parameters*/
/*  and then print the number via console with using some helper functions*/
int printNumber(int num,int borderWidth, char borderChar)
{

	int x[5]; /*Declaration of x array(it will keep the digits of number)*/

	int n;
				/*Declaration of some integers*/
	int i,j,
		a,b,c,d,
		k,l,m;


/*This if statement check that is the number negative? or check is the number */
/* greater than 99999 (if any of it true returns 0 otherwise returns 1)       */
	if(num<=0 || num>99999)
		{	return 0;}

/*This little loop find out how many digit the number is*/
		for(i=0;pow(10,i)<num;i++);
		
		n = i;

/*This loop take the mod of number each time and assign the value into a x[]*/
		for(a=0;a<n;a++)
		{
			x[a]=num%10;

			num/=10;
		}


/*starting border(top)*/
		for(i=0;i<borderWidth;i++)
		{
			for(j=0;j<(n*7)+(2*borderWidth);j++)
			{
				printf("%c",borderChar);	
			}
			printf("\n");
		}


/*The border with the white spaces(top)*/		
		for(b=0;b<borderWidth;b++)
		{
			printf("%c",borderChar);
		}
		for(c=0;c<n*7;c++)
		{
			printf(" ");				
		}
		for(d=0;d<borderWidth;d++)
		{
			printf("%c",borderChar);
		}

		printf("\n");


/*This loop start to print lines of numbers*/
		for(k=1;k<6;k++)
		{
			for(l=0;l<borderWidth;l++)/*The loop for each lines startingborder*/
			{
				printf("%c",borderChar);
			}

			for(m=n;m>-1;m--)/*Loop for printing each lines of numbers*/
			{
				switch(x[m])/*This case for find which digit is printing*/
				{
					case 0:
						zerofunc(k,borderChar);
						break;
					case 1:
						onefunc(k,borderChar);
						break;
					case 2:
						twofunc(k,borderChar);
						break;
					case 3:
						threefunc(k,borderChar);
						break;
					case 4:
						fourfunc(k,borderChar); 
						break; 
					case 5:	
						fivefunc(k,borderChar);
						break;
					case 6:
						sixfunc(k,borderChar);
						break;
					case 7:
						sevenfunc(k,borderChar);
						break;
					case 8:
						eightfunc(k,borderChar);
						break;
					case 9:
						ninefunc(k,borderChar);
						break;
						/* Calling the helper func with line number    */
						/*   ('k' is shows which line printing)        */
				}
			}

			for(l=0;l<borderWidth;l++)/*The loop for each lines endingborder*/
			{
				printf("%c",borderChar);
			}
			printf("\n");

		}

		/*The border with the white spaces(bottom)*/
		for(b=0;b<borderWidth;b++)
		{
			printf("%c",borderChar);
		}
		for(c=0;c<n*7;c++)
		{						
			printf(" ");      
		}
		for(d=0;d<borderWidth;d++)
		{
			printf("%c",borderChar);
		}

		printf("\n");

		/*ending border(bottom)*/
		for(i=0;i<borderWidth;i++)
		{
			for(j=0;j<(n*7)+(2*borderWidth);j++)
			{
				printf("%c",borderChar);	
			}
			printf("\n");
		}

	
	
	return 1;
}


/*############################################################################*/
/*                             Helper Functions                               */
/*############################################################################*/


/*           Those helper functions all works the same                      */
/*The funcs take line and character as a input parameter and print the lines*/
void zerofunc(int line,char borderChar)
{
	switch(line)
	{
		case 1:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 2:
		case 3:
		case 4:
			printf("  %c %c  ", borderChar,borderChar);
			break;

	}
}



void onefunc(int line,char borderChar)
{
	switch(line)
	{
		case 2:
			printf("  %c%c   ",borderChar,borderChar);
			break;
		case 1:
		case 3:
		case 4:
			printf("   %c   ", borderChar);
			break;
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;

	}
}



void twofunc(int line,char borderChar)
{
	switch(line)
	{
		case 2:
			printf("    %c  ",borderChar);
			break;
		case 4:
			printf("  %c    ", borderChar);
			break;
		case 1:
		case 3:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;

	}
}


void threefunc(int line,char borderChar)
{
	switch(line)
	{
		case 2:
		case 4:
			printf("    %c  ", borderChar);
			break;
		case 1:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 3:
			printf("   %c%c  ",borderChar,borderChar);
			break;

	}
}

void fourfunc(int line,char borderChar)
{
	switch(line)
	{
		case 4:
		case 5:
			printf("    %c  ", borderChar);
			break;
		case 3:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 1:
		case 2:
			printf("  %c %c  ",borderChar,borderChar);
			break;

	}
}

void fivefunc(int line,char borderChar)
{
	switch(line)
	{
		case 2:
			printf("  %c    ", borderChar);
			break;
		case 4:
			printf("    %c  ",borderChar );
			break;
		case 1:
		case 3:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;

	}
}

void sixfunc(int line,char borderChar)
{
	switch(line)
	{
		case 4:
			printf("  %c %c  ", borderChar,borderChar);
			break;
		case 2:
			printf("  %c    ", borderChar);
			break;
		case 1:
		case 3:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;

	}
}


void sevenfunc(int line,char borderChar)
{
	switch(line)
	{
		case 1:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			printf("    %c  ", borderChar);
			break;

	}
}

void eightfunc(int line,char borderChar)
{
	switch(line)
	{
		case 1:
		case 5:
		case 3:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 2:
		case 4:
			printf("  %c %c  ", borderChar,borderChar);
			break;

	}
}


void ninefunc(int line,char borderChar)
{
	switch(line)
	{
		case 1:
		case 3:
		case 5:
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			break;
		case 2:
			printf("  %c %c  ", borderChar,borderChar);
			break;
		case 4:
			printf("    %c  ", borderChar);
			break;

	}
}

/*############################################################################*/
/* 						       END OF part2.c                                 */
/*############################################################################*/








