#pragma once

typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* a;
    int size;
    int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListCout(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);