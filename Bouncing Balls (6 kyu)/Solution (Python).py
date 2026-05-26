def bouncing_ball(h, bounce, window):
    if h <= 0 or bounce <= 0 or bounce >= 1 or window >= h:
        return -1
    ball_seen = 1
    h *= bounce
    while h > window:
        ball_seen += 2
        h *= bounce
    return ball_seen