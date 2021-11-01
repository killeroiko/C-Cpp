#include "Array.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Array::Array()
{
    size=0;
}
Array::Array(int mysize)
{
    size=mysize;
    data=new int[size];
    for (int i=0;i<size;i++)
        data[i]=0;
}
Array::~Array()
{
    if (size>0)
        delete[] data;
}
int Array::getsize() {return size;}
bool Array::insert (int pos, int key)
{
    if (pos<size)
    {
        data[pos]=key;
        return true;
    }
    else
        return false;
}
bool Array::get (int pos, int &key)
{
    if (pos<size)
    {
        key=data[pos];
        return true;
    }
    else
        return false;
}
int Array::sum()
{
    int sum=0;
    for (int i=0;i<size;i++)
    {
        sum+=data[i];
    }
    return sum;
}
int Array::search(int key)
{
    int i=0;
    while (i<size && data[i]!=key)
        i++;
    if (data[i]==key)
        return i;
    else
        return -1;
}
void Array::swap (int i, int j)
{
    int temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}
int Array::partition (int left, int right, int pivotIndex)
{
    int pivot = data[pivotIndex];
    swap(pivotIndex,right);
    int storeIndex=left;
    for (int i=left;i<right;i++)
    {
        if (data[i]<=pivot)
        {
            swap(i,storeIndex);
            storeIndex++;
        }
    }
    swap(storeIndex,right);
    return storeIndex;
}
void Array::quicksort(int left, int right)
{
    if (left < right)
    {
        int pivotIndex=left +(right - left)/2;
        pivotIndex = partition(left,right,pivotIndex);
        quicksort(left,pivotIndex-1);
        quicksort(pivotIndex+1,right);
    }
}
