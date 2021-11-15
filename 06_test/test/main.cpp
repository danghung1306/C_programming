#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std::literals::chrono_literals;
using namespace std;

//int test_clock()
//{
//    // lấy thời điểm bắt đầu
//    auto start = steady_clock::now();
//    // lấy thời điểm kết thúc
//    auto end = steady_clock::now();
//    // lấy quãng thời gian end - start, tự động ép kiểu nó về kiểu giá trị số thực double,
//    //kiểu đơn vị mili giây (std::milli hoặc std::ratio<1, 1000>)
//    duration<double, std::milli> elapsed1 = end - start;
//    std::cout << "elapsed1 = " << elapsed1.count() << "ms\n";
//
//    // lấy quãng thời gian end - start, ép kiểu nó về kiểu giá trị số nguyên 32-bit,
//    //kiểu đơn vị 10^-8 giây (std::ratio<1, 100000000>)
//    //phải xài duration_cast vì end-start có thể mang đơn vị là nano giây,
//    //cast về đơn vị 10^-8 giây có thể bị mất vì nano giây, phải ép kiểu tường minh:
//    auto elapsed2 = duration_cast<duration<int, std::ratio<1, 100000000>>>(end - start);
//    std::cout << "elapsed2 = " << elapsed2.count() << " x 10^-8 seconds\n";
//
//    // so sánh dễ dàng
//    auto oneThousandNanosec = 1000ns;
//    std::cout << "elapsed2 " << (elapsed2 < oneThousandNanosec ? "<" : ">=")
//        << " " << oneThousandNanosec.count() << "ns\n";
//    std::cout << oneThousandNanosec.count() << "ns "
//        << (oneThousandNanosec < elapsed1 ? "<" : ">=") << " elapsed1\n";
//    std::cout << oneThousandNanosec.count() << "ns "
//        << (oneThousandNanosec == 1us ? "==" : "!=") << " 1us\n";
//
//    // cộng trừ ngon lành, nếu kiểu giá trị là số thực
//    duration<double> sec;
//    for (int i = 0; i < 123; ++i)
//        sec += elapsed1;
//    for (int i = 0; i < 123; ++i)
//        sec -= elapsed2;
//    std::cout << sec.count() << "s\n";
//
//    // còn kiểu giá trị số nguyên thì vẫn phải ép kiểu tường minh duration_cast
//    //khi thực hiện phép toán với quãng thời gian có kiểu giá trị số thực
//    nanoseconds ns;
//    for (int i = 0; i < 123; ++i)
//        ns += duration_cast<nanoseconds>(elapsed1);
//    for (int i = 0; i < 123; ++i)
//        ns -= elapsed2;
//    std::cout << ns.count() << "ns\n";
//
//    return 0;
//}
int main()
{
    atomic_t u = ATOMIC_INT_LOCK_FREE(0);
    system("pause");
    return 0;
}