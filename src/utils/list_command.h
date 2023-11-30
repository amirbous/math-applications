struct LinkedCommand {

    char single_word[20];
    struct LinkedCommand *next_word;

};

void BuildLinkedCommand(struct LinkedCommand *wordlist, char *line, int starting_index);

void PrintCommand(struct LinkedCommand *wordlist);