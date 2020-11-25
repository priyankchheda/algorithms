class HashTable:
    def __init__(self):
        self.max = 10
        self.arr = [[] for _ in range(self.max)]

    def get_hash(self, key):
        hash_value = 0
        for char in key:
            hash_value += ord(char)
        return hash_value % self.max

    def __getitem__(self, key):
        hash_value = self.get_hash(key)
        for element in self.arr[hash_value]:
            if element in self.arr[hash_value]:
                if element[0] == key:
                    return element[1]

    def __setitem__(self, key, value):
        hash_value = self.get_hash(key)
        for index, element in enumerate(self.arr[hash_value]):
            if element and element[0] == key:
                self.arr[hash_value][index] = (key, value)
                return

        self.arr[hash_value].append((key, value))

    def __delitem__(self, key):
        hash_value = self.get_hash(key)
        for index, element in enumerate(self.arr[hash_value]):
            if element[0] == key:
                del self.arr[hash_value][index]


def main():
    """ operational function """
    table = HashTable()
    table["march 6"] = 120
    table["march 6"] = 78
    table["march 8"] = 67
    table["march 9"] = 4
    table["march 17"] = 459

    print(table["march 6"]) # 78
    print(table["march 17"]) # 459

    del table["march 17"]
    print(table["march 17"]) # None


if __name__ == "__main__":
    main()
