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
    [[maybe_unused]] bot(int, int, char);
    [[maybe_unused]] bot(const bot &);
    [[maybe_unused]] bot(bot &&) noexcept;

    [[maybe_unused]] int get_x_position() const;
    [[maybe_unused]] int get_y_position() const;
    [[maybe_unused]] int get_orientation() const;
    [[maybe_unused]] int get_steps() const;

    [[maybe_unused]] void set_x_position(int temp);
    [[maybe_unused]] void set_y_position(int temp);
    [[maybe_unused]] void set_orientation(char temp);
    [[maybe_unused]] void set_steps(char temp);

    [[maybe_unused]] void move();
    [[maybe_unused]] void right();
    [[maybe_unused]] void left();
};


#endif