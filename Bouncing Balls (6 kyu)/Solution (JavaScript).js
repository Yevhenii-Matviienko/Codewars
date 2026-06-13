function bouncingBall(h, bounce, window) {
  if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) {
    return -1;
  }
  let ball_seen = 1;
  while (h * bounce > window) {
    ball_seen += 2;
    h *= bounce;
  }
  return ball_seen;
}