#include <bits/stdc++.h>
using namespace std;

class LRU{
public:
    LRU(int cap){
        capacity = cap;
    };
    int get(int key){
        if(map.find(key) == map.end()){
            return -1;
        }
        else{
            auto it = map.find(key); //get the element from list
            //move the element to the front
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
    };
    void put(int key, int value){
        if(map.find(key) != map.end())
            cache.erase(map.find(key)->second); //remove ori element in list

        //create new list element
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();

        //check capacity
        if(map.size() > capacity){
            auto idx = cache.rbegin()->first;
            cache.pop_back();
            map.erase(idx);
        }
    };

    void printCache(){
        for (auto it = cache.begin(); it!= cache.end(); it++){
            printf("%d, %d\n", it->first, it->second);
        }
        printf("\n");
    }

  private:
    list<pair<int, int>> cache; //stores every elements currently have
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> map; //stores the position in the cache
};




int main(){
    LRU inst = LRU(5);
    for (int i = 0; i < 5; i++){
        inst.put(i, i + 10);
    }

    inst.printCache();

    inst.get(3);
    inst.printCache();
    inst.put(2, 22);
    inst.printCache();

    inst.put(6, 22); //size will exceed, should pop out key=0
    inst.printCache();


    return 0;
}