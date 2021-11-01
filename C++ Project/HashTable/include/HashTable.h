#ifndef HASHTABLE_H
#define HASHTABLE_H
#ifndef HASHNODE_H
#define HASHNODE_H

template <typename K,typename V>
class HashNode
{
    public:
        HashNode(const K &data, const V &value):
            data(data),value(value),next(NULL) {}
        K getData() const{return data;}
        V getValue() const{return value;}
        void setValue(V value){HashNode::value = value;}
        HashNode *getNext() const{return next;}
        void setNext(HashNode *next) {next = next;}
    private:
        K data;
        V value;
        HashNode *next;
        HashNode(const HashNode &);
        HashNode & operator=(const HashNode &);
};

template<typename K, size_t TABLE_SIZE>
struct DataHash
{
    unsigned long operator()(const K& data) const
    {
        return reinterpret_cast<unsigned long>(data) % TABLE_SIZE;
    }
};

template<typename K,typename V,typename F = DataHash<K>>

class HashTable
{
    public:
        HashTable() {table = new HashNode<K,V> *[TABLE_SIZE]();}
        hashFunc() {}
        ~HashTable()
        {
            for (int i=0;i<TABLE_SIZE;i++)
            {
                HashNode<K,V> *entry = table[i];
                while (entry !=NULL)
                {
                    HashNode<K,V> *prev = entry;
                    entry = entry->getNext();
                    delete prev;
                }
                table[i]=NULL;
            }
            delete[] table;
        }
        bool get(const K &data, V &value)
        {
            unsigned long hashValue = hashFunc(data);
            HashNode<K,V> *entry = table[hashValue];
            while (entry !=NULL)
            {
                if (entry->getData() == data)
                {
                    value = entry->getValue();
                    return true;
                }
                entry = entry->getNext();
            }
            return false;
        }
        void put(const K &data,const V &value)
        {
            unsigned long hashValue = hashFunc(data);
            HashNode<K,V> *prev = NULL;
            HashNode<K,V> *entry = table[hashValue];
            while (entry != NULL && entry->getData() !=data)
            {
                prev = entry;
                entry = entry->getNext();
            }
            if (entry == NULL)
            {
                entry = new HashNode<K,V>(data,value);
                if(prev == NULL)
                {
                    table[hashValue] = entry;
                }
                else {entry->setValue(value);}
            }
        }
        void remove(const K &data)
        {
            unsigned long hashValue = hashFunc(data);
            HashNode<K,V> *prev = NULL;
            HashNode<K,V> *entry = table[hashValue];
            while (entry != NULL && entry->getData() !=data)
            {
                prev = entry;
                entry = entry->getNext();
            }
            if (entry == NULL) {return;}
            else
            {
                if (prev == NULL) {table[hashValue] = entry->getNext();}
                else {prev->setNext(entry->getNext());}
                delete entry;
            }
        }
    private:
        HashTable(const HashTable & other);
        const HashTable & operator=(const HashTable & other);
        HashNode<K,V> *table[TABLE_SIZE];
        F hashFunc;
};
struct MyDataHash
{
    unsigned long operator()(const int& k) const {return k % 10;}
};

HashTable<int, string, MyDataHash> htable;
htable.put(1, "val1");
htable.put(2, "val2");
htable.put(3, "val3");
string value;
htable.get(2,value);
cout<<value<<endl;
bool res = htable.get(3,value);
if(res)
     cout<<value<<endl;
htable.remove(3);
res = htable.get(3,value);
if(res)
    cout<<value<<endl;
#endif
#endif
