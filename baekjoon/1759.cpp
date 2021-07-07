#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//조합 문제

int main(){
    int l, c; //l개의 알파벳으로 구성되며 c개의 종류
    vector<char> alpha;
    int cnt = 0;
    char ch;
    scanf("%d %d ", &l, &c);
    
    while(cnt < c){
        scanf("%c", &ch);
        if(ch == ' ') continue;
        alpha.push_back(ch);
        cnt++;
    }
    
    //최소 한개의 모음과 최소 두개의 자음으로 이루어진 l 길이의 암호
    vector<int> v(c-l, 0);
    for(int i = 0;i < l;i++) v.push_back(1);
    
    
    int vowel = 0; //모음 aeiou
    int cons = 0; //자음
    vector<string> word; //가능한 단어를 담는 벡터
    
    do{
        vowel = cons = 0;
        string str = "";
        for(int i = 0;i < c;i++){
            if(v[i]){
                ch = alpha[i];
                str += ch;
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    vowel++;
                else cons++;
            }
        }
        if(vowel > 0 && cons > 1){
            sort(str.begin(), str.end());
            word.push_back(str);
        }
    }while(next_permutation(v.begin(), v.end()));

    
    sort(word.begin(), word.end());
    int s = word.size();
    for(int i = 0;i < s;i++)
        cout << word[i] << endl;
}