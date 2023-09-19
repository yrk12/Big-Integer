#include <bits/stdc++.h>
using namespace std;
//this is qa2
int main() {
    #ifndef ONLINE_JUDGE
        freopen("consecutive_cuts_chapter_2_input.txt", "r" , stdin);
        freopen("consecutive_cuts_chapter_2_output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    int a=1;
    while(a<=t){
        cout<<"Case #"<<a++<<": ";
        int n, k;
        cin>>n>>k;
        vector<int> a(n), b(n), ix;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        if(k==0 || (n==2  && k%2==0)){
            bool f=true;
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    f=false;
                    break;
                }
            }
            if(f){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int i=0, j=0;
            int cntin=0;
            for(int k=n-1;k>=0;k--){
                if(a[k]==a[i]){
                    cntin++;
                }
                else{
                    break;
                }
            }
            if(cntin!=n){
                for(int k=0;k<n;k++){
                    if(a[k]==a[i]){
                        cntin++;
                    }
                    else{
                        i=k;
                        break;
                    }
                }
            }
            if(b[0]==a[0] && a[0]==b[n-1]){
                int cntin1=0 ;
                for(int k=n-1;k>=0;k--){
                    if(b[k]==b[j]){
                        cntin1++;
                    }
                    else{
                        break;
                    }
                }
                if(cntin1!=n){
                    for(int k=0;k<n;k++){
                        if(b[k]==b[i]){
                            cntin1++;
                        }
                        else{
                            j=k;
                            break;
                        }
                    }
                }
                if(cntin1==cntin){
                    ix.push_back(j);
                }
            }
            while(j<n){
                if(b[j]==a[0]){
                    int cnt=0;
                    while(j<n && b[j]==a[0]){
                        cnt++;
                        j++;
                    }
                    if(cnt==cntin){
                        ix.push_back(j);
                    }
                }
                else{
                    j++;
                }
            }
            bool f=false;
            while(!ix.empty()){
                int k=i;
                j=ix.back();
                ix.pop_back();
                int l=0;
                for(;l<n;l++){
                    if(a[(l+k)%n]!=b[(l+j)%n]){
                        break;
                    }
                }
                if(n==l){
                    f=true;
                    break;
                }
            }
            if(f){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}