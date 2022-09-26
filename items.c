#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rooms.h"
#include "items.h"

struct ItemNode *allocateItem(char *name) {
    struct ItemNode *item = (struct ItemNode *) malloc(sizeof (struct ItemNode));
    if(item == NULL) {
        printf("malloc of struct item failed. \n");
        exit(0);
    }
    item->next = NULL;
    item->name = name;
    return item;
}

void randItems(struct Room *rooms[], struct ItemNode *items[]) {
    for(int i = 0; i < 6; i++) {
        int roomIndex = rand() % 9;
        if(rooms[roomIndex]->itemList == NULL) {
            rooms[roomIndex]->itemList = items[i];
        }
        else {
            i--;
        }
    }
}

void freeItems(struct ItemNode *items[]) {
    for(int i = 0; i < 6; i++) {
        free(items[i]);
    }
}