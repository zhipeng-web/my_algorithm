package 图广度优先

func isTransfer(str1 string, str2 string) bool { //判断两个基因序列是否可以互相转移
	count := 0
	for i := 0; i < len(str1); i++ {
		if str1[i] != str2[i] {
			count++
		}
	}
	if count == 1 {
		return true
	}
	return false
}

type pair struct {
	str  string
	step int
}

func minMutation(startGene string, endGene string, bank []string) int {
	var adjacent map[string][]string
	adjacent = make(map[string][]string)
	for i := 0; i < len(bank); i++ { //构造邻接表
		for j := 0; j < len(bank); j++ {
			if i == j {
				continue
			}
			if isTransfer(bank[i], bank[j]) {
				adjacent[bank[i]] = append(adjacent[bank[i]], bank[j])
			}
		}
	}
	_, ok := adjacent[startGene]
	if !ok {
		for _, str := range bank {
			if isTransfer(startGene, str) {
				adjacent[startGene] = append(adjacent[startGene], str)
			}
		}
	}

	var queue []pair //队列，广度优先
	queue = append(queue, pair{startGene, 0})

	var visited map[string]bool
	visited = make(map[string]bool)

	for len(queue) > 0 {
		head := queue[0]
		queue = queue[1:] //取队头元素，出队列
		visited[head.str] = true
		n := len(adjacent[head.str])
		for i := 0; i < n; i++ {
			nxt := adjacent[head.str][i]
			if nxt == endGene {
				return head.step + 1
			}
			if !visited[nxt] { //这个序列没有访问过
				queue = append(queue, pair{nxt, head.step + 1})
				visited[nxt] = true
			}
		}
	}

	return -1
}
