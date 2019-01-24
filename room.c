#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    char room_id[12];
    int room_type;
    int room_price;
    int room_max_people;
    char room_status[12];
};
int i = 0;

struct Room *getRoomData() {
    struct Room room[999];
    FILE *file = fopen("./data/rooms.txt", "r");
    char room_id[12];
    char room_type[12];
    char room_price[12];
    char room_max_people[12];
    char room_status[12];

    char delete_room_id[12];

    

    fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", room_id, room_type, room_price, room_max_people, room_status);

    while(fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", room[i].room_id, room_type, room_price, room_max_people, room[i].room_status) != EOF) {
        room[i].room_type = atoi(room_type);
        room[i].room_price = atoi(room_price);
        room[i].room_max_people = atoi(room_max_people);
        i++;
    }
    fclose(file);
    return room;
}

void displayRoom() {

    struct Room *room = getRoomData();

    printf("Room ID\t\tType\t\t\tRoom Price\t\tRoom Max People\t\tRoom Status\n");
    
    for(int j = 0; j< i; j++) {
        if(strcmp(room[j].room_status, "deleted") == 0) {
            continue;
        }
        printf("%s\t\t%d Bed(s)\t\t%d $\t\t\t%d People\t\t%s\n", 
        room[j].room_id,
        room[j].room_type,
        room[j].room_price,
        room[j].room_max_people,
        room[j].room_status
        );
    }

}

void displayAddRoom() {

    struct Room *room = getRoomData();

    int error = 0;

    char room_id[12];
    int room_type;
    int room_price;
    int room_max_people;
    char room_status[12];
    
    strcpy(room_status, "active");

    
    printf("Enter room ID: ");
    scanf("%s", room_id);
    printf("Enter room type: ");
    scanf("%d", &room_type);
    printf("Enter room price: ");
    scanf("%d", &room_price);
    printf("Enter room maximum people: ");
    scanf("%d", &room_max_people);

    FILE *file = fopen("./data/rooms.txt", "a+");
    
    for(int j = 0; j<i; j++) {
        if(strcmp(room[j].room_id, room_id) == 0) {
            error = 1;
        }
    }

    if(error == 0) {
        fprintf(file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", room_id, room_type, room_price, room_max_people, room_status);
    } else {
        printf("Duplicate Room ID.\n");
    }
    fclose(file);

}

void displayDeleteRoom() {
    struct Room *room = getRoomData();

    char delete_room_id[12];

    printf("Enter room ID: ");
    scanf("%s", delete_room_id);

    for(int j = 0; j< i; j++) {
        if(strcmp(room[j].room_id, delete_room_id) == 0) {
            strcpy(room[j].room_status, "deleted");
        }
    }

    FILE *write_file = fopen("./data/rooms.txt", "w");
    fprintf(write_file, "\nroom_id\t\t\troom_type\t\troom_price\t\troom_max\t\troom_status");
    for(int j = 0; j< i; j++) {
        fprintf(write_file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", room[j].room_id, room[j].room_type, room[j].room_price, room[j].room_max_people, room[j].room_status);
    }
    fclose(write_file);

    
}

void displayUpdateRoom() {
    
    struct Room *room = getRoomData();


    // for(int j = 0; j< i; j++) {
    //     if(strcmp(room[j].room_id, delete_room_id) == 0) {
    //         strcpy(room[j].room_status, "deleted");
    //     }
    // }

    // FILE *write_file = fopen("./data/rooms.txt", "w");
    // fprintf(write_file, "\nroom_id\t\t\troom_type\t\troom_price\t\troom_max\t\troom_status");
    // for(int j = 0; j< i; j++) {
    //     fprintf(write_file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", room[j].room_id, room[j].room_type, room[j].room_price, room[j].room_max_people, room[j].room_status);
    // }
    // fclose(write_file);
}

int main() {
    // printf("1. Check room availability\n");
    // printf("2. Make a booking\n");
    // printf("3. Check-in\n");
    // printf("4. Check-out\n");
    // printf("5. Cancel a booking\n");
    // printf("6. Back to main menu\n");
    // printf("Enter a number: \n");
    
    displayRoom();
    displayAddRoom();
}

