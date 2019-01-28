#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "room.h"

struct Booking {
    char book_id[12];
    char stay_days[12];
    char total_people[12];
    char customer_id[12];
    char room_id[12];
    char check_in[12];
    char check_out[12];
};
struct getBooking {
    struct Booking booking[999];
};

int b = 0;

struct getBooking getBookingData() {

    struct getBooking get;
    FILE *file = fopen("./data/booking.txt", "r");

    char temp[50];
    b = 0;

    fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", temp, temp, temp, temp, temp, temp, temp);

    while(fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", get.booking[b].book_id, get.booking[b].stay_days, get.booking[b].total_people, get.booking[b].customer_id, get.booking[b].room_id, get.booking[b].check_in, get.booking[b].check_out) != EOF) {
        b++;
    }
    fclose(file);
    return get;
}
void displayBooking() {

    struct getBooking displayBooking = getBookingData();

    printf("Book ID\t\tStay\t\tTotal People\t\tCustomer ID\t\tRoom ID\t\tCheck-In\t\tCheck-Out\n");
    
    for(int j = 0; j< b; j++) {
        printf("%s\t\t%s\t\t%s\t\t\t%s\t\t\t%s\t\t%s\t\t%s\n", 
        displayBooking.booking[j].book_id, 
        displayBooking.booking[j].stay_days,
        displayBooking.booking[j].total_people,
        displayBooking.booking[j].customer_id,
        displayBooking.booking[j].room_id,
        displayBooking.booking[j].check_in,
        displayBooking.booking[j].check_out
        );
    }

    displayLine();
    printf("1. Exit\n");
    displayLine();
    printf("Enter a number: ");
    int loop = 1;
    while(loop) {
        int option;
        scanf("%d", &option);
        if(option == 1) {
            loop = 0;
        } else {
            printf("Invalid choice.: ");
        }
    }
    
}

void displayRoomAvailability() {
}

