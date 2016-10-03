#include <iostream>
#include <string.h>
using namespace std;

void ReplaceBlack(char* str,int length)
{
	if(!str || length<=0)
		return;
	
	int strLen = strlen(str);
	
	int blankCount = 0;
	for(int i = 0; i < strLen;++i)
		if(str[i]==' ')
			blankCount++;

	int totalLen = strLen + blankCount*2;

	char* endT = str+totalLen;
	char* strEnd = str+strLen;

	while(endT!=strEnd)
	{
		if(*strEnd==' ')
		{
			*endT-- = '0';
			*endT-- = '2';
			*endT-- = '%';
		}
		else
		{
			*endT-- = *strEnd;
		}
		strEnd--;
	}
}
int main()
{
	char str[100] = "    ";
	// char str[100] = "i am liang li hui  ";
	cout << str<<endl;
	ReplaceBlack(str,100);
	cout << str<<endl;
	return 0;
}