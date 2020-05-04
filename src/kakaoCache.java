import java.util.LinkedHashMap;
import java.util.Map;

public class kakaoCache {
	public int solution(int cacheSize, String[] cities) {
	      int answer = 0;
	      LinkedHashMap<String, Integer> cache = new LinkedHashMap<String,Integer>(cacheSize,0.75f,true){
				protected boolean removeEldestEntry(Map.Entry<String, Integer> eldest) 
	            { 
	                return size() > cacheSize; 
	            } 
			};
	      for(String city : cities) {
	    	  city.toLowerCase();
	    	  if(cache.containsKey(city)) answer+=5;
	    	  else answer += 1;
	    	  cache.put(city, 0);
	      }
	      
	      return answer;
	  }
}
