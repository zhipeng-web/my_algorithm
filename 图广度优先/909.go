package 图广度优先

type MyQueue struct {
	x int
	y int
}

func newQueue(x int, y int) *MyQueue {
	return &MyQueue{x, y}
}

func reflect(num, n int) (row, col int) { //求坐标数组和矩阵的索引通常从 0 开始，
	// 而不是从 1 开始。因此，为了将从 1 开始的编号转换为从 0 开始的索引，需要将编号减去 1。
	row, col = (num-1)/n, (num-1)%n
	if row%2 == 1 {
		col = n - col - 1
	}
	row = n - row - 1
	return
}
func snakesAndLadders(board [][]int) int {
	n := len(board)
	visit := make([]bool, n*n+1)
	type pair struct {
		num, step int
	}
	queue := []pair{{1, 0}}
	for len(queue) > 0 {
		p := queue[0]
		queue = queue[1:] // 出队列
		for i := 1; i <= 6; i++ {
			nxt := p.num + i
			if nxt > n*n {
				break //越界
			}
			row, col := reflect(nxt, n)
			if board[row][col] > 0 {
				nxt = board[row][col]
			}
			if nxt == n*n {
				return p.step + 1
			}
			if !visit[nxt] {
				visit[nxt] = true
				queue = append(queue, pair{nxt, p.step + 1})
			}
		}
	}
	return -1
}
