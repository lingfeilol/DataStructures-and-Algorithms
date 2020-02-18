#include<stdio.h>
#include<string.h>
//字符串模式匹配
const char*  strindex(const char* s,const char* t)
{
	const char* ss = s;
	const char* ts = t;
	while (*ss)
	{
		const char* start = ss;//记录被匹配串的每一次开始匹配的位置
		while (*ss == *ts && *ts != '\0')
		{
			ss++;
			ts++;
		}
		if (*ts == '\0')//说明全部匹配成功
		{
			return  start;//返回一开始就匹配的位置
		}
		else     //匹配不成功  回溯
		{
			ss = start + 1;//主串从start+1开始
			ts = t;//模式串从头重新匹配
		}
	}
	return NULL;
}
int StrIndex(char* s, char* t)
{
	int i, j, start;
	start = 0;
	i = 0; j = 0;
	start = i;
	int slen = strlen(s);
	int tlen = strlen(t);
	while (i<slen  && j<tlen)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else  //回溯
		{
			start++; //主串往前走一步
			i = start; //下一次主串从start+1开始
			j = 0;//模式串还是从头开始
		}
	}
	if (j >= tlen)//匹配成功
	{
		return start;
	}
	else  //失败
	{
		return -1;
	}
}