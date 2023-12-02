#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct LinkedCommand
{
    char single_word[20];
    struct LinkedCommand *next_word;
};

typedef struct LinkedCommand LinkedCommand;

int SizeCommand(struct LinkedCommand *wordlist)
{

    if (wordlist == NULL)
        return 1;
    return 1 + SizeCommand(wordlist->next_word);
}

void PrintCommand(struct LinkedCommand *wordlist)
{
    printf("printing struct\n");
    if (wordlist == NULL)
        return;
    int j = 0;
    printf("TOKEN-> ");
    while (wordlist->single_word[j] != '\0')
    {
        printf("%c", wordlist->single_word[j]);
        j++;
    }
    printf("\n");

    PrintCommand(wordlist->next_word);
}

void BuildLinkedCommand(struct LinkedCommand *wordlist, char *line, int starting_index)
{

    int j, i = starting_index, construct_index = 0;
    int true_index;
    bool first = false;
    while (line[i] != '\0')
    {
        if (line[i] == ' ' || line[i] == '\n')
        {
            if (construct_index == 0)
            {
                if (line[i] == '\n')
                {
                    return;
                }
                else
                {
                    i++;
                    continue;
                }
            }
            else
            {
                if (wordlist == NULL)
                {
                    wordlist = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    first = true;
                    for (j = 0; j < construct_index; j++)
                    {
                        true_index = starting_index + j;
                        wordlist->single_word[j] = line[true_index];
                    }
                    wordlist->single_word[construct_index + 1] = '\0';
                }
                else
                {
                    wordlist->next_word = (LinkedCommand *)malloc(sizeof(LinkedCommand));
                    for (j = 0; j < construct_index; j++)
                    {
                        true_index = starting_index + j;
                        wordlist->next_word->single_word[j] = line[true_index];
                    }
                    wordlist->next_word->single_word[construct_index + 1] = '\0';
                }

                break;
            }
        }
        else
        {
            construct_index++;
            i++;
        }
    }
    if (first)
        BuildLinkedCommand(wordlist, line, starting_index + construct_index + 1);
    else
        BuildLinkedCommand(wordlist->next_word, line, starting_index + construct_index + 1);
}
