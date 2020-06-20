import java.util.*;

class point{
	int data;
	int idx;

	public point(int data, int idx) {
		this.data = data;
		this.idx = idx;
	}
}

public class kth {
	public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        List<point> sortArr = new ArrayList<point>();
        for(int i=0;i<array.length;i++)
        	sortArr.add(new point(array[i],i));
        
        Collections.sort(sortArr, new Comparator<point>(){
			@Override
			public int compare(point o1, point o2) {
				if(o1.data < o2.data) return -1;
				else return 1;
			}    	
        }); //오름차순으로 정렬
        
        for(int i=0;i<commands.length;i++) {
        	int firstIdx = commands[i][0]-1; int lastIdx = commands[i][1]-1; int answerIdx = commands[i][2];
        	int tempIdx = 0;
        	for(int j=0;j<sortArr.size();j++) {
        		if(sortArr.get(j).idx >= firstIdx && sortArr.get(j).idx <= lastIdx) {
        			if(++tempIdx == answerIdx) {
        				answer[i] = sortArr.get(j).data;
        				j=sortArr.size();
        			}
        		}
        	}
        }
        return answer;
    }
	/**
	 * 
	 * @purpose 최적화 
	 * @timecomplexity k'*(2*k + klogk) 
	 * @k' command 길이
	 * @k command 각각의 길이
	 */
	/*public int[] solution(int[] array, int[][] commands) {
         int[] answer = new int[commands.length];
        
        for(int i=0;i<commands.length;i++) {
        	int firstIdx = commands[i][0]-1; int lastIdx = commands[i][1]-1; int answerIdx = commands[i][2]-1;
            int[] temp = new int[lastIdx-firstIdx+1];
            int tempIdx =0;
        	for(int j=firstIdx;j<=lastIdx;j++) {
        		temp[tempIdx++] = array[j];
        	}
            Arrays.sort(temp);
            answer[i] = temp[answerIdx];
        }
        return answer;
    }*/
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] temp = solution(new int[]{1,5,2,6,3,7,4},new int[][]{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
	}

}
