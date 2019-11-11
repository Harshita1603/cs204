
#include <bits/stdc++.h> 
using namespace std; 
  

#define v 4  
  

#define MIN 10000 
  

void floydWarshall (int graph[][v])  
{  
 
    int dist[v][v], i, j, k;  
  
    for (i = 0; i < v; i++)  
        for (j = 0; j < v; j++)  
            dist[i][j] = graph[i][j];  
  
   
    for (k = 0; k < v; k++)  
    {  
       
        for (i = 0; i < v; i++)  
        { 
            for (j = 0; j < v; j++)  
            {  
                
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    for (int i = 0; i < v; i++)  
    {  
        for (int j = 0; j < v; j++)  
        {  
            if (dist[i][j] == MIN)  
                cout<<"-"<<" ";  
            else
                cout<<dist[i][j]<<" ";  
        }  
        cout<<endl;  
    }
   
    
}  
  

int main()  
{  
    
    int graph[v][v] = { {0, 5, MIN, 10},  
                        {MIN, 0, 3, MIN},  
                        {MIN, MIN, 0, 1},  
                        {MIN, MIN, MIN, 0}  
                    };  
  
   
    floydWarshall(graph);  
    return 0;  
}  
  
