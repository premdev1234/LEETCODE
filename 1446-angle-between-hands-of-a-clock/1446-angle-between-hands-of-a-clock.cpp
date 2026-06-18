class Solution {
public:
    double angleClock(int hour, int minutes) {
        double H = (double)hour , M = (double)minutes ;
        double h_tick = (5.0*H) + (M/12.0) ;
        double h_angle = 6.0*h_tick ;
        double m_angle = 6.0*M ;
        double angle = max(h_angle,m_angle)-min(h_angle,m_angle);
        double ans = min( angle , 360.0 - angle);
        return ans;
    }
};