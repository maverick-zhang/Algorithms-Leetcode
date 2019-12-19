//
// Created by maverick on 2019/12/19.
//

#ifndef ALGORITHMS_GRAPH_ADJACENT_MATRIX_H
#define ALGORITHMS_GRAPH_ADJACENT_MATRIX_H

#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

//使用邻接矩阵来表示图，其中1表示为两个相邻顶点连接
class GraphAdjacentMatrix
{
private:
    int E, V;

    bool directed;

    vector<vector<bool>> g;

    int index;    //记录迭代器当前的位置
    int iter_vertex; //记录当前迭代的顶点

    int * id = nullptr;
    bool * visited = nullptr;
    int count;

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
    explicit GraphAdjacentMatrix(int vertex, bool is_direct = false)
    {
        assert(vertex > 0);
        V = vertex;
        directed = is_direct;
        E = 0;
        index = -1;
        iter_vertex = -1;
        count = 0;

        for (int i = 0; i < V; ++i) {
            g.emplace_back(vector<bool>(V, false));
        }


    }

    explicit GraphAdjacentMatrix(const string & filename, bool is_direct)
    {
        fstream file(filename);
        assert(file.is_open());

        string line;

        V = E = -1;

        getline(file, line);
        stringstream ss(line);
        ss >> V >> E;
        directed = is_direct;

        index = -1;
        iter_vertex = -1;
        count = 0;

        //初始化邻接矩阵
        for (int i = 0; i < V; ++i) {
            g.emplace_back(vector<bool>(V, false));
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

    int vertex(){ return V;}
    int edge(){ return E;}

    bool has_edge(int v1, int v2)
    {
        assert(v1 >= 0 and v1 < V);
        assert(v2 >= 0 and v2 < V);

        if (v1 == v2)
            return true;

        return g[v1][v2];

    }

    void add_edge(int v1, int v2)
    {

        if (has_edge(v1, v2))
            return;

        g[v1][v2] = true;

        if (!directed)
        {
            g[v2][v1] = true;
        }

        E ++;

    }


    //返回顶点的迭代器，每一个返回值都代表其与顶点v相邻，使用index保存当前迭代的位置
    int begin(int v)
    {
        assert(v>0 and v < V);
        iter_vertex = v;
        //每一次使用迭代器都要去进行一次初始化
        for (int i = 0; i < V ; ++i) {
            if (g[v][i])
            {
                index = i;
                return i;
            }
        }

        index = V;

        return -1;
    }

    bool end()
    {
        return index >= V;
    }

    int next()
    {
        index ++;
        for (int i = index; i < V; i++)
        {
            if (g[iter_vertex][i])
            {
                index = i;
                return i;
            }
        }

        index = V;
        return -1;
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



//使用广度优先遍历查找任意节点v到达某个节点的最短距离
//广度遍历可以理解为层序遍历，离节点最近的层总是被优先遍历到，因此可以满足得到的结果都是最短路劲
template <typename Graph>
class ShortestPath
{
private:
    bool * visited;    //记录某个节点是否已经遍历过了
    int * from;        //记录从哪个节点到达该节点，用于倒推得到路径信息
    int vertex;        //起始点
    int * order;       //其余点到起始点的距离
    Graph & g;         //图的引用

public:
    ShortestPath(int v, Graph & graph):g(graph)
    {
        vertex = v;
        int V = graph.vertex();
        visited = new bool[V];
        order = new int[V];
        from = new int[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
            order[i] = -1;    //-1代表不连通，0为自己到自己的距离
            from[i] = -1;
        }

        //开始广度优先的遍历
        queue<int> que;

        que.push(vertex);
        int temp_vertex;
        while (!que.empty())
        {
            temp_vertex = que.front();
            que.pop();
            for (int i = g.begin(temp_vertex); !g.end(); i = g.next()) {
                if (!visited[i])
                {
                    visited[i] = true;
                    from[i] = temp_vertex;
                    order[i] = order[temp_vertex] + 1;
                    que.push(i);
                }
            }
        }


    }

    ~ShortestPath()
    {
        delete [] visited;
        delete [] from;
        delete [] order;
    }

    bool have_path(int w)
    {
        return visited[w];  //如果对于原点vertex，w在广度优先遍历的过程中被被遍历到，那么就代表两者之间是相连的
    }

    void path(int w, vector<int> & path_vt) //传入一个vector并把原点vertex到顶点w的路径信息写入vector中
    {
        assert(w>=0 and w < g.vertex());
        path_vt.clear();
        if (!have_path(w))
        {
            path_vt[0] = -1;
            return;
        }

        stack<int> st;

        int p = from[w];
        st.push(w);

        while (p != -1)
        {
            st.push(p);
            p = from[p];
        }

        while (!st.empty())
        {
            path_vt.push_back(st.top());
            st.pop();
        }
    }
};


#endif //ALGORITHMS_GRAPH_ADJACENT_MATRIX_H
