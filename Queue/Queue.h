#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../define.h"

struct TQueue{
    BYTE *base;
    BYTE *head;
    BYTE *tail;
    WORD maxSize;
    BYTE fullFlag;
};

bool IsQueueFull(struct TQueue *qe);
bool IsQueueEmpty(struct TQueue *qe);
bool IsQueueVaild(struct TQueue *qe);

int QueueInit(struct TQueue *qe,WORD maxSize);
void QueueDelete(struct TQueue *qe);
int QueueIn(struct TQueue *qe,BYTE data);
int QueueOut(struct TQueue *qe,BYTE *data);

#endif