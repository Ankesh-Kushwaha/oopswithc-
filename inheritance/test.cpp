#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  getline(cin, s);
  stringstream ss(s);
  vector<int> arr;
  while(getline(ss, s, ',')){
       if(s=="null")
         arr.push_back(-1);
      else
        arr.push_back(stoi(s));
  }

  for (int i = 0; i < arr.size();i++){
    cout << arr[i] << endl;
  }

    return 0;
}