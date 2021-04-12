#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x = 0; int y = 0; //current position
    int _x, _y; //values to move
    set<string> s;
    
    for(int i = 0;i < dirs.length();i++){
        char c = dirs[i];      
        
        //move position
        switch(c){
            case 'U':
                _x = 0; _y = 1;
                break;
            case 'D':
                _x = 0; _y = -1;
                break;
            case 'R':
                _x = 1; _y = 0;
                break;
            case 'L': 
                _x = -1; _y = 0;
                break;
        }
        
        //if the position to move doesn't get out the area
        if(x+_x >= -5 && x+_x <= 5 && y+_y >= -5 && y+_y <= 5){
            string a = to_string(x) + to_string(y);           
            x += _x; y += _y;
            string b = to_string(x) + to_string(y);
            
            //가는게 있다면 오는게 있는거지
            s.insert(a+b);
            s.insert(b+a);
        }
    }
    
    answer = s.size() / 2;
    
    return answer;
}