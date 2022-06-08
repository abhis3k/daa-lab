#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main(){

    clock_t st, et;
    double etime;

    st=clock();

    for(int i=0; i<1000; i++){
    }

    et = clock();

    etime=(double)(et-st)/CLOCKS_PER_SEC;
    //number of clock ticks per second for a particular machine

    cout<<showpoint<<setprecision(8)<<etime;
    //showpoint is a flag set, which helps in displaying 
    //floating numbers with decimal values
    return 0;

}