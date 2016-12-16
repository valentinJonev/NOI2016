#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Worker{
private:
    int handshakes_givven;
    int friends;

public:
    int get_friends(){
        return this->friends;
    }
    void add_friends(int friends){
        this->friends+=friends;
    }
    Worker(int handshakes_givven){
        this->handshakes_givven = handshakes_givven;
        this->friends = 0;
    }
    Worker(){}

    bool operator<(Worker& j) { return (this->get_friends() > j.get_friends()); }
};

int main()
{
    vector<Worker> workers;
    string n = "";
    getline(cin, n);
    string input = "";
    getline(cin, input);
    istringstream is( input );
    int handshakes;
    int workerNum = 0;
    while( is >> handshakes ) {
        if(handshakes > 0 && workerNum > 0){
            for(int i = 0; i < handshakes; i++){
                workers[i].add_friends(1);
            }
        }
        Worker worker(handshakes);
        worker.add_friends(handshakes);
        workers.push_back(worker);
        std::sort(workers.begin(), workers.end());
        workerNum++;
    }
    cout << workers[0].get_friends() << endl;
    cout << workers[workers.size()-1].get_friends() << endl;
}
