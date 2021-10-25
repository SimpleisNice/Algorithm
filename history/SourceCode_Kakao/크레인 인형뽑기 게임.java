import java.util.Vector;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int boardLen = board[0].length - 1;
        Vector<Integer> tempV = new Vector<Integer>();
        
        for(int i=0; i<moves.length; ++i) {
            int tempDoll = 0;
            int pos = 0;
            for(int j=boardLen; j>=0; --j){
                if(board[j][moves[i] - 1] == 0)
                    break;
                pos = j;
                tempDoll =board[j][moves[i] - 1];
            }
            
            if(tempDoll != 0) {
                board[pos][moves[i] - 1] = 0;
                
                if(tempV.isEmpty()) {
                    tempV.addElement(tempDoll);
                }else {
                    int len = tempV.size() - 1;
                    if(tempV.elementAt(len) == tempDoll) {
                        ++answer;
                        tempV.removeElementAt(len);
                    }else {
                        tempV.addElement(tempDoll);
                    }
                }
            }
        }
        return answer * 2;
    }
}