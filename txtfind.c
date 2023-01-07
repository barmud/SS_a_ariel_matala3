#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30

//take a line from standart input and put it inside s , the process made by one char at a time.
int getlineMine(char s[])
{
    char* temp =s;
    int counter = 0;
    char ch = getc(stdin);
    while (ch!='\n' && !feof(stdin))
    {
        temp[counter] = ch;
        counter++;
        ch = getc(stdin);
    }
    return counter;
}

//take a word from standart input and put it inside w , the process made by one char at a time.
int getword(char w[])
{
    int counter = 0;
    char* temp = w; 
    char ch = fgetc(stdin);
    while ( ch =='\n' || ch =='\t' || ch =='\r' || ch ==' ')
    {
        ch = fgetc(stdin);
    }
    while (ch!='\n' && ch!='\t' && ch!='\r' && ch!=' ' && ch!='\0' && !feof(stdin))
    {
        temp[counter] = ch;
        counter++;
        ch = fgetc(stdin);
    }
    return counter;
}
//check if str2 is substring of str1
int substring(char* str1,char* str2)
{
    char* str1C = str1;
    char* str2C = str2;
    while (*str1C!='\0' && *str2C!='\0')
    {
        if (*str1C != *str2C)
        {
            str1++;
            str1C = str1;
            str2C = str2;
        }
        else{
            str1C++;
            str2C++;
        }
    }
    return (*str2C == '\0');
    
}
//check if it possible to convert string s to t by erase n chars
int similar(char *s,char *t,int n)
{
    char* str1C = s;
    char* str2C = t;
    int counter = 0;
    while (*str1C!='\0' || *str2C!='\0')
    {  
    if (*str1C!='\0' && *str2C!='\0' && *str1C == *str2C)
    {
        str1C++;
        str2C++;
    }
    else if(*str1C!='\0')
    {
        str1C++;
        counter++;
    }
    else{
        str2C++;
        counter++;
    }
    }
    if (counter == n)
    {
        return 1;
    }
    return 0;
}
//print all the lines that contain the word str
void print_lines(char* str)
{
    char* s;
    s = (char*)calloc(LINE,sizeof(char));
    if (s == NULL)
    {
        return;
    }
    bzero(s,sizeof(char)*LINE);
    int count = getlineMine(s);
    while (count>0 || !feof(stdin))
    {
        if (substring(s,str) == 1)
        {
            printf("%s\n",s);
        } 
        bzero(s,sizeof(char)*LINE);
        count = getlineMine(s);
    }
    free(s);
}
//print all the words that similliar to str in all chars except one char at most.
void print_similar_words(char *str)
{
    char *w;
    w = (char*)calloc(WORD,sizeof(char));
    if (w == NULL)
    {
        return;
    }
    int count = getword(w);
    while (count > 0)
    {
        if (similar(w,str,0) || similar(w,str,1))
        {
            printf("%s\n", w);
        }
        bzero(w, sizeof(char)*WORD);
        count = getword(w);
    }
    free(w);
}
//analayzing the firstline which contain the searching word and which function to use
//if func = a : print lines include searching word , if func = b : print words similiar to searching word 
int main(void)
{
    char* firstline = (char*)calloc(LINE,sizeof(char));
    if (firstline == NULL)
    {
        return 1;
    }

    fgets(firstline,LINE*sizeof(char),stdin);

    char* search = (char*)calloc(WORD,sizeof(char));
    if (search == NULL)
    {
        return 1;
    }

    char func;
    bzero(&func,sizeof(char));
    int counter = 0;
    while (firstline[counter]!=' ')
    {
        search[counter] = firstline[counter];
        counter++;
    }
    while (firstline[counter]!='\n')
    {
        func = firstline[counter];
        counter++;
    }
    
    free(firstline);
    getlineMine(NULL); // the second line is empty. so we skip the next line in stdin.
    
    if (func == 'a')
    {
        print_lines(search);
    }
    if (func == 'b')
    {
        print_similar_words(search);
    }
    free(search);
    return 0;
}



