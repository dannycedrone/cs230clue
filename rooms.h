#include <stdio.h>
#include <stdlib.h>

#define NUM_CHARS 20

struct Room {
   char *name;
   struct Room *North;
   struct Room *South;
   struct Room *East;
   struct Room *West;
   struct ItemNode *itemList;
   char *characters[NUM_CHARS];
};

struct Room *allocateRoom();

struct Avatar {
   struct ItemNode *inventory;
   struct Room *location;
};

struct Avatar *allocateAvatar();

void randRooms(struct Room *rooms[],char *roomNames[]);
void randCharacters(struct Room *rooms[],char *characters[]);

void makeGrid(struct Room *rooms[]);

struct Answer {
    char *character;
    char *room;
    char *item;
};

struct Answer *randomizeAnswer( char *characters[], char *rooms[], char *items[]);

void freeRooms(struct Room *rooms[]);
