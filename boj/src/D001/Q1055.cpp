// BOJ 1055 [Endless]
// Supported by GitHub Copilot

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string q, s; cin >> q >> s;
    int e, x, y; cin >> e >> x >> y;
    int qlen = q.length(), slen = s.length();

    int dcnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '$') dcnt++;

    if(dcnt > 1){
        for(int offset = x; offset <= y; offset++) {
            int start = 0;
            // exploit
            long long word_size = slen - dcnt + qlen * dcnt;
            for(int i = 1; i < e; i++) {
                word_size = slen - dcnt + word_size * dcnt;
                if(word_size > y) break;
            }

            char c = '\0';
            while(c == '\0') {
                // locate
                int loc = start + offset;
                long long pos = 0, block_size = (word_size - slen + dcnt) / dcnt;
                for(int i = 0; i < slen; i++){
                    if(s[i] == '$'){
                        // [pos, pos + block_size)
                        if(pos <= loc && loc < pos + block_size) {
                            if(block_size == qlen){
                                c = q[offset - pos - 1];
                                break;
                            }
                            break;
                        }
                        else pos += block_size;
                    }
                    else if(pos == offset) {
                        c = s[i];
                        break;
                    }
                    else pos++;
                }
                word_size = block_size;
            }

            cout << c;
        }
        cout << '\n';
    }
}
