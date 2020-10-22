#include <stdio.h>

void length()
{
    char name[] = "Weeknd";
    int i = 0;
    while(name[i]!='\0'){
        i++;
    }
    printf("Length of the string %d",i);
}

void charCase()
{
    char arr[] = "WkdSlLdIDld";
    int i;
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i]>=65&&arr[i]<=90)
        {
            arr[i] += 32;
        }
        if(arr[i]>=97&&arr[i]<=122)
        {
            arr[i] -= 32;
        }
    }
}

void vowelConsonant()
{
    char arr[] = "Such is the time to do it";
    int i;int vCounter = 0, cCounter = 0;
    for(i = 0;arr[i]!='\0';i++)
    {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U')
        {
            vCounter++;
        }
        else if((arr[i]>=65&&arr[i]<=90)||(arr[i]>=97&&arr[i]<=122))
        {
            cCounter++;
        }
        else {}
    }
}

void wordCounter()
{
    char arr[] = "Such is the time to do it";
    int i;
    int wCounter = 1;
    for(i= 0;arr[i]!='\0';i++)
    {
        if(arr[i]==' '&&arr[i-1]!=' ')
            wCounter++;
    }

}

void valid()
{
    char arr[] = "asdfasdf324";
    int valid = 1;
    int i;
    for(i= 0;arr[i]!='\0';i++)
    {
        if(!(arr[i]>=65&&arr[i]<=90)&&!(arr[i]>=97&&arr[i]<=122)&&!(arr[i]>=48&&arr[i]<=57))
        {
            valid = -1;
        }
    }
}

void reverse()
{
    char arr[] = "python";
    int i,j;
    int temp;
    for(i = 0;arr[i]!='\0';i++)
    {}
    i = i - 1;
    for(j = 0;j<i;j++,i--)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    printf("%s",arr);
}

void duplicate()
{
    char arr[] = "finding";
    int H[26],i;
    for(i=0;arr[i]!='\0';i++)
    {
        H[arr[i]-97] += 1; 
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
            printf("%c %d",i+97,H[i]);
    }
}