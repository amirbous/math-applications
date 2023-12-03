struct LinkedCommand {

    char single_word[30];
    struct LinkedCommand *next_word;

};

char *getWord(struct LinkedCommand * wordlist, int index);
struct LinkedCommand * BuildLinkedCommand(char *line);

void PrintCommand(struct LinkedCommand *wordlist);

int SizeCommand(struct LinkedCommand *wordlist);

char * first(struct LinkedCommand *wordlist);
