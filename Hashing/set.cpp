#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet;

    // Insert elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // duplicate — won't be added

    // Check if 10 exists in the set
    if (mySet.find(10) != mySet.end()) {
        cout << "10 exists in the set" << endl;
    } else {
        cout << "10 does not exist in the set" << endl;
    }

    // Print all elements in the set
    cout << "Elements in the set: ";
    for (int num : mySet) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
