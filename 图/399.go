package 图

type UnionFind struct {
	parent []int
	weight []float64
}

// NewUnionFind 构造函数
func NewUnionFind(n int) *UnionFind {
	parent := make([]int, n)
	weight := make([]float64, n)
	for i := range parent {
		parent[i] = i
		weight[i] = 1.0
	}
	return &UnionFind{parent, weight}
}

// Find 查找根节点，并进行路径压缩
func (uf *UnionFind) Find(x int) int {
	if x != uf.parent[x] {
		origin := uf.parent[x]
		uf.parent[x] = uf.Find(uf.parent[x])
		uf.weight[x] *= uf.weight[origin]
	}
	return uf.parent[x]
}

// Union 合并节点，更新权值
func (uf *UnionFind) Union(x, y int, value float64) {
	rootX, rootY := uf.Find(x), uf.Find(y)
	if rootX == rootY {
		return
	}
	uf.parent[rootX] = rootY
	uf.weight[rootX] = uf.weight[y] * value / uf.weight[x]
}

func (uf *UnionFind) IsCollected(x, y int) float64 {
	rootX, rootY := uf.Find(x), uf.Find(y)
	if rootX == rootY {
		return uf.weight[x] / uf.weight[y]
	}
	return -1.0
}
func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	equationsSize := len(equations)
	//构建并查集
	uf := NewUnionFind(2 * equationsSize)
	hashMap := make(map[string]int)
	id := 0
	for i := 0; i < equationsSize; i++ {
		var1, var2 := equations[i][0], equations[i][1]
		if _, ok := hashMap[var1]; !ok {
			hashMap[var1] = id
			id++
		}
		if _, ok := hashMap[var2]; !ok {
			hashMap[var2] = id
			id++
		}
		uf.Union(hashMap[var1], hashMap[var2], values[i])
	}

	queriesSize := len(queries)
	res := make([]float64, queriesSize)
	for i := 0; i < queriesSize; i++ {
		var1, var2 := queries[i][0], queries[i][1]

		if id1, ok := hashMap[var1]; !ok {
			res[i] = -1.0
		} else if id2, ok := hashMap[var2]; !ok {
			res[i] = -1.0
		} else {
			res[i] = uf.IsCollected(id1, id2)
		}
	}
	return res
}
