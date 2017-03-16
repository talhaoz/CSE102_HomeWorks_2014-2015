/*----------------------------------------------------------------------------*/
/* */
/* HW07_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* --------- */
/* Created on 13/04/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/**/
/*-This simple program find is given string palindrome                        */
/*-                                                                           */
/*---------------------______Inputs__________---------------------------------*/
/*-A character String                                                         */
/*-                          */
/*----------------------____Outputs_________----------------------------------*/
/*-Return 1 if the string palindrome,otherwise 0                              */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <ctype.h>

int isPalindrome(char *str);/*Prototype of the func*/



int main()
{

	char str[]="abba";

	int aa;

	aa=isPalindrome(str);

	printf("%d\n", aa);


	return 0;
}

/*This func finds is given string palindrome or not*/

int isPalindrome(char *str)
{
	int i,size;

	size=0;

	/*Loop for calculate the size of string*/
	for(i=0;str[i]!='\0';i++)
	{
		size++;
	}


	/*This recursive func will stop when find the NULL character or size=1*/
	if(str[0]=='\0' || size==1)
	{
		return 1;
	}

	/*Check the each character is it a letter,if it is do this statement
															 otherwise pass it*/
	else if((str[0]>='A'&&str[0]<='Z') || (str[0]>='a'&&str[0]<='z'))
	{
		if((str[size-1]>='A'&&str[size-1]<='Z') || 
										   (str[size-1]>='a'&&str[size-1]<='z'))
		{
			/*Make the whole letters uppercase and check the first and 
														last letters are equal*/
			if(toupper(str[0])==toupper(str[size-1]))
			{
					/*Each time when the func reaches here assign 
												  the last character as a NULL*/
					str[size-1]='\0';
					
					if(isPalindrome(&str[1]))
					{
						return 1;
					}
			}
			else
			{
				return 0;
			}
		}
		/*if the last char is not a letter pass it and make it NULL*/
		else
		{	

			str[size-1]='\0';

			/*And then call the func again,but send zero index because
									 we didnt compare the zero index char yet */
			if(isPalindrome(&str[0]))
			{
				return 1;
			}

		}
		
	}
	/*if the first char is not a letter pass it*/
	else
	{	/*And call the func again with next index*/
		if(isPalindrome(&str[1]))
		{
			return 1;
		}
	}

	return 0;
}


/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/