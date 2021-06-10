#include <string>
#include <vector>
#include <stack>
using namespace std;
int arr[31];
int solution(vector<vector<int>> board, vector<int> moves) {
    int N = board.size();    
    for (int j = 0; j<N; j++){
        for (int i = 0; i<N; i++){
            if (board[i][j] != 0){
                arr[j] = i;
                break;   
            }
        }
    }

    stack<int> q;
    int answer = 0;
    for (int t = 0; t< moves.size(); t++){
        if (arr[moves[t]-1] >= N)
            continue;
        int item = board[arr[moves[t]-1]][moves[t]-1];  
        arr[moves[t]-1]++;
        if (q.size() > 0 && q.top() == item){
            answer+=2;
            q.pop();
        }
        else{
            q.push(item);
        }       
    }
    
    return answer;
}
