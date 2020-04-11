import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class funcDevelopment {
	public static int[] solution(int[] progresses, int[] speeds) {
		int[] answer = {};

		int idx = 0;
		long temp = 0;
		int day = 0;
		Stack<info<Integer, Integer>> answerList = new Stack<>();
		while (idx < progresses.length) {
			temp = (100 - progresses[idx]) / speeds[idx];
			day = (int) (((int) temp != temp) ? (int) temp + 1 : temp); // 반올림이 필요한경우
			idx++;

			if (answerList.isEmpty())
				answerList.push(new info<Integer, Integer>(day, 1));
			else if (answerList.peek().height < day)
				answerList.push(new info<Integer, Integer>(day, 1));
			else
				answerList.peek().index++;
		}
		answer = new int[idx = answerList.size()];
		while (--idx >= 0)
			answer[idx] = answerList.pop().index;
		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] participant = { 93, 30, 55 };
		int[] completion = { 1, 30, 5 };
		int[] answer = solution(participant, completion);
		for (int i : answer)
			System.out.print(i + " ");
	}
}
