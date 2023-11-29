struct Linked_command {

    char* single_word;
    struct Linked_command *next_word;

};

struct Linked_command * parseLine(char *line);