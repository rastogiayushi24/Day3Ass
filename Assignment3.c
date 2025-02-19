#include <stdio.h>
int findHighest(int scores[], int n) {
    int highest = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

int findLowest(int scores[], int n) {
    int lowest = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

float calculateAverage(int scores[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    return (float)sum / n;
}

int main() {
    int n;
    
    printf("Enter number of matches: ");
    scanf("%d", &n);
    
    int scores[n];
 
    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    int highest = findHighest(scores, n);
    int lowest = findLowest(scores, n);
    float average = calculateAverage(scores, n);
    
    printf("\nHighest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);
    
    return 0;
}
