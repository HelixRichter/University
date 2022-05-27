#ifndef BOT_H
#define BOT_H


class bot {
private:
    int x_position {};
    int y_position {};

    char orientation {};
    char steps {};

public:
    bot() noexcept;
    bot(int, int, char);
    bot(const bot &);
    bot(bot &&) noexcept;

    void move();
    void right();
    void left();
};


#endif