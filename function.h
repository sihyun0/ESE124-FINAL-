#ifndef FUNCTION_H
#define FUNCTION_H

#define MAX_SIZE 100
#define MAX_NUMBER_OF_STEPS 1000

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position stack[MAX_SIZE];
    int top;
} Memory;

// Function prototypes
void initializeMemory(Memory *mem);
void push(Memory *mem, Position pos);
Position pop(Memory *mem);
Position peek(const Memory *mem);
void clear(Memory *mem);
int isEmpty(const Memory *mem);
int isFull(const Memory *mem);
void mark();
void moveF(Position *pos);
void moveB(Position *pos);
void moveL(Position *pos);
void moveR(Position *pos);
int checkLeft(const Position *pos);
int checkRight(const Position *pos);
int checkForward(const Position *pos);
int checkBackward(const Position *pos);
void jumpForItching(Position *pos, int direction, int distance);
void cautiousJump(Position *pos, int direction);
void backtrack(Memory *mem, Position *pos);

#endif
