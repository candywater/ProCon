using System.Collections;
using System.Collections.Generic;
using System;

public class Solution
{
    HashSet<char> globalht = new HashSet<char>()
    {
        '1','2','3',
        '4','5','6',
        '7','8','9',
    };
    public bool IsValidSudoku(char[][] board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (!IsValidLine(board, i, i))
            {
                return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (!IsValidSub(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;

    }
    private bool IsValidLine(char[][] b, int x, int y)
    {
        HashSet<char> ht = new HashSet<char>(globalht);
        for (int i = 0; i < 9; i++)
        {
            if (!IsValid(b[x][i], ht)) return false;
        }
        ht = new HashSet<char>(globalht);
        for (int i = 0; i < 9; i++)
        {
            if (!IsValid(b[i][y], ht)) return false;
        }
        return true;

    }
    private bool IsValidSub(char[][] b, int m, int n)
    {
        HashSet<char> ht = new HashSet<char>(globalht);
        int x = m * 3;
        int y = n * 3;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (!IsValid(b[i][j], ht)) return false;
            }
        }
        return true;
    }
    private bool IsValid(char t, HashSet<char> ht)
    {
        if (ht.Contains(t))
        {
            ht.Remove(t);
        }
        else if(t != '.')
        {
            return false;
        }
        return true;
    }

    static void Main()
    {
        Solution s = new Solution();
        char[][] c = new char[][]
    {
        new char[]{'5','3','.','.','7','.','.','.','.'},
        new char[]{'6','.','.','1','9','5','.','.','.'},
        new char[]{'.','9','8','.','.','.','.','6','.'},
        new char[]{'8','.','.','.','6','.','.','.','3'},
        new char[]{'4','.','.','8','.','3','.','.','1'},
        new char[]{'7','.','.','.','2','.','.','.','6'},
        new char[]{'.','6','.','.','.','.','2','8','.'},
        new char[]{'.','.','.','4','1','9','.','.','5'},
        new char[]{'.','.','.','.','8','.','.','7','9'}
    };
        bool b = s.IsValidSudoku(c);
        Console.WriteLine(b);

    }
}

