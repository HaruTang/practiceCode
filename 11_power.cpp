#include <iostream>
using namespace std;

double powerWith(double base,unsigned int exponent)
{
	if(exponent==0)
		return 1;
	if(exponent==1)
		return base;

	double ret = powerWith(base,exponent>>1);
	ret*=ret;

	if(exponent&1==1)
		ret*=base;
	return ret;
}
double powerWith1(double base,unsigned int exponent)
{
	double ret = 1.0;
	for( int i = 1;i <= exponent;++i)
	{
		ret *= base;
	}
	return ret;
}

bool equal(double n1,double n2)
{
	return (n1 - n2 > -0.0000000001
		&& n1 - n2 < 0.0000000001);
}

double power(double base, int exponent)
{
	double ret = base;
	if(base==0&&exponent<0)
		return 0.0;

	unsigned int abs = (unsigned int)(exponent);
	if(exponent< 0)
		abs	= (unsigned int)(- exponent);
	ret = powerWith(base,abs);
	if(exponent<0)
		ret = 1.0/ret;
	return ret;
}

int main()
{
	cout << power(3.3,4)<<endl;
	return 0;
}