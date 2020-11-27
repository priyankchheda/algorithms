// Package shuffle generates a random permutation of array elements
package shuffle

import (
	"math/rand"
	"time"
)

// Shuffle randomize a given array. Here shuffle means that every permutation
// of array element shoudl equally likely.
// It uses Fisher-Yates (Knuth) shuffling algorithm.
//
// e.g. shuffle a deck of cards
//
// Fisher–Yates shuffle Algorithm works in O(n) time complexity.
// The assumption here is, we are given a function rand() that generates
// random number in O(1) time.
func Shuffle(data []int) {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < len(data); i++ {
		r := random.Intn(i + 1)
		data[i], data[r] = data[r], data[i]
	}
}
