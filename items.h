#include <stdio.h>
#include <stdlib.h>

struct ItemNode {
    char *name;
    struct ItemNode *next;
};

struct ItemNode *allocateItem(char *name);

void randItems(struct Room *rooms[], struct ItemNode *items[]);

void freeItems(struct ItemNode *items[]);

