/*----------------------------------------------------------------------------*/
/* */
/* HW01_131044003_Talha_Oz*/
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 21/02/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*These simple programme will calculate overall grade of the students         */
/*---------------------______Inputs__________---------------------------------*/
/*-Doubles midterms weight,homeworks weight and final exam weight             */
/*-Doubles midterms grade,homeworks grade and final exam grade                */
/*----------------------____Outputs_________----------------------------------*/
/*-Final Grade of the student                                                 */
/**/
/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>

#define PERCENT 100 /*Define constant macro*/

/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main (void)
{
    double midwe1,
           midwe2,
           midwe3,
	       hwwe1,
    	   hwwe2,
	       finalwe,          /*Determine some doubles*/
	       midgrade1,
	       midgrade2,
	       midgrade3,
	       hwgrade1,
	       hwgrade2,
	       fnlgrade;

    double finalgrade1,
           finalgrade2,
           finalgrade3,
           finalgrade;

	
	printf("Please enter the 1.midterm weight: ");

	scanf("%lf", &midwe1);

	printf("Please enter the 2.midterm weight: ");

	scanf("%lf", &midwe2);

	printf("Please enter the 3.midterm weight: ");

	scanf("%lf", &midwe3);

	printf("Please enter the 1.homework weight: ");

	scanf("%lf", &hwwe1);

	printf("Please enter the 2.homework weight: ");

	scanf("%lf", &hwwe2);

	printf("Please enter the final exam weight: "); /*Get the values*/
	                                                  /*from user*/
	scanf("%lf", &finalwe);

	printf("Please enter the 1.midterm grade: ");

	scanf("%lf", &midgrade1);

	printf("Please enter the 2.midterm grade: ");

	scanf("%lf", &midgrade2);

	printf("Please enter the 3.midterm grade: ");

	scanf("%lf", &midgrade3);

	printf("Please enter the 1.homework grade: ");

	scanf("%lf", &hwgrade1);

	printf("Please enter the 2.homework grade: ");

	scanf("%lf", &hwgrade2);

	printf("Please enter the final exam grade: ");

	scanf("%lf", &fnlgrade);

/*############################################################################*/
/*                              Calculate the Final Grade                     */
/*############################################################################*/	


	finalgrade1 = (midwe1/PERCENT)*midgrade1+(midwe2/PERCENT)*midgrade2;
	
	finalgrade2 = (midwe3/PERCENT)*midgrade3+(hwwe1/PERCENT)*hwgrade1;

	finalgrade3 = (hwwe2/PERCENT)*hwgrade2+(finalwe/PERCENT)*fnlgrade;

	finalgrade  = finalgrade1+finalgrade2+finalgrade3;

	


	printf("Your final grade is: %.2f\n", finalgrade);

    return 0;

}



/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/