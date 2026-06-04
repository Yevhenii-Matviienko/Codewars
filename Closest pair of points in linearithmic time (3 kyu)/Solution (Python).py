def closest_pair(points):
    def distance_square(a, b):
        return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

    def solve(p_x_y_s, p_y_s):
        n = len(p_x_y_s)
        if n <= 3:
            best_pair = (p_x_y_s[0], p_x_y_s[1])
            best_distance = distance_square(p_x_y_s[0], p_x_y_s[1])
            for i in range(n):
                for j in range(i + 1, n):
                    new_distance = distance_square(p_x_y_s[i], p_x_y_s[j])
                    if new_distance < best_distance:
                        best_distance = new_distance
                        best_pair = (p_x_y_s[i], p_x_y_s[j])
            return best_pair, best_distance
        middle = n // 2
        middle_point_x = p_x_y_s[middle][0]
        left_part_points_x = p_x_y_s[:middle]
        right_part_points_x = p_x_y_s[middle:]
        left_part_points_set = set(left_part_points_x)
        left_part_points_y = [point for point in p_y_s if point in left_part_points_set]
        right_part_points_y = [point for point in p_y_s if point not in left_part_points_set]
        points_pair_left_part, points_distance_left_part = solve(left_part_points_x, left_part_points_y)
        points_pair_right_part, points_distance_right_part = solve(right_part_points_x, right_part_points_y)
        if points_distance_left_part < points_distance_right_part:
            best_pair, best_distance = points_pair_left_part, points_distance_left_part
        else:
            best_pair, best_distance = points_pair_right_part, points_distance_right_part
        strip = [point for point in p_y_s if (point[0] - middle_point_x) ** 2 < best_distance]
        for i in range(len(strip)):
            for j in range(i + 1, min(i + 8, len(strip))):
                new_distance = distance_square(strip[i], strip[j])
                if new_distance < best_distance:
                    best_distance = new_distance
                    best_pair = (strip[i], strip[j])
        return best_pair, best_distance
    
    points = list(points)
    if len(points) == 2:
        return points[0], points[1]
    points_x_y_sorted = sorted(points)
    points_y_sorted = sorted(points, key=lambda p: p[1])
    return solve(points_x_y_sorted, points_y_sorted)[0]