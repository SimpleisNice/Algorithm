function solution(board, moves) {
    var answer = 0;
    let doll_array = [];
    let board_len = board.length - 1;
    
    moves.forEach((move_order) => {
        let temp_doll = 0;
        let pos = 0;
        for(let i = board_len;i>=0; --i) {
            if(board[i][move_order - 1]) { 
                temp_doll = board[i][move_order - 1];
                pos = i;
            }
            else 
                break;
        }
        if(temp_doll) {
            board[pos][move_order - 1] = 0;
            
            let temp_len = doll_array.length;
        
            if(temp_len) {
                if(doll_array[temp_len - 1] === temp_doll) {
                    ++answer;
                    doll_array.pop();
                }
                else
                    doll_array.push(temp_doll);
            }
            else
                doll_array.push(temp_doll);
        }
    });
    return answer * 2;
}