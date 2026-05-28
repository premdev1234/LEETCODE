class Solution:
    
    class Node:
        def __init__(self):
            self.children = {}
            self.index = -1 

    class Trie:
        def __init__(self, words):

            self.root = Solution.Node()
            self.words = words

            for index, word in enumerate(words):
                self.insert(word[::-1], index)

        def better(self, i, j):

            if j == -1:
                return True

            if len(self.words[i]) < len(self.words[j]):
                return True

            if len(self.words[i]) == len(self.words[j]) and i < j:
                return True

            return False        

        def insert(self, rev_word, index):

            node = self.root

            if self.better(index, node.index):
                node.index = index

            for c in rev_word:

                if c not in node.children:
                    node.children[c] = Solution.Node()

                node = node.children[c]

                if self.better(index, node.index):
                    node.index = index

        def query(self, word):

            rev = word[::-1]

            node = self.root

            for c in rev:

                if c not in node.children:
                    break

                node = node.children[c]

            return node.index


    def stringIndices(self, wordsContainer, wordsQuery):

        trie = self.Trie(wordsContainer)

        ans = []

        for word in wordsQuery:
            ans.append(trie.query(word))

        return ans