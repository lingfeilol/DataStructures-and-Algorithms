class Tiretree//构建一个前缀树
{
public:
    struct Node//节点结构
    {
        bool isEnd;
        unordered_map<char,Node*> children;
        Node(){
            isEnd=false;
        }
    };

    Node* root;
    Tiretree()
    {
        root=new Node();
    }

    void insert(string word)
    {
        auto node=this->root;
        for(auto w:word)
        {
            if(!node->children.count(w))//没出现过
            {
                node->children[w]=new Node();
            }
            node=node->children[w];//往下建
        }
        node->isEnd=true;//结尾
    }
    string startwith(string word)//前缀匹配，这里是找到匹配自己的最小字典树里的前缀
    {
        string minstr;
        auto node=this->root;
        bool falg=false;
        for(auto w:word)
        {
            minstr+=w;
            if(!node->children.count(w))
                break;
            node=node->children[w];
            if(node->isEnd==true)
            {
               falg=true;
               break;
            }
        }
        if(falg==false)
            return word;
        return minstr;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if(dict.empty()) return sentence;
        Tiretree tire;
        for(auto s:dict)//根据词典建立字典树
        {
            tire.insert(s);
        }
        string ret;
        //把句子分割成单词，再查字典树
        stringstream ss(sentence);
        string word;
        while(ss >> word)
        {
           ret+=tire.startwith(word)+' ';
        }
        if(ret.size()>0)
            ret.resize(ret.size()-1);
        return ret;
    }
};