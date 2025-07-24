#include<iostream>
using namespace std;
int main(){
    int row = 3;
    int col = 3;
    int ** arr = new int*[row];
    for(int i=0 ; i < row ; i++) {
        arr[i] = new int[col];
        //cin >> arr[i];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j] ;
        }
    }
    cout << endl;
    //printing
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //DEALLOCATING THE ARRAY 
    for(int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    cout << endl << "After deallocation " << endl;
      //printing
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}