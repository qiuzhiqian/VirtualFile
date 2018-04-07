#ifndef __VIRTUALFILE_H
#define __VIRTUALFILE_H

#include "Queue.h"

#define READ_LEN    1024
#define WRITE_LEN   1024

struct THw_Ops{

};

struct TVirtualFile{
    struct TQueue readQueue;
    struct TQueue writeQueue;
    struct THw_Ops ops;
};

void VF_Init(struct TVirtualFile *vf);
void VF_Open(struct TVirtualFile *vf);
int VF_Write(struct TVirtualFile *vf,char *data,int len);
int VF_Read(struct TVirtualFile *vf,char *data,int len);
void VF_Close(struct TVirtualFile *vf);
void VF_Delete(struct TVirtualFile *vf);

#endif