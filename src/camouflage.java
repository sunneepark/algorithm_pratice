import java.util.*;

public class camouflage {
	public static int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> list = new HashMap<>();
        for(String[] temp : clothes) 
        	list.put(temp[1],list.getOrDefault(temp[1],0)+1);
        
        Iterator<Integer> it = list.values().iterator();
        while(it.hasNext()) {
        	answer *= it.next().intValue()+1;
        }
        	
        return answer-1;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[][] participant = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
		System.out.println(solution(participant));
	}

}
