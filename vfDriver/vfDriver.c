#include "vfDriver.h"

//这个属于驱动层，大部分API都与底层硬件有关
//串口初始化代码放于此处
int vfHwInit(struct TVirtualFile *vf)
{

}

//从串口中接受一个字节放于此处
int vfRecHandle(struct TVirtualFile *vf,BYTE data)
{

}

//从串口中发送一个字节放于此处
int vfSendHandle(struct TVirtualFile *vf)
{

}