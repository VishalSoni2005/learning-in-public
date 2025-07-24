#include<bits/stdc++.h>
using namespace std;
int noPair = 0;
int inversion(vector<int>&v , vector<int>&u){
    int count = 0 ;
    int i=0;//a
    int j=0;//b
    while(i<v.size() && j<u.size()){
        if(v[i] > u[j] ) {
            count += (v.size() -i);
            i++;
        }
        else j++;
    }
    return count;
}
void mergeArray(vector<int>& v1 , vector<int>&v2 , vector<int>&v){
    int n = v1.size();
    int m = v2.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n && j<m){
        if(v1[i] <= v2[j]) v[k++] = v1[i++];     //  <= IS TO MAKE SORTING STABLE
        else v[k++] = v2[j++];
        
    }
    if(i == n) while(j<m) v[k++] = v2[j++];
    if(j == m) while(i < n) v[k++] = v1[i++];
}
void mergeSort(vector<int>&v){
    int n = v.size();
    if(n == 1) return;
    int n1 = n/2;
    int n2 = n - n/2;
    vector<int>v1(n1);    
    vector<int>v2(n2);  
    //COPYING THE ELEMENTS OF V ARRAY IN V1 AND V2
    for(int i=0;i<n1;i++){
        v1[i] = v[i];
    }
    for(int i=0;i<n2;i++){
        v2[i] = v[i+n1];
    }
    //ELEMENTS ARE DIVIDED {NOW MAGIC AKA RECURSION OCCURE}
    mergeSort(v1);
    mergeSort(v2);
    /////////////////////
    noPair += inversion(v1,v2);
    //////////////////////////
    mergeArray(v1,v2,v);
    /////////////////////
    v1.clear();       //WE ARE CLEARING VECTOR FOR EFFICIENT SPACE COMP....
    v2.clear();       //WE ARE CLEARING VECTOR FOR EFFICIENT SPACE COMP....  
}
int main(){
    int n;
    cout<<"Enter size array : ";
    cin>>n;
    vector<int>arr1(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    mergeSort(arr1);
    cout<<"Number of inversion pairs are : "<<noPair;
}
