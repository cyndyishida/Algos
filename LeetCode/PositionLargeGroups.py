class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """

        groups = []
        start = 0
        end = 0
        curr = S[0]
        while end  < len(S):
            if end + 1 < len(S):
                if curr != S[end + 1]:
                    if end - start >= 2:
                        groups.append([start, end])
                    start = end + 1
                    curr = S[end + 1]
            else:
                if end - start >= 2:
                    groups.append([start, end])
            end += 1


        return groups
