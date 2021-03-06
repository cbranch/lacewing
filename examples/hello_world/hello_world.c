
/* See `hello_world.cc` for a C++ version */

#include <lacewing.h>

void onGet(lw_ws * webserver, lw_stream * request)
{
    lw_stream_writef(request, "Hello world from %s", lw_version());
}

int main(int argc, char * argv[])
{
    lw_pump * eventpump = lw_eventpump_new();
    lw_ws * webserver = lw_ws_new(eventpump);

    lw_ws_onget(webserver, onGet);
    lw_ws_host(webserver, 8080);
    
    lw_eventpump_start_event_loop(eventpump);
    
    return 0;
}

