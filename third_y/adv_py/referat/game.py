import pygame
from random import randrange

WINDOW = 1000
TILE_SIZE = 50
RANGE = (TILE_SIZE // 2, WINDOW - TILE_SIZE // 2, TILE_SIZE)

# randrange(start, stop, step)
# *RANGE -> unpacking 
get_random_position = lambda: [randrange(*RANGE), randrange(*RANGE)]

# init snake
snake = pygame.rect.Rect([0, 0, TILE_SIZE - 2, TILE_SIZE - 2])
snake.center = get_random_position()
length = 1
segments = [snake.copy()]
snake_dir = (0,0)

time, time_step = 0, 175 # ms

# init food
food = snake.copy()
food.center = get_random_position()


screen = pygame.display.set_mode([WINDOW,WINDOW])
pygame.display.set_caption('Snake') 
clock = pygame.time.Clock()

while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			exit()
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_w:
				snake_dir = (0, -TILE_SIZE)
			if event.key == pygame.K_s:
				snake_dir = (0, +TILE_SIZE)
			if event.key == pygame.K_a:
				snake_dir = (-TILE_SIZE, 0)
			if event.key == pygame.K_d:
				snake_dir = (+TILE_SIZE, 0)

	screen.fill("black")

	# handle death
	self_eating = pygame.Rect.collidelist(snake,segments[:-1]) != -1 # true if collision accured
	if snake.left < 0 or snake.right > WINDOW or snake.top < 0 or snake.bottom > WINDOW or self_eating:
		# reseting the game
		snake.center, food.center = get_random_position(), get_random_position()
		length, snake_dir = 1, (0, 0)
		segments = [snake.copy()]

	# handle eating
	if snake.center == food.center:
		food.center = get_random_position()
		length += 1

	# draw
	pygame.draw.rect(screen, 'red', food) # food
	[pygame.draw.rect(screen, 'green', segment) for segment in segments] # snake

	# move
	time_now = pygame.time.get_ticks()
	if time_now - time > time_step:
		time = time_now
		snake.move_ip(snake_dir)
		segments.append(snake.copy())
		segments = segments[-length:]
		#print(len(segments))
	pygame.display.flip()
	clock.tick(60)
