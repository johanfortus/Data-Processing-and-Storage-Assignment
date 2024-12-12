#include "InMemoryDB.h"

void InMemoryDB::begin_transaction() {
    if(hasTransactionStarted == true)
        throw runtime_error("Only a single transaction may exist at a time");

    hasTransactionStarted = true;

}

void InMemoryDB::put(string key, int val) {
    if(hasTransactionStarted == false)
        throw runtime_error("No open transaction");

    currentTransaction.push_back({key, val});

}

int InMemoryDB::get(string key) {

    if(database.find(key) == database.end())
        return -1; // (null)

    return database[key];
}

void InMemoryDB::commit() {

    if(hasTransactionStarted == false)
        throw runtime_error("No open transaction");


    for(int i = 0; i < currentTransaction.size(); i++)
        database[currentTransaction[i].first] = currentTransaction[i].second;

    hasTransactionStarted = false;
}

void InMemoryDB::rollback() {
    if(hasTransactionStarted == false)
        throw runtime_error("No open transaction");

    currentTransaction.clear();
    hasTransactionStarted = false;
}
