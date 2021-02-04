""" Depth First Search Graph Traversal Algorithm

    Depth-first search (DFS) is an algorithm for traversing or searching
    graph data structures. The algorithm starts at the root node (selecting
    some arbitrary node as the root node in the case of a graph) and explores
    as far as possible along each branch before backtracking.

    Time Complexity: O(V+E)
"""

from collections import deque


def depth_first_search_recursion(graph, root):
    """ Depth first search graph traversal algorithm - iterative approach """
    def dfs_util(graph, vertex, visited):
        visited.add(vertex)
        print(vertex, end=" ")

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                dfs_util(graph, neighbour, visited)

    visited = set()
    dfs_util(graph, root, visited)


def depth_first_search_iteration(graph, root):
    """ Depth first search graph traversal algorithm - iterative approach """
    visited = set()
    stack = deque([root])
    visited.add(root)

    while stack:
        vertex = stack.pop()
        print(vertex, end=" ")

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                stack.append(neighbour)


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
    print("Depth First Traversal (Recursion): ", end="")
    depth_first_search_recursion(graph, 'A')
    print()

    print("Depth First Traversal (Iteration): ", end="")
    depth_first_search_iteration(graph, 'A')
    print()


if __name__ == "__main__":
    main()
