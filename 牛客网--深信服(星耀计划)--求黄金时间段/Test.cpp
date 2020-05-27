//题目描述：
//首行给定餐厅单总数
//接下来给出日期、时间段、销售额

package org.example;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Node {
	int beginTime;
	int value;

	public Node(int beginTime, int value) {
		this.beginTime = beginTime;
		this.value = value;
	}
}

public class Main2 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int orders = in.nextInt();
		int[][] input = new int[orders][3];
		Node[] inNode = new Node[orders];

		int maxResult = -1, maxTime = 0;
		for (int i = 0; i < orders; i++) {
			for (int j = 0; j < 3; j++) {
				input[i][j] = in.nextInt();
			}
			inNode[i] = new Node(input[i][1], input[i][2]);
		}
		Arrays.sort(inNode, new Comparator<Node>() {
			<a href = "/profile/992988" data - card - uid = "992988" class = "js-nc-card" target = "_blank">@Override public int compare(Node o1, Node o2) {
				return o1.beginTime - o2.beginTime;
			}
		});
		int end = 0, start = 0;
		int curTotal = 0;
		while (start != orders&&end != orders) {
			while (end < orders && inNode[end].beginTime - inNode[start].beginTime <= 7200) {
				curTotal += inNode[end].value;
				end++;
			}
			if (curTotal > maxResult) {
				maxResult = curTotal;
				maxTime = inNode[start].beginTime;
			}
			if (end == orders) {
				break;
			}
			while (start < orders && (inNode[end].beginTime - inNode[start].beginTime) > 7200) {
				curTotal -= inNode[start].value;
				start++;
			}
			//            curTotal -= inNode[start].value;
			if (start == orders) {
				break;
			}

		}
		System.out.printf("%d %d\n", maxTime, maxResult);//7200
	}
}