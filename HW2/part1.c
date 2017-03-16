/*----------------------------------------------------------------------------*/
/* */
/* HW02_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 28/02/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*This simple programme will calculate final grade of 3 students              */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers midterms weight,homeworks weight and final exam weight            */
/*-Integers midterms grade,homeworks grade and final exam grade               */
/*----------------------____Outputs_________----------------------------------*/
/*-Final Grade of the student                                                 */
/**/
/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>


#define HUND 100

void calculateLastGrade();

/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main()
{


	calculateLastGrade();

	calculateLastGrade();

	calculateLastGrade();


	return 0;
}

/*############################################################################*/
/*                                 Helper Function                            */
/*############################################################################*/

/*Get the values from user and calculate the fina grade*/

void calculateLastGrade()
{
	int midWe,
		hwWe,
		fnlWe,
		midGrade,
		hwGrade,
		fnlGrade;

	double res;

	printf("Please enter the 1. midterm weight:");
	scanf("%d", &midWe);

	printf("Please enter the 1. homework weight:");
	scanf("%d", &hwWe);

	printf("Please enter the final exam weight:");
	scanf("%d", &fnlWe);

	printf("Please enter the 1. midterm grade:");
	scanf("%d", &midGrade);

	printf("Please enter the 1. homework grade:");
	scanf("%d", &hwGrade);

	printf("Please enter the final exam grade:");
	scanf("%d", &fnlGrade);

	res=((midWe*midGrade)+(hwWe*hwGrade)+(fnlWe*fnlGrade))/HUND;

	printf("Your final grade is: %.6f\n", res);


}

/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/