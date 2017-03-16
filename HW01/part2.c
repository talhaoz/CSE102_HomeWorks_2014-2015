/*----------------------------------------------------------------------------*/
/* */
/* HW01_131044003_Talha_Oz*/
/* */
/*                              part2.c                                       */
/* --------- */
/* Created on 21/02/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*These simple programme will calculate that how many days you have lived     */
/*---------------------______Inputs__________---------------------------------*/
/*-Integers currentdate and  birthdate                                        */
/*-Integers new planet years,months and hours                                 */
/*----------------------____Outputs_________----------------------------------*/
/*-How many days you have lived                                               */
/*-how you re going to be old if you re in a another planet                   */


/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>

#define DAYSOFYEAR 365
#define DAYOFMONTH 30   /*Define some constant macro*/
#define HOURSOFADAY 24

/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main(void)
{

    int currentyear,
        currentmonth,
        currentday,
        birthyear,
        birthmonth,
        birthday,
        daysoflived,
        daysoflived1,
        daysoflived2;

    int hoursofday,             /*Determine some integers*/
        daysofmonth,
        monthsofyear;

    int yearsoflived,
        hoursofayear,
        daysoflivedplanet,
        monthsoflived1,
        monthsoflived,
        lastdaysoflived;

/*############################################################################*/
/*                  Get the current  date from user                           */
/*############################################################################*/
	
	printf("Please enter the current date.\n");

	printf("Year: ");

	scanf("%d", &currentyear);

	printf("Month: ");

	scanf("%d", &currentmonth);

	printf("Day: ");

	scanf("%d", &currentday);

/*############################################################################*/
/*             Get the birthdate from user                                    */
/*############################################################################*/

	printf("Please enter your birthdate.\n");

	printf("Year: ");

	scanf("%d", &birthyear);

	printf("Month: ");

	scanf("%d", &birthmonth);

	printf("Day: ");

	scanf("%d", &birthday);


	daysoflived1=(currentyear-birthyear)*DAYSOFYEAR;

	daysoflived2=(currentmonth-birthmonth)*DAYOFMONTH+(currentday-birthday);

	daysoflived=daysoflived1+daysoflived2;


/*############################################################################*/
/*                   Get the user that time of another planet                 */
/*############################################################################*/

	printf("You have lived %d days.\n", daysoflived);

	printf("Please enter about time of another planet:\n");

	printf("How many hours is a day? ");

	scanf("%d", &hoursofday);

	printf("How many days is a month? ");

	scanf("%d", &daysofmonth);

	printf("How many months is a year? ");

	scanf("%d", &monthsofyear);

/*############################################################################*/
/*               Calculate the how long time the user lived                   */
/*############################################################################*/

	hoursofayear=monthsofyear*daysofmonth;

	daysoflivedplanet=(daysoflived*HOURSOFADAY)/hoursofday;

	yearsoflived=daysoflivedplanet/hoursofayear;

	monthsoflived1=daysoflivedplanet-(yearsoflived*hoursofayear);

	monthsoflived=monthsoflived1/daysofmonth;

	lastdaysoflived=monthsoflived1-(monthsoflived*daysofmonth);

	printf("If you lived in a planet where a day is %d hours,", hoursofday);

	printf(" a month is %d days", daysofmonth);

	printf(" and a year is %d months:", monthsofyear);

	printf(" you were %d years, ",  yearsoflived);

	printf(" %d months and %d days old.\n", monthsoflived,lastdaysoflived);

	return 0;
}

/*###########################################################################*/
/* 						       END OF part2.c                                */
/*###########################################################################*/