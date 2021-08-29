""" Dijkstra's Algorithm to calculate single sources shortest path
"""

import heapq

def calculate_distances(graph, starting_vertex):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[starting_vertex] = 0

    pq = [(0, starting_vertex)]
    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)

        # Nodes can get added to the priority queue multiple times. We only
        # process a vertex the first time we remove it from the priority queue.
        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            # Only consider this new path if it's better than any path we've
            # already found.
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances


def main():
    """ operational function """
    graph = {
        'A': {'B': 5, 'E': 9, 'H': 8},
        'B': {'C': 12, 'D': 15, 'H': 4},
        'C': {'D': 3, 'G': 11},
        'D': {'G': 9},
        'E': {'F': 4, 'G': 20, 'H': 5},
        'F': {'C': 1, 'G': 13},
        'G': {},
        'H': {'C': 7, 'F': 6}
    }

    print(calculate_distances(graph, 'A'))


if __name__ == "__main__":
    main()
