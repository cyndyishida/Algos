'''
add words from magazine, word as the key, count as the value
for every word in the ransom note, 
- if word is in the dictionary & the count isn't 0 decrement tha key's value
- at any point that isn't true, make flag false


'''


def ransom_note(magazine, ransom):
    word_dict = {}
    for i in magazine:
        if i in word_dict:
            word_dict[i] += 1
        else:
            word_dict[i] = 1
    match = True
    for word in ransom:
        if word in word_dict and word_dict[word] != 0:
            word_dict[word] -= 1
        else:
            match = False
    return match
       
        
m, n = [int(i) for i in input().strip().split()]
answer = ransom_note(input().strip().split(' '), input().strip().split(' '))


print("Yes" if answer else "No")