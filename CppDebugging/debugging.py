import json
git config --global user.email




def stringToIntegerList(input):
    return json.loads(input)

def main():
    inp = "abcdddeeeeaabbbcd"
    sol = Solution()
    print(sol. largeGroupPositions(inp))
if __name__ == '__main__':
    main()