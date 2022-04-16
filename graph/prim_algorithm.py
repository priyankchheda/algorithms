""" Prim's Algorithm for finding minimum spanning tree
"""

import heapq

class Edge:
    """ undirected edge interface API """
    def __init__(self, vertex1, vertex2, weight):
        self.vertex1 = vertex1
        self.vertex2 = vertex2
        self.weight = weight

    def other(self, vertex):
        """ return other vertex of the edge """
        if vertex == self.vertex1:
            return self.vertex2
        return self.vertex1

    def __repr__(self):
        return f"({self.vertex1}, {self.vertex2}, {self.weight})"

    def __lt__(self, other):
        return self.weight < other.weight


class EdgeWeightedGraph:
    """ undirected weighted graph representation using adjacency list """
    def __init__(self, vertices_count):
        self.vertices_count = vertices_count
        self.edges = []

        self.adjacency_list = list()
        for _ in range(self.vertices_count):
            self.adjacency_list.append(set())

    def add_edge(self, edge):
        """ add edge to undirected weighted graph """
        self.adjacency_list[edge.vertex1].add(edge)
        self.adjacency_list[edge.vertex2].add(edge)
        self.edges.append(edge)

    def adjacent(self, vertex):
        """ edges incident to vertex """
        return self.adjacency_list[vertex]


class MinimumSpanningTree:
    """ Prim's Algorithm Python 3 Implementation """
    def __init__(self, graph):
        self.graph = graph
        self.mst_edges = []
        self.mst_weight = 0
        self.marked = [False] * self.graph.vertices_count
        self.priority_queue = []

    def visit(self, vertex):
        """ mark vertex and add adjcent edges to priority queue """
        self.marked[vertex] = True
        for edge in self.graph.adjacent(vertex):
            if not self.marked[edge.other(vertex)]:
                heapq.heappush(self.priority_queue, edge)

    def run(self):
        """ run prim's algorithm to find minimum spanning tree """
        self.visit(0)

        while self.priority_queue:
            edge = heapq.heappop(self.priority_queue)
            if self.marked[edge.vertex1] and self.marked[edge.vertex2]:
                continue
            self.mst_edges.append(edge)
            self.mst_weight += edge.weight
            if not self.marked[edge.vertex1]:
                self.visit(edge.vertex1)
            if not self.marked[edge.vertex2]:
                self.visit(edge.vertex2)


def main():
    """ operational function """
    graph = EdgeWeightedGraph(8)
    graph.add_edge(Edge(2, 3, 0.17))
    graph.add_edge(Edge(0, 7, 0.16))
    graph.add_edge(Edge(5, 7, 0.28))
    graph.add_edge(Edge(1, 7, 0.19))
    graph.add_edge(Edge(6, 2, 0.40))
    graph.add_edge(Edge(3, 6, 0.52))
    graph.add_edge(Edge(6, 0, 0.58))
    graph.add_edge(Edge(2, 7, 0.34))
    graph.add_edge(Edge(4, 5, 0.35))
    graph.add_edge(Edge(1, 2, 0.36))
    graph.add_edge(Edge(4, 7, 0.37))
    graph.add_edge(Edge(0, 2, 0.26))
    graph.add_edge(Edge(1, 3, 0.29))
    graph.add_edge(Edge(1, 5, 0.32))
    graph.add_edge(Edge(0, 4, 0.38))
    graph.add_edge(Edge(6, 4, 0.93))

    spanning_tree = MinimumSpanningTree(graph)
    spanning_tree.run()
    for edge in spanning_tree.mst_edges:
        print(edge)
    print(spanning_tree.mst_weight)


if __name__ == "__main__":
    main()
