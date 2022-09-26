#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rooms.h"
#include "items.h"

struct Room * allocateRoom() {
    struct Room *room = (struct Room *) malloc(sizeof(struct Room));
    if(room == NULL) {
        printf("malloc failed\n");
        exit(0);
    }
    room->name = NULL;
    room->North = NULL;
    room->South = NULL;
    room->East = NULL;
    room->West = NULL;
    room->itemList = NULL;
    for(int i = 0; i < NUM_CHARS; i++) {
        room->characters[i] = NULL;
    }
    return room;
}

struct Avatar *allocateAvatar() {
    struct Avatar *avatar = (struct Avatar *) malloc(sizeof(struct Avatar));
    avatar->inventory = NULL;
    avatar->location = NULL;
}

void randRooms(struct Room *rooms[],char *roomNames[]) {
    for(int i = 0; i < 9; i++) {
        int roomIndex = rand() % 9;
        if (rooms[roomIndex]->name == NULL) {
            rooms[roomIndex]->name = roomNames[i];
        }
        else {
            i--;
        }
    }
}

void randCharacters(struct Room *rooms[], char *characters[]) {
    for(int i = 0; i < 5; i++) {
        int roomIndex = rand() % 9;
        if(rooms[roomIndex]->characters[0] == NULL) {
            rooms[roomIndex]->characters[0] = characters[i];
        }
        else {
            i--;
        }
    }
}

void makeGrid(struct Room *rooms[]){
    rooms[0]->East = rooms[1];
    rooms[0]->South = rooms[4];
    rooms[1]->West = rooms[0];
    rooms[1]->East = rooms[2];
    rooms[1]->South = rooms[4];
    rooms[2]->West = rooms[1];
    rooms[2]->South = rooms[5];
    rooms[3]->North = rooms[0];
    rooms[3]->East = rooms[4];
    rooms[3]->South = rooms[6];
    rooms[4]->North = rooms[1];
    rooms[4]->South = rooms[7];
    rooms[4]->East = rooms[5];
    rooms[4]->West = rooms[3];
    rooms[5]->North = rooms[2];
    rooms[5]->West = rooms[4];
    rooms[5]->South = rooms[8];
    rooms[6]->North = rooms[3];
    rooms[6]->East = rooms[7];
    rooms[7]->North = rooms[4];
    rooms[7]->East = rooms[8];
    rooms[7]->West = rooms[6];
    rooms[8]->North = rooms[5];
    rooms[8]->West = rooms[7];
}

struct Answer *randomizeAnswer( char *characters[],char *rooms[],char *items[]) {
    struct Answer *answer = (struct Answer *) malloc(sizeof(struct Answer));

    int charIndex = rand() % 5;
    int roomIndex = rand() % 9;
    int itemIndex = rand() % 6;
    answer->character = characters[charIndex];
    answer->room = rooms[roomIndex];
    answer->item = items[itemIndex];

    return answer;
}

void freeRooms(struct Room *rooms[]) {
    for(int i = 0; i < 9; i++) {
        free(rooms[i]);
    }
}