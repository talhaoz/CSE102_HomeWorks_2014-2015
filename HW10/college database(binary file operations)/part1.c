/*----------------------------------------------------------------------------*/
/* */
/* HW010_131044003_Talha_Oz */
/* */
/*                              part1.c                                       */
/* ---------------------------------------------------------------------------*/
/* Created on 05/05/2016 by Talha_OZ */ 
/*____________________________________________________________________________*/
/*Description*/
/*This program is a simple database that takes informations from a binary file*/
/*        and put them in order and write them in a text file                 */
/*---------------------______Inputs__________---------------------------------*/
/*-A binary file */
/*----------------------____Outputs_________----------------------------------*/
/*-Output text file                                                           */
/*----------------------------------------------------------------------------*/



/*############################################################################*/
/*                                 Includes                                   */
/*############################################################################*/

#include <stdio.h>
#include <string.h>


#define MAXNUM 20
#define MAXLETTER 30

typedef struct{
	int id;
	char name[30];
	char surname[30];
} studentT;

typedef struct{
	char degree[30];
	int id;
	char name[30];
	char surname[30];
} lecturersT;
						             /*Define some struct types for easyness*/
typedef struct{
	int code;
	char name[30];
	int id;
} lecturesT;

typedef struct{
	char className[30];
	char day[30];
	int beginTime;
	int duraTime;
	int code;
} scheduleT;

typedef struct{
	int id;
	int code;
} coursesT;


/*Prototypes of the helper functions*/
void lecLec(lecturesT *l,int numOfl,lecturersT *lrr,int numOflrr,coursesT *c,
														 int numOfc,FILE *outp);

void stuLec(studentT *s,int numOfs,coursesT *c,int numOfc,FILE *outp);

void stuDay(studentT *s,int numOfs,coursesT *c,int numOfc,scheduleT *sc,
														int numOfsc,FILE *outp);


/*############################################################################*/
/*                                 Main Function                              */
/*############################################################################*/

int main(void)
{
	studentT s[MAXNUM];
	lecturersT lrr[MAXNUM];
	lecturesT l[MAXNUM];	/*Declaration of struct arrays*/
	scheduleT sc[MAXNUM];	/*We will read binary file into the struct arrays*/
	coursesT c[MAXNUM];

	int numOfs,
		numOflrr,
		numOfl,				/*Use them during read binary file for */
		numOfsc,			   /*how many input will be entered*/
		numOfc;


	FILE *inp,
		 *outp;


	inp=fopen("input.dat","rb");      /*Open the binary file*/
	outp=fopen("output.txt","w");		/*Open the output file*/


	/*if binary file couldnt open print an error*/
	if(inp==NULL)
	{
		printf("FILE OPEN ERROR !\n");

		return 0;
	}

	/*Read the binary file into the structs*/
	fread(&numOfs,sizeof(int),1,inp);
	fread(s,sizeof(studentT),numOfs,inp);

	fread(&numOflrr,sizeof(int),1,inp);
	fread(lrr,sizeof(lecturersT),numOflrr,inp);

	fread(&numOfl,sizeof(int),1,inp);
	fread(l,sizeof(lecturesT),numOfl,inp);

	fread(&numOfsc,sizeof(int),1,inp);
	fread(sc,sizeof(scheduleT),numOfsc,inp);

	fread(&numOfc,sizeof(int),1,inp);
	fread(c,sizeof(coursesT),numOfc,inp);


	/*Cal the functions*/
	lecLec(l,numOfl,lrr,numOflrr,c,numOfc,outp);

	fprintf(outp,"\n\n");

	stuLec(s,numOfs,c,numOfc,outp);

	fprintf(outp,"\n\n");

	stuDay(s,numOfs,c,numOfc,sc,numOfsc,outp);


	fclose(inp); /*Close both files*/
	fclose(outp);

	return 0;
}

/*############################################################################*/
/*                                 Helper Functions                           */
/*############################################################################*/



/*This func will print the Lecture-Lecturer part with using some algorithm*/
void lecLec(lecturesT *l,int numOfl,lecturersT *lrr,int numOflrr,coursesT *c,
														  int numOfc,FILE *outp)
{

	int i,j,k;

	int idle,indexLrr,tookCourse;

	fprintf(outp, "Lecture-Lecturer\n");

	/*Loop for print Lecture and lecturer according to lecture number*/
	for(i=0; i<numOfl; i++)
	{
		idle=l[i].id;  /*Take id of lecturer*/

		for(j=0; j<numOflrr; j++)
		{
			if(idle==lrr[j].id)		/*Compare the lecturer id for find the 
											lecturer index in lecturer struct*/
			{
				indexLrr=j;
			}
		}

		tookCourse=0;
		for(k=0; k<numOfc; k++)/*Loop for find the how many student took the  */
		{														 /*	   course */
			if(l[i].code==c[k].code)
			{
				tookCourse++;
			}
		}

		/*Print the data into output file*/
		fprintf(outp, "%s", l[i].name);
		fprintf(outp, " %s %s", lrr[indexLrr].name,lrr[indexLrr].surname);
		fprintf(outp, " %d\n", tookCourse);

	}
	return;
}

/*This func will print the Student-Lecture part with using some algorithm*/
void stuLec(studentT *s,int numOfs,coursesT *c,int numOfc,FILE *outp)
{
	int i,j,count;
	

	fprintf(outp, "Student-Lecture\n");

	/*loop for print the data according to number of student*/
	for(i=0; i<numOfs; i++)
	{
		fprintf(outp, "%d", s[i].id);
		fprintf(outp, " %s", s[i].name);
		fprintf(outp, " %s", s[i].surname);

		count=0;
		for(j=0; j<numOfc; j++)/*Loop for find the number of taken courses*/
		{
			if(s[i].id==c[j].id)
			{
				count++;
			}
		}

		fprintf(outp, " %d\n", count);
	}

	return;
}

/*This func will print the Student-Day part with using some algorithm*/
void stuDay(studentT *s,int numOfs,coursesT *c,int numOfc,scheduleT *sc,
														int numOfsc,FILE *outp)
{	
	int i,j,k,l,m,n,index;

	char str[MAXNUM][MAXLETTER];  /*Use this string array for read the days*/

	/*Make the all characters NUll */
	for(i=0; i<MAXNUM; i++)
	{
		str[i][0]='\0';
	}

	fprintf(outp, "Student-Day\n");

	/*Loop will works every time for each student*/
	for(i=0; i<numOfs; i++)
	{	
		index=0;
		for(j=0; j<numOfc; j++)/*Loop works for reach every courses*/
		{
			if(s[i].id==c[j].id)/*Try to find student id in the courses struct*/
			{
				for(k=0; k<numOfsc; k++)/*Works for reach every schedule index*/
				{
					if(c[j].code==sc[k].code)/*Try to find course code in     */ 
					{										 /*schedule struct*/
						strcpy(str[index],sc[k].day);
						index++;/*Copy the day into our string*/
					}
				}
			}
		}

		/*In these loops we will compare the days that we have took*/
		/*Because there can be same days and we will delete it*/
		for(l=0; l<numOfc; l++)
		{
			for(m=l+1; m<numOfc; m++)
			{
				if(strcmp(str[l],str[m])==0)/*compare the days each others*/
				{
					str[m][0]='\0';/*if there re same days ,delete one*/
				}

			}
		}

		fprintf(outp, "%d", s[i].id);
		fprintf(outp, " %s", s[i].name);
		fprintf(outp, " %s ", s[i].surname);

		/*Loop for print the days*/
		for(n=0; n<index; n++)
		{
			if(str[n]!='\0')
			{
				fprintf(outp, "%s", str[n]);

			  /*we re printg a comma between the days but not in the last one*/
				if(n!=index-1)
				{
					fprintf(outp, ",");
				}
			}
		}

		fprintf(outp,"\n");/*Print new line to write a new student*/

	}

	return;
}

/*############################################################################*/
/* 						       END OF part1.c                                 */
/*############################################################################*/