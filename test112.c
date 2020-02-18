//反转句子里的单词
void server(char *s,char* begin,char* end)
{
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
void *serverword(char* s)
{
	server(s,s,s+strlen(s)-1);
	char *cur = s;
	char* tmp;
	while (*s)
	{
		tmp = s;
		while (*tmp != ' '&& *tmp)
		{
			tmp++;
		}
		server(s, s, tmp - 1);
		if (*tmp)  //遇到空格
		{
			s = tmp + 1;
		}
		else
			s = tmp;
	}
}

void test1()
{
	char s1[1000];
	gets(s1);
	serverword(s1);
	puts(s1);
}
int main()
{
	/*char* s1 = "hjlhjk";
	char* s2 = "hjk";
	char* ret = strindex(s1, s2);
	if (*ret == NULL)
		printf("匹配失败！");
	else
		puts(ret);

	printf("匹配位置为：%d", StrIndex(s1, s2));*/
	test1();