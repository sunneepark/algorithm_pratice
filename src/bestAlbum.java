import java.util.*;

class Pair implements Comparable<Pair> {
	Integer key;
	List<Integer> value;

	public Pair(int key, List<Integer> value) {
		this.key = key;
		this.value = value;
	}

	public Integer getKey() {
		return key;
	}

	public List<Integer> getValue() {
		return value;
	}

	public void setValue(List<Integer> value) {
		this.value = value;
	}

	@Override
	public int compareTo(Pair s) {
		if (this.key > s.getKey()) {
			return -1;
		} else if (this.key < s.getKey()) {
			return 1;
		}
		return 0;
	}
}

public class bestAlbum {

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
				if(list.size()>3)
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
		ArrayList<Pair> total_arr = new ArrayList<>();

		idx = 0;
		while (it.hasNext()) {
			ArrayList<Integer> temp = it.next();
			total_arr.add(new Pair(temp.get(0), temp.subList(1, temp.size())));
		}

		Collections.sort(total_arr);

		List<Integer> arr_list = new ArrayList<>();
		// 가장 긴 장르부터 차례대로 붙이기
		for (int i = 0; i < total_arr.size(); i++) {
			arr_list.addAll(total_arr.get(i).getValue());
		}
		answer = new int[arr_list.size()];
		idx = 0;
		for (Integer result : arr_list)
			answer[idx++] = result;

		return answer;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] participant = { "classic", "pop", "classic", "classic", "pop" };
		int[] completion = { 500, 600, 150, 800, 2500 };
		int[] answer = solution(participant, completion);
		for (int i : answer)
			System.out.println(i + " ");
	}

}
