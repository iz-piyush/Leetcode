class Solution {
public:
    //
    vector<int> par;
    vector<int> siz;

    void dsu(int n){
        par.resize(n);
        siz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            siz[i]=0;
        }
    }

    int id(int i){
            if(par[i]==i) return i;
            return par[i]=id(par[i]);
    }

    void merge(int a,int b){
        int id1=id(a);
        int id2=id(b);
        
        if(id1!=id2){
        if(siz[id2]>siz[id1]){
            swap(id1,id2);
        }
        par[id2]=id1;
        if(siz[a]==siz[b]) siz[a]++;
        }
    }
    //

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<int> prime(n+1,1),dp(n+1),dp_(n+1);
        vector<int> adj[n+1];
        prime[0]=prime[1]=0;
        for(int i=2;i<=n/i;i++){
            for(long j=i+i;j<=n;j+=i){
                prime[j]=0;
            }
        }
        dsu(n+1);
        for(auto &k:edges){
            int x=k[0],y=k[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            if(!prime[x] and !prime[y]) merge(x,y);
        }

        long long ans=0;
        vector<int> sz(n+1);
        for(int i=1;i<=n;i++){
            sz[id(i)]++;
        }

        for(int i=1;i<=n;i++){
            // cout<<siz[i]<<' ';
            if(prime[i]==0) continue;
            int tot=0;
            vector<int> node;
            for(auto &x:adj[i]){
                int p=id(x);
                if(prime[p]) continue;
                tot+=sz[p];
                node.push_back(sz[p]);
            }
            // cout<<i<<"-> ";

            // for(auto x:node) cout<<x<<' ';cout<<'\n';

            while(!node.empty()){
                tot-=node.back();
                ans+=node.back()*1ll*(tot+1);
                node.pop_back();
            }
        }

        return ans;

    }
};