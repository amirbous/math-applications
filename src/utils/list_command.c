#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct LinkedCommand
{
    char single_word[30];
    struct LinkedCommand *next_word;
};

typedef struct LinkedCommand LinkedCommand;

char *getWord(struct LinkedCommand * wordlist, int index){

    int i = 0;
    LinkedCommand * tmp = wordlist;
    if (wordlist == NULL) return "";
    
    else 
    {
        while (i < index && tmp != NULL) {
        tmp = tmp->next_word;
        i++;
    }
    }
    if (tmp == NULL) return "";
    return tmp->single_word;



}

int SizeCommand(struct LinkedCommand *wordlist)
{

    if (wordlist == NULL)
        return 0;
    return 1 + SizeCommand(wordlist->next_word);
}

void PrintCommand(struct LinkedCommand *wordlist)
{
    if (wordlist == NULL)
        return;
    int j = 0;
    printf("TOKEN->");
    while (wordlist->single_word[j] != '\0')
    {
        printf("%c", wordlist->single_word[j]);
        j++;
    }
    printf("\n");

    PrintCommand(wordlist->next_word);
}

struct LinkedCommand *BuildLinkedCommand(char *line)
{

    int j, i = 0, construct_index = 0;
    int true_index;
    LinkedCommand *wordlist = NULL, *tmp = NULL;

    while (line[i] != '\0')
    {
        if (line[i] == ' ')
        {
            if (construct_index == 0)
            {
                
                    i++;
            }
            else
            {
                if (wordlist == NULL)
                {
                    wordlist = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    tmp = wordlist;
                }
                else
                {
                    printf("rourour");
                    tmp->next_word = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    tmp = tmp->next_word;
                }
                for (j = 0; j < construct_index; j++)
                {
                    true_index = i - construct_index + j;
                    
                    tmp->single_word[j] = line[true_index];
                    
                }
                tmp->single_word[construct_index] = '\0';
            }
            construct_index = 0;
            i += construct_index + 1;
        }
        else
        {
            construct_index++;
            i++;
        }
    }
    if (construct_index != 0) {
        if (wordlist == NULL)
                {
                    wordlist = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    tmp = wordlist;
                }
                else
                {
                    tmp->next_word = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    tmp = tmp->next_word;
                }
                for (j = 0; j < construct_index; j++)
                {
                    true_index = i - construct_index + j;
                    
                    tmp->single_word[j] = line[true_index];
                    
                }
                tmp->single_word[construct_index] = '\0';
    }
    return wordlist;
}


char * first(struct LinkedCommand * wordlist) {
    
    return wordlist == NULL ? "" : wordlist->single_word;
}