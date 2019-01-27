#include <stdio.h>
#include <stdlib.h>

#define PINK  "\x1B[35m"

void displayHeader() {
    printf("%s\n", PINK);
    printf("clear");
    printf(
    " _   _       _       _    ___  ___                                                  _       _____           _                 \n"
    "| | | |     | |     | |   |  \\/  |                                                 | |     /  ___|         | |                \n"
    "| |_| | ___ | |_ ___| |   | .  . | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_    \\ `--. _   _ ___| |_ ___ _ __ ___  \n"
    "|  _  |/ _ \\| __/ _ \\ |   | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|    `--. \\ | | / __| __/ _ \\ '_ ` _ \\ \n"
    "| | | | (_) | ||  __/ |   | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_    /\\__/ / |_| \\__ \\ ||  __/ | | | | |\n"
    "\\_| |_/\\___/ \\__\\___|_|   \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|   \\____/ \\__, |___/\\__\\___|_| |_| |_|\n"
    "                                                     __/ |                                         __/ |                      \n"
    "                                                    |___/                                         |___/                       \n"
    "                                    _    _      _                            _                                                \n"
    "                                   | |  | |    | |                          | |                                               \n"
    "                                   | |  | | ___| | ___ ___  _ __ ___   ___  | |                                               \n"
    "                                   | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |                                               \n"
    "                                   \\  /\\  /  __/ | (_| (_) | | | | | |  __/ |_|                                               \n"
    "                                    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)                                               \n"
    "____________________________________________________________________________________________________________________________________\n");
}

void displayMainMenu() {
    printf("Please choose an operation: \n\n");
    printf("1. Room Operation\n");
    printf("2. Customer Operation\n");
    printf("3. Booking Operation\n");
    printf("4. Exit Application\n\n");
    printf("Enter a number: \n");
}
void displayRoomOperation() {
    printf("Please choose an operation: \n\n");
    printf("1. View all rooms\n");
    printf("2. Add more room\n");
    printf("3. Update room information\n");
    printf("4. Delete room\n");
    printf("5. Back to main menu\n\n");
    printf("Enter a number: \n");
}

void displayCustomerOperation() {
    printf("Please choose an operation: \n\n");
    printf("1. View all customers\n");
    printf("2. Add more customer\n");
    printf("3. Update customer information\n");
    printf("4. Delete customer\n");
    printf("5. Back to main menu\n\n");
    printf("Enter a number: \n");
}

void displayBookingOperation() {
    printf("Please choose an operation: \n\n");
    printf("1. Check room availability\n");
    printf("2. Make a booking\n");
    printf("3. Check-in\n");
    printf("4. Check-out\n");
    printf("5. Cancel a booking\n");
    printf("6. Back to main menu\n");
    printf("Enter a number: \n");
}