import sys
input = sys.stdin.readline


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for letter in word:
            if letter not in current.children:
                current.children[letter] = TrieNode()
            current = current.children[letter]
        current.is_word = True

    def search(self, word):
        current = self.root
        for letter in word:
            if letter not in current.children:
                return False
            current = current.children[letter]
        return True


N, M = map(int, input().split())
T = Trie()
result = 0
for i in range(N):
    T.insert(input().rstrip())
for i in range(M):
    s = input().rstrip()
    if T.search(s):
        result += 1
print(result)
