#ifndef ARRAY_H
#define ARRAY_H


class Array
{
   private:
        int *data;
        int size;
        void swap (int i, int j);
        int partition (int left, int right, int pivoIndex);
    public:
        Array();
        Array(int mysize);
        ~Array();
        bool insert (int pos, int key);
        bool get (int pos, int &key);
        int getsize();
        int sum();
        int search (int key);
        void quicksort(int left,int right);
};

#endif // ARRAY_H
