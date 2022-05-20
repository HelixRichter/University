#ifndef MYTASK_1_95_MOVEBOT_H
#define MYTASK_1_95_MOVEBOT_H


class bot {
private:
    char x_position;
    char y_position;
public:
    bot();
    bot(char, char);
    bot(bot &);
    bot(bot &&);

    void switch_to();
    void turn_left();
    void turn_right();
};


#endif
