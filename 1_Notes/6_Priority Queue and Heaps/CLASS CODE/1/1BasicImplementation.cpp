#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int>hp;
private:
    void upheapify(int ci) {
        while(ci > 0) {
            int pi = (ci - 1) / 2;
            if(hp[ci] > hp[pi]) {
                swap(hp[ci], hp[pi]);
                ci = pi;
            }
            else break;
        }
    }
public:
    bool isempty() {
        return hp.size() == 0;
    }
    void insert(int element) {
        hp.push_back(element);
        upheapify(hp.size() -1);
    }

    void display() {
        cout << "[ ";
        for(int i=0; i<hp.size(); i++) cout << hp[i] << " ";
        cout << "]\n";
    }
};

int main() {
    MaxHeap hp;
    hp.insert(23);
    hp.insert(3);
    hp.insert(2);
    hp.insert(239);
    hp.insert(0);
    hp.insert(3);
    hp.insert(283);
    hp.insert(239);
    hp.insert(2773);
    hp.insert(283);
    hp.insert(23);
    hp.insert(273);
    hp.display();

}