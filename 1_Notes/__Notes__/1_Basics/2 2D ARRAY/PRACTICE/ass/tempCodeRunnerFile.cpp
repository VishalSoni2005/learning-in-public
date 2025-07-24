int res[m][b];
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            res[i][j] = 0;
            for(int k=0;k<a;k++){
                res[i][j] += arr[i][k]*brr[k][j];
            }
        }
    }