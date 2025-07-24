//Max heap
#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    vector<int> heap;
private:
    void upheapify(int ci) {
        while(ci > 0) {
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
            if(lc >= heap.size()-1 )break;
            int maxEl = idx;    //TO FIND INDEX OF MAXIMUM ELEMENT
            if(heap[maxEl] < heap[lc]) maxEl = lc;
            if(lc < heap.size() and heap[rc] > heap[maxEl]) maxEl = rc;
            if(maxEl != idx) {
                swap(heap[maxEl], heap[idx]);
                idx = maxEl;
            }
            else break;
        }
    }
public:
    void removeMaxPriority() {
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        downHeapify(0);
    }
    void push(int i) {
        heap.push_back(i);
        if(heap.size() != 0) upheapify(heap.size() - 1);
    }
    void display() {
        cout << "[ ";
        for(int i=0; i<heap.size() -1; i++) cout << heap[i] << " | ";
        cout << heap[heap.size() -1] << " ]\n";
    }
};
int main() {
    maxHeap h;
    h.push(15);
    h.push(25);
    h.push(30);
    h.push(50);
    h.push(40);
    h.push(10);
    h.push(20);
    h.push(100);

    h.display();

    h.removeMaxPriority();
    h.display();

}