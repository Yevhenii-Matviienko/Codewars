package bouncing

fun bouncingBall(h: Double, bounce: Double, window: Double): Int {
    if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) {
        return -1
    }
    var height = h
    var ball_seen = 1
    while (height * bounce > window) {
        ball_seen += 2
        height *= bounce
    }
    return ball_seen
}