#include "function.h"

void initializeMemory(Memory *mem) {
    mem->top = -1;
}

void push(Memory *mem, Position pos) {
    if (!isFull(mem)) {
        mem->stack[++mem->top] = pos;
    }
}

Position pop(Memory *mem) {
    Position pos = {0, 0};
    if (!isEmpty(mem)) {
        pos = mem->stack[mem->top--];
    }
    return pos;
}

Position peek(const Memory *mem) {
    Position pos = {0, 0};
    if (!isEmpty(mem)) {
        pos = mem->stack[mem->top];
    }
    return pos;
}

void clear(Memory *mem) {
    mem->top = -1;
}

int isEmpty(const Memory *mem) {
    return mem->top == -1;
}

int isFull(const Memory *mem) {
    return mem->top == MAX_SIZE - 1;
}

void mark() {
    // Implementation depends on specific pheromone marking method
}

void moveF(Position *pos) {
    pos->x += 1;
}

void moveB(Position *pos) {
    pos->x -= 1;
}

void moveL(Position *pos) {
    pos->y -= 1;
}

void moveR(Position *pos) {
    pos->y += 1;
}

int checkLeft(const Position *pos) {
    // This function should check the maze state to the left
    return 0; // Placeholder
}

int checkRight(const Position *pos) {
    // This function should check the maze state to the right
    return 0; // Placeholder
}

int checkForward(const Position *pos) {
    // This function should check the maze state in front
    return 0; // Placeholder
}

int checkBackward(const Position *pos) {
    // This function should check the maze state behind
    return 0; // Placeholder
}

void jumpForItching(Position *pos, int direction, int distance) {
    // Placeholder for jumping logic
}

void cautiousJump(Position *pos, int direction) {
    // Placeholder for cautious jumping logic
}

void backtrack(Memory *mem, Position *pos) {
    *pos = pop(mem);
}
