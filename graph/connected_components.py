""" Finding Connected Components using BFS Graph Traversal Algorithms
"""

def find_components(graph):
    """ breadth first search graph traversal algorithm """
    connected_components = []
    vertices = list(graph)

    while vertices:
        start_node = vertices.pop()
        queue = [start_node]
        visited = [start_node]

        while queue:
            node = queue.pop(0)
            for neighbour in graph[node]:
                if neighbour not in visited:
                    queue.append(neighbour)
                    visited.append(neighbour)
                    vertices.remove(neighbour)
        connected_components.append(visited)
    return connected_components


def main():
    """ operational function """
    graph = {
        '1': ['2', '3'],
        '2': ['3', '1'],
        '3': ['1', '2', '4'],
        '4': ['3'],
        '5': ['7', '6'],
        '6': ['5'],
        '7': ['5'],
        '8': [],
        '9': [],
    }

    print(find_components(graph))


if __name__ == "__main__":
    main()
