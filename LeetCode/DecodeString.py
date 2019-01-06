class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        i = 0
        result = list(s)
        auxillary_indicies = [] # treat like stack

        while i < len(result):
            if result[i] == '[':
                auxillary_indicies.append(int(i))
            elif result[i] == ']':
                start = auxillary_indicies.pop()
                num, idx = self.get_all_nums(result, start-1)
                current = num * result[start+1:i]
                result[start-idx : i+1] = current
                i -= 3 # offset for extra characters 
            i += 1

        return "".join(result)

    def get_all_nums(self, input_list, idx):
        int_val = []
        counter = 0
        while idx > -1 and input_list[idx].isnumeric():
            int_val.insert(0, input_list[idx])
            idx -=1
            counter +=1
        return int("".join(int_val)), counter
