遇到左括号入栈，遇到右括号和栈顶元素比较，若不匹配或栈空，直接返回０。
最后若栈非空，返回０，否则返回１
bool isValid(char * s){
    if(!s|| s[0]=="")//注意空字符串
        return true;
    if(strlen(s)%2==1)//长度为奇数直接无效
        return false;
    char* tmp=(char*)malloc(strlen(s));
    int top=-1;
    int i=0;
    for(i=0;i<strlen(s);i++)
    {
        switch(s[i]){
            case '(':
            case '{':
            case '[':
                tmp[++top]=s[i];//左括号依次入栈
                break;
            case ')':
                if(top<0 || tmp[top--]!='(')//跟上一个做匹配，不是则无效
                    return false;
                break;
            case '}':
                if(top<0 || tmp[top--]!='{')
                    return false;
                break;
            case ']':
                if(top<0 ||tmp[top--]!='[')
                    return false;
                break;
        }
    }
    if(top>=0)//如果栈里还有元素，没匹配完
        return false;
    return true;

}