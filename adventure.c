#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rooms.h"
#include "items.h"

// char *names[9] = {"kitchen", "dining room", "hall", "ballroom", "billiard room", "conservatory", "lounge", "library", "study"};
// char *items[6] = {"candlestick", "dagger", "lead pipe", "revolver", "rope", "wrench"};
// char *chars[5] = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "The Reverend Green", "Mrs. Peacock", "Professor Plum"};

int main() {
    srand(time(0));
    char *characters[] = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "The Reverend Green", "Mrs.Peacock"};
    char *roomNames[] = {"kitchen", "dining room", "hall", "conservatory", "ballroom", "billiard room", "library", "lounge", "study"};
    char *itemNames[] = {"candlestick", "dagger", "lead pipe", "revolver", "rope", "wrench"};
    struct Avatar *avatar = allocateAvatar();
    struct Answer *answer = randomizeAnswer(characters, roomNames, itemNames);

    struct Room *rooms[9];
    rooms[0] = allocateRoom();
    rooms[1] = allocateRoom();
    rooms[2] = allocateRoom();
    rooms[3] = allocateRoom();
    rooms[4] = allocateRoom();
    rooms[5] = allocateRoom();
    rooms[6] = allocateRoom();
    rooms[7] = allocateRoom();
    rooms[8] = allocateRoom();

    struct ItemNode *items[6];
    items[0] = allocateItem("candlestick");
    items[1] = allocateItem("dagger");
    items[2] = allocateItem("lead pipe");
    items[3] = allocateItem("revolver");
    items[4] = allocateItem("rope");
    items[5] = allocateItem("wrench");

    makeGrid(rooms);
    randRooms(rooms, roomNames);
    randCharacters(rooms, characters);
    randItems(rooms, items);
    avatar->location = rooms[rand()%9];
    while(1) {
        char input[NUM_CHARS];
        printf("Please enter a command or write 'help' to get a list of commands: ");
        fgets(input, NUM_CHARS, stdin);
        while (strlen(input) > 0 && (input[strlen(input) - 1] == '\n' || input[strlen(input) - 1] == ' ')) {
            input[strlen(input) - 1] = '\0';
        }
        if(strcmp(input,"help") == 0) {
            printf("Choose one of the available commands: \n1) List \n2) Look \n3) Go \n4) Take \n5) Drop \n6) Inventory \n7) Clue\n");
        }
        else if(strcmp(input,"list") == 0) {
            printf("Items: \n");
            for(int i = 0; i < 6; i++) {
                printf("%s\n", itemNames[i]);
            }
            printf("Characters: \n");
            for(int i = 0; i < 5; i++) {
                printf("%s\n", characters[i]);
            }
            printf("Rooms: \n");
            for(int i = 0; i < 9; i++) {
                printf("%s\n", roomNames[i]);
            }
        }
        else if(strcmp(input,"look") == 0) {
            printf("Current room: %s\n", avatar->location->name);
            if(avatar->location->North != NULL) {
                printf("To the north: %s\n", avatar->location->North->name);
            }
            if(avatar->location->South != NULL) {
                printf("To the south: %s\n", avatar->location->South->name);
            }
            if(avatar->location->East != NULL) {
                printf("To the east: %s\n", avatar->location->East->name);
            }
            if(avatar->location->West != NULL) {
                printf("To the West: %s\n", avatar->location->West->name);
            }
            printf("Items in the room: \n");
            if(avatar->location->itemList != NULL) {
                //go through linked list in room
                struct ItemNode *temp = avatar->location->itemList;
                while(temp != NULL) {
                    printf("%s\n", temp->name);
                    temp = temp->next;
                }
            }
            else {
                printf("No items in the room.\n");
            }
            printf("Characters in the room: \n");
            if(avatar->location->characters[0] != NULL) {
                int i = 0;
                while(avatar->location->characters[i] != NULL) {
                    printf("%s\n", avatar->location->characters[i]);
                    i++;
                }
            }
            else {
                printf("No characters in the room.\n");
            }
        }
        else if(strcmp(input,"take") == 0) {
            if(avatar->location->itemList != NULL) {
                printf("Which item would you like to take? Valid items:\n");
                struct ItemNode *temp = allocateItem(avatar->location->itemList->name);
                temp->next = avatar->location->itemList->next;
                while(temp != NULL) {
                    printf("%s\n", avatar->location->itemList->name);
                    temp = temp->next;
                }
            }
            //make sure to free items after taking
            else {
                printf("There are no items in this room.\n");
                continue;
            }

            char newString[NUM_CHARS];
            char buffer[NUM_CHARS];
            fgets(buffer, NUM_CHARS, stdin);
            for(int i = 0; i < NUM_CHARS; i++) {
                newString[i] = *(buffer + i);
            }

            // char item[NUM_CHARS];
            // fgets(item, NUM_CHARS, stdin);
            for(int i = 0;i < 6; i++) {
                if(strcmp(items[i]->name, newString) == 0) {
                    if(i == 0) {
                        items[i]->next = avatar->inventory;
                        break;
                    }
                    else {
                        items[i-1]->next = items[i+1];
                        items[i]->next = avatar->inventory;
                        break;
                    }
                }
            }

            //find room itemNode with next->name = input
            //avatar->inventory
            //set itemNode->next = itemNode->next->next
            

            // struct ItemNode *temp = avatar->location->itemList;
            // while(temp->next != NULL && strcmp(temp->name, input) =! 0) {
            //     temp = temp->next;
            // }

            
            
        }
        else if(strcmp(input,"drop") == 0) {

            // if(strcmp(input, "candlestick") == 0) {
            //     items[0]->next = avatar->location->itemList;
            // }
            // else if(strcmp(input, "dagger") == 0) {
            //     items[1]->next = avatar->location->itemList;
            // }
            // else if(strcmp(input, "lead pipe") == 0) {
            //     items[2]->next = avatar->location->itemList;
            // }
            // else if(strcmp(input, "revolver") == 0) {
            //     items[3]->next = avatar->location->itemList;
            // }
            // else if(strcmp(input, "rope") == 0) {
            //     items[4]->next = avatar->location->itemList;
            // }
            // else if(strcmp(input, "wrench") == 0) {
            //     items[5]->next = avatar->location->itemList;
            // }
        }
        else if(strcmp(input,"go") == 0) {
            char direction[NUM_CHARS];
            printf("Which direction would you like to go? ");
            fgets(direction, NUM_CHARS, stdin);
            if(strcmp(direction,"north\n") == 0 && avatar->location->North != NULL) {
                avatar->location = avatar->location->North;
            }
            else if(strcmp(direction,"south\n") == 0 && avatar->location->South != NULL) {
                avatar->location = avatar->location->South;
            }
            else if(strcmp(direction,"east\n") == 0 && avatar->location->East != NULL) {
                avatar->location = avatar->location->East;
            }
            else if(strcmp(direction,"west\n") == 0 && avatar->location->West != NULL) {
                avatar->location = avatar->location->West;
            }
            else {
                printf("Not a valid direction. Try a different command.\n");
            }
        }
        else if(strcmp(input,"inventory") == 0) {
            if(avatar->inventory != NULL) {
                struct ItemNode *temp = allocateItem(avatar->location->itemList->name);
                temp->next = avatar->inventory->next;
                while(temp != NULL) {
                    printf("%s", temp->name);
                    temp = temp->next;
                }
                free(temp);
            }
            else {
                printf("Inventory is empty.\n");
            }
            
        }
        else if(strcmp(input,"clue") == 0) {
            break;
        }
        
    }

    freeItems(items);
    freeRooms(rooms);
    free(avatar);
    free(answer);
    return 0;
}



