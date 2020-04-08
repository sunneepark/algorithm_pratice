import java.util.*;

public class nonCompletion {
	/**
	 * 
	 * @method Arraylist sort, binarysearch
	 * 
	 *         public static String solution(String[] participant, String[]
	 *         completion) { String answer = "";
	 * 
	 *         List<String> list = new ArrayList<>(Arrays.asList(participant));
	 *         Collections.sort(list); for(String element : completion) { int idx2 =
	 *         Collections.binarySearch(list, element); list.remove(idx2); }
	 *         Iterator<String> iter02 = list.iterator();
	 * 
	 *         while (iter02.hasNext()) { answer = iter02.next(); }
	 * 
	 *         return answer; }
	 * 
	 */

	/**
	 * @method hashmap
	 * 
	 */
	public static String solution(String[] participant, String[] completion) {
		String answer = "";

		HashMap<String, Integer> map = new HashMap<>();
		for (int i = 0; i < participant.length; i++) {
			map.compute(participant[i], (k, v) -> v != null ? null : 1);
			if (i < completion.length)
				map.compute(completion[i], (k, v) -> v != null ? null : 1);
		}

		return (String) map.keySet().iterator().next();

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] participant = { "kiki", "eden", "leo" };
		String[] completion = { "eden", "kiki" };
		System.out.println(solution(participant, completion));
	}

}
