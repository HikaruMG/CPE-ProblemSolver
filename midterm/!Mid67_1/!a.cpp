#include <bits/stdc++.h>
using namespace std;
int x;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.first != b.first)
            return a.first > b.first; // มากก่อน
        return a.second < b.second;   // ถ้าคะแนนเท่ากัน เล็กก่อน
    }
};

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second > right.second;
    }
};
int find(vector<int> v, int seek) {
    for (int i = 0; i < v.size(); i++) {
        if (seek == v[i]) {
            return 1;
            cout << "True" << endl;
        }
        // else {
        //    return -1;
        // }
    }
    return -1; // <-- moved down here!
}
int main(){
    int max = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L,N,K;
    cin >> L >> N >>K;
    vector<int> Author(L);
    // vector<int> book(L+1,0);
    vector<pair<int,int>> book;
    vector<int> ans;
    vector<int> already;
    // cout << L << endl;
    for (int i = 0; i <L; i++) {
        cin >> x;
        // cout << "x =" << x << endl;
        // Author[i].push_back(x);
        Author[i] = x;
    }
    // for(int t : Author){
    //     cout << t << endl;
    // }
    // for(int i = 0;i<L;i++){
    //     for(int t : Author[i]){
    //         cout << " book "<< i << "= Auth "<< t ;
    //         // cout << "."<< endl;
    //     }
    //     cout << endl;
    // }
    for(int i=0;i<=L;i++){
        book.push_back(make_pair(i,0));
    }
    for(int i=0;i<N;i++){
        cin >> x;
        int temp = book[x].second+1;
        // cout << "t "<< temp << endl;
        book[x].second = temp;
        // cout << book[x].first << " " << book[x].second << endl;

    }

    // for(int t : book){
    //     cout << t << endl;
    // }
    // for(auto i: book)
    //     cout << i.first << " " << i.second << endl;

    std::sort(book.begin(), book.end(), sort_pred());

    // for(auto i: book)
    //     cout << i.first << " " << i.second << endl;
    
    // for(int j = 0; j<K;j++){
    //     ans.push_back(book[j].first);
    // }
    already.push_back(Author[(book[0].first)-1]);
    ans.push_back(book[0].first);

    // for(int t : ans){
    //     cout << t << endl;
    // }

    // for(int t : already){
    //     cout << t << endl;
    // }

    for(int i= 1;i<book.size()-1;i++){
        int Ebook = (book[i].first)-1;
        int auth = Author[Ebook];
        // cout << "i: " << i << endl;
        if(std::find(already.begin(), already.end(), auth)!=already.end()){
            // cout << "Book;" << Ebook << endl;
            continue;
        }
        else{
            already.push_back(auth);
            int p = (book[i].first);
            // cout << p << endl;
            ans.push_back(p);
        }
        

    }
    for(int i=0;i<K;i++){
        cout << ans[i] << endl;
    }
}

