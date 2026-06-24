function closestPair(points) {
  function distance_square(a, b) {
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2;
  }

  function solve(p_x_y_s, p_y_x_s) {
    const n = p_x_y_s.length;
    if (n <= 3) {
      let best_pair = [p_x_y_s[0], p_x_y_s[1]];
      let best_distance = distance_square(p_x_y_s[0], p_x_y_s[1]);
      for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
          const new_distance = distance_square(p_x_y_s[i], p_x_y_s[j]);
          if (new_distance < best_distance) {
            best_distance = new_distance;
            best_pair = [p_x_y_s[i], p_x_y_s[j]];
          }
        }
      }
      return [best_pair, best_distance];
    }
    const middle = Math.floor(n / 2);
    const middle_point_x = p_x_y_s[middle][0];
    const left_part_points_x = p_x_y_s.slice(0, middle);
    const right_part_points_x = p_x_y_s.slice(middle);
    const left_part_points_set = new Set(left_part_points_x);
    const left_part_points_y = p_y_x_s.filter(point => left_part_points_set.has(point));
    const right_part_points_y = p_y_x_s.filter(point => !left_part_points_set.has(point));
    const [points_pair_left_part, points_distance_left_part] = solve(left_part_points_x, left_part_points_y);
    const [points_pair_right_part, points_distance_right_part] = solve(right_part_points_x, right_part_points_y);
    let best_pair;
    let best_distance;
    if (points_distance_left_part < points_distance_right_part) {
      best_pair = points_pair_left_part;
      best_distance = points_distance_left_part;
    } else {
      best_pair = points_pair_right_part;
      best_distance = points_distance_right_part;
    }
    const strip = p_y_x_s.filter(point => {
      return (point[0] - middle_point_x) ** 2 < best_distance;
    });
    for (let i = 0; i < strip.length; i++) {
      for (let j = i + 1; j < Math.min(i + 8, strip.length); j++) {
        const new_distance = distance_square(strip[i], strip[j]);
        if (new_distance < best_distance) {
          best_distance = new_distance;
          best_pair = [strip[i], strip[j]];
        }
      }
    }
    return [best_pair, best_distance];
  }

  points = Array.from(points);
  if (points.length === 2) {
    return [points[0], points[1]];
  }
  const points_x_y_sorted = [...points].sort((a, b) => {
    if (a[0] === b[0]) {
      return a[1] - b[1];
    }
    return a[0] - b[0];
  });
  const points_y_x_sorted = [...points].sort((a, b) => {
    if (a[1] === b[1]) {
      return a[0] - b[0];
    }
    return a[1] - b[1];
  });
  return solve(points_x_y_sorted, points_y_x_sorted)[0];
}