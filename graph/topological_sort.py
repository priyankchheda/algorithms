""" Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of
vertices such that for every directed edge uv, vertex u comes before v in
the ordering. Topological Sorting for a graph is not possible if the graph is
not a DAG.
"""

def topological_sort(graph):
    """ topological sort python implementation """
    stack = []
    visited = set()

    def topological_sort_util(vertex):
        """ modified depth-first search recursive algorithm """
        visited.add(vertex)
        for node in graph[vertex]:
            if node not in visited:
                topological_sort_util(node)
        stack.append(vertex)


    for vertex in list(graph):
        if vertex not in visited:
            topological_sort_util(vertex)

    stack.reverse()
    return stack


def main():
    """ operational function """
    graph = {
        0: [1, 2, 5],
        1: [4],
        2: [],
        3: [2, 4, 5, 6],
        4: [],
        5: [2],
        6: [0, 4]
    }
    print(topological_sort(graph))


if __name__ == "__main__":
    main()
