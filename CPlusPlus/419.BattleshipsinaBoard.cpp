class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m, n;
        m = board.size();
        if (m > 0)
            n = board[0].size();
        else
            return 0;
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    if (board[i][j] == 'X')
                        ret++;
                }
                if (i == 0 && j != 0 && board[i][j] == 'X' && board[i][j-1] != 'X')
                    ret++;
                if (i != 0 && j == 0 && board[i-1][j] != 'X' && board[i][j] == 'X')
                    ret++;
                if (i != 0 && j != 0 && board[i-1][j] != 'X' && board[i][j-1] != 'X' && board[i][j] == 'X')
                    ret++;
            }
        }
        return ret;
    }
};