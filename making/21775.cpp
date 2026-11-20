#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct Card {
    int id;
    int type;
    int n = -1;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> order(t);
    for (int i = 0; i < t; ++i) {
        cin >> order[i];
    }

    vector<Card> deck(t);
    string typeStr;
    for (int i = 0; i < t; ++i) {
        cin >> deck[i].id >> typeStr;
        if (typeStr== "next") {
            deck[i].type=0;;
        }
        else if(typeStr=="acquire"){
            deck[i].type=1;
            cin>>deck[i].n;
        }
        else {
            deck[i].type=2;
            cin>>deck[i].n;
        }
    }

    map<int, int> owner;              // 자원 번호 → 보유한 플레이어
    vector<int> player_hold(n + 1, -1);         // 각 플레이어가 현재 들고 있는 카드 index (없으면 -1)
    vector<int> result;
    int deck_idx = 0;
    stringstream out;
    for (int i = 0; i < t; ++i) {
        int player = order[i];

        Card* card;

        if (player_hold[player] != -1) {
            card = &deck[player_hold[player]];
        } else {
            card = &deck[deck_idx++];
            player_hold[player] = card - &deck[0]; // index 저장
        }

        out<<card->id<<'\n';

        if (card->type == 0) {
            player_hold[player] = -1;
        } else if (card->type == 1) {
            int res = card->n;
            if (owner.count(res)) {
                // 자원 이미 사용 중 → 다음 턴에 또 처리
                // 보류 상태 유지
            } else {
                owner[res] = player;
                player_hold[player] = -1;
            }
        } else if (card->type == 2) {
            int res = card->n;
            if (owner[res] == player) {
                owner.erase(res);
            }
            player_hold[player] = -1;
        }
    }

    cout<<out.str();

    return 0;
}