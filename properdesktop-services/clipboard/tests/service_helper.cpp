#include <chrono>

#include "base/event_loop.h"
#include "base/timer.h"

#include "../clipboard.h"

// Keeps the clipboard for 15 seconds, for checks by hand.
int main()
{
    properdesktop::base::EventLoop loop;
    Clipboard clipboard;
    properdesktop::base::Timer quit;
    quit.setSingleShot(true);
    quit.onTimeout = [&loop] {
        loop.quit();
    };
    quit.start(std::chrono::seconds(15));
    return loop.run();
}
