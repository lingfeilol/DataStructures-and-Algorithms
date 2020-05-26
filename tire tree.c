class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {//插入一个单词
        Trie* node=this;
        for(char w:word)
        {
            if(node->next[w-'a']==nullptr)//判断是否存在，不存在则添加
                node->next[w-'a']=new Trie();
            node=node->next[w-'a'];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. *///查找一个单词
    bool search(string word) {
        Trie* node=this;
        for(char w:word)
        {
            node=node->next[w-'a'];
            if(node==nullptr)
                return false;
        }
        return node->isEnd;//需要判断单词是否完整存在
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    //查找一个前缀
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char w:prefix)
        {
            node=node->next[w-'a'];
            if(node==nullptr)
                return false;
        }
        return true;//只要有prefix这个前缀即可
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */