package 字典树

type Trie struct {
	nextNode [26]*Trie //字典树存储下一层节点，a-z一一对应
	isEnd    bool
}

func Constructor() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	current := this
	for _, c := range word {
		index := c - 'a'
		if current.nextNode[index] == nil { //掺入单词字母，如果当前字母不存在就创建一个
			current.nextNode[index] = &Trie{}
		}
		current = current.nextNode[index] //指针下移
	}
	current.isEnd = true
}

func (this *Trie) Search(word string) bool {
	current := this
	for _, c := range word {
		index := c - 'a'
		if current.nextNode[index] == nil {
			return false
		}
		current = current.nextNode[index]
	}
	return current.isEnd
}

func (this *Trie) StartsWith(prefix string) bool {
	current := this
	for _, c := range prefix {
		index := c - 'a'
		if current.nextNode[index] == nil {
			return false
		}
		current = current.nextNode[index]
	}
	return true
}
