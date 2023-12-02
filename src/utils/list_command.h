struct LinkedCommand {

    char single_word[30];
    struct LinkedCommand *next_word;

};

struct LinkedCommand * BuildLinkedCommand(char *line);

void PrintCommand(struct LinkedCommand *wordlist);

int SizeCommand(struct LinkedCommand *wordlist);

char * first(struct LinkedCommand *wordlist);
