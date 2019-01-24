#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Booking {
    int book_id;
    int stay_days;
    int total_people;
    int customer_id;
    char room_id[12];
    int check_in;
    int check_out;
};

void displayBooking() {

    struct Booking booking[100];
    FILE *file = fopen("./data/booking.txt", "r");
    char temp[100];
    char book_id[12];
    char stay_days[12];
    char total_people[12];
    char customer_id[12];
    char room_id[12];
    char check_in[12];
    char check_out[12];

    int i = 0;

    fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", book_id, stay_days, total_people, customer_id, room_id, check_in, check_out);

    while(fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", book_id, stay_days, total_people, customer_id, booking[i].room_id, check_in, check_out) != EOF) {
        booking[i].book_id = atoi(book_id);
        booking[i].stay_days = atoi(stay_days);
        booking[i].total_people = atoi(total_people);
        booking[i].customer_id = atoi(customer_id);
        booking[i].check_in = atoi(check_in);
        booking[i].check_out = atoi(check_out);
        i++;
    }

    printf("Book ID\t\tStay\t\tTotal People\t\tCustomer ID\t\tRoom ID\t\tCheck-In\t\tCheck-Out\n");
    
    for(int j = 0; j< i; j++) {
        printf("%d\t\t%d\t\t%d\t\t\t%d\t\t\t%s\t\t%d\t\t%d\n", 
        booking[j].book_id, 
        booking[j].stay_days,
        booking[j].total_people,
        booking[j].customer_id,
        booking[j].room_id,
        booking[j].check_in,
        booking[j].check_out
        );
    }

    fclose(file);

}

int main() {
    // printf("1. Check room availability\n");
    // printf("2. Make a booking\n");
    // printf("3. Check-in\n");
    // printf("4. Check-out\n");
    // printf("5. Cancel a booking\n");
    // printf("6. Back to main menu\n");
    // printf("Enter a number: \n");
    
    displayBooking();
}

