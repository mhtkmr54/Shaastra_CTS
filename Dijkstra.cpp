#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>
#include <string>

//g++ -std=c++0x
using namespace std;

vector<int> Dijkstra(vector<vector<int> > arr, int start, int end, vector<int> distarr){
 vector<int>::iterator it;
 string path;
 int pathlen = 0;
 map <int,int> vis;
 for (int k = 0; k < end+1; k++)
 {
     vis.insert(pair<int,int>(k,0));
 }

 int len  = arr[0].size();
 //cout << len << " arr[0].size() ";
 deque<pair<int,int> >mydeque;

 mydeque.push_back(make_pair(pathlen,start));
 while(!mydeque.empty())
 {
    int path = mydeque.front().first;
    int curr  = mydeque.front().second;
    //cout << " node b4 popping " << mydeque.front().second << endl;
    mydeque.pop_front();
    //cout << "path covered till " << mydeque.front().first << " current node  " << curr << endl;
    if (vis[curr] == 0)
    {
      //cout << " node which popped eligible -------------------------------------------------  -----------"    << curr << endl;
      distarr[curr] = path;
      vis[curr] = 1;
      //cout << "MAP" << endl;
/*      for(auto elem : vis)
      {
         cout << elem.first << " " << elem.second << " " << "\n";
      }*/
      if (curr == end){
        string ans  = to_string(path);
             //cout << "dist arr --------------------------------------------------------DIST AARR" << endl;
              for(auto elem : distarr)
              {
                 //cout << elem << " ";
                 if (elem == -1)
                 {
                   it=find(distarr.begin(),distarr.end(),-1);
                   auto pos = it - distarr.begin();
                   distarr = Dijkstra (arr,start,pos,distarr);
                 }
              }
              cout << endl;
        return distarr;
      }
      for (int k = 0; k < len; k++)
      {
        if (arr[curr][k] != -99 && vis[k] == 0)

        {
            //cout << "visk" << vis[k] << endl;
            int edgelen = arr[curr][k];

              //cout << "adding node " << k << endl;
              mydeque.push_back(make_pair(edgelen+path ,k));

        }
      }
      sort(mydeque.begin(),mydeque.end());
      //cout << "mydeque" << endl;
/*      for(auto elem : mydeque)
      {
         std::cout << elem.first << " " << elem.second << " " << "\n";
      }*/
    }
 }

}

int main(){
  int tests;
  cin >> tests;
  for (int a =0; a < tests; a++)
  {
    int nodes;
  int edges;
  cin >> nodes;
  cin >> edges;
  /*cout << "edges" << edges << endl;
  cout << "nodes" << nodes << endl;*/
  //vector < vector<pair<int,int> > > myvecofvec(n);
  vector < vector <int> > arr;
  arr.resize(nodes,vector<int>(nodes, -99));

  /*cout << "b4" << endl;*/

/*  for (int i =0; i < nodes ; i++)
  {
     for (int j =0; j < nodes; j++)
     {
        cout << arr[i][j] << " ";
     }
     cout << endl;
  }
  cout << endl;*/


  for (int j = 0 ; j < edges; j++)
  {
    int f,s,dist;
    cin >> f >> s >> dist;
    arr[f-1][s-1] = dist;
    arr[s-1][f-1] = dist;
  }
  int start;
  cin >> start;
  start = start - 1;
  for (int i =0; i < nodes ; i++)
  {
     for (int j =0; j < nodes; j++)
     {
        cout << arr[i][j] << " ";
     }
     cout << endl;
  }
  cout << endl;
  vector <int> distarr;
  distarr.resize(nodes,-1);
  distarr = Dijkstra (arr,start,nodes-1,distarr);
  int l =0;
  for(auto elem : distarr)
      {
         if (l != start)
         {
           cout << elem << " ";
         }
        l++;
      }
      cout << endl;
  }


  return 0;
}

