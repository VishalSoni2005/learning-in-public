#include<iostream>
using namespace std;
int maze(int sr,int sc,int er,int ec){
    if(sr>er||sc>ec) return 0;//BASE CONDITION
    if(sr==er && sc==ec) return 1;//BASE CONDITION
    int rightWays = maze(sr,sc+1,er,ec);//RECURSIVE CALLS
    int downWays = maze(sr+1,sc,er,ec);//RECURSIVE CALLS
    return rightWays + downWays;

}
void printPath(int sr,int sc,int er,int ec, string s){
    if(sr>er||sc>ec) return;            //BASE CONDITION
    if(sr==er && sc==ec){//Exactly apne condition pe pahuch gaya hu
        cout<<s<<" ";
        return;
    }          
    printPath(sr,sc+1,er,ec,s+'R');  //sc+1 right         //RECURSIVE CALLS
    printPath(sr+1,sc,er,ec,s+'D');   //sr+1 down       //RECURSIVE CALLS
    return;
}
int main(){
    int sr;
    cout<<"Enter starting row index : ";
    cin>>sr;
    int sc;
    cout<<"Enter starting column index : ";
    cin>>sc;
    int er;
    cout<<"Enter ending row index : ";
    cin>>er;
    int ec;
    cout<<"Enter ending column index : ";
    cin>>ec;

    cout<<"No of ways to complete the matrix is : "<<maze(sr,sc,er,ec)<<endl;
    cout<<"Path followed is : ";
    printPath(sr,sc,er,ec,"");
}