package 字典树

type WordDictionary struct {
	nextChar [26]*WordDictionary //a-z和0-25一一对应，
	isEnd    bool                //是否单词结尾
}

func (this *WordDictionary) AddWord(word string) {
	current := this
	for _, ch := range word {
		index := ch - 'a'
		if current.nextChar[index] == nil {
			current.nextChar[index] = &WordDictionary{}
		}
		current = current.nextChar[index]
	}
	current.isEnd = true
}

func dfs(word string, root *WordDictionary, index int) bool {
	if root == nil {
		return false
	}
	if len(word) == index {
		return root.isEnd
	}
	c := word[index]
	if c != '.' {
		return dfs(word, root.nextChar[c-'a'], index+1)
	} else {
		for _, child := range root.nextChar {
			if dfs(word, child, index+1) {
				return true
			}
		}
	}
	return false
}

func (this *WordDictionary) Search(word string) bool {
	return dfs(word, this, 0)
}
