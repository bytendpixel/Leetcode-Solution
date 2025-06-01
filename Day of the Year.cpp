class Solution {
public:
    int dayOfYear(string date) {
        int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = (date[0] - 48) * 1000 + (date[1] - 48) * 100 +
                   (date[2] - 48) * 10 + (date[3] - 48);
        int month = (date[5] - 48) * 10 + (date[6] - 48) - 1;

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) monthDays[1] = 29;

        int total = (date[8] - 48) * 10 + (date[9] - 48);
        for (int i = 0; i < month; ++i)
            total += monthDays[i];
        return total;
    }
};
