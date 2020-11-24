""" Implementation of General Tree Data Structure
"""

class TreeNode:
    """ General tree implementation """
    def __init__(self, data):
        self.data = data
        self.children = []
        self.parent = None

    def add_child(self, child):
        """ adding child to tree node """
        child.parent = self
        self.children.append(child)

    def get_level(self):
        """ get level of node by calculating how many ancestor it has """
        level = 0
        parent = self.parent
        while parent:
            level += 1
            parent = parent.parent

        return level

    def print_tree(self):
        """ print tree in proper hierarchical format """
        spaces = ' ' * self.get_level() * 3
        prefix = spaces + "|__" if self.parent else ""
        print(prefix + self.data)
        if self.children:
            for child in self.children:
                child.print_tree()


def build_product_tree():
    """ operational code """
    root = TreeNode("Electronics")

    laptop = TreeNode("Laptop")
    laptop.add_child(TreeNode("Mac"))
    laptop.add_child(TreeNode("Surface"))
    laptop.add_child(TreeNode("Thinkpad"))

    cellphone = TreeNode("Cell Phone")
    cellphone.add_child(TreeNode("iPhone"))
    cellphone.add_child(TreeNode("Google Pixel"))
    cellphone.add_child(TreeNode("Vivo"))

    television = TreeNode("TV")
    television.add_child(TreeNode("Samsung"))
    television.add_child(TreeNode("LG"))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(television)

    root.print_tree()

if __name__ == '__main__':
    build_product_tree()
