//
// Created by stavih19 on 15/01/2020.
//

#include "boot.h"

using namespace boot;

int main(int argc, const char *args[]) {

    boot::Main<string, string>::main(argc, args);

    this_thread::sleep_for(chrono::milliseconds(120000));

    return 0;
}
