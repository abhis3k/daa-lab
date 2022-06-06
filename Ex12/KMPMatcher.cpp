#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class KMP
{
    char *pattern;
    int *lps;
    int M;
  public:
    KMP(){}
    KMP(char *pat);
    void printlps();
    void Compute_Prefix();
    void KMPMatcher(char *text);
};
KMP::KMP(char *pat)
{
    M = strlen(pat);
    pattern = new char[M+2];
    for (int i=1; i<=M+1; i++)
          pattern[i]= *(pat+i-1);
    lps = new int[M+1];
    Compute_Prefix();
}

void KMP::Compute_Prefix()
{
    int k = 0;
    lps[1] = 0; 
    for (int q=2; q<=M; q++)
    {
       while (k>0 && pattern[k+1] != pattern[q])
          k = lps[k];
       if (pattern[k+1] == pattern[q])
          k++;
       lps[q] = k;
    }
}
void KMP::printlps()
{
   for (int i=1; i<=M; i++)
      cout << lps[i] << ", ";
}
void KMP::KMPMatcher(char *text)
{
    int q = 0;
    int N=strlen(text);
    
    for (int i=0; i<N; i++)
    {
       cout << i <<": " << q;	
       while (q>0 && pattern[q+1] != text[i])
       {
          q = lps[q];
          cout << ", " << q;
       }
       if (pattern[q+1] == text[i])
          q++;	
       if (q == M)
       {
          cout << "Pattern found at position " << i-M+1 << endl;
          q = lps[q];
       }
       cout << endl;
    }
    cout << q << endl;
}
int main()
{
   char txt[50];   //"ABABDABABCABABCABAB";
   char pat[10];   //"ABABCABAB";
   char ch='y';
   cout << "Enter the pattern : "; cin >> pat;
   KMP K(pat);
   cout << "The preprocessed longest suffix array for the given pattern : "<<endl;
   K.printlps();
   cout << endl;
   do
   {
      cout << "Enter the text : "; cin >> txt;
      K.KMPMatcher(txt);
      cout << "Do you want to check for the same pattern in another text?(y/n) ";
      cin >> ch;
   }
   while (ch == 'y' || ch == 'Y');
   return 0;
}
