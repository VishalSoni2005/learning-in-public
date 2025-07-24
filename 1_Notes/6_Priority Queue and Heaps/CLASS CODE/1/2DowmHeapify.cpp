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
    void dowmHeapify(int idx) {
        while(idx < hp.size() ){
            int lc = 2 * idx + 1;
            int rc = 2 * idx + 2;
            if(lc >= hp.size()) break;
            int maxEl = idx;
            if(hp[lc] > hp[maxEl]) maxEl = lc;
            if(lc < hp.size() and hp[rc] > hp[maxEl]) maxEl = rc;
            if(maxEl != idx) {
                swap(hp[idx], hp[maxEl]);
                idx = maxEl;
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

    
    void pop_root() {
        if(hp.size() == 0) return ;
        swap(hp[0], hp[hp.size() - 1]);
        hp.pop_back();
        if(hp.size() != 0) dowmHeapify(0);
    }
    void display() {
        cout << "[ ";
        for(int i=0; i<hp.size(); i++) cout << hp[i] << " ";
        cout << "]\n";
    }
};

int main() {
    MaxHeap hp;
    hp.insert(1);
    hp.insert(2);
    hp.insert(3);
    hp.insert(4);
    hp.insert(5);
    hp.insert(6);
    hp.insert(7);
    hp.insert(8);
    hp.insert(9);    
    hp.insert(10);
    
    hp.pop_root();
    hp.display();

 
    // hp.pop_root();
    // hp.display();

    // hp.pop_root();
    // hp.display();

    // hp.pop_root();
    // hp.display();

    // hp.pop_root();
    // hp.display();
}