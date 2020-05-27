class WordDictionary {
    WordDictionary* child[26];
    bool isWord;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        for(int i=0;i<26;i++){
        child[i] = nullptr;    
        }
        isWord = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary * t = this;
        for(auto c:word){
            if(!t->child[c-'a'])
            t->child[c-'a'] = new WordDictionary();
            t = t->child[c-'a'];
        }
        t->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.length()==0)return isWord;
        WordDictionary * t = this;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            //通配符
            if(c=='.'){
                for(int j=0;j<26;j++){
                    if(t->child[j]){
                        if(t->child[j]->search(word.substr(i+1)))
                        return true;
                    }
                }
                return false;
            }
            else {
                t = t->child[c-'a'];
                if(!t)
                    return false;
            }

        }
        return t->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */