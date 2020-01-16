//
// Created by stavih19 on 15/01/2020.
//

#ifndef MILESTONE2_BOOT_H
#define MILESTONE2_BOOT_H

#include <string>
#include "MyserialServer.h"
#include "MyTestClientHandler.h"

namespace boot {

    template<class P, class S>
    class Main {
    public:
        static void main(int argc, const char *args[]) {
            int port = 5420; //atoi(args[1]); // 5400

            MyserialServer<P, S> server = MyserialServer<P, S>();
            auto *handler = new MyTestClientHandler();
            server.start(port, handler);
        }
    };
}

#endif //MILESTONE2_BOOT_H