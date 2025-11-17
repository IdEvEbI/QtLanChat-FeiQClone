#include "user.h"
#include "message.h"

int main() {
    User user("张三");
    Message msg("Hello");

    user.setMessage(&msg);
    msg.setSender(&user);

    user.printInfo();
    msg.printInfo();

    return 0;
}

