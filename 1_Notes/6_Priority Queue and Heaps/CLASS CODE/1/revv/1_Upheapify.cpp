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
public:
    void push(int i) {
        heap.push_back(i);
        upheapify(heap.size() - 1);
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

}