#include <stdio.h>
#include<stdlib.h>

#include "display.h"
#include "booking.h"
#include "room.h"
#include "customer.h"

void loopRoomOperation() {
    int loopRoom = 1;
    while(loopRoom) {

        displayHeader();
        displayRoomOperation();

        int roomInput;
        scanf("%d", &roomInput);

        switch(roomInput) {
            case 1:
                displayHeader();
                displayRoom();
                break;
            case 2:
                displayHeader();
                displayAddRoom();
                break;
            case 3:
                displayHeader();
                displayUpdateRoom();
                break;
            case 4:
                displayHeader();
                displayDeleteRoom();
                break;
            case 5:
                loopRoom = 0;
                break;
            default:
                loopRoom = 0;
        }
    }

}

void loopCustomerOperation() {
    int loopCustomer = 1;
    while(loopCustomer) {

        displayHeader();
        displayCustomerOperation();

        int customerInput;
        scanf("%d", &customerInput);

        switch(customerInput) {
            case 1:
                displayHeader();
                displayCustomer();
                break;
            case 2:
                displayHeader();
                displayAddCustomer();
                break;
            case 3:
                displayHeader();
                displayUpdateCustomer();
                break;
            case 4:
                displayHeader();
                displayDeleteCustomer();
                break;
            case 5:
                loopCustomer = 0;
                break;
            default:
                loopCustomer = 0;
        }
    }

}

void loopBookingOperation() {
    int loopBooking = 1;
    while(loopBooking) {

        displayHeader();
        displayBookingOperation();

        int bookingInput;
        scanf("%d", &bookingInput);

        switch(bookingInput) {
            case 1:
                displayHeader();
                displayBooking();
                break;
            case 2:
                displayHeader();

                break;
            case 3:
                displayHeader();

                break;
            case 4:
                displayHeader();
                break;
            case 5:
                loopBooking = 0;
                break;
            default:
                loopBooking = 0;
        }
    }

}
int main(void) {

    

    int loop = 1;
    while(loop) {

        displayHeader();
        displayMainMenu();

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                displayHeader();
                loopRoomOperation();
                break;
            case 2:
                displayHeader();
                loopCustomerOperation();
                break;
            case 3:
                displayHeader();
                loopBookingOperation();
                break;
            case 4:
                loop = 0;
                break;
            default:
                loop = 0;
        }
    }
    
}
