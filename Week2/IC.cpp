#include <iostream>
#include <list>
using namespace std;
string Command;
list<int> DataTmp;


int main()
{
    int n, X;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Command ;
        if (Command == "ri")
        {
            cin >> X;
            DataTmp.push_back(X);
        }
        else if (Command == "li")
        {
            cin >> X;
            DataTmp.push_front(X);
        }
        else if (Command == "rr")
        {
            if(DataTmp.empty()){
                continue;
            }
            else {
                int last = DataTmp.back();
                DataTmp.pop_back();
                DataTmp.push_front(last);
            }   
        }
        else if (Command == "lr")
        {
            if(DataTmp.empty()){
                continue;
            }
            else{
                int first = DataTmp.front();
                DataTmp.pop_front();
                DataTmp.push_back(first);
            }
        }
    }

    for (int val : DataTmp)
    {
        cout << val << endl;
    }
    return 0;
}