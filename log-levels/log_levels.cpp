#include <cctype>
#include <string>

namespace log_line {
    const std::string LOG_LEVEL_I{"INFO"};
    const std::string LOG_LEVEL_W{"WARNING"};
    const std::string LOG_LEVEL_E{"ERROR"};

    std::string message(const std::string &m) {
        std::string ret = m.substr(m.find(": ") + 2);

        return ret;
    }

    std::string log_level(const std::string &m) {
        if (m.find(LOG_LEVEL_I) == 1) {
            return LOG_LEVEL_I;
        } else if (m.find(LOG_LEVEL_W) == 1) {
            return LOG_LEVEL_W;
        }

        return LOG_LEVEL_E;
    }

    std::string reformat(const std::string &m) {
        std::string msg = message(m);
        std::string lev = log_level(m);

        return msg + " (" + lev + ")";
    }
} // namespace log_line
