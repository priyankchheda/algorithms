class LinearProbing:
    def __init__(self):
        self.size = 10
        self.arr = [None for _ in range(self.size)]

    def get_hash(self, key):
        hash_value = 0
        for char in key:
            hash_value += ord(char)
        return hash_value % self.size

    def put(self, key, value):
        index = self.get_hash(key)
        if self.arr[index] is not None:
            if self.arr[index][0] == key:
                # update existing value
                self.arr[index] = (key, value)
                return

            # rehash try to find another slot
            index = (index + 1) % self.size

        # insert new value
        self.arr[index] = (key, value)

    def get(self, key):
        index = self.get_hash(key)
        if self.arr[index] is not None:
            if self.arr[index][0] == key:
                return self.arr[index][1]

            index = (index + 1) % self.size

        # if key is not present
        return None


def main():
    """ operational function """
    table = LinearProbing()
    table.put("apple", 10)
    table.put("orange", 20)
    table.put("car", 30)
    table.put("table", 40)

    print(table.get("orange")) # 20
    print(table.get("kevin")) # None

    table.put("orange", 50)
    print(table.get("orange")) # 50

if __name__ == "__main__":
    main()

