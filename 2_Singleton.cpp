// 懒汉
// 饿汉
// 线程安全
// 双重检查/高效


#include <iostream>
#include <pthread.h>
using namespace std;
pthread_mutex_t lock ;//= PTHREAD_MUTEX_INITIALIZED;
class Singleton
{
	Singleton(){
		pthread_mutex_init(&lock,NULL);
	}
	static Singleton* m_instance;
public:
	// static Singleton* getInstance()
	// {
	// 	return m_instance;
	// }
	static Singleton* getInstance()
	{

		//////////////
		//单例存在之后,那么只需要判断是否存在,而不需要在进行互斥处理
		if(!m_instance)
		{
			{
				///////////////////
				//当两个线程都(首次不存在时)申请单例时,必要的加锁操作
				pthread_mutex_lock(&lock);
				if (!m_instance)
				{
					m_instance = new Singleton();
					pthread_mutex_unlock(&lock);
				}
			}
		}
		return m_instance;
	}
	static void Release()
	{
		pthread_mutex_destroy(&lock);
		if(m_instance)
		{
			cout << __func__<<endl;
			delete m_instance;
			m_instance = NULL;
		}
	}	
	~Singleton(){}

};

//饿汉
// Singleton* Singleton::m_instance = new Singleton();
//懒汉
Singleton* Singleton::m_instance = NULL;

//RAII删除器
struct Release
{
	~Release()
	{
		cout << __func__<<endl;
		Singleton::Release();
	}
};
Release s;

int main()
{
	Singleton* p = Singleton::getInstance();
	Singleton* q = Singleton::getInstance();
	cout << p<<endl;
	cout << q<<endl;
	return 0;
}