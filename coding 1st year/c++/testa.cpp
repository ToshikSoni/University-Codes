#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);//Insert element 1.
    v.push_back(2);//Insert element 2.

    //Now the vector(v) has 2 elements in it, with size 2

    v.pop_front(); // This method will remove the first element

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    //Prints [1]
    return 0;
}
