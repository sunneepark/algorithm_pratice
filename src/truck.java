import java.util.*;

public class truck {
	public static int solution(int bridge_length, int weight, int[] truck_weights) {
		int answer = 1;
		Queue<info> bridgeQueue = new LinkedList<>();
		int currentWeights = 0;
		int i=0;
		
		while(i<truck_weights.length) {
			int tempWeight = truck_weights[i];
			if(bridgeQueue.size() < bridge_length 
					&& currentWeights + tempWeight <= weight) {
				currentWeights += tempWeight;
				bridgeQueue.offer(new info(tempWeight, answer));
				System.out.println(answer);
				i++;
			}

			if((answer - (Integer)bridgeQueue.peek().index) == bridge_length-1) {
				currentWeights -= (Integer)bridgeQueue.peek().height;
				bridgeQueue.poll();
			}
			answer++;
		}
		while(!bridgeQueue.isEmpty()) {
			if((answer - (Integer)bridgeQueue.peek().index) == bridge_length-1)
				bridgeQueue.poll();
			answer++;
		}
		return answer; //두번째 while로 들어갈 때 한번 중복 체크
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int bridge_length = 100;
		int weight = 100;
		int[] truck_weights = { 10};

		System.out.println(solution(bridge_length, weight, truck_weights));
	}

}
