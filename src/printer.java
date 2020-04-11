import java.util.*;

class priority{
	int data;
	int index;
	public priority(int left,int right){
		this.data=left;
		this.index=right;
	}
}
public class printer {
	public static int solution(int[] priorities, int location) {
		int answer=1;
		
		Stack<priority> pq = new Stack<>();
		int idx=0;
		
		boolean[] checkIdx = new boolean[priorities.length];
		
		checkIdx[idx]=true;
		pq.push(new priority(priorities[idx], idx));
		
		while(pq.size() < priorities.length) {
			idx = ++idx % priorities.length;
			if(!checkIdx[idx]) {
				int temp = priorities[idx];
				while(!pq.isEmpty() && (pq.peek().data < temp)) {
					checkIdx[pq.peek().index]=false;
					pq.pop();
				}
				checkIdx[idx]=true;
				pq.push(new priority(temp, idx));
			}
		}
		answer = pq.size();
		while(!pq.isEmpty()) {
			if(pq.peek().index == location)
				break;
			pq.pop();
			answer--;
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
