#!/usr/bin/python

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        print(self.val)


def serialize(node):
    # serialize with pre-order traversal

    lastLeft = ''
    lastRight = ''

    if node.left is not None:
        lastLeft = ',' + serialize(node.left)

    if node.right is not None:
        lastRight = ',' + serialize(node.right)

    return node.val + lastLeft + lastRight


def deserializeHelper(node, nodesToConvert, depth):
    while len(nodesToConvert) > 0:
        # look at the next value
        nextValue = nodesToConvert[0]
        # split string to determine depth...
        nextValueExpanded = nextValue.split('.')
        # and next depth
        nextValueDepth = len(nextValueExpanded)

        if nextValueDepth == depth + 1:
            # the next value is a child element - remove it from the list and make a new node
            nextNode = Node(nodesToConvert.pop(0))
            # assign child according to its direction - the last string in the next value list
            # then call helper again with next node as the root
            if nextValueExpanded[-1] == 'left':
                node.left = nextNode
                deserializeHelper(node.left, nodesToConvert, nextValueDepth)
            else:
                node.right = nextNode
                deserializeHelper(node.right, nodesToConvert, nextValueDepth)
        else:
            # the next value is not a child of current root
            return


def deserialize(inputStr):
    nodesToConvert = inputStr.split(',')
    root = Node(nodesToConvert.pop(0))
    deserializeHelper(root, nodesToConvert, 0)
    return root


if __name__ == '__main__':
    print('running test...')
    assert deserialize(serialize(Node('root', Node('left', Node('left.left')), Node('right')))).left.left.val == 'left.left'
    print('passed!')

    assert deserialize(serialize(Node('root', Node('left', Node('left.left'), Node('left.right')), Node('right')))).left.right.val == 'left.right'
    print('passed!')

    assert deserialize(serialize(Node('root', Node('left', Node('left.left', Node('left.left.right')), Node('left.right')), Node('right')))).left.left.right.val == 'left.left.right'
    print('passed!')
