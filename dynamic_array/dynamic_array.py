""" Dynamic array is similar to an array, but with the difference that its
    size can be dynamically modified at runtime.
    We are using C style raw array using ctypes modules instead of python
    built-in list.
"""

import ctypes


class DynamicArray:
    def __init__(self, capacity):
        self._idx = 0
        self.lenght = 0
        self.capacity = capacity
        self.array = self._make_array()

    def __getitem__(self, key):
        if key < 0 or key >= self.lenght:
            raise IndexError('dynamic array index out of range')
        return self.array[key]

    def __len__(self):
        return self.lenght

    def __iter__(self):
        return self

    def __next__(self):
        if self._idx >= self.lenght:
            self._idx = 0
            raise StopIteration
        result = self.array[self._idx]
        self._idx += 1
        return result

    def _make_array(self):
        return (ctypes.py_object * self.capacity)()

    def _resize(self, new_capacity):
        self.capacity = new_capacity
        _array = self._make_array()
        for i in range(self.lenght):
            _array[i] = self.array[i]
        self.array = _array

    def append(self, value):
        if self.lenght >= self.capacity:
            self._resize(self.capacity * 2)
        self.array[self.lenght] = value
        self.lenght += 1

    def insert_at(self, elem, index):
        if index < 0 or index > self.lenght:
            raise IndexError("dynamic array index out of range")
        if self.lenght >= self.capacity:
            self._resize(self.capacity * 2)
        idx = self.lenght - 1
        while idx >= index:
            self.array[idx + 1] = self.array[idx]
            idx -= 1
        self.array[index] = elem
        self.lenght += 1

    def remove_at(self, index):
        if index < 0 or index >= self.lenght:
            raise IndexError("dynamic array index out of range")
        idx = index
        while idx < self.lenght - 1:
            self.array[idx] = self.array[idx+1]
            idx += 1
        self.array[self.lenght] = None
        self.lenght -= 1
