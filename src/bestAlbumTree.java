import java.util.*;

public class bestAlbumTree {

	public static int[] solution(String[] genres, int[] plays) {
		int[] answer = {};
		HashMap<String, ArrayList<Integer>> dic = new HashMap<>();

		int idx = 0;
		for (String elem : genres) {
			ArrayList<Integer> list = new ArrayList<Integer>();
			if (dic.containsKey(elem)) {
				list = dic.get(elem);
				list.set(0, list.get(0) + plays[idx]); // 장르당 총 재생 시간 길이 갱신
				int i=1;
				for(;i<list.size();i++) {
					if(plays[list.get(i)] < plays[idx])
						break;
				}
				list.add(i,idx);
				if(list.size() > 3)
					list.remove(3);
			} else {
				list.add(plays[idx]);
				list.add(idx);
			}
			dic.put(elem, list);
			idx++;
		}
		// 가장 긴 장르 뽑기
		Iterator<ArrayList<Integer>> it = dic.values().iterator();
		TreeMap<Integer, ArrayList<Integer>> total_arr = new TreeMap<>(Collections.reverseOrder());

		idx = 0;
		int answer_size = 0;
		while (it.hasNext()) { //treemap 으로 정렬
			ArrayList<Integer> temp = it.next();
			answer_size += temp.size()-1;
			total_arr.put(temp.get(0), new ArrayList<Integer>(temp.subList(1,temp.size())));
		}

		// 가장 긴 장르부터 차례대로 붙이기
		Iterator<Integer> it_total_arr = total_arr.keySet().iterator();
		
		answer = new int[answer_size];
		idx = 0;
		while(it_total_arr.hasNext()) {
			ArrayList<Integer> temp_genre = total_arr.get(it_total_arr.next());
			for(Integer elem :temp_genre)
				answer[idx++] = elem;
		}

		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[][] participant = {{ "classic", "pop", "classic", "classic", "pop" },
				{"a","b","c","d","e","f"}
		};
		
		int[][] completion = { {500, 600, 501, 800, 900},{1,2,3,4,5,6} };
		int[] answer = solution(participant[1], completion[1]);
		for (int i : answer)
			System.out.println(i + " ");
	}


}
