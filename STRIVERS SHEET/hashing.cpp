// #include<bits/stdc++.h>


// using namespace std;



// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
    
    
//     //pre store
    
//     int hash[13]={0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }
    
    
//     //fetch
    
//     int q;
//     cin>>q;
//     for(int i=0;i<q;i++){
//         int x;
//         cin>>x;
//         cout<<hash[x]<<" ";
//     }
// }
// 
// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     string s;
//     cin>>s;
    
//     int hash[256]={0};
//     for(int i=0;i<s.size();i++){
//         hash[s[i]]++;
//     }
    
    
//     int q;
//     cin>>q;
//     while(q--){
//         char c;
//         cin>>c;
//         cout<<hash[c]<<" ";
//     }
// }


//using map

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
    
//     //pre store
//     map<int,int> map;
//     for(int i=0;i<n;i++){
//         map[arr[i]]++;
        
//     }
    
    
//     // iterrating the map
//     // 
//     // for( auto a :map){
//     //     cout<<a.first<<"->"<<a.second<<endl;
//     // }
    
//     int q;
//     cin>>q;
//     while(q--){
//     int x;
//     cin>>x;
//     cout<<map[x]<<" ";
// }
// }
// 
// 
// using map to store string freq
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s;
//     cin>>s;
    
    
    
//     // pre store?
//     map<char,int> map;
//     for(int i=0;i<s.size();i++){
//         map[s[i]]++;
//     }
    
    
//     // // iterrating the map
//     for(auto it:map){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }
    
//     //fetch
//     int q;
//     cin>>q;
//     while(q--){
//         char c;
//         cin>>c;
//         cout<<map[c]<<" ";
//     }
// }

// Find the highest/lowest frequency element
// 
// // 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
    
//     //pre store
//     map<int,int> map;
//     for(int i=0;i<n;i++){
//         map[arr[i]]++;
//     }
    
//     for( auto it :map){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }
//     //find the highest frequency
//     int max=INT_MIN;
//     int min=INT_MAX;
//     int maxele;
//     int minele;
//     for( auto it :map){
//         if(it.second>max){
//             max=it.second;
//             maxele=it.first;
//         }
//         if(it.second<min){
//             min=it.second;
//             minele=it.first;
//         }
//     }
//     cout<<maxele<<" "<<max<<endl;
//     cout<<minele<<" "<<min<<endl;
    
// }

// int maxFrequencyElements(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int maxFreq=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         int count=0;
//         for(auto it:mp){
//             if(it.second>maxFreq){
//                 maxFreq=it.second;
//             }
           
//         }
//         for(auto it:mp){
//              if(it.second==maxFreq){
//                 count+=it.second;
//             }
//         }
//         return count;
//     }