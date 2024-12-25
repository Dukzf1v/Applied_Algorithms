#include<bits/stdc++.h>
using namespace std;
#define maxn 1000006
const int MOD = 1e9+7;
int n, a[maxn];
int temp[maxn];

int merge(int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int count = 0;
    int k = left;
    while(i<=mid && j<=right){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            k++; i++;
        } else {
            count += mid - i + 1;
            count %= MOD;
            temp[k] = a[j];
            k++; j++;
        }
    }
    while(i<=mid){
        temp[k] = a[i];
        k++; i++;
    }
    while(j<=right){
        temp[k] = a[j];
        k++; j++;
    }
    for(int i = left; i <= right; i++) a[i] = temp[i];
    return count;
}

int mergeSort(int left, int right){
    int count = 0;
    if(left < right){
        int mid = (left+right)/2;
        count = (count+mergeSort(left,mid))%MOD;
        count = (count+mergeSort(mid+1,right))%MOD;
        count = (count+merge(left,mid,right))%MOD;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << mergeSort(0,n-1);
    return 0;
}