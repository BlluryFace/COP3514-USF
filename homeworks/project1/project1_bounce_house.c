// Name: Huy Dinh Bui
// Description: The program calculate the cost of renting a bounce house
#include <stdio.h>

int main() {
    // Declare variables
    int selection, days, hours;
    int charge = 0;
    // Declare pricing
    const int firstThreeHours[] = {58, 85, 100, 180};
    const int hourlyRate[] = {8, 12, 15, 20};
    const int maxCharged[] = {80, 120, 150, 250};
    // Prompt user for selection
    printf("Please select from four bounce houses: 1, 2, 3, and 4\n");
    printf("Enter bounce house selection: ");
    scanf("%d", &selection);
    // Validate the selection
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }
    // Since C's indexing start at 0, we have to lower the selection by 1 to match the indexing
    selection -= 1;

    printf("Enter days: ");
    scanf("%d", &days);
    printf("Enter hours: ");
    scanf("%d", &hours);

    // Validate the days
    if (days < 0) {
        printf("Invalid days.\n");
        return 0;
    }
    // Validate the hours
    if (hours < 0 || hours >= 24) {
        printf("Invalid hours.\n");
        return 0;
    }

    // Calculate the charge
    if (days > 0) { // Multi-day rental charge
        charge = days * maxCharged[selection];
        // Charge extra hours for the last day if exist
        if (hours > 0) {
            if (hours * hourlyRate[selection] > maxCharged[selection]) {
                charge += maxCharged[selection];
            } else {
                charge += hours * hourlyRate[selection];
            }
        }
    } else {
        // Single-day rental charge
        if (hours <= 3) {
            charge = firstThreeHours[selection]; // First 3 hours charge
        } else {
            charge = firstThreeHours[selection] + (hours - 3) * hourlyRate[selection];
            if (charge > maxCharged[selection]) {
                charge = maxCharged[selection];
            }
        }
    }

    printf("Charge($): %.0d\n", charge);

    return 0;
}