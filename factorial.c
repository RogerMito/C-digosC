#include <iostream>
using namespace std;

int fatorial (int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fatorial (n-1);
	}

}

int main()
{
      int n;
      cout<<"\tInforme o número que deseja calcular o fatorial"<<endl;
      cin>>n;
      if(n >= 0)
	cout<<fatorial(n)<<endl;
      return 0;
}
