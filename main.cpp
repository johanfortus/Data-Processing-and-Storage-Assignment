#include <iostream>
#include "InMemoryDB.h"
using namespace std;

int main() {

    InMemoryDB inmemoryDB;

    // should return null, because A doesn’t exist in the DB yet
    cout << inmemoryDB.get("A") << endl;

    // should throw an error because a transaction is not in progress
    inmemoryDB.put("A", 5);

    // starts a new transaction
    inmemoryDB.begin_transaction();

    // set’s value of A to 5, but its not committed yet
    inmemoryDB.put("A", 5);

    // should return null, because updates to A are not committed yet
    cout << inmemoryDB.get("A") << endl;

    // update A’s value to 6 within the transaction
    inmemoryDB.put("A", 6);

    // commits the open transaction
    inmemoryDB.commit();

    // should return 6, that was the last value of A to be committed
    cout << inmemoryDB.get("A") << endl;

    // throws an error, because there is no open transaction
    inmemoryDB.commit();

    // should return null because B does not exist in the database
    cout << inmemoryDB.get("B") << endl;

    // starts a new transaction
    inmemoryDB.begin_transaction();

    // Set key B’s value to 10 within the transaction
    inmemoryDB.put("B", 10);

    // Rollback the transaction - revert any changes made to B
    inmemoryDB.rollback();

    // Should return null because changes to B were rolled back
    cout << inmemoryDB.get("B") << endl;

    return 0;
}