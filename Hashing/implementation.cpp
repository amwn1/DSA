#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m; // creation of the map 
    
    // insetion of the map 
    pair<string,int> p = make_pair("aman",1);
    m.insert(p);
    
    //second way of insertion

    pair<string, int> pair2("malik",2);
    m.insert(pair2);

    //third way of insertion

    m["kumar"] = 3; // this will insert the value 3 with the key kumar 

    return 0;
}
