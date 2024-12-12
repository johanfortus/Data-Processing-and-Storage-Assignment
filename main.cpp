#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {

    unordered_map<string, int> database;
    database["hello"] = 1;
    unordered_map<string, int>::iterator iter;
    if(database.find("hell") == database.end()) {
        cout << "yes" << endl;
    };

    return 0;
}