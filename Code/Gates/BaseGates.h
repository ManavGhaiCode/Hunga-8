#ifndef _BASE_GATES_H_
#define _BASE_GATES_H_

#include <vector>

namespace Gates {
    struct SimpleGate {
        bool input;
        bool output;

        virtual void run() = 0;
    };

    class Gate {
        public:
            bool input[2];
            bool output;

            virtual void run() = 0;
    };

    class DoubleGate {
        public:
            bool input[2];
            bool output[2];

            virtual void run() = 0;
    };

    template<int IF, int OF> class CustomGate {
        public:
            bool input[IF];
            bool output[OF];

            virtual void run() = 0; 
    };

    class notGate : public SimpleGate {
        public:
            void run() override {
                output = !input;
            }
    };

    class andGate : public Gate {
        public:
            void run() override {
                output = input[0] && input[1];
            }
    };
}

#endif