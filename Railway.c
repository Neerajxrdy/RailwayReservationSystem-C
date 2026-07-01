#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_NAME "railway_records.txt"

typedef struct {
    int pnr;
    char name[50];
    int age;
    char gender[10];
    char phone[20];

    char boarding[50];
    char destination[50];
    char trainName[50];
    char startTime[20];
    char endTime[20];

    char coach[30];
    int farePerSeat;
    int seats;
    int totalFare;

    char paymentMode[30];
    char paymentStatus[30];
} Ticket;

Ticket tickets[MAX];
int count = 0;
int pnrCounter = 1000;

void removeNewLine(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void inputString(const char *msg, char *str, int size) {
    printf("%s", msg);
    fgets(str, size, stdin);
    removeNewLine(str);
}

int inputInt(const char *msg) {
    char temp[20];
    printf("%s", msg);
    fgets(temp, sizeof(temp), stdin);
    return atoi(temp);
}

void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error saving file!\n");
        return;
    }

    fprintf(fp, "%d %d\n", count, pnrCounter);

    for (int i = 0; i < count; i++) {
        fprintf(fp,
            "%d|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%d|%d|%d|%s|%s\n",
            tickets[i].pnr, tickets[i].name, tickets[i].age,
            tickets[i].gender, tickets[i].phone,
            tickets[i].boarding, tickets[i].destination,
            tickets[i].trainName, tickets[i].startTime,
            tickets[i].endTime, tickets[i].coach,
            tickets[i].farePerSeat, tickets[i].seats,
            tickets[i].totalFare,
            tickets[i].paymentMode, tickets[i].paymentStatus
        );
    }

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;

    fscanf(fp, "%d %d\n", &count, &pnrCounter);

    for (int i = 0; i < count; i++) {
        fscanf(fp,
            "%d|%49[^|]|%d|%9[^|]|%19[^|]|%49[^|]|%49[^|]|%49[^|]|%19[^|]|%19[^|]|%29[^|]|%d|%d|%d|%29[^|]|%29[^\n]\n",
            &tickets[i].pnr, tickets[i].name, &tickets[i].age,
            tickets[i].gender, tickets[i].phone,
            tickets[i].boarding, tickets[i].destination,
            tickets[i].trainName, tickets[i].startTime,
            tickets[i].endTime, tickets[i].coach,
            &tickets[i].farePerSeat, &tickets[i].seats,
            &tickets[i].totalFare,
            tickets[i].paymentMode, tickets[i].paymentStatus
        );
    }

    fclose(fp);
}

void selectRoute(int i) {
    int ch;
    printf("\n1. Hyderabad-Chennai\n2. Hyderabad-Bangalore\n3. Hyderabad-Delhi\n");
    ch = inputInt("Choose route: ");

    switch (ch) {
        case 1:
            strcpy(tickets[i].boarding, "Hyderabad");
            strcpy(tickets[i].destination, "Chennai");
            strcpy(tickets[i].trainName, "Charminar Express");
            break;
        case 2:
            strcpy(tickets[i].destination, "Bangalore");
            strcpy(tickets[i].trainName, "Kacheguda Express");
            break;
        default:
            strcpy(tickets[i].destination, "Delhi");
            strcpy(tickets[i].trainName, "Dakshin Express");
    }
}

void selectCoach(int i) {
    int ch = inputInt("\n1.Sleeper(500)\n2.AC(1200)\nChoose: ");
    if (ch == 1) {
        strcpy(tickets[i].coach, "Sleeper");
        tickets[i].farePerSeat = 500;
    } else {
        strcpy(tickets[i].coach, "AC");
        tickets[i].farePerSeat = 1200;
    }
}

int makePayment(int i) {
    printf("\nTotal Fare: %d", tickets[i].totalFare);
    int confirm = inputInt("\nConfirm payment (1-Yes, 0-No): ");

    if (confirm) {
        strcpy(tickets[i].paymentStatus, "Success");
        return 1;
    }
    strcpy(tickets[i].paymentStatus, "Pending");
    return 0;
}

void printTicket(int i) {
    printf("\n--- TICKET ---");
    printf("\nPNR: %d", tickets[i].pnr);
    printf("\nName: %s", tickets[i].name);
    printf("\nRoute: %s -> %s", tickets[i].boarding, tickets[i].destination);
    printf("\nSeats: %d | Total: %d", tickets[i].seats, tickets[i].totalFare);
    printf("\nStatus: %s\n", tickets[i].paymentStatus);
}

    void bookTicket() {
    if (count >= MAX) return;

    int i = count;
    tickets[i].pnr = ++pnrCounter;

    inputString("Name: ", tickets[i].name, 50);
    tickets[i].age = inputInt("Age: ");

    selectRoute(i);
    selectCoach(i);

    tickets[i].seats = inputInt("Seats: ");
    tickets[i].totalFare = tickets[i].seats * tickets[i].farePerSeat;

    if (makePayment(i)) {
        count++;
        saveToFile();
        printTicket(i);
    }
}

void menu() {
    int ch;
    while (1) {
        printf("\n1.Book 2.View 3.Exit");
        ch = inputInt("\nChoice: ");

        if (ch == 1) bookTicket();
        else if (ch == 2)
            for (int i = 0; i < count; i++) printTicket(i);
        else break;
    }
}

int main() {
    loadFromFile();
    menu();
    return 0;
}