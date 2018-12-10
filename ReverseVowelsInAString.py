class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        first_vowel = 0
        last_vowel = len(s) - 1
        vowels = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        while first_vowel < last_vowel:
            if( s[first_vowel] in vowels) and (s[last_vowel] in vowels): 
                s[first_vowel], s[last_vowel] = s[last_vowel], s[first_vowel]
                first_vowel += 1
                last_vowel -= 1 
            else:
                if s[first_vowel]  not in vowels:
                    first_vowel += 1
                if s[last_vowel] not in vowels :
                    last_vowel -= 1
            
        return "".join(s)
