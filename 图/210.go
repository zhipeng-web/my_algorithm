package 图

func findOrder(numCourses int, prerequisites [][]int) []int {
	var answer []int
	if prerequisites == nil {
		return nil
	}
	inDegree := make([]int, numCourses)   //入度表
	adjacent := make([][]int, numCourses) //邻接矩阵
	for _, data := range prerequisites {  //初始化邻接矩阵
		pre := data[1] //前置课程
		cur := data[0]
		inDegree[cur]++ //课程每有一门前置课程，入度 + 1
		adjacent[pre] = append(adjacent[pre], cur)
	}

	var queue []int //队列，实现拓扑排序
	for i := 0; i < numCourses; i++ {
		if inDegree[i] == 0 {
			queue = append(queue, i)
		}
	}
	for len(queue) > 0 {
		curCourse := queue[0]
		answer = append(answer, curCourse)
		queue = queue[1:] //出队列
		// 将前置课程是curCourse的课程入度-1， 如果入度减少到0，则入队列
		n := len(adjacent[curCourse])
		for i := 0; i < n; i++ {
			inDegree[adjacent[curCourse][i]]-- //入度 -1
			if inDegree[adjacent[curCourse][i]] == 0 {
				queue = append(queue, adjacent[curCourse][i])
			}
		}
	}
	if len(answer) != numCourses {
		return nil
	}
	return answer
}
