#ifndef _GATES_H_
#define _GATES_H_

#include "BaseGates.h"

namespace Gates {
    class nandGate : public Gates::Gate {
        private:
            Gates::notGate not0;
            Gates::andGate and0;

        public:
            void run() override {
                and0.input[0] = input[0];
                and0.input[1] = input[1];
                and0.run();

                not0.input = and0.output;
                not0.run();

                output = not0.output;
            }
    };

    class orGate : public Gates::Gate {
        private:
            nandGate nand0;
            notGate not0;
            notGate not1;

        public:
            void run() override {
                not0.input = input[0];
                not1.input = input[1];

                not0.run();
                not1.run();

                nand0.input[0] = not0.output;
                nand0.input[1] = not1.output;

                nand0.run();

                output = nand0.output;
            }
    };

    class XORGate : public Gates::Gate {
        private:
            orGate or0;
            andGate and0;
            nandGate nand0; 

        public:
            void run() override {
                or0.input[0] = input[0];
                or0.input[1] = input[1];
                nand0.input[0] = input[0];
                nand0.input[1] = input[1];

                or0.run();
                nand0.run();

                and0.input[0] = or0.output;
                and0.input[1] = nand0.output;

                and0.run();

                output = and0.output;
            }
    };
}

#endif