package 图

type Graph struct {
	nodes   [][]int
	visited []int //0未访问，1正在访问， 2访问过
}

func NewGraph(datas [][]int, n int) *Graph { //构造图
	nodes := make([][]int, n)
	visited := make([]int, n)
	for i := 0; i < n; i++ { //初始化图访问
		visited[i] = 0
	}

	for _, data := range datas { //构造图的邻接链表
		cur := data[0]
		pre := data[1] //先学前置课程pre才能学课程cur
		nodes[pre] = append(nodes[pre], cur)
	}
	return &Graph{nodes: nodes, visited: visited}
}

func dfs(node int, graph *Graph) bool {
	graph.visited[node] = 1

	for _, neighbor := range graph.nodes[node] {
		if graph.visited[neighbor] == 1 { //遇到正在访问的节点，说明存在环
			return true
		}
		if graph.visited[neighbor] == 0 && dfs(neighbor, graph) { //查看邻居节点是否存在环,存在环则
			return true
		}
	}

	graph.visited[node] = 2
	return false
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	myGraph := NewGraph(prerequisites, numCourses)
	for i := 0; i < numCourses; i++ {
		if myGraph.visited[i] == 0 && dfs(i, myGraph) {
			return false
		}
	}
	return true
}
