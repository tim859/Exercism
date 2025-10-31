#pragma once

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond {

    inline const ptime advance(const ptime& date_time) { return date_time + seconds(1000000000); }

}  // namespace gigasecond
