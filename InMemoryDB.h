#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <stdexcept>
using namespace std;

class InMemoryDB {

    bool hasTransactionStarted = false;

public:

    unordered_map<string, int> database;

    void begin_transaction();

    void put(string key, int val);


    int get(string key);

    void commit();

    void rollback();
};