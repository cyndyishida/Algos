import math 
def answer(area):
    # answer 
    squares  = []
    while area >= 1:

        x = int(area ** (1/2) )** 2
        squares.append(x )
        area -= x

    return squares




print(answer(12))
