#include <stdio.h>
#include <string.h>
#define MAX_PASSENGERS 100
typedef struct {
    char name[50];
    int age;
    char destination[50];
} Passenger;

void addPassengers(Passenger passengers[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for Passenger %d (Name, Age, Destination): ", i + 1);
        scanf(" %[^\n]", passengers[i].name);  
        printf("Enter Age: ");
        scanf("%d", &passengers[i].age);
        printf("Enter Destination: ");
        scanf(" %[^\n]", passengers[i].destination); 
    }
}

void sortPassengers(Passenger passengers[], int n) {
    Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

void searchPassengers(Passenger passengers[], int n, char destination[]) {
    int found = 0;
    printf("Passengers traveling to %s:\n", destination);
    for (int i = 0; i < n; i++) {
        if (strcasecmp(passengers[i].destination, destination) == 0) {  
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found.\n");
    }
}

void displayPassengers(Passenger passengers[], int n) {
    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }
}

int main() {
    int n;
    Passenger passengers[MAX_PASSENGERS];
    char searchDest[50];

    printf("Enter number of passengers: ");
    scanf("%d", &n);
    getchar(); 

    addPassengers(passengers, n);
    sortPassengers(passengers, n);
    displayPassengers(passengers, n);

    printf("\nEnter destination to search: ");
    scanf(" %[^\n]", searchDest);
    searchPassengers(passengers, n, searchDest);

    return 0;
}
