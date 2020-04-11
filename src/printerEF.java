import java.util.*;

public class printerEF {
	public static int solution(int[] priorities, int location) {
		int answer=0;
		Queue<Integer> q = new LinkedList<>();
		for(int i:priorities)
			q.offer(i);
		Arrays.sort(priorities);
		while(answer < priorities.length) {
			int temp = q.poll();
			location--;
			if(temp == priorities[(priorities.length-1) - answer]) {
				answer++;
				if(location<0)
					break;
			}
			else {
				q.offer(temp);
				if(location<0)
					location = q.size() -1;
			}		
		}
		return answer;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] priorities = {2,1,3,2};
		int location = 2;
		System.out.println(solution(priorities, location));
	}
}
