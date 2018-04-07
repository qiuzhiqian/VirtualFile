/**
 * 虚拟文件，提供初始化，打开，读，写，关闭，销毁操作
*/
#include "virtualFile.h"

void VF_Init(struct TVirtualFile *vf)
{
    QueueInit(&vf->readQueue,READ_LEN);
    QueueInit(&vf->writeQueue,WRITE_LEN);
}

void VF_Open(struct TVirtualFile *vf)
{

}

int VF_Write(struct TVirtualFile *vf,char *data,int len)
{
    int iRet=0;
    int i=0;
    for(i=0;i<len;i++)
    {
        iRet=QueueIn(&vf->writeQueue,data[i]);
        if(iRet<0)
        {
            break;
        }
    }
    return i;
}

int VF_Read(struct TVirtualFile *vf,char *data,int len)
{
    int iRet=0;
    int i=0;
    for(i=0;i<len;i++)
    {
        iRet=QueueOut(&vf->readQueue,data+i);
        if(iRet<0)
        {
            break;
        }
    }
    return i;
}

void VF_Close(struct TVirtualFile *vf)
{

}

void VF_Delete(struct TVirtualFile *vf)
{
    QueueDelete(&vf->readQueue);
    QueueDelete(&vf->writeQueue);
}