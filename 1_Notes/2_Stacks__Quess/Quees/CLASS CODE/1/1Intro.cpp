#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> qe;
    for(int i=1; i<=10; i++)    qe.push(i*10);

    cout<< qe.front() << endl;

    cout << "Your Queue Sir : ";
    for(int i=1; i<=10; i++) {
        int x = qe.front();
        cout << x << " ";
        qe.pop();
        qe.push(x);
    }
}