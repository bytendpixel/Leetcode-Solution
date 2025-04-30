class Solution {
public:

    void merge(int a, int b, int *parent, int *rank){
        int p1=a,p2=b;
        while(p1!=parent[p1]) p1=parent[p1];
        while(p2!=parent[p2]) p2=parent[p2];

        if (p1==p2) return;

        if (rank[p1]>rank[p2]){
            parent[p2]=parent[b]=p1;
        }else if (rank[p1]<rank[p2]){
            parent[p1]=parent[a]=p2;
        }else{
            parent[p2]=parent[b]=p1;
            rank[p1]++;
        }

    }

    int largestComponentSize(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n=nums.size(),max=0;
        int parent[n],rank[n];
        for (int i=0;i<n;i++) {
            parent[i]=i;
            rank[i]=0;
            if (nums[i]>max) max=nums[i];
        }

        int t[max+1],last[max+1];
        for (int i=1;i<=max;i++) {
            t[i]=i;
            last[i]=-1;
        }
        for (int i=2;i*i<=max;i++) if (t[i]==i){
            for (int j=i;j<=max;j+=i) if (t[j]==j) t[j]=i;
        }

        for (int i=0;i<n;i++){
            int p=t[nums[i]];
            while(p!=1){

                if (last[p]==-1) last[p]=i;
                else{
                    merge(i,last[p],parent,rank);
                    last[p]=i;
                }

                nums[i]/=p;
                p=t[nums[i]];
            }
        }

        int biggestSize=0;
        for (int i=0;i<n;i++) rank[i]=0;
        for (int i=0;i<n;i++){
            int p=i;
            while(p!=parent[p]) p=parent[p];
            if (++rank[p]>biggestSize) biggestSize=rank[p];
        }

        return biggestSize;
    }
};
