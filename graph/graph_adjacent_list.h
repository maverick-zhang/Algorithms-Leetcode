//
// Created by maverick on 2019/12/19.
//

#ifndef ALGORITHMS_GRAPH_ADJACENT_LIST_H
#define ALGORITHMS_GRAPH_ADJACENT_LIST_H

#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>


using namespace std;

class GraphAdjacentList
{
private:
    int V;      //vertex图中的顶点数
    int E;      //edge图中的边的数目

    bool directed;  //是否为有向图

    int index;    //记录迭代器当前的位置
    int iter_vertex; //记录当前迭代的顶点

    vector<vector<int>> g;    //保存图中的邻接表

    int * id = nullptr;       //记录顶点所处的连通分量的数组
    bool * visited = nullptr;
    int count;      //记录连通分量的个数


    //从顶点v对图进行深度遍历
    void dfs(int v)
    {

        for(int i = begin(v); !end(); i = next())
        {
            if (i == -1)
                break;
            if (visited[i])
                continue;
            visited[i] = true;
            id[i] = count;
        }

    }



public:
    explicit GraphAdjacentList(int vertex, bool is_direct = false)     //输入顶点数和是否为有向图来创建一个空的图
    {
        assert(vertex > 0);
        V = vertex;
        E = 0;
        directed = is_direct;

        index = -1;
        iter_vertex = -1;
        count = 0;

        //初始化邻接表
        for (int i = 0; i < V; ++i) {
            g.emplace_back(vector<int>());
        }


    }

    explicit GraphAdjacentList(const string & filename, bool is_direct = false)
    {
        fstream file(filename);
        assert(file.is_open());
        V = E = 0;
        string line;

        getline(file, line);
        stringstream ss(line);
        ss >> V >> E;
        directed = is_direct;

        index = -1;
        iter_vertex = -1;
        count = 0;

        //初始化邻接表
        for (int i = 0; i < V; ++i) {
            g.emplace_back(vector<int>());
        }

        int v1, v2;
        while (!file.eof())
        {
            getline(file, line);
            stringstream ss(line);
            ss >> v1 >> v2;
            add_edge(v1, v2);
        }


    }

    ~GraphAdjacentList(){delete [] id; delete [] visited;}

    //返回图中的顶点个数和边的个数
    int vertex(){ return V;}
    int edge(){ return E;}

    bool has_edge(int v1, int v2)  //指定两个顶点之间v1和v2是否有边，对于有向图则表示是否存在从v1到v2的边
    {
        assert(v1 >=0 and v1 < V);
        assert(v2 >=0 and v2 < V);

        for (int i : g[v1]) {
            if (i == v2)
                return true;
        }

        return false;
    }


    void add_edge(int v1, int v2)    //给顶点v1和顶点v2之间添加一条边
    {
        if (v1 == v2)
            return;

        if (has_edge(v1, v2))
            return;

        g[v1].push_back(v2);

        if (!directed)
        {
            g[v2].push_back(v1);
        }

        E ++;
    }

    int begin(int v)
    {
        assert(v>=00 and v<V);
        iter_vertex = v;
        index = 0;
        if (g[v].empty())
            return -1;
        return g[v][index];

    bool end()
    {
        return (index + 1) >= g[iter_vertex].size();
    }

    int next()
    {
        index ++;
        return g[iter_vertex][index];
    }


    //返回图中的连通分量个数
    int component()
    {
        if (V == 0)
            return 0;
        if (count == 0)
        {
            id = new int[V];
            visited = new bool[V];
            for (int j = 0; j < V; ++j) {
                visited[j] = false;
            }
            for(int i=0; i<V; i++)
            {
                if (!visited[i])
                {
                    count ++;
                    dfs(i);
                }
            }

        }

        return count;

    }

    bool is_connected(int v1, int v2)
    {
        assert(v1 >=0 and v1 < V);
        assert(v2 >=0 and v2 < V);
        if (count==0)
            component();
        return id[v1] == id[v2];
    }

};

#endif //ALGORITHMS_GRAPH_ADJACENT_LIST_H
