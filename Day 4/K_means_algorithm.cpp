#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

struct point
{
    double x, y;
    // input x,y
    point(double x, double y) : x(x), y(y) {}
    // default constructor
    point() : x(0), y(0) {}
};

int main()
{
    int n;
    cin >> n;
    point p[n];
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }
    cout<<"Points in the set :"<<nl;
    for (auto x : p)
    {
        cout << x.x << " " << x.y << nl;
    }
    cout<<nl;
    int k;//number of clusters
    cin >> k;
    point currentcentroid[k],previouscentroid[k];
    for (int i = 0; i < k; i++)
    {
        double x, y;
        cin >> x >> y;
        currentcentroid[i] = point(x, y);
    }

    cout<<"The "<<k<<" Centroids are :"<<nl;
    for (auto x : currentcentroid)
    {
        cout << x.x << " " << x.y << nl;
    }
    cout<<nl;

    // k-means algorithm
    bool flag = true;
    int cluster[n],step=1;
    while (flag)
    {
        cout<<"Step : "<<step<<nl;step++;
        for (int i = 0; i < k; i++){previouscentroid[i] = currentcentroid[i];}//copy the centroid

        double distance[k][n];//k array of size n to store the distance of each point from each centroid
        for (int i = 0; i < k; i++)
        {
            cout<<"Distance from centroid "<<i+1<<nl;
            for (int j = 0; j < n; j++)
            {
                distance[i][j] = sqrt(pow((p[j].x - currentcentroid[i].x), 2) + pow((p[j].y - currentcentroid[i].y), 2));
                cout << distance[i][j] << " ";// print the distances
            }
            cout<<nl<<nl;
        }

        // devide the points into k clusters
        for (int i = 0; i < n; i++)
        {
            double min = distance[0][i];
            int index = 0;
            for (int j = 1; j < k; j++)
            {
                if (distance[j][i] < min)
                {
                    min = distance[j][i];
                    index = j;
                }
            }
            cluster[i] = index;
        }
        // print the clusters
        cout<<"Clusters : ";
        for (int i = 0; i < n; i++)
        {
            cout << cluster[i] << " ";
        }
        cout << nl;
        // update the centroids
        for (int i = 0; i < k; i++)
        {
            double sumx = 0, sumy = 0;
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (cluster[j] == i)
                {
                    sumx += p[j].x;
                    sumy += p[j].y;
                    count++;
                }
            }
            currentcentroid[i].x = sumx / count;
            currentcentroid[i].y = sumy / count;
        }
        // print the centroids
        cout<<"Updated Centroids :"<<nl;
        for (auto x : currentcentroid)
        {
            cout << x.x << " " << x.y << nl;
        }
        cout<<nl;

        // if the two cenroids are same then stop the loop
        flag = false;
        for (int i = 0; i < k; i++)
        {
            if (!((previouscentroid[i].x == currentcentroid[i].x) && (previouscentroid[i].y == currentcentroid[i].y)))
            {
                flag = true;
            }
        }
    }

    return 0;
}
/*
k=2
7
1 1 
1.5 2
3 4
5 7
3.5 5
4.5 5
3.5 4.5
2
1 1
5 7
*/
/*
k=3
7
1 1 
1.5 2
3 4
5 7
3.5 5
4.5 5
3.5 4.5
3
1 1
5 7
3 4
Clusters : 0 0 2 1 2 2 2 
Updated Centroids :
1.25 1.5
5 7
3.625 4.625
*/