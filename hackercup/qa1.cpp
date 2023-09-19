#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("consecutive_cuts_chapter_1_input.txt", "r" , stdin);
        freopen("consecutive_cuts_chapter_1_output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    int a=1;
    while(a<=t){
        cout<<"Case #"<<a++<<": ";
        int n, k;
        cin>>n>>k;
        vector<int> a(n), b(n);
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
            while(j<n-1 && a[i]!=b[j]){
                j++;
            }
            if(i==0 && j==0 && 1==k){
                cout<<"NO"<<endl;
            }
            else{
                bool f=true;
                for(int l=0;l<n;l++){
                    if(a[(i+l)%n]!=b[(j+l)%n]){
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
        }
    }
    return 0;
}