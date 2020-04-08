import java.util.*;

public class phonenumList {
	/** using hashset
	 * public static boolean solution(String[] phone_book) {
		boolean answer = true;
		Set<String> list = new HashSet<>(Arrays.asList(phone_book));
		
		for(String elem : phone_book) {
			for(int i=0;i<elem.length()-1;i++) {
				if(list.contains(elem.substring(0,i+1))) {
					answer = !answer;
					return answer;
				}
			}
		}
		return answer;
	}**/
	/**
	 * @method using string sort
	 */
	public static boolean solution(String[] phone_book) {
      
      boolean answer=true;
      Arrays.sort(phone_book);
      
      for(int i=0; i<phone_book.length-1; i++){

          if(phone_book[i+1].startsWith(phone_book[i])) 
        	  return !answer;
      }
      return answer;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] completion = { "119", "97674223", "1195524421"};
		System.out.println(solution(completion));
	}

}
