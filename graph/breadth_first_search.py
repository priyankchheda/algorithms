""" Breadth-First Search Graph Traversal Algorithm

    Breadth-First Search  is a traversing algorithm where you should start
    traversing from a selected node (source or starting node) and traverse
    the graph layerwise thus exploring the neighbour nodes (nodes which
    are directly connected to source node). You must then move towards the
    next-level neighbour nodes.

    Time Complexity: O(V+E)
    Space Complexity: O(V)
"""

from collections import deque

def breadth_first_search(graph, root):
    """ graph traversal algorithm
        breadth first search implementation
    """
    visited = set()
    queue = deque([root])
    visited.add(root)

    while queue:
        vertex = queue.popleft()
        print(str(vertex), end=" ")

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


def main():
    """ operational function """
    graph = {
        "A": ["B", "C", "D"],
        "B": ["E"],
        "C": ["F", "G"],
        "D": ["H"],
        "E": ["I"],
        "F": ["J"],
        "G": [],
        "H": [],
        "I": [],
        "J": []
    }
    print("Breadth First Traversal: ", end="")
    breadth_first_search(graph, "A")
    print()


if __name__ == "__main__":
    main()
