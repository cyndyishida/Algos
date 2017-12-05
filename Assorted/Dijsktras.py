def min_distance(unvisited, dist) :
    min_ele = 100000000
    min_node = None 
    for i in unvisited:
        if min_ele > dist[i]:
            min_node = i
            min_ele = dist[i]

    return min_node 




def Dijkstra(Graph, source):
    unvisited = set()
    dist[source]  = 0                      # Distance from source to source is set to 0
    for vertex in Graph:                    # Initializations
        if v !=  source:
            dist[v] = None                 # Unknown distance function from source to each node set to infinity
        unvisited.add(v)                      # All nodes initially in Q

    while unvisited:                              # The main loop
        v = min_distance( unvisited, dist )   # In the first run-through, this vertex is the source node
        unvisited.remove(v)

        for neighbor in v:                    # where neighbor u has not yet been removed from Q.
            alt = dist[v] + neighbor.cost(v)
            if alt < dist[neighbor]:               # A shorter path to u has been found
                dist[neighbor] = alt            # Update distance of u 
    return dist
