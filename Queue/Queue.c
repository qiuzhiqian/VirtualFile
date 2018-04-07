//API包括init,
#include "define.h"
#include "Queue.h"

bool IsQueueFull(struct TQueue *qe)
{
    if(qe->head == qe->tail && qe->fullFlag==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsQueueEmpty(struct TQueue *qe)
{
    if(qe->head == qe->tail && qe->fullFlag!=1)
    {
        return true;
    }
    else
        return false;
}

//模块内使用
static bool IsVaildPointer(BYTE *p,BYTE *base,int maxSize)
{
    if(p>=base &&p<(base+maxSize))
        return true;
    else
    {
        return false;
    }
}

bool IsQueueVaild(struct TQueue *qe)
{
    if(qe->head != NULL && qe->tail !=NULL)
    {
        if(IsVaildPointer(qe->head,qe->base,qe->maxSize) && 
            IsVaildPointer(qe->tail,qe->base,qe->maxSize))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        false;
    }
}

int QueueInit(struct TQueue *qe,WORD maxSize)
{
    if(qe==NULL)
    {
        return -1;
    }
    if(qe->base==NULL)
    {
        qe->base = malloc(maxSize);
    }
    qe->head=qe->tail=qe->base;
    qe->maxSize=maxSize;
    qe->fullFlag=0;
    return 0;
}

void QueueDelete(struct TQueue *qe)
{
    if(qe->base!=NULL)
    {
        free(qe->base);
    }
    qe->head=qe->tail=qe->base=NULL;
    qe->maxSize=0;
    qe->fullFlag=0;
}

int QueueIn(struct TQueue *qe,BYTE data)
{
    if(!IsQueueVaild(qe))
    {
        return -1;
    }
    else if(IsQueueFull(qe))
    {
        printf("full.\n");
        return -1;
    }
    else
    {
        *(qe->head)=data;
        qe->head++;
        if(qe->head>=qe->base+qe->maxSize)
        {
            qe->head=qe->base;
        }

        if(qe->head == qe->tail && qe->fullFlag==0)   //说明放满了
        {
            qe->fullFlag=1;
        }
    }
    return 0;
}

int QueueOut(struct TQueue *qe,BYTE *data)
{
    if(!IsQueueVaild(qe))
    {
        return -1;
    }
    else if(IsQueueEmpty(qe))
    {
        return -1;
    }
    else
    {
        *data=*(qe->tail);
        qe->tail++;
        if(qe->tail>=qe->base+qe->maxSize)
        {
            qe->tail=qe->base;
        }

        if(qe->tail!=qe->base+qe->maxSize && qe->fullFlag==1) //说明有空余
        {
            qe->fullFlag=0;
        }
    }
    return 0;
}
