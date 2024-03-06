#pragma once
class Time
{
public:
    Time() = default;
    ~Time() = default;

    void set_target_frame_rate(int _frame_rate);

    void tick();
    void late_tick();

    float get_delta_time() { return dt; }
    int get_frames_per_second() { return frame_rate; }

private:
    float dt = 0;
    float now = 0;
    float last = 0;

    float frame_last = 0;
    float frame_delay = 0;
    float frame_time = 0;

    int frame_rate = 0;
    int frame_count = 0;
};
