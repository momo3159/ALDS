#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<queue>
#include<map>

using namespace std;

struct Card {
    int num;
    char suit;
};

int main(){

    int n;
    cin >> n;

    vector<Card> cards(n); //バブルソート
    vector<Card> cards1(n); //選択ソート
    for(int i=0;i<n;i++){
        cin >> cards[i].suit;
        cin >> cards[i].num;
        cards1[i].suit = cards[i].suit;
        cards1[i].num = cards[i].num;
    }

    // バブルソート
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(cards[j].num < cards[j-1].num) {
                swap(cards[j], cards[j-1]);
            }
        }
    }

    // 選択ソート
    int min;
    int idx = 0;;
    for(int i=0;i<n-1;i++){
        min = cards1[i].num;
        idx = i;
        for(int j=i+1;j<n;j++){
            if(cards1[j].num < min){
                min = cards1[j].num;
                idx = j;
            }
        }
        swap(cards1[idx], cards1[i]);
    }

    for(int i=0;i<n;i++){
        if(i > 0) cout << " ";
        cout << cards[i].suit << cards[i].num;
    }
    cout << endl;
    cout << "Stable" << endl;

    bool isStable = true;
    for(int i=0;i<n;i++){
        if(i > 0) cout << " ";
        cout << cards1[i].suit << cards1[i].num;
    }
    cout << endl;
    for(int i=0;i<n;i++){
        if(cards[i].suit != cards1[i].suit){
            isStable = false;
            break;
        }
    }
    if(isStable) cout << "Stable" << endl;
    else cout << "Not Stable" << endl;
}
