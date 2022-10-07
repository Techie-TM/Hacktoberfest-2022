

//User function Template for Java
import java.util.*;

class Solution
{
   //Function to find the shortest distance of all the vertices
   //from the source vertex S.
   static class EdgeWsf implements Comparable<EdgeWsf>{
       int nbr;
       int wsf;
       EdgeWsf(int nbr, int wsf){
           this.nbr = nbr;
           this.wsf = wsf;
       }
       
       @Override
       public int compareTo(EdgeWsf other){
           return this.wsf - other.wsf;
       }
       
   }
   
   static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S)
   {
       // Write your code here
       PriorityQueue<EdgeWsf> pq = new PriorityQueue<>();
       
       //find source
       EdgeWsf source = new EdgeWsf(S, 0);
       pq.offer(source);
       
       boolean[] visited = new boolean[V];
       int[] res = new int[V];
       
       while(pq.size() > 0){
           EdgeWsf cur = pq.poll();
           int v = cur.nbr;
           
           if(visited[v] == true) continue;
           
           visited[v] = true;
           
           res[v] = cur.wsf;
           
           for(ArrayList<Integer> x : adj.get(v)){
               if(visited[x.get(0)] == false){
                   pq.offer(new EdgeWsf(x.get(0), cur.wsf+x.get(1)));
               }
           }
       }
       return res;
   }
}