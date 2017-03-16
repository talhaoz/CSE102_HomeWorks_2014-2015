/*----------------------------------------------------------------------------*/
/* */
/* HW04_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 23/03/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program calculates the sine and cosine value                   */
/*-        with using the taylor series                                       */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers= get an positive integer number for degree                        */
/*-Integers= get an positive integer number for n                             */
/*----------------------____Outputs_________----------------------------------*/
/*-sine(x) and cosine(x)  value via taylor series                             */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>

#define PI 3.14  	/*Define some macros to easy to read programme*/

#define ONEEIGHTY 180

/*--------Fucntion Prototypes------------*/
void getInputs(int *degree, int *n,int *exit);	

double sine(int degree, int n);

double cosine(int degree, int n);


int main()
{
	int degreee,nn,exitt;
	double sinxx,cosxx;

	getInputs(&degreee,&nn,&exitt);

		if(exitt==0)
		{
			sinxx=sine(degreee,nn);
			cosxx=cosine(degreee,nn);

			if(degreee<0)
			{
				degreee=-degreee;
			printf("sin(%d) where n is %d = %.4f\n", degreee,nn,sinxx);
			printf("cos(%d) where n is %d = %.4f\n", degreee,nn,cosxx);
			}
			else
			{
			printf("sin(%d) where n is %d = %.4f\n", degreee,nn,sinxx);
			printf("cos(%d) where n is %d = %.4f\n", degreee,nn,cosxx);
			}
		}
		else
		{
			return -1;
		}
	

	return 0;
}

/* Getinputs function that take a degree and n value from user */
/*				  and if  user enter 'e' character             */
/*				  returns 1 otherwise returns 0                */
void getInputs(int *degree, int *n, int *exit)
{
	int status;

	char temp;
	
	status=scanf("%d %d", degree, n);

	if(status==0)
	{
		scanf("%c",&temp);

		if(temp=='E' || temp=='e')
		{
			*exit=1;
		}
		else
		{
			*exit=0;
		}

	}
	else
	{
		*exit=0;
	}
	
	return;
}



/*      the sine func take the degree and n value as a input parameter    */
/* and put them into taylor series and then calculate the sine(x) value  */

double sine(int degree, int n)
{
	int i,j,k;
	double fac,xpow;
						/*Declaration of some integers and doubles*/
	double x;
	double sinx;

/*This condition check the degree,if degree greater than 180, */
/*			  assign the degree as negative                 */

	degree=degree%360;

	if(degree<=180 && degree>=0)
	{
		degree=degree;
	}
	else if(degree==360)
	{
		degree=(degree-180);
	}
	else
	{
		degree=-(degree-180);
	}

/*This assigment for turning degree to the radian format*/
	x=(double)degree*(double)(PI/ONEEIGHTY);


	sinx=0.0;

/*These loops calculating power and fac, and then put them in the formula*/
	for(i=0;i<n;i++)
	{	

		fac=1.0;

		for(j=1;j<=2*i+1;j++)
		{
			fac*=j;

		}

		xpow=1.0;
		for(k=1;k<=2*i+1;k++)
		{
			xpow*=x;
		}

/*This statement check the i,and decide the sum should be negative or positive*/	
		if(i%2==0.0)
		{
			sinx+=xpow/fac;
		}
		else if(i%2!=0.0)
		{
			sinx+=-xpow/fac;
		}

	}
	return sinx;
}


/*      the cosine func take the degree and n value as a input parameter   */
/* and put them into taylor series and then calculate the cosine(x) value  */

double cosine(int degree, int n)
{
	int i,j,k;
	double fac,xpow;
						/*Declaration of some integers and doubles*/
	double x;
	double cosx;


/*This condition check the degree,if degree greater than 180, */
/*			  assign the degree as negative                 */

	degree=degree%360;

	if(degree<=180 && degree>=0)
	{
		degree=degree;
	}
	else if(degree==360)
	{
		degree=(degree-360);
	}
	else
	{
		degree=-(degree-180);
	}

/*This assigment for turning degree to the radian format*/

	x=(double)degree*(double)(PI/ONEEIGHTY);
	
	
	cosx=0.0;

/*These loops calculating power and fac, and then put them in the formula*/
	for(i=0;i<n;i++)
	{	

		fac=1.0;
		for(j=1;j<=2*i;j++)
		{
			fac*=j;

		}

		xpow=1;
		for(k=1;k<=2*i;k++)
		{
			xpow*=x;			
		}	

/*This statement check the i,and decide the sum should be negative or positive*/		
		if(i%2==0)
		{
			cosx+=xpow/fac;
		}
		else if(i%2!=0)
		{
			cosx+=-xpow/fac;
		}
		else
		{
			cosx+=xpow/fac;
		}

	}


	return cosx;
}

/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/
