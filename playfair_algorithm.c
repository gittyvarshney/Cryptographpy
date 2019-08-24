#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,m;
printf("Please provide the Cipher Text Matrix: \n");
char mat[5][5] = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
for(i=0; i<5; i++)
{
    for(j=0; j<5; j++)
    {
        printf("%c ",mat[i][j]);
    }
        printf("\n");
}
char text[1024];
char refined_text[1024];
int k=0;
printf("Please provide the text: ");
scanf("%s",text);
char temp;
int count =0;
for(i=0;text[i]!='\0';i++)
{

    if(k%2!=0 && temp == text[i])
    {
        refined_text[k] = 'x';
        temp = text[i];
        i--;
    }
    else
    {
        refined_text[k] = text[i];
        temp = text[i];
    }

    k++;
    count++;
}
if(count%2 != 0)
{
    refined_text[k++] = 'x';
    refined_text[k] = '\0';
}
else
{
    refined_text[k] = '\0';
}
printf("refined text: ");
printf("%s",refined_text);
printf("\nCount is: %d \n",count);
char ciphered_text[1024];

for(m=0;refined_text[m]!='\0';m=m+2)
{
    int x1,y1,x2,y2;
    char a = refined_text[m];
    char b = refined_text[m+1];
//checking
int tmp1=1;
int tmp2=1;
for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {

        if(a == mat[i][j])
        {
            x1 = i;
            y1 = j;
            tmp1 = 0;
        }
        else if(b == mat[i][j])
        {
            x2 = i;
            y2 = j;
            tmp2 = 0;
        }

    }
    if(tmp1 ==0 && tmp2 ==0)
    {
        break;
    }
}
if(x1 == x2)
{
    y1= (y1+1)%5;
    y2 = (y2+1)%5;
}
else if(y1 == y2)
{
    x1 = (x1+1)%5;
    x2 = (x2+1)%5;
}
else
{
    temp = y1;
    y1 = y2;
    y2 = temp;
}
ciphered_text[m] = mat[x1][y1];
ciphered_text[m+1] = mat[x2][y2];
}
ciphered_text[m] = '\0';
printf("The Ciphered text is %s",ciphered_text);


return 0;
}
