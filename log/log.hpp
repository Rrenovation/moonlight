#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

class logs
{
private:
    logs(size_t max_size, size_t max_files) : mlogger(spdlog::rotating_logger_mt("moonlight", "logs/moonlight.txt", max_size, max_files))
    {
        // 定制输出格式
        // spdlog::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");
        mlogger->info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
        spdlog::flush_every(std::chrono::seconds(1));
    }
    ~logs()
    {
        spdlog::shutdown();
    }
    std::shared_ptr<spdlog::logger> mlogger;

public:
    logs(const logs &) = delete;
    logs(logs &&) = delete;
    logs &operator=(const logs &) = delete;
    logs &operator=(logs &&) = delete;

    static logs *instance()
    {
        static logs p(1048576 * 5, 3);
        return &p;
    }

    template <typename... Args>
    inline static void info(Args &&...args)
    {
        logs::instance()->mlogger->info(std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline static void debug(Args &&...args)
    {
        logs::instance()->mlogger->debug(std::forward<Args>(args)...);
    }
};

#endif