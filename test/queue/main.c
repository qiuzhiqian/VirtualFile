#include "Queue.h"

struct TQueue qtest;

int main(int argc,char **argv)
{
    memset((char *)&qtest,0,sizeof(struct TQueue));
    BYTE indata=0x00;
    BYTE outdata=0;
    QueueInit(&qtest,4);
    QueueIn(&qtest,1);
    QueueIn(&qtest,2);
    QueueIn(&qtest,3);
    QueueIn(&qtest,4);
    QueueIn(&qtest,5);
    QueueIn(&qtest,6);
    for(int i=0;i<10;i++)
    {
        //QueueIn(&qtest,indata++);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        /*QueueIn(&qtest,indata++);
        QueueIn(&qtest,indata++);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        QueueIn(&qtest,indata++);
        QueueIn(&qtest,indata++);
        QueueIn(&qtest,indata++);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        QueueIn(&qtest,indata++);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);
        QueueOut(&qtest,&outdata);
        printf("%02x.\n",outdata);*/
    }
}