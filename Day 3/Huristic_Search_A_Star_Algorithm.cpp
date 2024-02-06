#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> huristic;                    // straight line cost of each node from source to destination
unordered_map<string, vector<pair<string, int>>> graph; // graph representation
void astar(string source, string destination)
{
    unordered_map<string, int> gcost;
    unordered_map<string, int> fcost;
    unordered_map<string, string> parent;
    for (auto x : huristic)
    {
        gcost[x.first] = INT_MAX;
        fcost[x.first] = INT_MAX;
    }
    gcost[source] = 0;
    fcost[source] = huristic[source];
    set<pair<int, string>> s;
    s.insert({fcost[source], source});
    while (!s.empty())
    {
        auto p = *(s.begin());
        string node = p.second;
        int nodecost = p.first;
        s.erase(s.begin());
        for (auto x : graph[node])
        {
            string child = x.first;
            int cost = x.second;
            if (gcost[child] > gcost[node] + cost)
            {
                parent[child] = node;
                gcost[child] = gcost[node] + cost;
                fcost[child] = gcost[child] + huristic[child];
                s.insert({fcost[child], child});
            }
        }
    }
    // printing the path
    string temp = destination;
    vector<string> path;
    while (temp != source)
    {
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
        if (i != path.size() - 1)
        {
            cout << "-> ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n; // no of nodes
    for (int i = 0; i < n; i++)
    {
        string s;
        int cost;
        cin >> s >> cost;
        huristic[s] = cost;
    }
    int edge; // no of edges
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        string source, destination;
        int cost;
        cin >> source >> destination >> cost;
        graph[source].push_back({destination, cost});
        graph[destination].push_back({source, cost});
    }
    string source = "Arad", destination = "Bucharest";
    cin >> source >> destination;
    astar(source, destination);
    return 0;
}
// Input:
/*
20
Arad 366
Bucharest 0
Craiova 160
Dobreta 242
Eforie 161
Fagaras 178
Giurgiu 77
Hirsova 151
Iasi 226
Lugoj 244
Mehadia 241
Neamt 234
Oradea 380
Pitesti 98
Rimnicu_Vilcea 193
Sibiu 253
Timisoara 329
Urziceni 80
Vaslui 199
Zarind 374

23
Arad Sibiu 140
Arad Timisoara 118
Arad Zarind 75
Oradea Zarind 71
Oradea Sibiu 151
Sibiu Fagaras 99
Sibiu Rimnicu_Vilcea 80
Timisoara Lugoj 111
Lugoj Mehadia 70
Mehadia Dobreta 75
Dobreta Craiova 120
Craiova Rimnicu_Vilcea 146
Craiova Pitesti 138
Rimnicu_Vilcea Pitesti 97
Fagaras Bucharest 211
Pitesti Bucharest 101
Bucharest Giurgiu 90
Bucharest Urziceni 85
Urziceni Hirsova 98
Hirsova Eforie 86
Urziceni Vaslui 142
Vaslui Iasi 92
Iasi Neamt 87

Arad Bucharest
*/