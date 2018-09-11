# given infinite amount of cards numbered of 1-10, find the probablity of the dealer NOT getting a sum between 17 - 21 inclusive 



MAX_LIMIT = 22 
NUM_CARDS = 10 

def get_prob(card_count, curr_sum, last_prob):
    global MAX_LIMIT
    global NUM_CARDS
    keep_going  = card_count / NUM_CARDS * last_prob 
    lost_amount = (NUM_CARDS - (MAX_LIMIT - curr_sum) +1 ) / NUM_CARDS
    return keep_going * lost_amount if lost_amount else keep_going 

def find_blackjack_prob():
    dp_table = [None for i in range(16)]

    dp_table[15] = .5 
    for card_c, i in enumerate(range(14, -1, -1)):
        dp_table[i] = get_prob(card_c +1 , i+1 , dp_table[i +1] ) 
    return dp_table[0]




print(find_blackjack_prob())


