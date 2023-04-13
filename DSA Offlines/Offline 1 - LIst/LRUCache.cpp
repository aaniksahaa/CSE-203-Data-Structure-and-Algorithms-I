#include<bits/stdc++.h>
#include "MyListArr.cpp"
//#include "MyListLL.cpp"
using namespace std;

template<class U, class V>
class data{
public:
    U key;
    V value;
    data()
    {

    }
    data(U key, V value)
    {
        this->key = key;
        this->value = value;
    }
    bool operator==(data d)
    {
        return key == d.key;   // We need to find the data with same key as given key
    }
};

template<class U, class V>
class LRUCache{
    MyList<data<U,V>>cache;
    int capacity;
    void bringCurrentToFront()
    {
        data<U,V>d = cache.getValue();
        cache.erase();  // O(1)
        cache.setToBegin();
        cache.push(d);  // O(1)
    }
    void removeLRU()
    {
        cache.setToEnd();
        cache.erase();
    }
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    V get(U key)
    {
        cache.setToBegin();
        int i = 0;
        while(i<cache.size() && cache.getValue().key != key)
        {
            cache.next();
            i++;
        }
        if(i == cache.size())
        {
            int *p = new int(-1);
            V*dummy = reinterpret_cast<V*>(p);
            return *dummy;  // equivalent to -1
        }
        V value = cache.getValue().value;
        bringCurrentToFront();
        return value;

    }
    void put(U key, V value)
    {
        cache.setToBegin();
        int i = 0;
        while(i<cache.size() && cache.getValue().key != key)
        {
            cache.next();
            i++;
        }
        if(i == cache.size())  // Key does not exist
        {
            if(cache.size() == capacity)
            {
                removeLRU();
            }
            cache.setToBegin();
            data<U,V>d(key,value);
            cache.push(d);
        }
        else
        {
            data<U,V>d = cache.getValue();
            d.value = value;
            cache.erase();
            cache.push(d);   //  update the value in cache
            bringCurrentToFront();
        }
    }

};

int main()
{
    freopen("lru_input.txt", "r", stdin);
    freopen("lru_output.txt", "w", stdout);
    int C,Q;
    cin>>C>>Q;
    LRUCache<int,int>LC(C);
    for(int i=0;i<Q;i++)
    {
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int key;
            cin>>key;
            cout<<LC.get(key)<<"\n";
        }
        else
        {
            int key, value;
            cin>>key>>value;
            LC.put(key,value);
        }
    }
    return 0;
}
