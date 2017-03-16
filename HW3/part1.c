/*----------------------------------------------------------------------------*/
/* */
/* HW03_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 08/03/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program checks whether the given number is an odd,             */
/*-        a factorial or a narcissistic number                               */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers get an integer number from user                                   */
/*-Integers midterms grade,homeworks grade and final exam grade               */
/*----------------------____Outputs_________----------------------------------*/
/*-The num is an odd number , narcissistic or a factorial number              */
/*----------------------------------------------------------------------------*/


/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <math.h>

void narcisNumFunc(int num);

void facFunc(int num);    /*Prototypes of the functions*/

void oddNumFunc(int num);


/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main(void)
{
	int intnum,
		propnum;

	char yn;

	printf("*****************************************************\n");
	printf("*                     WELCOME!                      *\n");
	printf("*    This program checks whether the given number   *\n");
	printf("*  is an odd, a factorial or a narcissistic number  *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");

	do
	{
		printf("\nPlease enter a positive integer : ");
		scanf("%d", &intnum);

		if(intnum>0)
		{
			printf("Which property would like to check?\n");
			printf("1)Odd number\n2)Factorial number\n3)Narcissistic number\n");
			printf("Please enter(1/2/3): ");
			scanf("%d", &propnum);

			switch(propnum)
			{
				case 1:
						oddNumFunc(intnum);
						break;
				case 2:
						facFunc(intnum);
						break;
				case 3:
						narcisNumFunc(intnum);
						break;
			}

		}
		else
		{
			printf("The entered number is not positive.\n");
		}

		printf("Do you want to continue (y/n)? ");
		scanf(" %c", &yn);

	}while(yn=='y'||yn=='Y');

	printf("Good bye !\n");

	return 0;

}

/*############################################################################*/
/*                                 Helper Functions                           */
/*############################################################################*/



/*Check the number is a narcissistic or not*/
void narcisNumFunc(int num)
{
	int decade,
		power,
		res,
		res1,
		res2,
		reslast;

	int usernum;

	usernum=num;/*assign the num into another integer because we will reassign*/
							                                /*the num integer*/
	
	while(num!=0) /*Take the int number and find how many digit the number is*/
	{
		num/=10;

		decade ++;
	}

	num=usernum;
	
	power=decade;

	
	res=num%10;

	reslast=pow(res,power);

	decade-=1;
	
	while(decade!=0)/*start loop and take the power of each digit and sum all*/
	{

		num=num/10;

		res1=num%10;

		res2=pow(res1,power);

		reslast=reslast+res2;

		decade --;


	}

		if(reslast==usernum)
		{
			printf("%d is narcissistic number !\n", usernum);
		}
		else
		{
			printf("%d is not a narcissistic number !\n", usernum);
		}

		return;
}

/*Check the number is a factorial or not*/
void facFunc(int num)
{
	int fac,
		i;

	i=2;
	fac=1;


/*loop from one and multiply until find the number or greater than the number*/
	while((num!=fac)&&(num>fac))
	{
		fac*=i;

		i++;
	}

	if(fac==num)
	{
		printf("%d is a factorial number !\n", num);
	}
	else
	{
		printf("%d is not a factorial number !\n", num);
	}

	return;
}

/*Check the number is an odd number or not*/

void oddNumFunc(int num)
{
	if((num%2)!=0)/*if the number cant divide by two the number is odd*/
	{
		printf("%d is an odd number !\n", num);
	}
	else
	{
		printf("%d is not an odd number !\n", num);
	}

	return;
}

/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/
 