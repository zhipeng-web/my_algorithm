//
// Created by china on 2024/4/18.
//
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // 更新访问顺序
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // 如果已存在，更新值并更新访问顺序
            cache[key].first = value;
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
        } else {
            // 如果不存在，插入新值并检查容量
            if (cache.size() >= capacity) {
                int least_recently_used = order.back();
                order.pop_back();
                cache.erase(least_recently_used);
            }
            order.push_front(key);
            cache[key] = make_pair(value, order.begin());
        }
    }
};

// 示例用法
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 输出 1
    cache.put(3, 3); // 因为容量已满，移除 key 2
    cout << cache.get(2) << endl; // 输出 -1，因为 key 2 不再缓存中
    cache.put(4, 4); // 因为容量已满，移除 key 1
    cout << cache.get(1) << endl; // 输出 -1，因为 key 1 不再缓存中
    cout << cache.get(3) << endl; // 输出 3
    cout << cache.get(4) << endl; // 输出 4

    return 0;
}
