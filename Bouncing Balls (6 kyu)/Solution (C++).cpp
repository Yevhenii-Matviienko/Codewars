using namespace std;

class Bouncingball {
    public:
        static int bouncingBall(double h, double bounce, double window)
        {
            if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) {
                return -1;
            }
            int ball_seen = 1;
            while (h * bounce > window)
            {
                ball_seen += 2;
                h *= bounce;
            }
            return ball_seen;
        }
};