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

void PrintCommand(struct LinkedCommand *wordlist){
    int j = 0;
    while (wordlist->single_word[j] != '\0') {

        printf("%c", wordlist->single_word[j]);
        j++;
    }
    printf("\n");
    if (wordlist->next_word == NULL) return;
    PrintCommand(wordlist->next_word);

}

void BuildLinkedCommand(struct LinkedCommand *wordlist, char *line, int starting_index)
{
    wordlist->next_word = NULL;
    int j, i = starting_index, construct_index = 0;
    int true_index;

    while (line[i] != '\0')
    {
        if (line[i] == ' ' || line[i] == '\n')
        {
            if (construct_index == 0)
            {
                i++;
            }
            else{ 
                for (j = 0; j < construct_index; j++)
                {
                    true_index = starting_index + j;
                    wordlist->single_word[j] = line[true_index];
                }
                wordlist->single_word[starting_index + i + 1] = '\0';
                i++;
                break;
            }
        }
        else
        {

            construct_index++;
        }

        i++;
    }
    if (construct_index == 0)
        return;
    LinkedCommand *next = (LinkedCommand *)malloc(sizeof(LinkedCommand));
    wordlist->next_word = next;
    BuildLinkedCommand(next, line, starting_index + i);
}
