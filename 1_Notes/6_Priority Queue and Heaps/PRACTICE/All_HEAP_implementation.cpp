// #include<bits/stdc++.h>
// using namespace std;
// class maxHeap{
//     vector<int> heap;
// private:
//     void upheapify(int ci) {
//         while(ci < heap.size()) {
//             int pi = (ci - 1) / 2;
//             if(heap[ci] > heap[pi]) {
//                 swap(heap[ci], heap[pi]);
//                 ci = pi;
//             }
//             else break;
//         }
//     }
//     // void dowmHeapify(int idx) {
//     //     while(idx < heap.size()) {
//     //         int lc = 2 * idx + 1;
//     //         int rc = 2 * idx + 2;
//     //         if(lc > heap.size()) break;
//     //         int check = idx;
//     //         //now compare for highest amount parent lc and rc
//     //         if(heap[lc] > heap[check]) check = lc;
//     //         if(lc < heap.size() and heap[rc] > heap[check]) check = rc;
//     //         if(check != idx) {
//     //             swap(heap[idx], heap[check]);
//     //             idx = check;
//     //         }
//     //         else break;
//     //     }
//     // }
//     void downHeapify(int idx) {
//         while(idx < heap.size()) {
//             int lc = 2 * idx + 1;
//             int rc = 2 * idx + 2;
//             if(lc > heap.size()) break;
//             int mxel = idx;
//             if(heap[lc] > heap[mxel]) mxel = lc;
//             if(lc < heap.size() and heap[rc] > heap[mxel]) mxel = rc;
//             if(mxel != idx) {
//                 swap(heap[idx], heap[mxel]);
//                 idx = mxel;
//             }
//             else break;
//         }
//     }
// public:
//     void push(int n) {
//         heap.push_back(n);
//         upheapify(heap.size() - 1);
//     }
//     void removeHighestPriority() {
//         if(heap.size() == 0) return ;
//         swap(heap[0], heap[heap.size()-1]);
//         heap.pop_back();
//         if(heap.size() != 0)downHeapify(0);
//     }
//     void peek() {
//         cout << heap[0] << endl;
//     }
//     void display() {
//         cout << "[ " << heap[0] << " | ";
//         for(int i=1; i<heap.size() - 1; i++) cout << heap[i] << " | ";
//         cout << heap[heap.size() -1] << " ]" << endl;
//     }
// };
// int main() {
//     maxHeap h;
//     h.push(1);
//     h.push(2);
//     h.push(3);
//     h.push(4);
//     h.push(5);
//     h.push(6);
//     h.push(7);
//     h.push(8);
//     h.push(9);
//     h.push(10);

//     h.display();


//     h.removeHighestPriority();
//     h.display();

    

// }

#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    vector<int> arr;
private:
    void upHeapify(int ci) {
        while(ci > 0) {
            int pi = (ci - 1) / 2;
            if(arr[ci] > arr[pi]) {
                swap(arr[ci], arr[pi]);
                ci = pi;
            }
            else break;
        }
    }
    void downHeapify(int idx) {
        while(idx < arr.size()) {
            int leftIdx = 2 * idx + 1;
            int rightIdx = 2 * idx + 2;
            if(leftIdx > arr.size()) break;
            int maxElIdx = idx;
            if(arr[leftIdx] > arr[maxElIdx]) maxElIdx = leftIdx;
            if(leftIdx > arr.size() and arr[rightIdx] > arr[maxElIdx]) maxElIdx = rightIdx;
            if(maxElIdx != idx) {
                swap(arr[maxElIdx], arr[idx]);
                idx = maxElIdx;
            }
            else break;
         }
    }
   // void downHeapify(int idx) {
//         while(idx < heap.size()) {
//             int lc = 2 * idx + 1;
//             int rc = 2 * idx + 2;
//             if(lc > heap.size()) break;
//             int mxel = idx;
//             if(heap[lc] > heap[mxel]) mxel = lc;
//             if(lc < heap.size() and heap[rc] > heap[mxel]) mxel = rc;
//             if(mxel != idx) {
//                 swap(heap[idx], heap[mxel]);
//                 idx = mxel;
//             }
//             else break;
//         }
//     }
public:
    void insert(int ele) {   // => T.C = o(log n)
        arr.push_back(ele);
        upHeapify(arr.size()-1);
    }
    void remove_HighestPriority() {
        // if(arr.size() == 0) return;
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        downHeapify(0);
    }
    void display() {
        cout << "[ " << arr[0] << " | ";
        for(int i=1; i<arr.size() - 1; i++) cout << arr[i] << " | ";
        cout << arr[arr.size() -1] << " ]" << endl;
    }
};
int main() {
    maxHeap hp;
    hp.insert(200);
    hp.insert(11);
    hp.insert(12);
    hp.insert(22);
    hp.insert(100);
    hp.insert(99);
    hp.insert(103);
    hp.insert(10);
    hp.insert(9);
    hp.insert(8);
    hp.insert(1);
    hp.display();

    hp.remove_HighestPriority();
    hp.display();
    priority_queue<pair<int, int>>mp;
}
