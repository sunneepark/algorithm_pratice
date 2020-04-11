import java.util.Stack;

public class targetNumber {
	public static int DFS (int[] numbers, int idx, int target, int sum) {
		if(idx == numbers.length) return (sum == target) ? 1 : 0;
		else return DFS(numbers, idx+1, target, sum+numbers[idx])
				+ DFS(numbers, idx+1, target, sum-numbers[idx]);
	}
	public static int solution(int[] numbers, int target) {
       return DFS(numbers, 0, target, 0);
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] numbers = {1,1,1,1,1};
		int target = 3;
		System.out.println(solution(numbers, target));
	}

}
