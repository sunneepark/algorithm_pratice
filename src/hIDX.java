import java.util.Arrays;

public class hIDX {
	public static int solution(int[] citations) {
        int answer = citations.length;
        Arrays.sort(citations);
        int i=citations.length-1;
        for(;i>=0;i--) {
        	if(citations[i] < (citations.length-i)+1 ) {
        		answer = i;
        		break;
        	}
        	else if(citations[i] == (citations.length-i)+1 ) {
        		answer = citations[i];
        		break;
        	}
        }
       
        return answer;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int answer = solution(new int[] {3, 0, 6, 1, 5});
	}

}
