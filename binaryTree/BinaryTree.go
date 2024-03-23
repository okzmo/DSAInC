package main

import (
	"errors"
	"fmt"
)

type Node struct {
	val        int
	leftChild  *Node
	rightChild *Node
}

type BinaryTree struct {
	head Node
}

func insert(root *Node, node Node) *Node {
	if root == nil {
		return &node
	} else if node.val < root.val {
		root.leftChild = insert(root.leftChild, node)
	} else if node.val > root.val {
		root.rightChild = insert(root.rightChild, node)
	}

	return root
}

func (b *BinaryTree) Insert(val int) {
	node := Node{val: val}
	insert(&b.head, node)
}

func search(root *Node, val int) *Node {
	if root == nil {
		return nil
	} else if val < root.val {
		return search(root.leftChild, val)
	} else if val > root.val {
		return search(root.rightChild, val)
	}

	return root
}

func (b *BinaryTree) Search(val int) (*Node, error) {
	node := search(&b.head, val)
	if node == nil {
		return nil, errors.New("no node with this value has been found")
	}
	return node, nil
}

func successor(root *Node) int {
	curr := root.rightChild
	for curr.leftChild != nil {
		curr = curr.leftChild
	}

	return curr.val
}

func predecessor(root *Node) int {
	curr := root.leftChild
	for curr.rightChild != nil {
		curr = curr.rightChild
	}

	return curr.val
}

func remove(root *Node, val int) *Node {
	if root == nil {
		return root
	} else if val < root.val {
		root.leftChild = remove(root.leftChild, val)
	} else if val > root.val {
		root.rightChild = remove(root.rightChild, val)
	} else {
		if root.leftChild == nil && root.rightChild == nil {
			root = nil
		} else if root.leftChild != nil {
			root.val = successor(root)
			root.rightChild = remove(root.rightChild, val)
		} else if root.rightChild != nil {
			root.val = successor(root)
			root.leftChild = remove(root.leftChild, val)
		}
	}

	return root
}

func (b *BinaryTree) Remove(val int) (*Node, error) {
	node, err := b.Search(val)
	copyNode := &Node{val: node.val}
	if err != nil {
		return nil, errors.New("the node you want to remove does not exist")
	}

	remove(&b.head, val)

	return copyNode, nil
}

func main() {
	fmt.Println("hello world")
	binaryTree := BinaryTree{head: Node{val: 5}}
	binaryTree.Insert(10)
	binaryTree.Insert(2)
	binaryTree.Insert(15)
	binaryTree.Insert(12)
	fmt.Println(binaryTree.head)

	node, _ := binaryTree.Remove(2)
	fmt.Println(node)
	fmt.Println(binaryTree.head)
}
