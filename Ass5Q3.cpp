#include <bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>>&mat, int n, int m){
    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
    for (int i=0;i<n+2;i++){
        for (int j=0;j<m+2;j++){
            if (i==0||j==0||i==n+1||j==m+1){
                vis[i][j] = true;
            }
        }
    }
    int tl = 0;
    int bl = n-1;
    int ll = 0;
    int rl = m-1;

    while (tl<bl&&ll<rl){
        
        int previ = tl;
        int prevj = ll;
        int stor = mat[tl][ll];
        int i = tl;
        int j = ll+1;
        bool l = true;
        bool t, r, b;
        while (i!=tl&&j!=ll){
            cout<<i<<" "<<j<<endl;
            if (vis[i+1][j+1]==true){
                // break;
                if (t){
                    l = true;
                    t = false;
                    j++;
                    i++;
                }else if(l){
                    b = true;
                    l = false;
                    i--;
                    j++;
                }else if(b){
                    r = true;
                    b = false;
                    j--;
                    i--;
                }else{
                    t = true;
                    r = false;
                    i++;
                    j--;
                }
            }
            vis[i+1][j+1] = true;
            int x = mat[i][j];
            mat[i][j] = stor;
            stor = x;
            if (t){j++;}
            else if (r){i++;}
            else if(b){j--;}
            else{i--;}
        }


        tl--;
        bl++;
        ll++;
        rl--;
    }

}


int  main(){
    int n, m, t;
    cin>>n>>m>>t;
    vector<vector<int>>mat(n, vector<int>(m)), ans(n, vector<int>(m));
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    rotate(mat, n, m);

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }






}