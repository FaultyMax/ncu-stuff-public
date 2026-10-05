
my_points = [(-4, -5), (3, -1), (-3, -2), (5, 3), (7, 5), (4, -1), (-1, -4), (-3, -4), (2, -3), (6, 5), (-2, -2), (-5, -4), (-1, -2), (5, 1)]


def find_orientation(P0, P1, P2):
    
    z = (P1[0] - P0[0])*(P2[1] - P0[1]) - (P1[1] - P0[1])*(P2[0] - P0[0])

    return z

    if z < 0:
        pass
    if z > 0:
        pass
    else:
        pass


def find_convex_hull(points):

    #  find P0
    min_y = min([y for x, y in my_points])
    P0 = [x for x in points if x[1] == min_y]

    if len(P0) == 1:
        P0 = P0[0]
    else:
        P0 = min([x for x, y in my_points])

    print(P0)

    print(find_orientation((1, 1), (3, 1), (5, 2)))
    print(find_orientation((1, 1), (5, 4), (5, 2)))


find_convex_hull(my_points)
