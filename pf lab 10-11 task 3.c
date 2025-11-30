#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int seats;
};

void book_seat(struct Flight *f) {
    if (f->seats > 0) {
        f->seats--;
        printf("\nSeat booked successfully!\n");
    } else {
        printf("No seats available!\n");
    }
}

void display_flight(struct Flight f) {
    printf("\n--- Flight Details ---\n");
    printf("Flight No: %d\n", f.flightNumber);
    printf("From: %s\n", f.departure);
    printf("To: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Seats Available: %d\n", f.seats);
}

int main() {
    struct Flight f1 = {101, "Karachi", "Lahore", "12-12-2025", 3};

    display_flight(f1);
    book_seat(&f1);
    display_flight(f1);

    return 0;
}
