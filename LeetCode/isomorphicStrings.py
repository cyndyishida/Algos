class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_dict = {}
        t_dict = {}
        
        s_dict = {s[i]: s_dict.get(i, []) + [i] for i in range(len(s)) }
        t_dict = {t[j]: t_dict.get(j, []) + [j] for j in range(len(t)) }
            
        for i in range(len(s)):
            if s_dict[s[i]] != t_dict[t[i]]:
                return False
            
            
        return True
