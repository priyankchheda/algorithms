""" Implementation of Graph Data Structure and Graph Theory Algorithms
    in Python
"""

class Graph:
    """ Graph data structure Wrapper"""
    def __init__(self, graph_dict=None):
        """ initialize a graph object
            if no dictionary or none is given, an empty dictionary
            will be used
            :param graph_dict: initial graph setup
        """
        if not graph_dict:
            graph_dict = {}
        self._graph_dict = graph_dict

    def is_vertex(self, node):
        """ Returns true if node is vertex of graph, otherwise false """
        return node in self._graph_dict

    def add_vertex(self, node):
        """ Adds new vertex to graph. If vertex is already present in graph,
            no action will take place.
            :param node: new node to be added to graph
        """
        if node not in self._graph_dict:
            self._graph_dict[node] = []

    def add_edge(self, node, neighbour):
        """ Adds new directed edge to graph starting from 'node' to 'neighbor'
            It will insert node to graph, if the node is not already present
            :param node: starting graph vertex
            :param neighbour: ending graph vertex
        """
        if node not in self._graph_dict:
            self.add_vertex(node)
        if neighbour not in self._graph_dict:
            self.add_vertex(neighbour)
        self._graph_dict[node].append(neighbour)

    def order(self):
        """ Order returns the order of a graph i.e. number of vertices
            :returns: returns number of vertices
        """
        return len(list(self._graph_dict))

    def vertices(self):
        """ return list of all vertices in graph """
        return list(self._graph_dict)

    def neighbours(self, node):
        """ returns all vertices of given node
            :param node: graph vertex
            :returns: all node neighbour vertices
        """
        return self._graph_dict[node]

    def show_edges(self):
        """ show all the graph edges """
        for node in self._graph_dict:
            for neighbour in self._graph_dict[node]:
                print(f"{node} -> {neighbour}")


def main():
    """ Operational Function """
    g_dict = {
        '1': ['2', '3'],
        '2': ['3', '1'],
        '3': ['1', '2', '4'],
        '4': ['3']
    }
    g_obj = Graph(g_dict)
    g_obj.show_edges()


if __name__ == "__main__":
    main()
