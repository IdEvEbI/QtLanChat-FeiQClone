#include <iostream>
#include <string>

enum OrderStatus {
    Pending,    // 待付款
    Paid,       // 已付款
    Shipped,    // 已发货
    Completed   // 已完成
};

struct Order {
    std::string orderId;
    OrderStatus status;
};

void printOrder(const Order& order) {
    std::cout << "订单号: " << order.orderId << std::endl;
    std::cout << "状态: ";

    switch (order.status) {
        case OrderStatus::Pending:
            std::cout << "待付款" << std::endl;
            break;
        case OrderStatus::Paid:
            std::cout << "已付款" << std::endl;
            break;
        case OrderStatus::Shipped:
            std::cout << "已发货" << std::endl;
            break;
        case OrderStatus::Completed:
            std::cout << "已完成" << std::endl;
            break;
    }
}

void updateOrderStatus(Order& order, OrderStatus newStatus) {
    order.status = newStatus;
    std::cout << "订单状态已更新" << std::endl;
}

int main() {
    Order order = {"ORD001", OrderStatus::Pending};
    printOrder(order);

    updateOrderStatus(order, OrderStatus::Paid);
    printOrder(order);

    return 0;
}
