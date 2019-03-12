package hashtable

type Record struct {
	Key   int
	Value int
	Next  *Record
}

const (
	minLoadFactor    = 0.25
	maxLoadFactor    = 0.75
	defaultTableSize = 3
)

type HashTable struct {
	Hash []*Record
	Size int
}

func createHashTable(tableSize int) HashTable {
	return HashTable{Hash: make([]*Record, tableSize), Size: 0}
}

func CreateHashTable() HashTable {
	return HashTable{Hash: make([]*Record, defaultTableSize), Size: 0}
}

func hashFunction(key, size int) int {
	return key % size
}

func (h *HashTable) put(key, value int) bool {
	index := hashFunction(key, len(h.Hash))
	iterator := h.Hash[index]
	node := Record{key, value, nil}
	if iterator == nil {
		h.Hash[index] = &node
	} else {
		prev := &Record{0, 0, nil}
		for iterator != nil {
			if iterator.Key == key {
				iterator.Value = value
				return false
			}
			prev = iterator
			iterator = iterator.Next
		}
		prev.Next = &node
	}
	h.Size += 1
	return true
}

func (h *HashTable) Put(key, value int) {
	sizeChanged := h.put(key, value)
	if sizeChanged == true {
		h.checkLoadFactorAndUpdate()
	}
}

func (h *HashTable) Get(key int) (bool, int) {
	index := hashFunction(key, len(h.Hash))
	iterator := h.Hash[index]
	for iterator != nil {
		if iterator.Key == key {
			return true, iterator.Value
		}
		iterator = iterator.Next
	}
	return false, 0
}

func (h *HashTable) del(key int) bool {
	index := hashFunction(key, len(h.Hash))
	iterator := h.Hash[index]
	if iterator == nil {
		return false
	}
	if iterator.Key == key {
		h.Hash[index] = iterator.Next
		h.Size -= 1
		return true
	} else {
		prev := iterator
		iterator = iterator.Next
		for iterator != nil {
			if iterator.Key == key {
				prev.Next = iterator.Next
				h.Size -= 1
				return true
			}
			prev = iterator
			iterator = iterator.Next
		}
		return false
	}
}

func (h *HashTable) Del(key int) bool {
	sizeChanged := h.del(key)
	if sizeChanged == true {
		h.checkLoadFactorAndUpdate()
	}
	return sizeChanged
}

func (h *HashTable) getLoadFactor() float64 {
	return float64(h.Size) / float64(len(h.Hash))
}

func (h *HashTable) checkLoadFactorAndUpdate() {
	if h.Size == 0 {
		return
	} else {
		loadFactor := h.getLoadFactor()
		if loadFactor < minLoadFactor {
			hash := createHashTable(len(h.Hash) / 2)
			for _, record := range h.Hash {
				for record != nil {
					hash.put(record.Key, record.Value)
					record = record.Next
				}
			}
			h.Hash = hash.Hash
		} else if loadFactor > maxLoadFactor {
			hash := createHashTable(h.Size * 2)
			for _, record := range h.Hash {
				for record != nil {
					hash.put(record.Key, record.Value)
					record = record.Next
				}
			}
			h.Hash = hash.Hash
		}
	}
}
