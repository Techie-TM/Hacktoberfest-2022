#include <iostream> 
#include <list>

using namespace std;
class Graph{
    int v;
    list<int> *adj;
    public:
      Graph(int v);
      void addEDGE(int a,int b);
       void BFS(int s); 
};
Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
};
void Graph::addEDGE(int a,int b){
   adj[a].push_back(b);
};
void Graph::BFS(int s){
     bool *visited = new bool[v];
     for(int i=0;i<v;i++){
         visited[i]=false;
     }
     list<int> queue;
     visited[s]=true;
     queue.push_back(s);
     list<int>::iterator i;
      while(!queue.empty()){
          s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
}
};
int main()
{
    Graph g(4);
    g.addEDGE(0, 1);
    g.addEDGE(0, 2);
    g.addEDGE(1, 2);
    g.addEDGE(2, 0);
    g.addEDGE(2, 3);
    g.addEDGE(3, 3);
    g.BFS(2);
 
    return 0;
}
