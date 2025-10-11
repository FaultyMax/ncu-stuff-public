
import math

class Point:
	
	x = 0
	y = 0
	
	def __init__(self,a,b):
		self.x = a
		self.y = b
	def __str__(self):
		return str(f"({self.x}, {self.y})")
	def __add__(self, o):
		return self.x +	o.x, self.y + o.y
	def distance(a,b):
		return math.sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)) 
		
		
		

if __name__ =="__main__":
	
	a = Point(3,6)
	b = Point(-1,7)
	c = a +b
	print(Point.distance(a,b))
	print(c)
