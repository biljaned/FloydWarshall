#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,INF=100000000;
    cout << "Unesite prvo broj cvorova, pa zatim i broj grana: ";
    cin >> n >> m;
    cout << "Unesite grane u grafu: " << endl;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));//dist[a][b] predstavlja najmanje rastojanje koje je potrebno da predjemo od a do b
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        dist[a][b]=w;
        dist[b][a]=w;
    }
    for(int a=1; a<=n; a++)
        dist[a][a]=0;//rastojanje od samog sebe je 0
    for(int c=1; c<=n; c++){//c je cvor iz kog dolazimo od a, a iz koga dolazimo u b
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                dist[a][b]=min(dist[a][b],dist[a][c]+dist[c][b]);
                dist[b][a]=dist[a][b];//ako je neusmeren graf
            }
        }
    }
    int q;
    cout << "Unesite broj pitanja koja imate: ";
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << "Najmanja distanca od cvora " << a << " do cvora " << b << " je: " << dist[a][b] << endl;
    }

    return 0;
}
