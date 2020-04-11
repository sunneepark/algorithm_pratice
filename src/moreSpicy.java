import java.util.PriorityQueue;

public class moreSpicy {
	public static int solution(int[] scoville, int k) {
		int answer = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i : scoville)
			pq.add(i);
		
		while(pq.size() >= 2) {
			pq.offer(pq.poll() + pq.poll()*2);
			answer++;
			if(pq.peek() > k)
				return answer;
		}
		
		return -1;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] priorities = {1,2,3,9,10,12};
		int location = 7;
		System.out.println(solution(priorities, location));
	}

}
