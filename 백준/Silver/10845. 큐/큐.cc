#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int main () {
    int n;
    queue<int> q;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str.compare("push")==0){
            int m;
            cin >> m;
            q.push(m);
        }else if(str.compare("pop")==0){
            if(q.empty())
                cout<<-1<<"\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }else if(str.compare("size")==0){
            cout<<q.size()<<"\n";
        }else if(str.compare("empty")==0){
            cout<<(q.empty()?1:0)<<"\n";
        }else if(str.compare("front")==0){
            if(q.empty())
                cout<<-1<<"\n";
            else
                cout<<q.front()<<"\n";
        }else if(str.compare("back")==0){
            if(q.empty())
                cout<<-1<<"\n";
            else
                cout<<q.back()<<"\n";
        }
    }
}
