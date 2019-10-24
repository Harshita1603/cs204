#include <bits/stdc++.h> 
using namespace std; 

typedef long long lli;
typedef long li;

int COUNT; 

bool IS_TRUE(int x, int y, int key,vector<vector<int>> &input,vector<vector<int>> &visited,int n,int m) 
{ 
    if (x < n && y < m && x >= 0 && y >= 0) { 
        if (visited[x][y] == false && input[x][y] == key) 
            return true; 
        else
            return false; 
    } 
    else
        return false; 
} 

void BFS(int x, int y, int i, int j,vector<vector<int>> &input,vector<vector<int>> &visited,vector<vector<int>> &g_visited,int n,int m) 
{ 
    visited[i][j] = 1; 
    g_visited[i][j] = 1;
    COUNT++;
    if (x != y) 
        return; 
  
    int x_move[] = { 0, 0, 1, -1 }; 
    int y_move[] = { 1, -1, 0, 0 }; 
  
    for (int u = 0; u < 4; u++) 
        if (IS_TRUE(i + y_move[u], j + x_move[u], x, input, visited,n,m)) 
            BFS(x, y, i + y_move[u], j + x_move[u], input,visited,g_visited,n,m); 
} 
  

void reset_visited(vector<vector<int>> &visited,int n, int m) 
{ 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            visited[i][j] = 0; 
}  
void reset_result(int key,vector<vector<int>> &input,vector<vector<int>> &visited,vector<vector<int>> &result,int n, int m) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (visited[i][j] && input[i][j] == key) 
                result[i][j] = visited[i][j]; 
            else
                result[i][j] = 0; 
        } 
    } 
} 

int LargestConnectedGrid(vector<vector<int>> &input,vector<vector<int>> &visited,vector<vector<int>> &g_visited,vector<vector<int>> &result,int n, int m) 
{ 
    int current_max = INT_MIN; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if(g_visited[i][j]==0){
                COUNT = 0; 
  
                // checking cell to the right 
                if (j < m) 
                    BFS(input[i][j], input[i][j + 1], i, j, input,visited,g_visited,n,m); 
    
                // updating result 
                if (COUNT > current_max) { 
                    current_max = COUNT; 
                    reset_result(input[i][j], input,visited,result,n,m); 
                } 
                reset_visited(visited,n,m); 
                COUNT = 0; 
    
                // checking cell downwards 
                if (i + 1 < n) 
                    BFS(input[i][j], input[i + 1][j], i, j, input,visited,g_visited,n,m); 
    
                // updating result 
                if (COUNT > current_max) { 
                    current_max = COUNT; 
                    reset_result(input[i][j], input,visited,result,n,m); 
                } 
            }
            

        } 
    } 
    return current_max;
} 

int main() 
{ 
    int m1,n1,c;
    cin>>n1>>m1>>c;
    
    vector<vector<int>> input(n1);
    
    int temp;
    for(long i=0;i<n1;i++){
        for(long j=0;j<m1;j++){
            input[i].push_back(0);
        }
    }
    int x,y;
    for(long i=0;i<c;i++){
        cin>>x>>y;
        input[x-1][y-1] = 1;
    }
    

    vector<vector<int>> vis(n1);
    vector<vector<int>> g_vis(n1);
    vector<vector<int>> res(n1);
    
    for(long i=0;i<n1;i++){
        for(long j=0;j<m1;j++){
            vis[i].push_back(0);
            g_vis[i].push_back(0);
            res[i].push_back(0);
        }
    }
    for(long i=0;i<n1;i++){
        for(long j=0;j<m1;j++){
            if(!input[i][j]){
                g_vis[i][j]=1;
            }
        }
    }
    
    cout<<LargestConnectedGrid(input,vis,g_vis,res,n1,m1); 
    return 0; 
} 
