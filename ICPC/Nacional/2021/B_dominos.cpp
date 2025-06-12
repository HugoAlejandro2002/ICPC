#include <iostream>
#include <vector>
#define input freopen("in.txt", "r", stdin)

using namespace std;

int main()
{
    input;
    int n, l;
    // int X,h,w;
    cin >> n >> l;

    double dominos[n][3];

    for (int i = 0; i < n; i++)
    {
        // cout<<n<<endl;
        // cout<<i<<endl;
        cin >> dominos[i][0] >> dominos[i][1] >> dominos[i][2];
        dominos[i][2] += dominos[i][0];
    }

    int q;
    double x, y;
    vector<double> points;
    // cout<<"entra"<<endl;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        // cout<<i<<endl;
        for (int d = 0; d < n; d++)
        {
            if (dominos[d][0] <= x)
            {
                // double pend = (y-dominos[d][1])/(x-dominos[d][0]);
                double base = x - y * (x - dominos[d][0]) / (y - dominos[d][1]);
                points.push_back(base);
            }
            if (dominos[d][2] >= x)
            {
                double base = x - y * (x - dominos[d][2]) / (y - dominos[d][1]);
                points.push_back(base);
            }
        }

        int ps = points.size();

        for (int p = 0; p < ps; p++)
        {
            cout<<points[p]<<" ";
        }
        cout<<endl;

        double iluminado = 0;
        int p = 0;
        while (p < ps && points[p] < 0)
        {
            p++;
        }
        if (p==ps-1)
        {
            iluminado+=(l-dominos[n-1][0]);
        }
        
        while (p < ps && points[p] <= x)
        {
            // cout<<"antes"<<endl;
            if (p == 0)
            {
                // cout<<"suma_antes"<<endl;
                iluminado += points[p];
                // cout<<iluminado<<endl;
            }
            else
            {
                // cout<<"suma_antes"<<endl;
                // cout<<iluminado<<endl;
                double light = points[p] - dominos[p - 1][2];
                // cout<<"ligth: "<<light<<endl;
                if (light > 0)
                {
                    iluminado += light;
                    // cout<<"il: "<<iluminado<<endl;
                }
                // cout<<iluminado<<endl;
            }
            p++;
        }

        if (p>1 && dominos[p-2][2]==x)
        {
            p--;
        }
        // cout<<"p: "<<p<<endl;
        int ret=1;
        if (dominos[p - 1][2] >= x)
        {
            ret=0;
        }
        else
        {
            iluminado += (dominos[p][0] - dominos[p - 1][2]);
        }

        // cout<<p<<endl;
        if (p==0)
        {
            iluminado+=(dominos[p][0]);
        }
        
        while (p < ps && points[p] >= x)
        {
            // cout<<"despues"<<endl;
            // cout<<"iluminado: "<<iluminado<<endl;

            if (p==ps-1)
            {
                iluminado+=(l-points[p]);
            } else {
                double light = dominos[p + ret][0] - points[p];
                if (light > 0)
                {
                    iluminado += light;
                }
            }
            
            if (points[p]>l)
            {
                break;
            }
             
            p++;
        }

        cout << iluminado << endl;
        points.clear();
    }

    return 0;
}