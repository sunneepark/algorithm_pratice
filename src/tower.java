import java.util.*;

class info<L,R> {
	L height;
	R index;
	public info(L left,R right){
		this.height=left;
		this.index=right;
	}
}
public class tower {
	
	public static int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        Stack<info<Integer,Integer>> heightTop = new Stack<>();
        
        int i=heights.length-1;
        heightTop.push(new info(heights[i],i));
        while(--i >= 0) {
        	if(heights[i] > heightTop.peek().height){
        		do {
        			answer[heightTop.peek().index]= i+1;
        			heightTop.pop();
        		}
        		while(!heightTop.empty() && heights[i] > heightTop.peek().height);
        	}
        	
        	heightTop.add(new info(heights[i],i));
        }
       
        return answer;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] completion = { 6,9,5,7,4 };
		int[] answer = solution(completion);
		for (int i : answer)
			System.out.println(i + " ");
	}

}


