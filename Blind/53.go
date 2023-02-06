package main

type TreeNode struct {
	Val		int
	Left	*TreeNode
	Right	*TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	current := root
	if p.Val > q.Val {
		p, q = q, p
	}
	for {
		if current.Left == nil || current.Right == nil {
			break
		}
		if current.Val < p.Val {
			current = current.Right
			continue
		} else if current.Val > q.Val {
			current = current.Left
			continue
		}
		break
	}
	return current
}