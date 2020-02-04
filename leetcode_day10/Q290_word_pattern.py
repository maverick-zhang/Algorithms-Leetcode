class Solution:
    def wordPattern(self, pattern: str, words: str) -> bool:
        words_list = words.split(" ")
        if len(words_list) != len(pattern):
            return False
        char_to_word = {}
        word_to_char= {}
        for i in range(len(pattern)):
            if pattern[i] not in char_to_word and words_list[i] not in word_to_char:
                char_to_word[pattern[i]] = words_list[i]
                word_to_char[words_list[i]] = pattern[i]
            elif pattern[i] in char_to_word and words_list[i] in word_to_char:
                if char_to_word[pattern[i]] != words_list[i] or word_to_char[words_list[i]] != pattern[i]:
                    return False
            else:
                return False
        return True



if __name__ == '__main__':
    s = Solution()
    s.wordPattern("aba", "dog cat cat")