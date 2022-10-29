import java.util.*;
class Board {
    String[][] board;
    Board() {
        board = new String[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                board[i][j] = i+","+j;
        }
    }
    boolean isEmpty(int x, int y) {
        String tile = board[x][y];
        return (tile.equals(" X ") == false && tile.equals(" O ") == false);
    }
    boolean isMovesLeft() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                if (this.isEmpty(i, j))
                    return true;
        }
        return false;
    }
    void setTile(int x, int y, String player) {
        board[x][y] = player;
    }
    // String getTile(int x, int y) {
    //     return board[x][y];
    // }
    String checkWin() {
        if (board[0][0].equals(board[1][1]) && board[1][1].equals(board[2][2]))
            return board[1][1];
        if (board[0][2].equals(board[1][1]) && board[1][1].equals(board[2][0]))
            return board[1][1];
        if (board[0][2].equals(board[1][2]) && board[1][2].equals(board[2][2]))
            return board[1][2];
        if (board[0][1].equals(board[1][1]) && board[1][1].equals(board[2][1]))
            return board[1][1];
        if (board[0][0].equals(board[1][0]) && board[1][0].equals(board[2][0]))
            return board[1][0];
        if (board[1][0].equals(board[1][1]) && board[1][1].equals(board[1][2]))
            return board[1][1];
        if (board[0][0].equals(board[0][1]) && board[0][1].equals(board[0][2]))
            return board[0][1];
        if (board[2][0].equals(board[2][1]) && board[2][1].equals(board[2][2]))
            return board[2][1];
        return "none";
    } 
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                System.out.print(board[i][j]+"\t");
            System.out.println();
        }
    }
}
class Player {
    String val;
    Player(String val) {
        this.val = val;
    }
    boolean isValid(int x, int y) {
        return !(x < 0 || x >= 3 || y < 0 || y >= 3);
    }
    void move(Board b, int x, int y) {
        if(isValid(x, y) && b.isEmpty(x, y))
            b.setTile(x, y, val);
        else {
            System.out.print("Invalid Move. Enter Again : ");
            Scanner sc = new Scanner(System.in);
            x = sc.nextInt(); y = sc.nextInt();
            move(b, x, y);
        }
    }
}
class AI {
    Board board;
    Player AI, opponent;
    AI(Board board, Player opponent) {
        this.AI = new Player(" O ");
        this.board = board;
        this.opponent = opponent;
    }
    int evaluate() {
        String winner = board.checkWin();
        if (winner.equals(this.AI.val))
            return +10;
        if (winner.equals(this.opponent.val))
            return -10;
        return 0;
    }
    int minimax(int depth, boolean isMax) {
        int score = evaluate();
        if (score == 10 || score == -10)
            return score;
        if (board.isMovesLeft() == false)
            return 0;

        if (isMax) {
            int best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board.isEmpty(i, j)) {
                        AI.move(board, i, j);
                        best = Math.max(best, minimax(depth+1, !isMax));
                        board.setTile(i, j, i+","+j);
                    }
                }
            }
            return best;
        }
        else {
            int best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board.isEmpty(i, j)) {
                        opponent.move(board, i, j);
                        best = Math.min(best, minimax(depth+1, !isMax));
                        board.setTile(i, j, i+","+j);
                    }
                }
            }
            return best;
        }
    }
    void setBestTile() {
        int bestVal = -1000;
        int bestX = -1, bestY = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.isEmpty(i, j)) {
                    AI.move(board, i, j);
                    int moveVal = minimax(0, false);
                    board.setTile(i, j, i+","+j);
                    if (moveVal > bestVal) {
                        bestX = i; bestY = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        //System.out.println("The value of the best Move is : " + bestVal);
        AI.move(board, bestX, bestY);
    }
}

public class TTT {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Board board = new Board();
        Player player = new Player(" X ");
        AI ai = new AI(board, player);
        boolean flag = true;

        System.out.print("Enter who'll go first.\n");
        System.out.print("0. You, 1. AI : ");
        int choice = sc.nextInt() % 2;
        board.print();

        for (int i = 0; board.isMovesLeft(); i++) {
            if(i % 2 == choice && board.isMovesLeft()) {
                System.out.print("\nEnter your move : ");
                int x = sc.nextInt(); int y = sc.nextInt();
                player.move(board, x, y);
                board.print();
            }
            else if (board.isMovesLeft()) {
                System.out.println("\nAI's move : ");
                ai.setBestTile();
                board.print();
            }

            if(i >= 5) {
                String winner = board.checkWin();
                if (!winner.equals("none")) {
                    System.out.print("\nWinner is : ");
                    System.out.println(((winner.equals(" X ")) ? "Player" : "AI")+" wins");
                    flag = false; break;
                }
            }
        }
        if (flag)
            System.out.println("\nDraw. No one wins");
        sc.close();
    }
}
