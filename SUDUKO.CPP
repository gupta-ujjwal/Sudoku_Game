#include<stdio.h>
#include<conio.h>
#include<dos.h>
void show(char matrix[9][9])
{
int i,j;
for(j=0;j<13;j++)
printf("--");
printf("\n");
for(i=0;i<9;i++)
{printf("| ");
for(j=0;j<9;j++)
{
printf("%c ",matrix[i][j]);
if(j==2||j==5||j==8)
printf("| ");
}printf("\n");
if(i==2||i==5||i==8)
{
for(j=0;j<13;j++)
printf("--");
printf("\n");
}
}
}
 void swap(char matrix[9][9],char sample[9][9])
 {
 int i,j;
 for(i=0;i<9;i++)
 {
 for(j=0;j<9;j++)
 matrix[i][j]=sample[i][j];
 }
 }
int check_row(char matrix[9][9],int row,char val)
{int i;
    for(i=0;i<9;i++)
    {
	if(val==matrix[row][i])
	    return 0;
    }
    return 1;
}

int check_col(char matrix[9][9],int col,char val)
{int i;
    for(i=0;i<9;i++)
    {
	if(val==matrix[i][col])
	    return 0;
    }
    return 1;
}

int check_box(char matrix[9][9],int row,int col,char val)
{
    int n1,n2,i,j;
    for(i=0;i<3;i++)
    {
	if((3*i==row)||((3*i+1)==row)||((3*i+2)==row))
	    n1=i;
	if((3*i==col)||((3*i+1)==col)||((3*i+2)==col))
	    n2=i;
    }
  for(i=(3*n1);i<=(3*n1+2);i++)
    {
	for(j=(3*n2);j<=(3*n2+2);j++)
	{
	    if(matrix[i][j]==val)
		return 0;
	}
    }
    return 1;
}

int check(char matrix[9][9])
{int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
if(matrix[i][j]==' ');
return 1;
}
}
return 0;
}

main()
{
clrscr();
int row,col,check1,check2,check3,level;/*check1= checking row
check2= checking col
check 3= checking box*/
char matrix[9][9];
char in;
printf("---------------------------WELCOME TO THE SUDOKO-------------------------------\n");
printf("\nEnter 1 for beginner , 2 for moderate and 3 for hard\n");
scanf("%d",&level);
clrscr();
if(level==1)
{
      char matrix1[9][9] ={{'2', ' ', ' ', '8', ' ', '4', ' ', ' ', '6'},
			  {' ', ' ', '6', ' ', ' ', ' ', '5', ' ', ' '},
			  {' ', '7', '4', ' ', ' ', ' ', '9', '2', ' '},
			  {'3', ' ', ' ', ' ', '4', ' ', ' ', ' ', '7'},
			  {' ', ' ', ' ', '3', ' ', '5', ' ', ' ', ' '},
			  {'4', ' ', ' ', ' ', '6', ' ', ' ', ' ', '9'},
			  {' ', '1', '9', ' ', ' ', ' ', '7', '4', ' '},
			  {' ', ' ', '8', ' ', ' ', ' ', '2', ' ', ' '},
			  {'5', ' ', ' ', '6', ' ', '8', ' ', ' ', '1'}};
swap(matrix,matrix1);
}
else if(level==2)
{     char matrix2[9][9] = {{' ', ' ', ' ', ' ', ' ', '5', ' ', ' ', '4'},
			  {' ', '2', '3', '4', ' ', '6', ' ', '5', ' '},
			  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '6', ' '},
			  {'9', ' ', '4', ' ', ' ', ' ', ' ', '7', ' '},
			  {' ', ' ', ' ', '5', '6', '7', ' ', ' ', ' '},
			  {' ', '5', ' ', ' ', ' ', ' ', '8', ' ', '3'},
			  {' ', '4', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			  {' ', '3', ' ', '7', ' ', '1', '9', '8', ' '},
			  {'2', ' ', ' ', '8', ' ', ' ', ' ', ' ', '7'}};
swap(matrix,matrix2);
}
else if(level==3)
{
     char matrix3[9][9] = {{' ', '9', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			  {' ', ' ', ' ', '2', ' ', ' ', '6', ' ', ' '},
			  {' ', '5', ' ', ' ', '7', ' ', '4', '8', '3'},
			  {' ', ' ', '9', ' ', '5', ' ', ' ', ' ', '8'},
			  {' ', '8', ' ', '3', ' ', '4', ' ', '1', ' '},
			  {'3', ' ', ' ', ' ', '8', ' ', '5', ' ', ' '},
			  {'8', '7', '3', ' ', '1', ' ', ' ', '6', ' '},
			  {' ', ' ', '6', ' ', ' ', '2', ' ', ' ', ' '},
			  {' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', ' '}};
swap(matrix,matrix3);
}
    show(matrix);
while(check(matrix)==1)
{
printf("Enter -1 to stop\n");
printf("Enter the position you want to enter value(for example to enter a value between 3 and 6 enter 1 then 2)\n");
scanf("%d",&row);
if(row==-1)
break;
scanf("%d",&col);
row--;
col--;
printf("Enter the value to be printed\n");
scanf(" %c",&in);
check1=check_row(matrix,row,in);
check2=check_col(matrix,col,in);
check3=check_box(matrix,row,col,in);

if(check1==0||check2==0||check3==0)
{
printf("wrong input\a");
sleep(2);
clrscr();
show(matrix);
}
else
{
matrix[row][col]=in;
clrscr();
show(matrix);
}

}
getch();
}

