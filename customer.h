#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char c_ID[100];
    char c_name[100];
    char c_nationality[100];
    char c_num[100];
    char c_sex[50];
    char c_status[100];
};
struct getCustomer {
    struct Customer customer[999];
};

int a = 0;

struct getCustomer getCustomerData() {

    struct getCustomer get;
    FILE *file = fopen("./data/customers.txt", "r");

    a = 0;
    char temp[50];

    fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", temp, temp, temp, temp, temp, temp);

    while(fscanf(file, "%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s", get.customer[a].c_ID, get.customer[a].c_name, get.customer[a].c_nationality, get.customer[a].c_num, get.customer[a].c_sex, get.customer[a].c_status) != EOF) {
        a++;
    }

    fclose(file);
    return get;
}

void displayCustomer() {
    struct getCustomer displayCustomer = getCustomerData();

    printf("ID\tName\t\t\tNationality\tPhone\t\tSex\tStatus\n");
    displayLine();
    for(int j = 0; j< a; j++) {
        if(strcmp(displayCustomer.customer[j].c_status, "deleted") == 0) {
            continue;
        }
        printf("%s\t%s\t\t%s\t\t%s\t%s\t%s\n", 
        displayCustomer.customer[j].c_ID,
        displayCustomer.customer[j].c_name,
        displayCustomer.customer[j].c_nationality,
        displayCustomer.customer[j].c_num,
        displayCustomer.customer[j].c_sex,
        displayCustomer.customer[j].c_status
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

void displayAddCustomer() {

    struct getCustomer get = getCustomerData();

    char c_ID[100];
    char c_name[100];
    char c_nationality[100];
    char c_num[100];
    char c_sex[50];
    char c_status[100];
    
    strcpy(c_status, "active");

    
    printf("Enter customer ID: ");
    scanf("%s", c_ID);

    for(int j = 0; j<a; j++) {
        if(strcmp(get.customer[j].c_ID, c_ID) == 0 && strcmp(get.customer[j].c_status, "active") == 0) {
            printf("Duplicate Room ID.\n");
            return;
        }
    }

    printf("Enter customer name: ");
    scanf("%s", c_name);
    printf("Enter customer nationality: ");
    scanf("%s", c_nationality);
    printf("Enter customer phone: ");
    scanf("%s", c_num);
    printf("Enter customer sex: ");
    scanf("%s", c_sex);

    FILE *file = fopen("./data/customers.txt", "a+");
    
    fprintf(file, "\n%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t\t\t\t%s\t\t%s\t\t\t\t\t%s", c_ID, c_name, c_nationality, c_num, c_sex, c_status);
    fclose(file);

}

void displayDeleteCustomer() {
    
    struct getCustomer get = getCustomerData();


    char delete_customer_id[12];

    printf("Enter customer ID: ");
    scanf("%s", delete_customer_id);

    for(int j = 0; j< a; j++) {
        if(strcmp(get.customer[j].c_ID, delete_customer_id) == 0) {
            strcpy(get.customer[j].c_status, "deleted");
        }
    }

    FILE *write_file = fopen("./data/customers.txt", "w");
    fprintf(write_file, "customer_id\t\tcustomer_name\t\t\tcustomer_nationality\t\tcustomer_phone\tcustomer_sex\t\tcustomer_status");
    for(int j = 0; j< a; j++) {
        fprintf(write_file, "\n%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t\t\t\t%s\t\t%s\t\t\t\t\t%s", get.customer[j].c_ID, get.customer[j].c_name, get.customer[j].c_nationality, get.customer[j].c_num, get.customer[j].c_sex, get.customer[j].c_status);
    }
    fclose(write_file);

    
}

void displayUpdateCustomer() {
    
    struct getCustomer get = getCustomerData();

    char update_customer_id[12];

    printf("Enter customer ID: ");
    scanf("%s", update_customer_id);

    for(int j = 0; j<a; j++) {
        if(strcmp(get.customer[j].c_ID, update_customer_id) == 0 && strcmp(get.customer[j].c_status, "active") == 0) {
            printf("Customer ID: \t\t%s\n", get.customer[j].c_ID);
            printf("Customer Name: \t\t%s\n", get.customer[j].c_name);
            printf("Customer Nationality: \t%s\n", get.customer[j].c_nationality);
            printf("Customer Phone: \t%s\n", get.customer[j].c_num);
            printf("Customer Sex: \t\t%s\n", get.customer[j].c_sex);

            char c_name[100];
            char c_nationality[100];
            char c_num[100];
            char c_sex[50];

            printf("Enter customer name: ");
            scanf("%s", c_name);
            printf("Enter customer nationality: ");
            scanf("%s", c_nationality);
            printf("Enter customer phone: ");
            scanf("%s", c_num);
            printf("Enter customer sex: ");
            scanf("%s", c_sex);

            for(int j = 0; j<a; j++) {
                if(strcmp(get.customer[j].c_ID, update_customer_id) == 0 && strcmp(get.customer[j].c_status, "active") == 0) {
                    strcpy(get.customer[j].c_name, c_name);
                    strcpy(get.customer[j].c_nationality, c_nationality);
                    strcpy(get.customer[j].c_num, c_num);
                    strcpy(get.customer[j].c_sex, c_sex);
                }
            }

            FILE *write_file = fopen("./data/customers.txt", "w");
            fprintf(write_file, "customer_id\t\tcustomer_name\t\t\tcustomer_nationality\t\tcustomer_phone\tcustomer_sex\t\tcustomer_status");
            for(int j = 0; j< a; j++) {
                fprintf(write_file, "\n%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t\t\t\t%s\t\t%s\t\t\t\t\t%s", get.customer[j].c_ID, get.customer[j].c_name, get.customer[j].c_nationality, get.customer[j].c_num, get.customer[j].c_sex, get.customer[j].c_status);
            }
            fclose(write_file);
            return;
        }
    }

    printf("Room ID is not existed.\n");

}

