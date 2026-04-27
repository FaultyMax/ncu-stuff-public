class BST_TREE:
	def __init__(self,val = None):
		self.root_node = Node(val) if val is not None else None
		if val is not None:
			self.root_node.counter += 1
		
	def insert(self,val):
		if not self.root_node:
			self.root_node = Node(val)
		else:
			self.root_node.insert(val)
		
	def find(self,key):
		if self.root_node:
			return self.root_node.find(key)
		
	def max_node(self):
		if self.root_node:
			return self.root_node.max_node()
		
	def min_node(self):
		if self.root_node:
			return self.root_node.min_node()
		
	def delete_node(self,key):
		if self.root_node:
			self.root_node = self.root_node.delete_node(self.root_node, key)
		
	def inorder(self):
		if self.root_node:
			self.root_node.inorder()
		
class Node:
	def __init__(self,val = None,parent = None):
		self.value = val
		self.counter = 0
		self.left = None
		self.right = None
		self.parent = parent
		
	def inorder(self):
		if self.left:
			self.left.inorder()
		print(self.value)
		if self.right:
			self.right.inorder()
	
	def inorder_list(self):
		
		if self.left:
			self.left.inorder_list()
		k = self.value
		if self.right:
			self.right.inorder_list()
		# trzeba cos pomyslec tutaj
		
	
	def insert(self,val):
		
		if self.value > val:
			if self.left:
				self.left.insert(val)
				return
			self.left = Node(val,self)
			self.left.counter += 1
		elif self.value < val:
			if self.right:
				self.right.insert(val)
				return
			self.right = Node(val,self)
			self.right.counter += 1
		elif self.value == val:
			self.counter += 1
			
	def find(self,key):
		if self.value is None:
			return False
		if self.value == key:
			return self
		if self.value > key:
			if not self.left:
				return False
			return self.left.find(key)
		elif self.value < key:
			if not self.right:
				return False
			return self.right.find(key)
		
	def max_node(self):
		if not self.right:
			return self
		else:
			return self.right.max_node()
	
	def min_node(self):
		if not self.left:
			return self
		else:
			return self.left.min_node()

	def delete_node(self,node,key):
			
		if node is None:
			return None
		
		if key < node.value:
			node.left = self.delete_node(node.left, key)
		elif key > node.value:
			node.right = self.delete_node(node.right, key)
		else:
			
			if node.counter > 1:
				node.counter -= 1
				return node
			
			if node.left is None:
				return node.right
			elif node.right is None:
				return node.left
				
			successor = node.right.min_node()
			node.value = successor.value
			node.counter = successor.counter
			successor.counter = 1
			node.right = self.delete_node(node.right,successor.value)
			
		return node
			
			

root = BST_TREE(14)

root.insert(8)
root.insert(8)
root.insert(5)
root.insert(4)
root.insert(7)
root.insert(19)
root.insert(32)
root.insert(17)
root.insert(12)

root.inorder()

root.root_node.inorder_list()

# Oblicz sumę k-najmniejszych elementów w drzewie.

k = 3
t_sum = 0

for i in range(k):
	f = root.min_node()
	t_sum += f.value
	root.delete_node(f.value)
	
print(f"\n{t_sum}\n")

# Sprawdź czy drzewo jest poprawnym BST.

	
	
