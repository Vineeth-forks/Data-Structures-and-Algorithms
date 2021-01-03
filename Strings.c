// To declare a character, it should be in single quotes.
// To find the end of the string, one uses the string terminator '\0'.
// For returning a string from a function use 'char*' as the return type.
#include<stdio.h>

int count(char ch[])
{
    int count=0;
    while(ch[count]!='\0')
        count++;
    return count;
}
char* caseInterchange(char ch[])
{
    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]>=65 && ch[i]<=90)
            ch[i] = ch[i] + 32;
        else if(ch[i]>=97 && ch[i]<=122)
            ch[i] = ch[i] - 32;
        else{}
    }   
    return ch;
}
int numberOfWords(char ch[])
{
    int wCounter = 1;
    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]==' ' && ch[i-1]!=' ')
            wCounter++;
    }
    return wCounter;
}
char* reverse(char ch[])
{
    int end = count(ch)-1;
    int temp;
    for(int start=0;start<end;start++,end--)
    {
        temp = ch[start];
        ch[start] = ch[end];
        ch[end] = temp;
    }
    return ch;
}
void duplicateChar(char ch[])
{
    int H[26];
    for(int i=0; ch[i]!='\0'; i++)
    {
        H[ch[i]-97] += 1;
    }
    for(int i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("%c\t%d",i+97,H[i]);
        }
    }
}
int main()
{
    
}