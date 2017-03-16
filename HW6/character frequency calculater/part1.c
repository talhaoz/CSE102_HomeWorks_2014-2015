/*----------------------------------------------------------------------------*/
/* */
/* HW06_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 09/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program calculates the character frequency                     */
/*-                                                                           */
/*---------------------______Inputs__________---------------------------------*/
/*-String                                                                     */
/*-                          */
/*----------------------____Outputs_________----------------------------------*/
/*-An array that have the alphabetic,numeric and other chaacter frequency     */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <ctype.h>



void freq(char *str,int *fr);



int main()
{
	char str[]="aaabCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |";

	int fr[37],i;

	char aa;

	freq(str,fr);

	for(i=0;i<37;i++)
	{
		aa=(char)('A'+i);
		printf("%c => %d\n", aa,fr[i]);
	}

	return 0;
}

/*This little func calculate the frequency of the given string and put them 
														into the integer array*/
void freq(char *str,int *fr)
{
    int i,a,aa;
    
    char lel;
    
    for(i=0;i<37;i++)
    {
        fr[i]=0;
    }
    
    for(i=0;str[i]!='\0';i++)
    { /*This statement only work for alphabetic characters*/
        if(((int)(str[i])<=90&&(int)(str[i])>=65) || 
        								((int)(str[i])<=122&&(int)(str[i])>=97))
        {
           
            lel = toupper(str[i]);
            aa = (int)lel - (int)'A';
            fr[aa]++;
            
        }
        /*This statement only work for numeric characters*/
        else if((int)(str[i])<=57 && (int)(str[i])>=48)
        {
            
            
                    a=str[i]-'0';
                    fr[a+26]++;
            
        } /*This statement only work for other characters*/
        else if(str[i]<48 || (str[i]>57&&str[i]<65) ||
        								  (str[i]>90&&str[i]<97) || str[i]>122)
        {	
            fr[36]++;

        }
        
        
    }
    
}

/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/