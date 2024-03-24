package main

import (
	"errors"
	"fmt"
)

type Comparer func(a, b int) bool

type Heap struct {
	items   []int
	compare Comparer
}

func left(i int) int {
	return i*2 + 1
}

func right(i int) int {
	return i*2 + 2
}

func parent(i int) int {
	return (i - 1) / 2
}

func (h *Heap) swap(i, j int) {
	h.items[i], h.items[j] = h.items[j], h.items[i]
}

func (h *Heap) heapifyDown(idx int) {
	lastIdx := len(h.items) - 1
	l, r := left(idx), right(idx)
	childCmp := 0

	for l <= lastIdx {
		if l == lastIdx {
			childCmp = l
		} else if h.compare(h.items[l], h.items[r]) {
			childCmp = l
		} else {
			childCmp = r
		}

		if h.compare(h.items[childCmp], h.items[idx]) {
			h.swap(idx, childCmp)
			idx = childCmp
			l, r = left(idx), right(idx)
		} else {
			break
		}
	}
}

func (h *Heap) heapifyUp(idx int) {
	for h.compare(h.items[idx], h.items[parent(idx)]) {
		h.swap(idx, parent(idx))
		idx = parent(idx)
	}
}

func (h *Heap) Insert(val int) {
	h.items = append(h.items, val)
	h.heapifyUp(len(h.items) - 1)
}

func (h *Heap) Extract() (int, error) {
	l := len(h.items) - 1

	if l < 0 {
		return -1, errors.New("can't extract a value from an array with a length of 0")
	}

	val := h.items[0]
	h.items[0] = h.items[l]
	h.items = h.items[:l]

	h.heapifyDown(0)

	return val, nil
}

func NewHeap(compare Comparer) *Heap {
	return &Heap{compare: compare}
}

func main() {
	minHeap := NewHeap(func(a, b int) bool { return a < b })
	maxHeap := NewHeap(func(a, b int) bool { return a > b })

	minHeap.Insert(5)
	minHeap.Insert(2)
	minHeap.Insert(3)
	minHeap.Insert(10)
	maxHeap.Insert(5)
	maxHeap.Insert(2)
	maxHeap.Insert(3)
	maxHeap.Insert(10)

	val, _ := minHeap.Extract()
	fmt.Println(val)
	fmt.Println(minHeap)

	val, _ = maxHeap.Extract()
	fmt.Println(val)
	fmt.Println(maxHeap)
}
