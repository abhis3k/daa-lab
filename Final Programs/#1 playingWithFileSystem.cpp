#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream ob; //output to file
    int r;
    ob.open("dummy.txt");
    for(int i=0; i<100; i++){
        r = rand()%50-25;
        //generating random +ve and -ve nos within 50
        ob<<r<<"  ";
    }
    ob.close();

    ifstream ob1; //input from file
    int a[100];
    ob1.open("dummy.txt");
    for(int j=0; j<100; j++){
        ob1>>a[j];
        cout<<a[j]<<"  ";
    }

    return 0;
}