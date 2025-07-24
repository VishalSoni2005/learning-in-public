//  in heap sort we replace the inefficient linear search subroutine of selection sort with heap
// heap can give min element and then remove it in logn time
#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    vector<int>heap;
    int k;
private:
    void upHeapify(int ci) {
        while(ci < heap.size()){
            int pi = (ci - 1) / 2;
            if(heap[ci] > heap[pi]) {
                swap(heap[ci], heap[pi]);
                ci = pi;
            }
            else break;
        }
    }
    void downHeapify(int pi) {
        while(pi < heap.size()) {
            int lc = 2 * pi + 1;
            int rc = 2 * pi + 2;
            if(lc > heap.size()) break;
            int maxEle = pi;
            if(heap[lc] > heap[maxEle]) maxEle = lc;
            if(lc < heap.size() and heap[rc] > heap[maxEle]) maxEle = rc;
            if(maxEle != pi) {
                swap(heap[pi], heap[maxEle]);
                pi = maxEle;
            }
            else break;
        }
    } 
public:
    maxHeap(vector<int> currArr) {
        this->k = currArr.size()-1;
        this->heap = currArr;
        
        int n = (currArr.size() / 2) - 1;
        for(int i=n; i>=0; i--) downHeapify(i); // here we provide pi of element of currArr
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