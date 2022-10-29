#include <iostream>
#include "SeqList.h"
#include <assert.h>

void SeqListInit(SL *ps)
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void SeqListCout(SL *sl)
{
    for (int i = 0; i < sl->size; i++)
    {
        std::cout << sl->a[i] << " ";
    }
    std::cout << "end\n";
}

void SeqListCheckCapacity(SL *ps)
{
    if (ps->size == ps->capacity)
    {
        int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
        // if ps->a == NULL; realloc == malloc;
        SLDataType *tmp = (SLDataType *)realloc(ps->a, newcapacity * sizeof(SLDataType));
        if (tmp == NULL)
        {
            std::cout << "realloc fail\n";
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}

void SeqListDestory(SL *ps)
{
    SeqListCheckCapacity(ps);
    free(ps->a);
    SeqListInit(ps);
}

void SeqListPushBack(SL *ps, SLDataType x)
{
    ps->a[ps->size] = x;
    ps->size++;
}

void SeqListPopBack(SL *ps)
{
    assert(ps->a > 0);
    ps->size--;
}

void SeqListPushFront(SL *ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
    int end = ps->size - 1;
    while (end >= 0)
    {
        ps->a[end + 1] = ps->a[end];
        --end;
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListPopFront(SL *ps)
{
    assert(ps->size > 0);
    int begin = 1;
    while (begin < ps->size)
    {
        ps->a[begin-1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
    // ps->a=ps->a+1;
}

void menu()
{
    std::cout<<"********************\n";
    std::cout<<"Please input you cmd\n";
}

int main()
{
    SL slist;
    SL *sl = &slist;
    SeqListInit(sl);
    SeqListPushFront(sl, 909);
    SeqListCout(sl);
    SeqListPopFront(sl);
    SeqListCout(sl);
    // SeqListDestory(sl);
}