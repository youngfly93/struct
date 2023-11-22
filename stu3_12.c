int main(){
    int n ;
    vector<int> arr;
    cin >> n;
    for(int i = 0,a;i < n ;i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int p = arr[n/2] ,ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(arr[i] - p); 
    }
    cout << ans << endl;
    return 0;
}