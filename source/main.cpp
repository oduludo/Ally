/**
 * main.cpp
 *
 * This is where your app lives.
 */


#include "../include/crow.h"
#include "../include/html.h"


int main() {

    crow::SimpleApp app;

    // Index
    CROW_ROUTE(app, "/")([](){

        mstch::map context{{
               "application_name", std::string{"Ally"}
        }};

        return render(get_html("index.html"), context);

    });

    app.port(8000).multithreaded().run();

    return 0;

}
