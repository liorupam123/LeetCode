class MyHashSet {
public:
    vector<list<int>> m;
    int siz;
  
    MyHashSet() {
        int siz=1e6+1;
      m.resize(siz);
    }
    int hash(int key){
      return key%siz;
    }
  list<int> :: iterator search(int key){
    int i=hash(key);
    return find(m[i].begin(),m[i].end(),key);
  }
    
    void add(int key) {
       if(contains(key))  return ;
      int i=hash(key);
      m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))  return ;
      int i=hash(key);
      m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
      return (search(key)!=m[i].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */