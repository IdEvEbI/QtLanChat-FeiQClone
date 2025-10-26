// 项目中的实际应用示例
#include <iostream>

int main() {
    std::cout << "=== QtLanChat 消息类型处理 ===" << std::endl;
    
    char messageType;
    std::cout << "请输入消息类型（t=文本, i=图片, f=文件, v=语音）: ";
    std::cin >> messageType;
    
    switch (messageType) {
        case 't':
        case 'T':
            std::cout << ">>> 处理文本消息" << std::endl;
            std::cout << ">>> 显示文本内容" << std::endl;
            break;
        case 'i':
        case 'I':
            std::cout << ">>> 处理图片消息" << std::endl;
            std::cout << ">>> 加载图片" << std::endl;
            std::cout << ">>> 显示图片预览" << std::endl;
            break;
        case 'f':
        case 'F':
            std::cout << ">>> 处理文件消息" << std::endl;
            std::cout << ">>> 下载文件" << std::endl;
            std::cout << ">>> 显示文件信息" << std::endl;
            break;
        case 'v':
        case 'V':
            std::cout << ">>> 处理语音消息" << std::endl;
            std::cout << ">>> 播放语音" << std::endl;
            break;
        default:
            std::cout << ">>> 未知的消息类型" << std::endl;
            std::cout << ">>> 无法处理此消息" << std::endl;
            break;
    }
    
    return 0;
}

