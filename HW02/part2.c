/*----------------------------------------------------------------------------*/
/* */
/* HW02_131044003_Talha_Öz */
/* */
/*                              part2.c                                       */
/* --------- */
/* Created on 28/02/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*This simple programme will calculate the areas and perimeters of 3 shapes   */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers width and heights of rectangle                                    */
/*-Integers width of square and radius of Circle                              */
/*----------------------____Outputs_________----------------------------------*/
/*-Areas and perimeters of the shapes                                         */
/**/
/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/


#include <stdio.h>

#define TWO 2
#define FOUR 4 
#define PI 3.14

int areaOfRectangle(int witdh, int height);
int perimeterOfRectangle(int witdh, int height);

int areaOfSquare(int witdh);
int perimeterOfSquare(int witdh);

double areaOfCircle(int radius);
double perimeterOfCircle(int radius);


/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main(void)
{
	int wofRect,
		hofRect,
		wofSquare,
		rofCircle;

	int areaofRect,
		   areaofSqr,
		   areaofCirc,
		   perofCirc,
		   perofSqr,
		   perofRect;


	printf("Please enter the witdh of the rectangle:");
	scanf("%d", &wofRect);

	printf("Please enter the height of the rectangle:");
	scanf("%d", &hofRect);

	areaofRect=areaOfRectangle(wofRect,hofRect);
	perofRect=perimeterOfRectangle(wofRect,hofRect);

	printf("The area of the rectangle is: %d\n", areaofRect);
	printf("The perimeter of the rectangle is: %d\n", perofRect);

	

	printf("Please enter the witdh of the square:");
	scanf("%d", &wofSquare);

	areaofSqr=areaOfSquare(wofSquare);
	perofSqr=perimeterOfSquare(wofSquare);

	printf("The area of the square is: %d\n", areaofSqr);
	printf("The perimeter of the square is: %d\n", perofSqr);



	printf("Please enter the radius of the circle:");
	scanf("%d", &rofCircle);

	areaofCirc=areaOfCircle(rofCircle);
	perofCirc=perimeterOfCircle(rofCircle);

	printf("The area of the circle is: %d\n", areaofCirc);
	printf("The perimeter of the circle is: %d\n", perofCirc);



	return 0;
}
/*############################################################################*/
/*                                 Helper Functions                           */
/*############################################################################*/

/*Get the width and height from user and calculate the area of rectangle*/

int areaOfRectangle(int witdh, int height)
{

	return(witdh*height);
}

/*Get the width and height from user and calculate the perimeter of rectangle*/

int perimeterOfRectangle(int witdh, int height)
{

	return(TWO*(witdh+height));
}

/*Get the width  from user and calculate the area of square*/
int areaOfSquare(int witdh)
{
	return(witdh*witdh);
}
/*Get the width  from user and calculate the perimeter of square*/

int perimeterOfSquare(int witdh)
{
	return(FOUR*witdh);
}

/*Get the radius from user and calculate the area of circle*/

double areaOfCircle(int radius)
{
	return(PI*radius*radius);
}

/*Get the radius from user and calculate the perimeter of circle*/

double perimeterOfCircle(int radius)
{
	return(TWO*PI*radius);
}


/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/