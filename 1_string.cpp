#include <iostream>
#include <string.h>
using namespace std;

class String
{
friend ostream& operator<<(ostream& os,const String& s);

public:
	String(const char* pData = NULL)
	{
		if(pData == NULL)
		{
			m_pData = new char [1];
			m_pData[0] = '\0';
		}
		else
		{
			m_pData = new char [strlen(pData)+1];
			strcpy(m_pData,pData);
		}

	}
	String(const String& s)
	:m_pData(new char [strlen(s.m_pData)+1])
	{
		strcpy(m_pData,s.m_pData);
	}
	String& operator=(const String& s)
	{
		if(this!=&s)
		{
			String tmp(s.m_pData);
			swap(m_pData,tmp.m_pData);			
		}
		return *this;
	}
	~String()
	{
		if(m_pData)
		{
			delete [] m_pData;
			m_pData = NULL;
		}
	}
private:
	char* m_pData;	
};

ostream& operator<<(ostream& os,const String& s)
{
	os<< s.m_pData;
	return os;
}

int main(int argc, char const *argv[])
{
	const char * p = "hello";
	String s1;
	String s(p);
	String r(s);
	String q = r;
	cout << s <<endl;
	cout << r <<endl;
	cout << q <<endl;

	return 0;
}