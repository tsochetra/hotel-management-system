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
struct getRoom {
    struct Room room[999];
};

int i = 0;

struct getRoom getRoomData() {

    struct getRoom get;
    FILE *file = fopen("./data/rooms.txt", "r");
    char room_id[12];
    char room_type[12];
    char room_price[12];
    char room_max_people[12];
    char room_status[12];
    i = 0;

    fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", room_id, room_type, room_price, room_max_people, room_status);

    while(fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", get.room[i].room_id, room_type, room_price, room_max_people, get.room[i].room_status) != EOF) {
        get.room[i].room_type = atoi(room_type);
        get.room[i].room_price = atoi(room_price);
        get.room[i].room_max_people = atoi(room_max_people);
        i++;
    }
    fclose(file);
    return get;
}

void displayRoom() {
    struct getRoom displayRoom = getRoomData();

    printf("Room ID\t\tType\t\t\tRoom Price\t\tRoom Max People\t\tRoom Status\n");
    
    for(int j = 0; j< i; j++) {
        if(strcmp(displayRoom.room[j].room_status, "deleted") == 0) {
            continue;
        }
        printf("%s\t\t%d Bed(s)\t\t%d $\t\t\t%d People\t\t%s\n", 
        displayRoom.room[j].room_id,
        displayRoom.room[j].room_type,
        displayRoom.room[j].room_price,
        displayRoom.room[j].room_max_people,
        displayRoom.room[j].room_status
        );
    }

}

void displayAddRoom() {

    struct getRoom get = getRoomData();

    char room_id[12];
    int room_type;
    int room_price;
    int room_max_people;
    char room_status[12];
    
    strcpy(room_status, "active");

    
    printf("Enter room ID: ");
    scanf("%s", room_id);

    for(int j = 0; j<i; j++) {
        if(strcmp(get.room[j].room_id, room_id) == 0 && strcmp(get.room[j].room_status, "active") == 0) {
            printf("Duplicate Room ID.\n");
            return;
        }
    }

    printf("Enter room type: ");
    scanf("%d", &room_type);
    printf("Enter room price: ");
    scanf("%d", &room_price);
    printf("Enter room maximum people: ");
    scanf("%d", &room_max_people);


    FILE *file = fopen("./data/rooms.txt", "a+");
    
    fprintf(file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", room_id, room_type, room_price, room_max_people, room_status);
    fclose(file);

}

void displayDeleteRoom() {

    //get all rows from text data
    struct getRoom get = getRoomData();


    char delete_room_id[12];

    printf("Enter room ID: ");
    scanf("%s", delete_room_id);

    for(int j = 0; j< i; j++) {
        if(strcmp(get.room[j].room_id, delete_room_id) == 0) {
            strcpy(get.room[j].room_status, "deleted");
        }
    }

    FILE *write_file = fopen("./data/rooms.txt", "w");
    fprintf(write_file, "\nroom_id\t\t\troom_type\t\troom_price\t\troom_max\t\troom_status");
    for(int j = 0; j< i; j++) {
        fprintf(write_file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", get.room[j].room_id, get.room[j].room_type, get.room[j].room_price, get.room[j].room_max_people, get.room[j].room_status);
    }
    fclose(write_file);

    
}

void displayUpdateRoom() {
    
    struct getRoom get = getRoomData();

    char update_room_id[12];

    printf("Enter room ID: ");
    scanf("%s", update_room_id);

    for(int j = 0; j<i; j++) {
        if(strcmp(get.room[j].room_id, update_room_id) == 0 && strcmp(get.room[j].room_status, "active") == 0) {
            printf("Room ID: \t\t%s\n", get.room[j].room_id);
            printf("Room Type: \t\t%d Bed(s)\n", get.room[j].room_type);
            printf("Room Price: \t\t%d $\n", get.room[j].room_price);
            printf("Room Max People: \t%d People\n", get.room[j].room_max_people);
            printf("Room Status: \t\t%s\n", get.room[j].room_status);

            int room_type;
            int room_price;
            int room_max_people;

            printf("Enter room type: ");
            scanf("%d", &room_type);
            printf("Enter room price: ");
            scanf("%d", &room_price);
            printf("Enter room maximum people: ");
            scanf("%d", &room_max_people);

            for(int j = 0; j<i; j++) {
                if(strcmp(get.room[j].room_id, update_room_id) == 0 && strcmp(get.room[j].room_status, "active") == 0) {
                    get.room[j].room_type = room_type;
                    get.room[j].room_price = room_price;
                    get.room[j].room_max_people = room_max_people;
                }
            }

            FILE *write_file = fopen("./data/rooms.txt", "w");
            fprintf(write_file, "\nroom_id\t\t\troom_type\t\troom_price\t\troom_max\t\troom_status");
            for(int k = 0; k< i; k++) {
                fprintf(write_file, "\n%s\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%s", get.room[k].room_id, get.room[k].room_type, get.room[k].room_price, get.room[k].room_max_people, get.room[k].room_status);
            }
            fclose(write_file);
            return;
        }
    }

    printf("Room ID is not existed.\n");

}

