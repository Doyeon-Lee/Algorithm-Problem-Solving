#include <string>
#include <vector>
using namespace std;

string convert_sharp(string str){
    int pos = 0;
    char c;
    string buf = "";
    while(str.find('#') != string::npos){ //#이 없을 때까지 반복
        pos = str.find('#');
        c = str.at(pos-1);
        buf = (char)tolower(c);
        str.replace(pos-1, 2, buf);
    } //while문 close
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string title = ""; //제목을 담는 스트링
    string music = ""; //악보를 담는 스트링
    string buf = ""; //중간중간 사용하는 버퍼
    string play = ""; //musicinfos의 벡터를 하나씩 참고할 스트링
    int start, end, time, ans_time = 0; //시작, 끝, 총 시간, 정답곡의 시간

    for(int i = 0;i < musicinfos.size();i++){
        play = musicinfos[i];
        //음악의 시작, 끝 시간을 구한다
        buf = play.substr(0, 2);
        start = ((buf.at(0) - '0')*10 + buf.at(1) - '0') * 60;
        buf = play.substr(3, 2);
        start += (buf.at(0) - '0')*10 + buf.at(1) - '0';

        buf = play.substr(6, 2);
        end = ((buf.at(0) - '0')*10 + buf.at(1) - '0') * 60;
        buf = play.substr(9, 2);
        end += (buf.at(0) - '0')*10 + buf.at(1) - '0';
        time = end - start; //음악의 재생 시간

        //곡의 제목을 구하고 악보를 스트링에 저장한다
        int pos = play.find(',',12);
        title = play.substr(12, pos-12);
        music = play.substr(pos+1);

        //m과 악보의 #을 전부 변환
        music = convert_sharp(music);
        m = convert_sharp(m);

        //재생시간만큼의 악보를 덧붙여준다
        int len = music.length();
        buf = music;

        //재생시간 < 곡의 길이
        if(time < len) music = buf.substr(0, time);
        else{ //재생시간 > 곡의 길이
            for(int i = 0;i < time/len;i++) music += buf;
            music += buf.substr(0, time % len);
        }

        //네오의 기억과 비교한다
        if(music.find(m) != -1){ //악보에 있다면
            if(ans_time == 0){
                answer = title;
                ans_time = time;}
            else{
                if(ans_time < time){
                    ans_time = time;
                    answer = title;}
            }
        } //if문 close
    } //반복문 close    
    return answer;
}