
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class LogNode{
public:
    int start;
    int end;
    string id;
    LogNode* prev, *next;
    LogNode(string _id, int _start){
        id= _id;
        start = _start;
        end = -1;
    }
};

class Log
{
public:
    Log(){
        head = new LogNode("", -1);
        tail = new LogNode("", -1);
        head->next = tail;
        tail->prev = head;
    };
    LogNode *head, *tail;
    //list<LogNode> l;
    unordered_map<string, LogNode*> map; //id, timestamp
    void add(string id, int timestamp);
    void end(string id, int timestamp);
    void print();
};

void Log::add(string id, int timestamp){
    LogNode *newNode= new LogNode(id, timestamp);
    map[id] = newNode;
    auto tmp = tail->prev;
    tmp->next = newNode;
    newNode->prev = tmp;
    newNode->next = tail;
    tail->prev = newNode;
}

void Log::end(string id, int timestamp){
    auto cur = map.find(id);
    if(cur != map.end() && cur->second->end == -1){
        cur->second->end = timestamp;
        map.erase(id);
    }
}

void Log::print(){
    LogNode *cur = head->next;
    while(cur != tail){
        if(cur->end != -1){
            printf("%s, start at %d, end at %d\n", cur->id.c_str(), cur->start, cur->end);
        }
        cur = cur->next;
    }
}

int main(){
    Log CLog;
    CLog.add("1", 100);
    CLog.add("2", 101);
    CLog.end("2", 102);
    CLog.end("1", 202);
    CLog.print();
    return 0;
}