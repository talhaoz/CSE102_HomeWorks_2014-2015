/*----------------------------------------------------------------------------*/
/* */
/* HW06_131044003_Talha_Oz */
/* */
/*                              part3.c                                       */
/* --------- */
/* Created on 09/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program calculates the occurrences of a substring in           */
/*-                                                            a given string */
/*---------------------______Inputs__________---------------------------------*/
/*-String                                                                     */
/*-Substring                                                                  */
/*----------------------____Outputs_________----------------------------------*/
/*-Returning value is how many time the substring showed up                   */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <string.h>


int count(char *str,char *substr);


/*This func calculates the substing occurrences and return it    */
int count(char *str,char *substr)
{
	int length1,length2,i,j,k,check,counter;
	
	/*Finding both strings size*/
	length1=strlen(str);

	length2=strlen(substr);

	counter=0;
	

	for(i=0;i<length1;i++)
	{
		check=0;
		j=i+2;
		if(str[i]==substr[0])
		{
			for(k=2;k<length2;k+=2)
			{
				if(str[j]==substr[k])
				{
					check++;
					j+=2;
				}
			}
			if(check==(int)length2/2)
			{
				counter++;
			}
		}

	}
	return counter;

}

/*############################################################################*/
/* 						       END OF part3.c                                 */
/*############################################################################*/