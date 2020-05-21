import java.util.Scanner;
import java.io.FileInputStream;

public class supplyRoad {
	static int minTime = 0;
	static int minCosts[][];
	static int boardSize = 0;
	static int direction [][] = {{-1,0},{0,1},{1,0},{0,-1}};
	public static void dfs(int x, int y, int[][] board, boolean[][] visited, int[][] cost, int tempCost) {
		cost[x][y] = tempCost;
		if(x == boardSize-1 && y == boardSize-1) {
			if(minTime > cost[x][y]) {
				minTime = cost[x][y];
				minCosts = cost;
			}
			return;
		}
		for(int i=0;i<4;i++) {
			int tempX = x+direction[i][1]; 
			int tempY = y+direction[i][0];
			if(tempX >=0 && tempX < boardSize && tempY >= 0 && tempY < boardSize && !visited[tempX][tempY]) {
				int temp = tempCost+board[tempX][tempY];
				if(minCosts[tempX][tempY] > temp) {
					dfs(tempX, tempY, board, visited, cost,temp);
				}
			}
		}
	}
	public static void main(String args[]) throws Exception
	{
		/*
		   아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
		   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
		   이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
		   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
		   단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
		 */
		//System.setIn(new FileInputStream("res/input.txt"));

		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt();
			
			int board[][] = new int[n][n];
			String temp="";
			sc.nextLine();
			for(int i=0;i<n;i++) {
				temp = sc.nextLine();
				for(int j=0;j<n;j++) {
					board[i][j] = temp.charAt(j)-'0';
				}
			}
			minTime = n*n*10;
			minCosts = new int[n][n];
			boardSize = n;
			int cost[][] = new int[n][n];
			boolean visited[][] = new boolean[n][n];
			for(int j=0;j<n*n;j++) {
				cost[j/n][j%n] = minTime;
				minCosts[j/n][j%n] = minTime;
				visited[j/n][j%n] = false;
			}
			dfs(0, 0, board, visited, cost, board[0][0]);
			System.out.println("#"+test_case+" "+minTime);
			
		}
	}

}
