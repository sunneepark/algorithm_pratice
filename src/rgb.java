import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

class dfsPair {
	int x;
	int y;

	public dfsPair(int left, int right) {
		this.x = left;
		this.y = right;
	}
}

public class rgb {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); // 문자 입력을 인자로 Scanner 생성
		int n = scan.nextInt();

		char[][] map = new char[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = scan.next().charAt(0);
		
		int answerRGB = -1;
		int answerRB = -1;
		
		Queue<dfsPair> dfs = new LinkedList<>();
		dfs.offer(new dfsPair(0,0));
		while (!dfs.isEmpty()) {
			dfsPair temp = dfs.poll();
			int tempX = temp.x;
			int tempY = temp.y;
			if(map[tempX][tempY] != map[tempX+1][tempY])
		}
	}

}
