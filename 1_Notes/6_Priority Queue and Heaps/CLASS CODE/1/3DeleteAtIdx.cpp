#include<bits/stdc++.h>
using namespace std;
class heap{
    vector<int>heap;
private:
    void upHeapify(int ci) {
        while(ci > 0) {
            int pi = (ci - 1)/2;
            if(heap[pi] < heap[ci]) {
                swap(heap[ci], heap[pi]);
                ci = pi;
            }
            else break;
        }
    }

    void downHeapify(int idx) {
        while(idx < heap.size()) {
            int lc = 2 * idx + 1;
            int rc = 2 * idx + 2;
            if(lc >= heap.size()) break;
            int maxEl = idx;
            if(heap[lc] > heap[maxEl]) maxEl = lc;
            if(lc < heap.size() and heap[rc] > heap[maxEl]) maxEl = rc;
            if(maxEl != idx) {
                swap(heap[idx], heap[maxEl]);
                idx = maxEl;
            }
            else break;
        }
    }
public:
    void push(int element) {
        heap.push_back(element);
        upHeapify(heap.size()-1);
    }
    void removeHighestPriority() {
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        if(heap.size()) downHeapify(0);
    }
    void deleteAtIdx(int idx) {
        heap[idx] = INT_MAX;
        upHeapify(idx);
        removeHighestPriority();
    }
    void display() {
        cout << "[ ";
        for(int i=0; i<heap.size() -1; i++) cout << heap[i] << " | ";
        cout << heap[heap.size() -1] << " ]\n";
    }
};
int main() {
    heap h;
    h.push(15);
    h.push(25);
    h.push(30);
    h.push(50);
    h.push(40);
    h.push(10);
    h.push(20);
    h.push(100);
    h.display();

    h.removeHighestPriority();
    h.display();

    h.deleteAtIdx(2);
    h.display();
}