#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class RabinKarp
{
  char Pattern[100];
  int m;
  int d;
  long int q;

public:

  RabinKarp(char p[])
  {
    strcpy(Pattern, p);
    m = strlen(Pattern);
    d = 10;
    q = 100000;
  }

  void match(char Text[])
  {
     int n=strlen(Text);
     long int h = long(pow(d, m-1)) % q;
     long int p=0, t=0;
     for (int i=0; i<m; i++)
     {
	     p = (p*d+(Pattern[i]-'a'+1)) % q;
	     t = (t*d+(Text[i]-'a'+1)) % q;
     }
     cout << "Pattern = "<<p<<endl<<endl;
     for (int s=0; s<=n-m; s++)
     {
       cout << "T"<<s <<"="<<t<<endl;
	   if (p == t)
	   {
	     int flag = 1;
	     for (int i=0; i<m; i++)
	     {
	       if (Pattern[i] != Text[s+i])
	       {
	  	     flag = 0;
		     break;
	       }
	     }
	     if (flag)
	         cout << "Pattern matches with shift" << s << endl;
	   }
	   if (s<n-m)
	     t = (((t - (Text[s]-'a'+1)*h)*d)+(Text[s+m]- 'a'+1)) % q;
     }
  }
};
int main()
{
  char p[100], t[500];
  char ch;
  cout << "Enter the pattern to match: ";
  cin >> p;
  RabinKarp rk(p);
  do
  {
     cout << "Enter the text to match: ";
     cin >> t;
     rk.match(t);
     cout << "Do you want search in another text (y/n) ? ";
     cin >> ch;
  }
  while (ch == 'y' || ch == 'Y');
  return 0;
}

