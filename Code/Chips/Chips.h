#include "../Gates/BaseGates.h"
#include "../Gates/Gates.h"

namespace Chips {
    class Adder : public Gates::CustomGate<3, 2> {
        private:
            Gates::XORGate xor0;
            Gates::XORGate xor1;
            Gates::andGate and0;
            Gates::andGate and1;
            Gates::orGate or0;

        public:
            void run() override {
                xor0.input[0] = input[0];
                xor0.input[1] = input[1];
                xor0.run();

                xor1.input[0] = xor0.output;
                xor1.input[1] = input[2];
                xor1.run();

                and0.input[0] = input[0];
                and0.input[1] = input[1];

                and1.input[0] = xor0.output;
                and1.input[1] = input[2];

                and0.run();
                and1.run();

                or0.input[0] = and0.output;
                or0.input[1] = and1.output;

                or0.run();

                output[0] = xor1.output;
                output[1] = or0.output;
            }
    };

    class Adder8Bit : public Gates::CustomGate<16, 9> {
        private:
            Adder adder0;
            Adder adder1;
            Adder adder2;
            Adder adder3;
            Adder adder4;
            Adder adder5;
            Adder adder6;
            Adder adder7;
        
        public:
            void run() override {
                adder0.input[0] = input[0];
                adder0.input[1] = input[8];
                adder0.input[2] = 0;

                adder0.run();

                adder1.input[0] = input[1];
                adder1.input[1] = input[9];
                adder1.input[2] = adder0.output[1];

                adder1.run();

                adder2.input[0] = input[2];
                adder2.input[1] = input[10];
                adder2.input[2] = adder1.output[1];

                adder2.run();

                adder3.input[0] = input[3];
                adder3.input[1] = input[11];
                adder3.input[2] = adder2.output[1];

                adder3.run();

                adder4.input[0] = input[4];
                adder4.input[1] = input[12];
                adder4.input[2] = adder3.output[1];

                adder4.run();

                adder5.input[0] = input[5];
                adder5.input[1] = input[13];
                adder5.input[2] = adder4.output[1];

                adder5.run();

                adder6.input[0] = input[6];
                adder6.input[1] = input[14];
                adder6.input[2] = adder5.output[1];

                adder6.run();

                adder7.input[0] = input[7];
                adder7.input[1] = input[15];
                adder7.input[2] = adder6.output[1];

                adder7.run();

                output[0] = adder0.output[0];
                output[1] = adder1.output[0];
                output[2] = adder2.output[0];
                output[3] = adder3.output[0];
                output[4] = adder4.output[0];
                output[5] = adder5.output[0];
                output[6] = adder6.output[0];
                output[7] = adder7.output[0];

                output[8] = adder7.output[1];
            }

    };

    class Adder16Bit : public Gates::CustomGate<33, 17> {
        private:
            Adder adder0;
            Adder adder1;
            Adder adder2;
            Adder adder3;
            Adder adder4;
            Adder adder5;
            Adder adder6;
            Adder adder7;
            Adder adder8;
            Adder adder9;
            Adder adder10;
            Adder adder11;
            Adder adder12;
            Adder adder13;
            Adder adder14;
            Adder adder15;
        
        public:
            void run() override {
                adder0.input[0] = input[0];
                adder0.input[1] = input[16];
                adder0.input[2] = input[32];

                adder0.run();

                adder1.input[0] = input[1];
                adder1.input[1] = input[17];
                adder1.input[2] = adder0.output[1];

                adder1.run();

                adder2.input[0] = input[2];
                adder2.input[1] = input[18];
                adder2.input[2] = adder1.output[1];

                adder2.run();

                adder3.input[0] = input[3];
                adder3.input[1] = input[19];
                adder3.input[2] = adder2.output[1];

                adder3.run();

                adder4.input[0] = input[4];
                adder4.input[1] = input[20];
                adder4.input[2] = adder3.output[1];

                adder4.run();

                adder5.input[0] = input[5];
                adder5.input[1] = input[21];
                adder5.input[2] = adder4.output[1];

                adder5.run();

                adder6.input[0] = input[6];
                adder6.input[1] = input[22];
                adder6.input[2] = adder5.output[1];

                adder6.run();

                adder7.input[0] = input[7];
                adder7.input[1] = input[23];
                adder7.input[2] = adder6.output[1];

                adder7.run();

                adder8.input[0] = input[8];
                adder8.input[1] = input[24];
                adder8.input[2] = adder7.output[1];

                adder8.run();

                adder9.input[0] = input[9];
                adder9.input[1] = input[25];
                adder9.input[2] = adder8.output[1];

                adder9.run();

                adder10.input[0] = input[10];
                adder10.input[1] = input[26];
                adder10.input[2] = adder9.output[1];

                adder10.run();

                adder11.input[0] = input[11];
                adder11.input[1] = input[27];
                adder11.input[2] = adder10.output[1];

                adder11.run();

                adder12.input[0] = input[12];
                adder12.input[1] = input[28];
                adder12.input[2] = adder11.output[1];

                adder12.run();

                adder13.input[0] = input[13];
                adder13.input[1] = input[29];
                adder13.input[2] = adder12.output[1];

                adder13.run();

                adder14.input[0] = input[14];
                adder14.input[1] = input[30];
                adder14.input[2] = adder13.output[1];

                adder14.run();

                adder15.input[0] = input[15];
                adder15.input[1] = input[31];
                adder15.input[2] = adder14.output[1];

                adder15.run();

                output[0] = adder0.output[0];
                output[1] = adder1.output[0];
                output[2] = adder2.output[0];
                output[3] = adder3.output[0];
                output[4] = adder4.output[0];
                output[5] = adder5.output[0];
                output[6] = adder6.output[0];
                output[7] = adder7.output[0];
                output[8] = adder8.output[0];
                output[9] = adder9.output[0];
                output[10] = adder10.output[0];
                output[11] = adder11.output[0];
                output[12] = adder12.output[0];
                output[13] = adder13.output[0];
                output[14] = adder14.output[0];
                output[15] = adder15.output[0];

                output[16] = adder15.output[1];
            }
    };

    // class ALU : public Gates::CustomGate<33, 18> {
    //     private:
    //         Gates::XORGate xor0;
    //         Gates::XORGate xor1;
    //         Gates::XORGate xor2;
    //         Gates::XORGate xor3;
    //         Gates::XORGate xor4;
    //         Gates::XORGate xor5;
    //         Gates::XORGate xor6;
    //         Gates::XORGate xor7;
    //         Gates::XORGate xor8;
    //         Gates::XORGate xor9;
    //         Gates::XORGate xor10;
    //         Gates::XORGate xor11;
    //         Gates::XORGate xor12;
    //         Gates::XORGate xor13;
    //         Gates::XORGate xor14;
    //         Gates::XORGate xor15;

    //         Adder16Bit adder16_bit0;

    //         Gates::andGate and0;
    //         Gates::notGate not0;

    //     public:
    //         void run() override {
    //             xor0.input[0] = input[16];
    //             xor1.input[0] = input[17];
    //             xor2.input[0] = input[18];
    //             xor3.input[0] = input[19];
    //             xor4.input[0] = input[20];
    //             xor5.input[0] = input[21];
    //             xor6.input[0] = input[22];
    //             xor7.input[0] = input[23];
    //             xor8.input[0] = input[24];
    //             xor9.input[0] = input[25];
    //             xor10.input[0] = input[26];
    //             xor11.input[0] = input[27];
    //             xor12.input[0] = input[28];
    //             xor13.input[0] = input[29];
    //             xor14.input[0] = input[30];
    //             xor15.input[0] = input[31];

    //             xor0.input[1] = input[32];
    //             xor1.input[1] = input[32];
    //             xor2.input[1] = input[32];
    //             xor3.input[1] = input[32];
    //             xor4.input[1] = input[32];
    //             xor5.input[1] = input[32];
    //             xor6.input[1] = input[32];
    //             xor7.input[1] = input[32];
    //             xor8.input[1] = input[32];
    //             xor9.input[1] = input[32];
    //             xor10.input[1] = input[32];
    //             xor11.input[1] = input[32];
    //             xor12.input[1] = input[32];
    //             xor13.input[1] = input[32];
    //             xor14.input[1] = input[32];
    //             xor15.input[1] = input[32];

    //             xor0.run();
    //             xor1.run();
    //             xor2.run();
    //             xor3.run();
    //             xor4.run();
    //             xor5.run();
    //             xor6.run();
    //             xor7.run();
    //             xor8.run();
    //             xor9.run();
    //             xor10.run();
    //             xor11.run();
    //             xor12.run();
    //             xor13.run();
    //             xor14.run();
    //             xor15.run();

    //             adder16_bit0.input[0] = input[0];
    //             adder16_bit0.input[1] = input[1];
    //             adder16_bit0.input[2] = input[2];
    //             adder16_bit0.input[3] = input[3];
    //             adder16_bit0.input[4] = input[4];
    //             adder16_bit0.input[5] = input[5];
    //             adder16_bit0.input[6] = input[6];
    //             adder16_bit0.input[7] = input[7];
    //             adder16_bit0.input[8] = input[8];
    //             adder16_bit0.input[9] = input[9];
    //             adder16_bit0.input[10] = input[10];
    //             adder16_bit0.input[11] = input[11];
    //             adder16_bit0.input[12] = input[12];
    //             adder16_bit0.input[13] = input[13];
    //             adder16_bit0.input[14] = input[14];
    //             adder16_bit0.input[15] = input[15];
    //             adder16_bit0.input[16] = xor0.output;
    //             adder16_bit0.input[17] = xor1.output;
    //             adder16_bit0.input[18] = xor2.output;
    //             adder16_bit0.input[19] = xor3.output;
    //             adder16_bit0.input[20] = xor4.output;
    //             adder16_bit0.input[21] = xor5.output;
    //             adder16_bit0.input[22] = xor6.output;
    //             adder16_bit0.input[23] = xor7.output;
    //             adder16_bit0.input[24] = xor8.output;
    //             adder16_bit0.input[25] = xor9.output;
    //             adder16_bit0.input[26] = xor10.output;
    //             adder16_bit0.input[27] = xor11.output;
    //             adder16_bit0.input[28] = xor12.output;
    //             adder16_bit0.input[29] = xor13.output;
    //             adder16_bit0.input[30] = xor14.output;
    //             adder16_bit0.input[31] = xor15.output;

    //             adder16_bit0.input[32] = input[32];
    //             adder16_bit0.run();

    //             output[0] = adder16_bit0.output[0];
    //             output[1] = adder16_bit0.output[1];
    //             output[2] = adder16_bit0.output[2];
    //             output[3] = adder16_bit0.output[3];
    //             output[4] = adder16_bit0.output[4];
    //             output[5] = adder16_bit0.output[5];
    //             output[6] = adder16_bit0.output[6];
    //             output[7] = adder16_bit0.output[7];
    //             output[8] = adder16_bit0.output[8];
    //             output[9] = adder16_bit0.output[9];
    //             output[10] = adder16_bit0.output[10];
    //             output[11] = adder16_bit0.output[11];
    //             output[12] = adder16_bit0.output[12];
    //             output[13] = adder16_bit0.output[13];
    //             output[14] = adder16_bit0.output[14];
    //             output[15] = adder16_bit0.output[15];

    //             output[16] = adder16_bit0.output[15];

    //             not0.input = input[32];
    //             not0.run();

    //             and0.input[0] = adder16_bit0.output[16];
    //             and0.input[1] = not0.output;

    //             and0.run();

    //             output[17] = and0.output;
    //         }
    // };
}