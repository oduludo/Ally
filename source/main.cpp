//
// Created by Ludo van Orden on 31/10/2018.
//

#include "../include/crow.h"

int main() {

    crow::SimpleApp app;

    // Add item
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.port(8000).multithreaded().run();

    return 0;

}
