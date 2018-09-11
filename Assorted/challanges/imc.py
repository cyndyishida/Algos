# Given the description of a game of battleships, find how many ships are sunk and how many have been hit but not sunk


def find_ship(hit, ships):
    for ship in ships:
        if hit in ship:
            ship[hit] = False


def add_positions(ships, N):
    for ship in ships:
        if len(ship) == 2 :
            top, bottom = ship.keys()
            if top[0:-1] != bottom[0:-1] and top[-1] != bottom[-1]:
                ship[top[0:-1] + bottom[-1]] = True
                ship[bottom[0:-1] + top[-1]] = True

            elif top[0:-1] == bottom[0:-1] and top[-1] != bottom[-1]:
                new = chr((ord(top[-1]) + 1) )
                ship[top[0:-1]+new] = True

            elif top[-1] == bottom[-1] and top[0:-1] != bottom[0:-1]:
                new = int(top[0:-1]) + 1
                ship[str(new) + top[-1]] = True



def solution(N, S, T):
    # write your code in Python 3.6
    #  O( M * N )runtime  where N is the number of ships and M is the number of hits
    # O(N * T)  space where N is the number of ships and T= number of positions that make up the ship


    if not T:
        return "0,0"

    # list of dictionaries that represent ships
    ships = list( {j: True for j in i.split()} for i in S.split(","))
    add_positions(ships, N)


    hits = set(i for i in T.split())

    for hit in hits:
        find_ship(hit, ships)


    hit_count = 0
    sunk_count = 0

    for ship in ships:
        curr_count = sum(1 for i in ship.values() if not i)
        if curr_count  == len(ship):
            sunk_count +=1
        elif curr_count >= 1 :
            hit_count += 1

    return f"{sunk_count},{hit_count}"



print(solution(12,'7C 7D,3K 3K,4D 4G,1K 1K,9C 9E,2C 2F,12L 12L,2J 2L,3D 3F,6G 9G,8H 8J,8A 10A,10C 10D,3L 6L,5F 5I,6D 6D,8D 8E,11K 12K,4C 6C,12H 12J,8L 10L,7F 9F,11C 12C,10H 10J,3J 3J,2I 3I,6J 6K,4J 4K,3B 3C,11F 11G,8B 11B,6H 6I,5J 5K,6E 7E,10E 11E,11H 11J,11A 11A,1B 1B', '1J 4H 10L 3G 5J 11B 5I 10G 6E 1H 5H 3B 11A 11I 8G 12C 4C 2C 9L 5A 10A 10F 8D 4E 11H 6C 7H 5L 1G 10J 8K 6J 2I 4J 8J 6K 3J 5K 9H 6B 10H 12E 11F 12D 10I 5B 2A 7D 11L 6D 11D 7K 1L 10B 1K 4G 2G 9D 2J 11K 4B 8E 7E 3D 12H 1E 5E 6G 4I 1B 6H 4D 12J 7J 12A 7G 8I 1F 6A 12G 4K 3A 4L 2L 3I 10D 2F 1D 8H 3K 12F 3E 4A 11E 9B 3L 8A 12K 5C 7C'))



#print(solution(4, '1A 1B, 1B 2B', '1B') )
