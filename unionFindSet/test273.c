class UnionFindSet
{
public:
    UnionFindSet(size_t n)
    {
        _v.resize(n,-1);
    }
    size_t Find(int x)
    {
        while(_v[x]>=0)
            x=_v[x];
        return x;
    }
    bool Union(int x1,int x2)
    {
        int root1=Find(x1);
        int root2=Find(x2);
        if(root1!=root2)
        {
            _v[root1]+=_v[root2];
            _v[root2]=root1;
            return true;
        }
        return false;
    }
private:
    vector<int> _v;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(26);//全为小写字母
        //先把相等的放入集合中，在把不相同的判断是否是在集合里，在，说明不合法
        for(auto& str:equations)
        {
            if(str[1]=='=')
            {
                ufs.Union(str[0]-'a',str[3]-'a');
            }
        }
        for(auto& str:equations)
        {
            if(str[1]=='!')
            {
                if(ufs.Find(str[0]-'a') == ufs.Find(str[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};