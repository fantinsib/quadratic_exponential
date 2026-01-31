#pragma once

#include <optional>



class Date {

    /**
     * @brief Creates a Date object
     * 
     * @param D the day (value comprised between 1 and 31)
     * @param M the month (value comprised between 1 and 12)
     * @param Y the year
     * @param h optional : the hour. If not specified, value is set to 0
     * @param m optional : the minute. If not specified, value is set to 0
     * @param s optional : the second. If not specified, value is set to 0
     */
public:
    Date(int D, int M, int Y, 
        std::optional<int> h = std::nullopt, 
        std::optional<int> m= std::nullopt, 
        std::optional<int> s= std::nullopt);
    int D;
    int M;
    int Y;
    int h;
    int m;
    int s;
    
    int month() {return M;}
    int year() {return Y;}
    int day() {return D;}
    int hour() {return h;}
    int second() {return s;}
    int minute() {return m;}
};
