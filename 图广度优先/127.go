package 图广度优先

func find(wordList []string, str string) bool {
	for _, word := range wordList {
		if str == word {
			return true
		}
	}
	return false
}

func isConnect(str1 string, str2 string) bool { //判断两个字符串是否邻接，只差一个字母邻接
	countDifferernt := 0
	for i := 0; i < len(str1); i++ {
		if str1[i] != str2[i] {
			countDifferernt++
		}
	}
	if countDifferernt == 1 {
		return true
	}
	return false
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	if !find(wordList, endWord) {
		return 0
	}
	var adjacent map[string][]string //邻接矩阵
	adjacent = make(map[string][]string)

	var visited map[string]bool //记录单词是访问过，访问过的不在访问
	visited = make(map[string]bool)

	n := len(wordList)

	for i := 0; i < n; i++ { //构造邻接矩阵
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if isTransfer(wordList[i], wordList[j]) {
				adjacent[wordList[i]] = append(adjacent[wordList[i]], wordList[j])
			}
		}
	}

	_, ok := adjacent[beginWord]
	if !ok { //构造beginWorld的邻接表
		for i := 0; i < n; i++ {
			if isTransfer(beginWord, wordList[i]) {
				adjacent[beginWord] = append(adjacent[beginWord], wordList[i])
			}
		}
	}

	var queue []pair //队列，pair定义在433.go
	queue = append(queue, pair{beginWord, 1})

	for len(queue) > 0 {
		head := queue[0]
		queue = queue[1:] //去除队列头节点，出队列
		visited[head.str] = true

		for _, neighbor := range adjacent[head.str] {
			if neighbor == endWord {
				return head.step + 1
			}

			if !visited[neighbor] { //扩展节点，如果邻居没有访问过就加入队列
				queue = append(queue, pair{neighbor, head.step + 1})
				visited[neighbor] = true
			}
		}
	}
	return 0
}
