"""
L = list of emails, 
where based on these rules you know that different formatted emails are the same
1. dots dont matter in local
2. ignore everything after '+'
return the number of emails that have redundant formats
"""



def solution(L):
    # write your code in Python 3.6
    # hash table problem, basically create a frequency table
    # run time is O( N * M )
    # N = len(L)
    # M = len(local part of email )
    e_freq = {}

    for email in L:
        sep = email.index('@')
        stop = email.index('+') if '+' in email[0:sep] else sep

        local = ''.join(i for i in email[0:stop] if i != '.')
        domain = email[sep:]

        e_freq[local+domain] = e_freq.get(local+domain, 0 ) + 1


    return sum(1 for i in e_freq.values() if i > 1)

