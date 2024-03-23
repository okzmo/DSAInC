package main

import (
	"errors"
	"fmt"
)

type Queue struct {
	values []int
}

func (q *Queue) enque(val int) {
	q.values = append(q.values, val)
}

func (q *Queue) deque() (int, error) {
	if len(q.values) == 0 {
		return 0, errors.New("The queue is already empty")
	}

	latestVal := q.values[0]
	q.values = q.values[1:]

	return latestVal, nil
}

func main() {
	fmt.Println("hello world")
	queue := Queue{}
	queue.enque(2)
	queue.enque(3)
	queue.enque(4)
	fmt.Println(queue.values) // [2,3,4]
	val, _ := queue.deque()
	fmt.Println(val)          // 2
	fmt.Println(queue.values) // [3,4]
	val, _ = queue.deque()
	fmt.Println(val)          // 3
	fmt.Println(queue.values) // [4]
	val, _ = queue.deque()    // 4
	val, err := queue.deque() // nothing, throw an error
	if err != nil {
		fmt.Println(err)
	}
}
