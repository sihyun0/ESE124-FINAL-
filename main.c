#include "function.h"
#include <stdio.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (!inputFile || !outputFile) {
        perror("Error opening file");
        return 1;
    }

    Memory memory;
    Position currentPosition = {0, 0};
    initializeMemory(&memory);

    // Example of reading initial position from input file
    if (fscanf(inputFile, "%d %d", &currentPosition.x, &currentPosition.y) != 2) {
        fprintf(stderr, "Error reading initial position from input file\n");
        return 1;
    }

    // Process maze movements
    push(&memory, currentPosition);  // Store initial position
    moveF(&currentPosition);         // Move forward
    mark();                          // Mark the current position with pheromone

    Position retrievedPosition = pop(&memory);  // Retrieve the last position
    fprintf(outputFile, "Moved to: (%d, %d)\n", currentPosition.x, currentPosition.y);
    fprintf(outputFile, "Retrieved position: (%d, %d)\n", retrievedPosition.x, retrievedPosition.y);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
