/*----------------------------------------------------------------------------*/
/* */
/* HW07_131044003_Talha_Oz */
/* */
/*                              part2.c                                       */
/* --------- */
/* Created on 13/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-Simulating hitting an air hockey disk and check will be goal or not         */
/*-                                                                           */
/*---------------------______Inputs__________---------------------------------*/
/*-Doubles=wallwidth,wallheight,angle,ballradius,ballcenterx,goalwidth        */
/*-                          */
/*----------------------____Outputs_________----------------------------------*/
/*-if the disc will be goal return 1, otherwise return 0                      */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_REFLECTION_ANGLE 175
#define MIN_REFLECTION_ANGLE 5

#define PI 3.14159265

/*This func makes random numbers between -5 and +5*/
int randNumber(int angle)
{
	int aa;

	srand(angle);
	aa=rand()%11;

	if(aa<=10&&aa>=5)
	{
		aa=-(aa-5);
	}

	return aa;
}

int reflection(int angle);

int kickDisc(double wallWidth, double wallHeight, double ballCenterX,
			 double kickAngle, double ballRadius, double goalWidth);




int main()
{
	int aa;

	aa=kickDisc(10,26,2,45,1,2);

	printf("%d\n", aa);

	return 0;
}

/*This func call the random number func and add the rand to the current angle*/
int reflection(int angle)
{
	int refAngle;

	refAngle=angle+randNumber(angle);
	/*if the reflection angle greater than 175,assign it to the 175 degree*/
	if(refAngle>MAX_REFLECTION_ANGLE)
	{
		refAngle=MAX_REFLECTION_ANGLE;
	}
	/*if the reflection angle smaller than 5,assign it to the 5 degree*/
	else if(refAngle<MIN_REFLECTION_ANGLE)
	{
		refAngle=MIN_REFLECTION_ANGLE;
	}

	return refAngle;
}

/*This recursive func simulate the hitting disc and check goal or not*/	
int kickDisc(double wallWidth, double wallHeight, double ballCenterX,
			 double kickAngle, double ballRadius, double goalWidth)
{

	double w,h,dc,r,a,gw,checkH,checkGoal1,checkGoal2;

	int rr;

	w=wallWidth;
	h=wallHeight;
	dc=ballCenterX;	/*Assign the inputs smaller characters for easyness*/
	a=kickAngle;
	r=ballRadius;
	gw=goalWidth;

	if(a>=180)
	{
		a=a-180;
	}

	a=a*(PI/180);/*Turn the angle to the radian*/


	/*Each time it will calculate the rest of height*/
	checkH=h-fabs(((w-r-dc)/cos(a))*sin(a));

	/*calculating the goal posts*/
	checkGoal1=w/2-gw/2;
	checkGoal2=w/2+gw/2;

	/*if the rest of height smaller than zero do this statement, 
	so we arrive the last point we should use our last height for check the goal
	(We even subtract the radius because 
								if the ball touch the goal line,its goal too)*/
	if(checkH-r<0)
	{	
		
		/*First check: is the ball bigger than goal width return 0*/
		if(2*r>gw)
		{
			return 0;
		}

		/*Checking is the ball between the goal posts*/
		if(fabs(((h/sin(a))*cos(a))>=checkGoal1 &&
										   fabs((h/sin(a))*cos(a))<=checkGoal2))
		{	

			return 1;
		}

		
		else
		{
			return 0;
		}

	}
	/*if the rest of height greater than zero,the ball hasnt arrived yet*/
	else
	{	/*So te ball should keep moving(We call the function)*/

		

		/*New func values:change height with rest of height*/
		/*Add ange a random number between -5 to +5 degrees*/
		/*Change the dc because we dont need it anymore,but now our radius*2 */
		rr=kickDisc(wallWidth,checkH,ballRadius,
									reflection(kickAngle),ballRadius,goalWidth);
	}

	return rr;
}

/*############################################################################*/
/* 						       END OF part2.c                                 */
/*############################################################################*/