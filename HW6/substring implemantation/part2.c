/*----------------------------------------------------------------------------*/
/* */
/* HW06_131044003_Talha_Oz */
/* */
/*                              part2.c                                       */
/* --------- */
/* Created on 09/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program will find the substing in a given another string        /
/*-                                                                           */
/*---------------------______Inputs__________---------------------------------*/
/*-Searching string                                                           */
/*-Substring                          */
/*----------------------____Outputs_________----------------------------------*/
/*-An adress of where substring found first    */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <string.h>


char *matcher(char *haystack,char *needle);

int main()
{
	char str1[]="lorem ipsum dolor sit amet";

	char str2[]="m ";

	*matcher(str1,str2);

	return 0;
}

/*This func will find where substring first showed up and return its adress*/
char *matcher(char *haystack,char *needle)
{
	int length1,length2,i,j,k,check;

	/*Finding both strings size*/
	length1=strlen(haystack);

	length2=strlen(needle);


/*This statement only works substring smaller than given string*/	
	if((length2<=length1)&&length1!=0&&length2!=0)
	{
		for(i=0;i<length1;i++)
		{
			check=0;
			j=i+2;
			if(haystack[i]==needle[0])
			{
				if(length2<=2)
				{
					return &haystack[i];
				}
				for(k=2;k<length2;k+=2)
				{
					if(haystack[j]==needle[k])
					{
						check++;
						j+=2;
					}
				}
				if(check==(int)length2/2)
				{

					return &haystack[i];
		
				}
			}

		}
	}
	/*if there is no match return null */
	return NULL;

}

/*############################################################################*/
/* 						       END OF part2.c                                 */
/*############################################################################*/
