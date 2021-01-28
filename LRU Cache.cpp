class LRUCache {
	list<pair<int,int>>  qu;  //<data,count>
	map<int, list<pair<int,int>>::iterator>  hashmap;  //key,queue index;
	int cap;
public:
	LRUCache(int capacity) {
		cap = capacity;
		//qu = new list<int>();
		//hashmap = new map<int, int>();

	}

	int get(int key) {
		
		map<int, list<pair<int, int>>::iterator>::iterator it;
		it = hashmap.find(key);
		if (it == hashmap.end())
			return -1;
		int value =  it->second->second;
		int mykey = it->second->second;
		qu.erase(it->second);
		hashmap.erase(key);
		qu.push_front(pair<int, int>(key, value));
		hashmap[key] = qu.begin();
		
		return value;

	}

	void put(int key, int value) {
		
		if (hashmap.find(key) == hashmap.end())
		{
			if (qu.size() == cap)
			{
				int last = qu.back().first;
				qu.pop_back();
				hashmap.erase(last);

			}
		}
		else
		{
			qu.erase(hashmap[key]);
		}
		qu.push_front(pair<int,int>(key,value));
		hashmap[key] = qu.begin();

	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/