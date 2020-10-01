#include <bits/stdc++.h>
using namespace std;

/* Prerequisites: What are graphs, difference between undirected and directed graphs, vectors in C++*/
void addedge_matrixrep(vector<vector<int>> &adjmat, int source, int destination, int cost=1)     // cost is the default paramter here, in case of    
{                                                                               // weighted graph, you can pass the weights in the function
    adjmat[source][destination] = cost;
    adjmat[destination][source] = cost;             // in case of directed graph, this will not be present as in directed graph (a-->b) is not (b-->a)
} 

void addedge_listrep(vector<vector<int>> &adjlist, int source, int destination)
{
    adjlist[source].push_back(destination);
    adjlist[destination].push_back(source);            // in case of directed graph, this will not be present as in directed graph (a-->b) is not (b-->a)
}

/*void addedge_listrep_weighted(vector<vector<pair<int,int> &adjlist, int source, int dest )  // case of undirected weighted graph
{
    adjlist[source].push_back({cost,dest});              // putting costs as first element eases out to find lowest costing edge by sorting.
    adjlist.[dest].push_back({cost,source});             // in case of directed graph, this will not be present as in directed graph (a-->b) is not (b-->a)
}*/

int main()
{
    /* We will try learn about the ways for representing graphs. We will first try to represent the undirected graph
       then extend the concept to represent undirected graph.
       There are basically two ways of representation of graphs:
            1. Using Adjacency matrix 
            2. Using Adjacency List

            0                 4-------5
            | \              /
            |  \            /
            |   \          / 
            |    1--------3--------6        
            |   /                 /  
            |  /                 /
            | /                 /
            2           8------7         9

        

        Yeah I tried and failed writing DS with the graph.But let's bear with it and move ahead.The above graphs have 10 vertices 
        and 8 undirected edges( (1---2) is equivalent to (2---1))
        */

       /*
       
        ADJACENCY MATRIX REPRESENTATION
        =============================================================================================================
        Here in this kind of representation, we construct a square 2D vector of dimension n*n, where n is the number of nodes,10 in
        our case.Lets call this matrix as adjmat.Now we fill each position in this matrix with 0 or 1, which depicts the presence or absence of edge between two nodes.
        If there exists an edge between node A and node B, then we will mark adjmat[A][B]=1 else adj[A][B] would be zero. For example, in above graph
            adjmat[1][2]=1
            adjmat[1][0]=1
            adjmat[1][3]=1
        But, adjmat[1][8]=0 or adjmat[1][9]=0  
        
        */
       vector<vector<int>> adjmat(10,vector<int>(10,0));  // Declaring a 10*10 matrix initialised with Zero.
       addedge_matrixrep(adjmat,1,0); 
       addedge_matrixrep(adjmat,1,2);
       addedge_matrixrep(adjmat,1,3);
       addedge_matrixrep(adjmat,3,6);
       addedge_matrixrep(adjmat,3,4);
       addedge_matrixrep(adjmat,4,5);
       addedge_matrixrep(adjmat,6,7);
       addedge_matrixrep(adjmat,7,8);    //added all the 8 edges
       
       // the adjmat will look like
       /*      0 1 2 3 4 5 6 7 8 9 
            ----------------------
            0| 0 1 0 0 0 0 0 0 0 0 
            1| 1 0 1 1 0 0 0 0 0 0 
            2| 0 1 0 0 0 0 0 0 0 0 
            3| 0 1 0 0 1 0 1 0 0 0 
            4| 0 0 0 1 0 1 0 0 0 0 
            5| 0 0 0 0 1 0 0 0 0 0 
            6| 0 0 0 1 0 0 0 1 0 0 
            7| 0 0 0 0 0 0 1 0 1 0 
            8| 0 0 0 0 0 0 0 1 0 0 
            9| 0 0 0 0 0 0 0 0 0 0    // No '1' in the 10th row or column , which shows that node 9 is not connected with any other node.
            
            You can notice the edges between (0,1), (1,2) and others.You can also notice the symmeteric nature of the matrix, which happens
            as the graph is undirected.This representation can check for existence of edge between two nodes in O(1). But,sadly we see a lot
            of zeroes in the matrix. This is a disadvantage of adjacency matrix representaion that it takes O(n*n) space even for sparse graphs.
        
        ADJACENCY LIST REPRESENTATION
        ====================================================================================================================================

            So we compromise between space and time to come up with adjacency list representation where we make a variable sized dynamic 2D 
            vector. This vector has n( no of nodes) of variable size. The size of each vector gives the number of edges coming into that particular
            node. Each entry in the row R shows the nodes that can be directly reached by the node R.

            for exapmle , in above graph
            0: 1 2
            1: 0 2 3
        */
       vector<vector<int>> adjlist(10); // Declared a 2D vector with 10 rows

       addedge_listrep(adjlist,1,0);
       addedge_listrep(adjlist,1,2);
       addedge_listrep(adjlist,1,3);
       addedge_listrep(adjlist,3,6);
       addedge_listrep(adjlist,3,4);
       addedge_listrep(adjlist,4,5);
       addedge_listrep(adjlist,6,7);
       addedge_listrep(adjlist,7,8);
       
       // the adjlist will look like
   /*   0|->1 
        1|->0 2 3 
        2|->1 
        3|->1 6 4 
        4|->3 5 
        5|->4 
        6|->3 7 
        7|->6 8 
        8|->7 
        9|->
  */
 
        /* This adjacency list saves up space but at the cost of increased time complexity for checking whether there exits a node between two edges*/
       // for dealing with weighted graphs we can make a vector of pairs to store the destination and the corresponding cost of the edge
       // like this vector<vector<pair<int,int>> adjlist(10,vector<pair<int,int>>) */

       /*So each representation has its pros and cons. To read more about this feel free to refer
                        https://stackoverflow.com/questions/2218322/what-is-better-adjacency-lists-or-adjacency-matrices-for-graph-problems-in-c

        */
       return 0;
}