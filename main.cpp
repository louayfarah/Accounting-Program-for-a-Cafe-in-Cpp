//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
//key-value pair
template <typename K, typename V> struct token
{
    K key;
    V value;
};
 
//hashmap data structure
template <typename K, typename V> class MyHashMap
{
private:
    int size = 0;
    int capacity = 20;
public:
    vector<token<K, V>> t;
    vector<token<K, V>*> table;
    void init();
    void rehash();
    int hashFunction(K key);
    void put(K key, V value);
    void remove(K key);
    V* get(K key);
    int count(K key);
    int hashMapSize();
    bool isEmpty();
    int mySize();
};
 
template <typename K, typename V> void MyHashMap<K, V>::init()
{
    t.assign(10000*capacity, {"", {}});
    for(auto elt: t)
    {
        table.pb(&elt);
    }
}
 
 
//rehashing function 
template <typename K, typename V> void MyHashMap<K, V>::rehash()
{
    capacity = int(t.size());
    vector<token<K, V>*> temp = table;
    vector<token<K, V>> tempt = t;
    t.assign(2*capacity, {"", {}});
    table.clear();
    for(auto elt: t)
    {
        table.pb(&elt);
    }
    capacity*=2;
 
    for(auto entry: tempt)
    {
        int hv = MyHashMap::hashFunction(entry.key);
        MyHashMap::t[hv] = entry;
    }
}
 
//hash function
template <typename K, typename V> int MyHashMap<K, V>::hashFunction(K key)
{
    capacity = int(t.size());
    int x = 93;
    for(auto elt: key)
    {
        x = (((x*197)%capacity) + (elt%capacity))%capacity;
    }
 
    x = x%capacity;
 
    while(!(MyHashMap::t[x]).key.empty())
    {
        if((MyHashMap::t[x]).key == key)
        {
 
            return x;
        }
 
        x = (x+1)%capacity;
    }
 
    return x;
}
 
//put a key-value pair in the map
template <typename K, typename V> void MyHashMap<K, V>::put(K key, V value)
{
    if(MyHashMap::size == MyHashMap::capacity)
    {
        MyHashMap::rehash();
    }
 
    int hv = MyHashMap::hashFunction(key);
    t[hv].key = key;
    t[hv].value = value;
 
    MyHashMap::size++;
}
 
//remove a key-value pair in the map
template <typename K, typename V> void MyHashMap<K, V>::remove(K key)
{
    int hv = MyHashMap::hashFunction(key);
    MyHashMap::t[hv] = {"", {}};
    MyHashMap::size--;
}
 
template <typename K, typename V> V* MyHashMap<K, V>::get(K key)
{
    int hv = MyHashMap::hashFunction(key);
    if(MyHashMap::t[hv].key != key)
    {
        return nullptr;
    }
    return &(MyHashMap::t[hv].value);
}
 
//return 1 if the k is present in the map
template <typename K, typename V> int MyHashMap<K, V>::count(K key)
{
    int hv = MyHashMap::hashFunction(key);
    if(MyHashMap::t[hv].key != key)
    {
        return 0;
    }
 
    return 1;
}
 
//return the size of the hashmap
template <typename K, typename V> int MyHashMap<K, V>::hashMapSize()
{
    return MyHashMap::size;
}
 
template <typename K, typename V> bool MyHashMap<K, V>::isEmpty()
{
    return (MyHashMap::size == 0);
}
 
template <typename K, typename V> int MyHashMap<K, V>::mySize()
{
    return (MyHashMap::size);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    MyHashMap<string, vector<string>> revenues;
    MyHashMap<string, int> nbReceipts;
    MyHashMap<string, int> ids;
    MyHashMap<string, int> dates;
 
    revenues.init();
    nbReceipts.init();
    ids.init();
    dates.init();
 
 
    string s;
    getline(cin, s);
 
 
    vector<string> possible_days;
 
    for(int line = 0; line<n; line++)
    {
 
        getline(cin, s);
 
        string date = "";
        int curr = 0;
        while(curr < int(s.length()))
        {
            if(s[curr] == ' ')
                break;
            date.pb(s[curr]);
            curr++;
        }
 
        curr++;
 
 
        while(curr < int(s.length()))
        {
            if(s[curr] == ' ')
                break;
            curr++;
        }
 
        curr++;
 
        string receipt = "";
        while(curr < int(s.length()))
        {
            if(s[curr] == ' ')
                break;
            receipt.pb(s[curr]);
            curr++;
        }
 
        curr+=2;
 
        string price = "";
        while(curr < int(s.length()))
        {
            if(s[curr] == ' ')
                break;
            price.pb(s[curr]);
            curr++;
        }
 
        if(dates.count(date) == 0)
        {
            possible_days.pb(date);
            dates.put(date, 1);
            revenues.put(date, {});
            nbReceipts.put(date, 0);
        }
 
        receipt+=date;
        if(ids.count(receipt) == 0)
        {
            ids.put(receipt, 1);
            nbReceipts.put(date, *(nbReceipts.get(date))+1);
        }
 
        vector<string> *temp = revenues.get(date);
        temp->pb(price);
    }
 
 
    for(auto date: possible_days)
    {
        cout << date << ' ';
 
        double total_price = 0;
        for(auto price: *revenues.get(date))
        {
            total_price += stod(price);
        }
 
        cout << '$' << setprecision(2) << fixed << total_price << ' ';
 
        cout << *nbReceipts.get(date) << endl;
    }
 
    return 0;
}
