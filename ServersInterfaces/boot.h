//
// Created by stavih19 on 15/01/2020.
//

#ifndef MILESTONE2_BOOT_H
#define MILESTONE2_BOOT_H

#include <string>
#include "../MyParallelServer.h"
#include "../MyTestClientHandler.h"
#include "../MatrixCLientHandler.h"

namespace boot {
    //template<class P, class S>
    class Main {
    public:
        static void main(int argc, const char *args[]) {
            int port = 5444; //atoi(args[1]); // 5400

            auto server = MyParallelServer();
            auto *handler = new MatrixCLientHandler();
            server.start(port, handler);
        }
    };
}

#endif //MILESTONE2_BOOT_H