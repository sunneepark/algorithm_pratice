import java.util.Scanner;
import java.io.FileInputStream;

public class supplyRoad {
	static int minTime = 0;
	static int boardSize = 0;
	static int direction [][] = {{-1,0},{0,1},{1,0},{0,-1}};
	static int board[][];
	public static void dfs(int x, int y, int[][] cost, int tempCost) {
		 if(tempCost > minTime) return;
		cost[x][y] = tempCost;
		if((x == boardSize-1 && y == boardSize-2) || (x == boardSize-2 && y == boardSize-1 )) {
			if(minTime > cost[x][y]) {
				minTime = cost[x][y];
			}
			return;
		}
		for(int i=0;i<4;i++) {
			int tempX = x+direction[i][0]; 
			int tempY = y+direction[i][1];

			if(tempX >=0 && tempX < boardSize && tempY >= 0 && tempY < boardSize ) {
				int temp = tempCost+board[tempX][tempY];

				//System.out.println(tempX+" "+tempY);
				if(cost[tempX][tempY] > temp) {
					dfs(tempX, tempY, cost,temp);
				}
			}
		}
		return;
	}
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt();
			
			board = new int[n][n];
			String temp="";
			sc.nextLine();
			for(int i=0;i<n;i++) {
				temp = sc.nextLine();
				for(int j=0;j<n;j++) {
					board[i][j] = temp.charAt(j)-'0';
				}
			}
			minTime = n*n*10;
			boardSize = n;
			int cost[][] = new int[n][n];
			for(int j=0;j<n*n;j++) {
				cost[j/n][j%n] = minTime;
			}
			dfs(0, 0, cost, board[0][0]);
			System.out.println("#"+test_case+" "+minTime);
			
		}
	}

}
