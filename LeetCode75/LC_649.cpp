class Solution {
public:
    string predictPartyVictory(string senate) {
        bool draw=true;
        queue<char> rounds[2];
        char first='R';
        int index=0, next_idx=1, count=0;

        for(char c : senate) rounds[0].push(c);
        while(draw) {
            if(abs(count)>=rounds[index].size())
                draw=false;
            while(!rounds[index].empty()) {
                char c = rounds[index].front();
                rounds[index].pop();
                if(c==first) {
                    if(count>=0) {
                        rounds[next_idx].push(c);
                    }
                    count++;
                } else {
                    if(count<=0) {
                        rounds[next_idx].push(c);
                    }
                    count--;
                }
            }
            next_idx = index;
            index = (index+1)%2;
        }
        return rounds[index].front()=='R'? "Radiant":"Dire";
    }
};
