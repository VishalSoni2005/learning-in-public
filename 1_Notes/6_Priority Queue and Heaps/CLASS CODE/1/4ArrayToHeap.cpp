#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    int i;
    vector<int> heap;
private:
    void upHeapify(int ci) {
        while(ci < heap.size()) {
            int pi = (ci - 1) / 2;
            if(heap[ci] > heap[pi]) {
                swap(heap[pi], heap[ci]);
                ci = pi;
            }
            else break;
        }
    }
    void downHeapify(int idx) {
        while(idx < heap.size()) {
            int lc = 2 * idx + 1;
            int rc = 2 * idx + 2;
            if(lc > heap.size()) break;
            int mxel = idx;
            if(heap[lc] > heap[mxel]) mxel = lc;
            if(lc < heap.size() and heap[rc] > heap[mxel]) mxel = rc;
            if(mxel != idx) {
                swap(heap[idx], heap[mxel]);
                idx = mxel;
            }
            else break;
        }
    }
public:
    maxHeap (vector<int> v) {
        heap = v;
        for(int i=1; i<heap.size(); i++) { // T.C. -> O(nlogn)
            upHeapify(i);
        }
    }
    void push(int element) { //NO NEED OF PUSH FUNCTION
        heap.push_back(element);
        upHeapify(heap.size()-1);
    }
    

    void display() {
        cout << "[ ";
        for(int i=0; i<heap.size() -1; i++) cout << heap[i] << " | ";
        cout << heap[heap.size() -1] << " ]\n";
    }
};
int main() {
    vector<int> v = {15, 25, 30, 50, 40, 10, 20, 100};
    maxHeap h(v);
    h.display();
    h.push(900);
    h.display();
}